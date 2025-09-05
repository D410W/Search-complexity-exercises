#include <cmath>
#include "math_lib.hpp"

namespace mb {

value_type add(value_type a, value_type b) { return a + b; }
value_type mul(value_type a, value_type b) { return a * b; }
value_type div(value_type a, value_type b) { return a / b; }
value_type exp(value_type a, value_type b) { return std::pow(a, b); }
}  // namespace mb
