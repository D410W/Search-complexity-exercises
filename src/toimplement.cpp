/*!
 * @author Thales Justino
 * @date August 30th, 2025.
 * @date September 1st, 2025.
 */

#ifndef GRAAL_HPP
#define GRAAL_HPP

#include <utility>
using std::pair;

namespace graal {

/*!
 * Finds and returns a pair with the smallest and greatest elements in a range.
 *
 * @tparam Itr Iterator to the range.
 * @tparam Compare A regular comparison function.Comparison functor.
 *
 * @param first Pointer to the first element of the range
 * (inclusive).
 * @param last Pointer to the last+1 element of the range
 * (exclusive).
 * @param cmp The comparison function that return true if the first element is
 * *less* than the second.
 *
 * @return A pair of the smallest and greatest elements.
 *
 */
template <typename Itr, typename Compare>
std::pair<Itr, Itr> minmax(Itr first, Itr last, Compare cmp) {
  Itr min{first}; //
  Itr max{first}; // min and max default to first, in case the range has size = 0;
  
  for  (Itr it{first}; it != last; ++it) {       // iterator 'it' for looking through all elements in the range.
    if (cmp(*it, *min)) min = it;                // if (*it < *min) then: min = it
    
    if (!cmp(*it, *max)) max = it; // if (*it >= *max) then: max = it
                                   // this always returns the last instance of the greatest element.
  }
    
  return {min, max};
}

/*!
 * Reverses the elements in a range by switching (first with last), etc.
 *
 * @tparam BidirIt Bi-directional terator to the range.
 *
 * @param first Pointer to the first element of the range we want to reverse
 * (inclusive).
 * @param last Pointer to the last+1 element of the range we want to reverse
 * (exclusive).
 *
 */
template <class BidirIt> void reverse(BidirIt first, BidirIt last) {
  --last;                  // decreases 'last' iterator so it points to an element in the range.
  while (first < last) {
    std::swap(*first, *last); // uses std::swap for convenience.
    
    ++first; // increases left pointer and decreases right pointer so that 'first' and 'last'
    --last;  // elements swap, then 'second' and 'second to last', 'third' and 'third to last', etc.
  }
}

/*!
 * Copies the range 'first' through 'last' to the provided start location 'd_first'
 * in memory. Assumes there's enough memory already allocated.
 *
 * @tparam InputIt Iterator to the range.
 *
 * @param first Pointer to the first element of the range to copy.
 * (inclusive).
 * @param last Pointer to the last+1 element of the range to copy.
 * (exclusive).
 * @param d_first Pointer to the first element of the copied result range.
 * (inclusive).
 *
 * @return Pointer to the last+1 element of the copied result range.
 *
 */
template <class InputIt>
InputIt copy(InputIt first, InputIt last, InputIt d_first) {
  // assumes there's enough memory space allocated. doesn't make any initial checks.
  while (first < last) {
    *d_first = *first; // 'copy range' element gets assigned with 'original range' element.
    
    ++d_first; // increments both d_first and first so that both are in the same relative position:
    ++first;   // they both start at arr1[0] and arr2[0], then [1] and [1], then [2] and [2], etc.

  }
  
  return d_first;
}

/*!
 * Finds and returns the address of an element in the provided range which is
 * true for the provided boolean function.
 *
 * @tparam InputIt Iterator to the range.
 * @tparam UnaryPredicate A regular boolean function.
 *
 * @param first Pointer to the first element of the range
 * (inclusive).
 * @param last Pointer to the last+1 element of the range
 * (exclusive).
 * @param p The boolean function that describes the 'found' condition.
 *
 * @return A pointer to the found element, or 'last' if not found.
 *
 */
template <class InputIt, class UnaryPredicate>
InputIt find_if(InputIt first, InputIt last, UnaryPredicate p) {
  while (first < last) { // iterates through all elements in the range
    if (p(*first)) return first;      // returns first instance of an element which satisfies condition 'p'
    ++first;             // iterates through all elements in the range
  }
  return last;    // if not found, return 'last';
}

/*!
 * Returns 'true' if all elements in a provided range return true for
 * a predicate 'p'. Returns 'false' otherwise.
 *
 * @tparam InputIt Iterator to the range.
 * @tparam UnaryPredicate A regular boolean function.
 *
 * @param first Pointer to the first element of the range
 * (inclusive).
 * @param last Pointer to the last+1 element of the range
 * (exclusive).
 * @param p The boolean function that describes the desired predicate.
 *
 * @return A boolean which is false if at least one element is false for 'p'.
 *
 */
template <class InputIt, class UnaryPredicate>
bool all_of(InputIt first, InputIt last, UnaryPredicate p) {
  while (first < last) { // iterates through all elements in the range
    if (!p(*first)) return false; // if at least one element doesn't have the property 'p', then
                                  // not 'all elements are true for p'. return false.
    ++first;             // iterates through all elements in the range
  }
  return true;        // otherwise, return true.
}

/*!
 * Returns 'true' if at least one element in a provided range returns true for
 * a predicate 'p'. Returns 'false' otherwise.
 *
 * @tparam InputIt Iterator to the range.
 * @tparam UnaryPredicate A regular boolean function.
 *
 * @param first Pointer to the first element of the range
 * (inclusive).
 * @param last Pointer to the last+1 element of the range
 * (exclusive).
 * @param p The boolean function that describes the desired predicate.
 *
 * @return A boolean which is false only if all elements are false for 'p'.
 *
 */
template <class InputIt, class UnaryPredicate>
bool any_of(InputIt first, InputIt last, UnaryPredicate p) {
  while (first < last) { // iterates through all elements in the range.
    if (p(*first)) return true;   // if at least one element is true for 'p', returns true.
    ++first;             // iterates through all elements in the range.
  }
  return false;  // otherwise, return false.
}

/*!
 * Returns 'true' if no elements in a provided range return true for
 * a predicate 'p'. Returns 'false' otherwise.
 *
 * @tparam InputIt Iterator to the range.
 * @tparam UnaryPredicate A regular boolean function.
 *
 * @param first Pointer to the first element of the range
 * (inclusive).
 * @param last Pointer to the last+1 element of the range
 * (exclusive).
 * @param p The boolean function that describes the desired predicate.
 *
 * @return A boolean which is false if at least one element is true for 'p'.
 *
 */
template <class InputIt, class UnaryPredicate>
bool none_of(InputIt first, InputIt last, UnaryPredicate p) {
  while (first < last) {   // iterates through all elements in the range.
    if (p(*first)) return false;  // if at least one element is true for 'p', then 'no elements have this
    ++first;                      // property' is false.
  }
  return true; // otherwise, true.
}

/*!
 * Checks if a range [first1; last1) has the same elements as another
 * range starting at 'first2'. Assumes both have the same length.
 *
 * @tparam InputIt1 Iterator to the first range.
 * @tparam InputIt2 Iterator to the second range.
 * @tparam Equal A regular boolean function.
 *
 * @param first1 Pointer to the first element of the first range
 * (inclusive).
 * @param last1 Pointer to the last+1 element of the first range
 * (exclusive).
 * @param first2 Pointer to the first element of the second range
 * (inclusive).
 * @param eq A binary function that returns true if both elements
 * are equal. Returns false otherwise.
 *
 * @return A boolean which represents (range1 == range2).
 *
 */
template <class InputIt1, class InputIt2, class Equal>
bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2, Equal eq) {
  // assumes both ranges have the same length. no initial check.
  while (first1 < last1) {
    if (*first1 != *first2) return false; // if elements in the same relative position of their arrays
                                          // are different, then the ranges are different.
    ++first1;    // increments both first1 and first2 so that both are in the same relative position:
    ++first2;    // they both start at arr1[0] and arr2[0], then [1] and [1], then [2] and [2], etc.
  }
  return true;
}

/*!
 * Checks if a range [first1; last1) has the same elements as another
 * range [first2; last2).
 *
 * @tparam InputIt1 Iterator to the first range.
 * @tparam InputIt2 Iterator to the second range.
 * @tparam Equal A regular boolean function.
 *
 * @param first1 Pointer to the first element of the first range
 * (inclusive).
 * @param last1 Pointer to the last+1 element of the first range
 * (exclusive).
 * @param first2 Pointer to the first element of the second range
 * (inclusive).
 * @param last2 Pointer to the last+1 element of the second range
 * (exclusive).
 * @param eq A binary function that returns true if both elements
 * are equal. Returns false otherwise.
 *
 * @return A boolean which represents (range1 == range2).
 *
 */
template <class InputIt1, class InputIt2, class Equal>
bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2,
           Equal eq) {
  if ( (last1 - first1) != (last2 - first2) ) return false;    // if sizes are different, ranges are different.
  
  while (first1 < last1) {            // goes through all elements
    if (*first1 != *first2) return false; // if an element at current position is the same as another
    ++first1;                             // element at the same relative position in the '2' range, then
    ++first2;                             // everything is good. if they are different,  both ranges are different.
    // increments both first1 and first2 so that both are in the same relative position:
    // they both start at arr1[0] and arr2[0], then [1] and [1], then [2] and [2], etc.
  }
  return true;
}

/*!
 * Modifies provided range so that it removes repeated elements,
 * while maintaining the order of elements.
 *
 * @tparam InputIt Iterator to the range.
 * @tparam Equal A regular boolean function.
 *
 * @param first1 Pointer to the first element of the first range
 * (inclusive).
 * @param last1 Pointer to the last+1 element of the first range
 * (exclusive).
 * @param eq A binary function that returns true if both elements
 * are equal. Returns false otherwise.
 *
 * @return A pointer to the last+1 element of the new 'unique' range.
 *
 */
template <class InputIt, class Equal>
InputIt unique(InputIt first, InputIt last, Equal eq) {
  
  InputIt unique_first = first;    // saving 'first'.
  InputIt unique_last = first;     // keeping track of 'last' so that this new range called 'unique'
                                   // acts as an unordered set.
  while (first < last) {         // processing all elements in provided range.
  
    bool is_repeated = false;
    for (InputIt it = unique_first; it < unique_last; ++it) {      // checking whole 'unique' range, which is used as an unordered set.
      if (eq(*it, *first)) is_repeated = true;                     // if '*first' is already present in 'unique' range, repeated = true.
    }
    
    if (!is_repeated) {             // if element is new:
      *unique_last = *first;        // add it to the last position.
      ++unique_last;                // increase size of this new 'unique' range.
    }
    
    ++first;                     // processing all elements in provided range.
  }
  
  return unique_last;
}

/*!
 * Partitions the provided range in two so that the elements which return true
 * for a provided boolean function are in the first section, while the ones
 * who return false are in the second part.
 * Basically splits the provided range into two, the first one being the 'true'
 * one, and the second one being the 'false' one.
 *
 * @tparam ForwardIt Iterator to the range.
 * @tparam UnaryPredicate A regular boolean function.
 *
 * @param first1 Pointer to the first element of the range
 * (inclusive).
 * @param last1 Pointer to the last+1 element of the range
 * (exclusive).
 * @param p A boolean function that returns true if the element has
 * the desired property.
 *
 * @return A pointer to the first element of the second 'false' range.
 *
 */
template <class ForwardIt, class UnaryPredicate>
ForwardIt partition(ForwardIt first, ForwardIt last, UnaryPredicate p) {

  ForwardIt first2 = first;     // keeps track of the start of the 'false' range.
  
  while (first < last) {        // processing all elements
  
    if (p(*first)) {                  // if *first has the property we're looking for:
      std::swap(*first, *first2);       // puts this element into the last position of 'true' range, which
      ++first2;                         // is equal to the start of the 'false' range, since [first, last).
    }
  
    ++first;                     // processing all elements
  }

  return first2;    // returns the start of the second 'false' range.
}

} // namespace graal.

#endif
