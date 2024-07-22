#ifndef GOTO_ALLOCATOR_H_
#define GOTO_ALLOCATOR_H_
#include <cstddef>
#include "goto_construct.h"
namespace gotostl {

template <typename T>
class allocator {
 public:
  typedef size_t size_type;
  typedef ptrdiff_t difference_type;
  typedef T value_type;
  typedef T* pointer;
  typedef T const* const_pointer;
  typedef T& reference;
  typedef T const& const_reference;

 public:
  // TODO: constructor
  // TODO: copy construct
  // TODO: rebind
 public:
  pointer allocate(size_type n, void const* = 0);
  void deallocate(pointer p, size_type n);
  void construct(pointer p, T const& x);
  void destroy(pointer p);
  size_type max_size() const;
  pointer address(reference x) const;
  const_pointer address(const_reference x) const;
};
};  // namespace gotostl
#endif