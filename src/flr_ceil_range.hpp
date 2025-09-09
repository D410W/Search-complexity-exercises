#pragma once

namespace ths {
  
  template<typename valuetype, typename Cmp>
  valuetype *lbound(valuetype *first, valuetype *last, valuetype value, Cmp lt) {

    valuetype *left = first;
    valuetype *right = last;
    valuetype *middle = nullptr;

    while (left != right) {
      middle = left + (right - left)/2;

      if (*middle == value) {
        right = middle;     // same action as if value < middle
      } else if (lt(value, *middle)) {
        right = middle;
      } else {
        left = middle + 1;
      }
    }

    return left;
  }

  template<typename valuetype, typename Cmp>
  valuetype *ubound(valuetype *first, valuetype *last, valuetype value, Cmp lt) {

    valuetype *left = first;
    valuetype *right = last;
    valuetype *middle = nullptr;

    while (left != right) {
      middle = left + (right - left)/2;

      if (*middle == value) {
        left = middle + 1;     // same action as if value > middle
      } else if (lt(value, *middle)) {
        right = middle;
      } else {
        left = middle + 1;
      }
    }

    return left;
  }
  
  template<typename valuetype, typename Cmp>
  std::pair<valuetype, valuetype> flr_ceil_range(valuetype *first, valuetype *last, valuetype target, Cmp lt) {
    valuetype *lower = lbound(first, last, target, lt);
    valuetype *upper = ubound(first, last, target, lt);
    
    std::pair<valuetype, valuetype> ans{};
    if (*lower == target) ans.first = *lower;
    else ans.first = *(lower-1);

    if (*(upper-1) == target) ans.second = *(upper-1);
    else ans.second = *upper;
    
    return ans;

  }
  
}
