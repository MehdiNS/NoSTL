#pragma once
#include <math.h>

namespace nostd {
template <class T> const T &max(const T &a, const T &b) {
  return (a > b) ? a : b;
}

template <class T> const T &min(const T &a, const T &b) {
  return (a < b) ? a : b;
}

template <class T> const T &clamp(const T &x, const T &lo, const T &hi) {
  return (x < lo) ? lo : (x > hi ? hi : x);
}

template <class T> const T &saturate(const T &x) {
  static const T lo = 0;
  static const T hi = 1;
  return clamp(x, lo, hi);
}
} // namespace nostd
