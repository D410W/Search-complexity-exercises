/*!
 * \file searching.cpp
 * Binary search, Linear search, Upper bound, lower bound implementation for an
 * array of integers.
 * \author Selan R. dos Santos
 * \date June 17th, 2021.
 */

#include "searching.hpp"

namespace sa {

/*!
 * Performs a **linear search** for `value` in `[first;last)` and returns a
 * pointer to the location of `value` in the range `[first,last]`, or `last` if
 * no such element is found.
 * \param first Pointer to the begining of the data range.
 * \param last Pointer just past the last element of the data range.
 * \param value The value we are looking for.
 */
value_type *lsearch(value_type *first, value_type *last, value_type value) {

  while (first < last) {

    if (*first == value)
      return first;

    ++first;
  }

  return last;
}

/*!
 * Performs a **binary search** for `value` in `[first;last)` and returns a
 * pointer to the location of `value` in the range `[first,last]`, or `last` if
 * no such element is found.
 * \note The range **must** be sorted.
 * \param first Pointer to the begining of the data range.
 * \param last Pointer just past the last element of the data range.
 * \param value The value we are looking for.
 */
value_type *bsearch(value_type *first, value_type *last, value_type value) {

  value_type *left = first;
  value_type *right = last;
  value_type *middle = nullptr;

  while (left != right) {

    long number_of_elements = (long)(right - left);

    middle = left + number_of_elements/2;

    if (*middle == value) {
      return middle;
    } else if (*middle > value) {
      right = middle;
    } else {
      left = middle + 1;
    }
  }

  return last;
}
/*!
 * Performs a **binary search** for `value` in `[first;last)` and returns a
 * pointer to the location of `value` in the range `[first,last]`, or `last` if
 * no such element is found.
 * \note The range **must** be sorted.
 * \param first Pointer to the begining of the data range.
 * \param last Pointer just past the last element of the data range.
 * \param value The value we are looking for.
 */
value_type *bsearch_rec(value_type *first, value_type *last, value_type value) {
  long number_of_elements = (long)(last - first);
  
  if (number_of_elements == 0) return last;
  
  value_type *middle = first + number_of_elements/2;
  
  if (*middle == value) {
    return middle;
  } else if (*middle < value) {
    return bsearch_rec(middle + 1, last, value);
  } else {
  
    value_type *answer = bsearch_rec(first, middle, value);
    
    if (answer == middle) {
      return last;
    } else {
      return answer;
    }
    
  }
}

/*!
 * Returns a pointer to the first element in the range `[first, last)` that is
 * _not less_  than (i.e. greater or equal to) `value`, or `last` if no such
 * element is found.
 * \note The range **must** be sorted.
 * \param first Pointer to the begining of the data range.
 * \param last Pointer just past the last element of the data range.
 * \param value The value we are looking for.
 */
value_type *lbound(value_type *first, value_type *last, value_type value) {

  value_type *left = first;
  value_type *right = last;
  value_type *middle = nullptr;

  while (left != right) {

    long number_of_elements = (long)(right - left);

    middle = left + number_of_elements/2;

    if (*middle == value) {
      right = middle;     // same action as if value < middle
    } else if (*middle > value) {
      right = middle;
    } else {
      left = middle + 1;
    }
  }

  return left;
}

/*!
 * Returns a pointer to the first element in the range `[first, last)` that is
 * _greater_  than `value`, or `last` if no such element is found.
 * \note The range **must** be sorted.
 * \param first Pointer to the begining of the data range.
 * \param last Pointer just past the last element of the data range.
 * \param value The value we are looking for.
 */
value_type *ubound(value_type *first, value_type *last, value_type value) {

  value_type *left = first;
  value_type *right = last;
  value_type *middle = nullptr;

  while (left != right) {

    long number_of_elements = (long)(right - left);

    middle = left + number_of_elements/2;

    if (*middle == value) {
      left = middle + 1;     // same action as if value > middle
    } else if (*middle > value) {
      right = middle;
    } else {
      left = middle + 1;
    }
  }

  return left;
}

value_type *tsearch(value_type *first, value_type *last, value_type value) {

  value_type *left = first;
  value_type *right = last;
  
  value_type *third_left = nullptr;
  value_type *third_right = nullptr;

  while (left != right) {

    long number_of_elements = (long)(right - left);

    third_left = left + number_of_elements/3;
    third_right = third_left + number_of_elements/3;
    
    if (*third_left == value) return third_left;
    else if (*third_right == value) return third_right;

    else if (value < *third_left) {    // check if value is in the first third of the section
      right = third_left;
    } else if (value > *third_right) { // check if value is in the last third of the section
      left = third_right + 1;
    } else {                           // if not in first or third lefts, then it's in the middle.
      left = third_left + 1;
      right = third_right;
    }
  }

  return last;
}

} // namespace sa
