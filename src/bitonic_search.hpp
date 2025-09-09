#pragma once

namespace ths {

  template<typename valuetype, typename Cmp>
  valuetype *bsearch(valuetype *first, valuetype *last, valuetype target, Cmp lt, bool is_crescent = true) {

    valuetype *left = first;
    valuetype *right = last;
    valuetype *middle = nullptr;

    while (left != right) {

      middle = left + (right - left)/2;
      
      if (is_crescent) {
        if (*middle == target) {
          return middle;
        } else if (lt(target, *middle)) {
          right = middle;
        } else {
          left = middle + 1;
        }
     } else {
        if (*middle == target) {
          return middle;
        } else if (lt(target, *middle)) {
          left = middle + 1;
        } else {
          right = middle;
        }
     }
    }

    return last;
  }
  
  template<typename valuetype, typename Cmp>
  valuetype *bsearch_max(valuetype *first, valuetype *last, valuetype value, Cmp lt) {
    
    valuetype *left = first;
    valuetype *right = last;
    valuetype *middle = nullptr;

    while (left != right) {

      middle = left + (right - left)/2;

      if (!lt( *middle, *(middle-1) ) && !lt( *middle, *(middle+1) )) {
        return middle;
      } else if (lt( *middle, *(middle-1) )) {
        right = middle;
      } else {
        left = middle + 1;
      }
      
    }

    return last;
  }

  template<typename valuetype, typename Cmp>
  valuetype *bitonic_search(valuetype *first, valuetype *last, valuetype target, Cmp lt) {
    
    valuetype *max = bsearch_max(first, last, target, lt);
    
    valuetype *crescent_find = bsearch(first, max, target, lt, true);
    valuetype *decrescent_find = bsearch(max, last, target, lt, false);
    
    // std::cout << (crescent_find-first) << ' ' << (decrescent_find-first) << '\n';
    // std::cout << *crescent_find << ' ' << *decrescent_find << '\n';
    
    if (crescent_find != max) return crescent_find;
    if (decrescent_find != last) return decrescent_find;
    
    return last;
  }

}
