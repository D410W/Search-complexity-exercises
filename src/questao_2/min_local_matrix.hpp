#pragma once

namespace ths {
  
  template<typename Itr>
  Itr access_matrix(Itr first, std::pair<unsigned int, unsigned int> size,
                               std::pair<unsigned int, unsigned int> index) {
    
    return first + ( index.first * size.second + index.second );
    
  }
  
  template<typename Itr, typename Cmp>
  Itr local_horiz_min(Itr first, Itr last, Cmp lt){
    Itr mid = first + (last-first)/2;
    
    bool changed{true};
    while (changed) {
      changed = false;
      
      if ( mid != first && lt( *(mid-1), *mid ) ) {
        --mid;
        changed = true;
      } else if ( (mid+1) != last && lt( *(mid+1), *mid ) ) {
        ++mid;
        changed = true;
      }
      
    }
    
    return mid;
  }
  
  template<typename Itr, typename Cmp>
  Itr local_vertical_min(Itr first, std::pair<unsigned int, unsigned int> size, Cmp lt){
    Itr mid = first + (size.first/2) * size.second;
    
    bool changed{true};
    while (changed) {
      changed = false;
      
      if ( mid != first && lt( *(mid-size.second), *mid ) ) {
        mid -= size.second;
        changed = true;
      } else if ( (mid+size.second) != (first + size.first * size.second) && lt( *(mid+size.second), *mid ) ) {
        mid += size.second;
        changed = true;
      }
      
    }
    
    return mid;
  }
  
  template<typename Itr, typename Cmp>
  Itr local_min_m(Itr matrix, std::pair<unsigned int, unsigned int> size, Cmp lt){
    
    Itr pos_first = access_matrix(matrix, size, {size.first/2, 0});
    
    int i1 = size.first/2;
    int i2 = 0;
    
    Itr candidate = local_horiz_min(pos_first, pos_first + size.second, lt);
    
    bool horizontal{false};
    while (true) {
    
      bool is_min = true;
      
      if ( i1 > 0 && !lt(*candidate, *access_matrix(matrix, size, {i1-1, i2})) ) is_min = false;
      if ( i1 < size.first-1 && !lt(*candidate, *access_matrix(matrix, size, {i1+1, i2})) ) is_min = false;
      if ( i2 > 0 && !lt(*candidate, *access_matrix(matrix, size, {i1, i2-1})) ) is_min = false;
      if ( i2 < size.second-1 && !lt(*candidate, *access_matrix(matrix, size, {i1, i2+1})) ) is_min = false;
      
      if (is_min) break;
      
      if (horizontal) {
        pos_first = access_matrix(matrix, size, {i1, 0});
        candidate = local_horiz_min(pos_first, pos_first + size.second, lt);
      } else {
        pos_first = access_matrix(matrix, size, {0, i2});
        candidate = local_vertical_min(pos_first, {size.first, size.second}, lt);
      }
      
      i1 = (candidate - matrix)/size.first;
      i2 = (candidate - matrix)%size.second;
            
      horizontal = !horizontal;
      
    }
    
    return candidate;
  }
  
}
