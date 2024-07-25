#pragma once
#include <cstddef>
namespace gotostl {
// define iterator tag
struct input_iterator_tag {};
struct output_iterator_tag {};
struct forward_iterator_tag : public input_iterator_tag {};
struct bidirectional_iterator_tag : public forward_iterator_tag {};
struct random_access_iterator_tag : public bidirectional_iterator_tag {};

template <typename Category, typename T, typename Pointer = T*,
          typename Reference = T&, typename Difference = ptrdiff_t>
struct iterator_base {
  // any user defined iterator call derive from this base class
  typedef Category iterator_category;
  typedef T value_type;
  typedef Pointer pointer;
  typedef Reference reference_type;
  typedef Difference difference_type;
};

template <typename Iterator>
struct iterator_traits {
  typedef typename Iterator::iterator_category iterator_category;
  typedef typename Iterator::value_type value_type;
  typedef typename Iterator::pointer pointer;
  typedef typename Iterator::reference reference;
  typedef typename Iterator::difference_type difference_type;
};

};  // namespace gotostl