#pragma once

namespace ths {
  
  // passed range must be *strictly* crescent, otherwise
  // the binary search approach doesn't work.
  template<typename Itr, typename Cmp>
  Itr find_identity(Itr first, Itr last, Cmp lt) {
    
    Itr left = first;
    Itr right = last;
    Itr middle = nullptr;

    while (left != right) {
      middle = left + (right-left)/2;
            
      if (*middle == (middle - first)) {
        return middle;
      } else if (lt(middle - first, *middle)) {
        right = middle;
      } else {
        left = middle + 1;
      }
      
    }
    
    return last;
    
  }
  
}
