#pragma once

namespace ths {
    
  template<typename valuetype, typename Cmp>
  valuetype *bin_search_dupl(valuetype *first, valuetype *last, valuetype target, Cmp lt) {

    valuetype *left = first;
    valuetype *right = last;
    valuetype *middle = nullptr;

    while (left != right) {

      long number_of_elements = (long)(right - left);

      middle = left + number_of_elements/2;

      if (*middle == target) {
        right = middle;     // same action as if value < middle
      } else if (*middle > target) {
        right = middle;
      } else {
        left = middle + 1;
      }
    }
    
    if (*left == target) return left;
    else return last;
  }
  
}
