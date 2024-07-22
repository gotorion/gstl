#pragma once
#include <cstddef>
#include <cstdlib>
#include <new>
#include "goto_type_traits.h"

namespace gotostl {
template <typename T1, typename T2>
inline void construct(T1* p, T2 const& value) {
  new ((void*)p) T1(value);
}

template <typename T>
inline void construct(T* p) {
  new ((void*)p) T();
}

template <typename T>
inline void destroy(T* p) {
  p->~T();
}

template <typename ForwardIterator>
void destroy_aux(ForwardIterator first, ForwardIterator last, false_type) {
  for (; first != last; ++first) {
    destroy(&(*first));
  }
}

template <typename ForwardIterator>
inline void destroy_aux(ForwardIterator first, ForwardIterator last,
                        true_type) {
  // has trivial destruct, do nothing
}

template <typename ForwardIterator, typename T>
inline void destroy(ForwardIterator first, ForwardIterator last, T*) {
  typedef typename type_traits<T>::has_trivial_destructor trivial_destructor;
  destroy_aux(first, last, trivial_destructor());
}

template <typename ForwarIterator>
inline void destroy(ForwarIterator first, ForwarIterator last) {
  // TODO:萃取出迭代器中值的类型
  destroy(first, last, ValueType);
}

};  // namespace gotostl