#pragma once

namespace ths {

  void sort(int *first, int *last) {
    
    while (first != last) {
      int *min = first;
      for (int *it = first+1; it != last; ++it) if (*it < *min) min = it;
      
      std::iter_swap(min, first);
      
      ++first;
    }
        
  }
  
  bool has_duplicate(int *first, int *last) {
  
    sort(first, last);

    while (first != last-1) {
      
      if (*first == *(first+1)) return true;
      
      ++first;
    }
    
    return false;
    
  }
  
}
