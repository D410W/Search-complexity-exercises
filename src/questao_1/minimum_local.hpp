#pragma once

namespace ths {
  
  template<typename Itr, typename Cmp>
  Itr local_min(Itr first, Itr last, Cmp lt){
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
  
}
