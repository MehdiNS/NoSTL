#pragma once

// Some code from http://en.cppreference.com
namespace nostd {
template <class InputIt, class OutputIt>
OutputIt copy(InputIt first, InputIt last, OutputIt d_first) {
  while (first != last)
    *d_first++ = *first++;
  return d_first;
}

template <class ForwardIt, class T>
void fill(ForwardIt first, ForwardIt last, const T &value) {
  for (; first != last; ++first)
    *first = value;
}

template <class T> void swap(T &a, T &b) {
  T tmp{a};
  a = b;
  b = tmp;
}

template <class T, int N> void swap(T (&a)[N], T (&b)[N]) {
  for (int i = 0; i < N; ++i)
    swap(a[i], b[i]);
}

template <class InputIt1, class InputIt2>
bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2) {
  for (; first1 != last1; ++first1, ++first2) {
    if (!(*first1 == *first2)) {
      return false;
    }
  }
  return true;
}
} // namespace nostd
