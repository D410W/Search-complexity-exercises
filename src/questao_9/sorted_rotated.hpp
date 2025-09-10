#pragma once

namespace ths {

  template<typename Valuetype, typename Cmp>
  Valuetype *bsearch(Valuetype *first, Valuetype *last, Valuetype target, Cmp lt) {

    Valuetype *left = first;
    Valuetype *right = last;
    Valuetype *middle = nullptr;

    while (left != right) {
      middle = left + (right - left)/2;

      if (*middle == target) {
        return middle;
      } else if (lt(target, *middle)) {
        right = middle;
      } else {
        left = middle + 1;
      }
    }

    return last;
  }

  template<typename Valuetype, typename Cmp>
  Valuetype *bsearch_rot(Valuetype *first, Valuetype *last, Valuetype target, Cmp lt) {
    
    Valuetype *max = first;
    for (Valuetype *it = first + 1; it != last; ++it) {
      if (lt( *it, *(it-1) )) {
        max = it;
        break;
      }
    }
    
    Valuetype *res1 = bsearch(first, max, target, lt);
    Valuetype *res2 = bsearch(max, last, target, lt);
    
    if (res1 != max) return res1;
    if (res2 != last) return res2;
    return last;
    
  }

}
