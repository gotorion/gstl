#ifndef GOTO_TYPE_TRAITES_H_
#define GOTO_TYPE_TRAITES_H_
namespace gotostl {

#define TEMPLATE_NULL template <>

struct true_type {};
struct false_type {};

template <typename T>
struct type_traits {
  // 保守起见默认都为false_type
  typedef false_type has_trivial_default_constructor;
  typedef false_type has_trivial_copy_constructor;
  typedef false_type has_trivial_assignment_operator;
  typedef false_type has_trivial_destructor;
  typedef false_type is_pod_type;
};
// 针对内置类型进行特化
TEMPLATE_NULL struct type_traits<bool> {
  typedef true_type has_trivial_default_constructor;
  typedef true_type has_trivial_copy_constructor;
  typedef true_type has_trivial_assignment_operator;
  typedef true_type has_trivial_destructor;
  typedef true_type is_pod_type;
};

TEMPLATE_NULL struct type_traits<signed char> {
  typedef true_type has_trivial_default_constructor;
  typedef true_type has_trivial_copy_constructor;
  typedef true_type has_trivial_assignment_operator;
  typedef true_type has_trivial_destructor;
  typedef true_type is_pod_type;
};

TEMPLATE_NULL struct type_traits<char> {
  typedef true_type has_trivial_default_constructor;
  typedef true_type has_trivial_copy_constructor;
  typedef true_type has_trivial_assignment_operator;
  typedef true_type has_trivial_destructor;
  typedef true_type is_pod_type;
};

TEMPLATE_NULL struct type_traits<unsigned char> {
  typedef true_type has_trivial_default_constructor;
  typedef true_type has_trivial_copy_constructor;
  typedef true_type has_trivial_assignment_operator;
  typedef true_type has_trivial_destructor;
  typedef true_type is_pod_type;
};

TEMPLATE_NULL struct type_traits<wchar_t> {
  typedef true_type has_trivial_default_constructor;
  typedef true_type has_trivial_copy_constructor;
  typedef true_type has_trivial_assignment_operator;
  typedef true_type has_trivial_destructor;
  typedef true_type is_pod_type;
};

TEMPLATE_NULL struct type_traits<short> {
  typedef true_type has_trivial_default_constructor;
  typedef true_type has_trivial_copy_constructor;
  typedef true_type has_trivial_assignment_operator;
  typedef true_type has_trivial_destructor;
  typedef true_type is_pod_type;
};

TEMPLATE_NULL struct type_traits<unsigned short> {
  typedef true_type has_trivial_default_constructor;
  typedef true_type has_trivial_copy_constructor;
  typedef true_type has_trivial_assignment_operator;
  typedef true_type has_trivial_destructor;
  typedef true_type is_pod_type;
};

TEMPLATE_NULL struct type_traits<int> {
  typedef true_type has_trivial_default_constructor;
  typedef true_type has_trivial_copy_constructor;
  typedef true_type has_trivial_assignment_operator;
  typedef true_type has_trivial_destructor;
  typedef true_type is_pod_type;
};

TEMPLATE_NULL struct type_traits<unsigned int> {
  typedef true_type has_trivial_default_constructor;
  typedef true_type has_trivial_copy_constructor;
  typedef true_type has_trivial_assignment_operator;
  typedef true_type has_trivial_destructor;
  typedef true_type is_pod_type;
};

TEMPLATE_NULL struct type_traits<long> {
  typedef true_type has_trivial_default_constructor;
  typedef true_type has_trivial_copy_constructor;
  typedef true_type has_trivial_assignment_operator;
  typedef true_type has_trivial_destructor;
  typedef true_type is_pod_type;
};

TEMPLATE_NULL struct type_traits<unsigned long> {
  typedef true_type has_trivial_default_constructor;
  typedef true_type has_trivial_copy_constructor;
  typedef true_type has_trivial_assignment_operator;
  typedef true_type has_trivial_destructor;
  typedef true_type is_pod_type;
};

TEMPLATE_NULL struct type_traits<long long> {
  typedef true_type has_trivial_default_constructor;
  typedef true_type has_trivial_copy_constructor;
  typedef true_type has_trivial_assignment_operator;
  typedef true_type has_trivial_destructor;
  typedef true_type is_pod_type;
};

TEMPLATE_NULL struct type_traits<unsigned long long> {
  typedef true_type has_trivial_default_constructor;
  typedef true_type has_trivial_copy_constructor;
  typedef true_type has_trivial_assignment_operator;
  typedef true_type has_trivial_destructor;
  typedef true_type is_pod_type;
};

TEMPLATE_NULL struct type_traits<float> {
  typedef true_type has_trivial_default_constructor;
  typedef true_type has_trivial_copy_constructor;
  typedef true_type has_trivial_assignment_operator;
  typedef true_type has_trivial_destructor;
  typedef true_type is_pod_type;
};
TEMPLATE_NULL struct type_traits<double> {
  typedef true_type has_trivial_default_constructor;
  typedef true_type has_trivial_copy_constructor;
  typedef true_type has_trivial_assignment_operator;
  typedef true_type has_trivial_destructor;
  typedef true_type is_pod_type;
};

TEMPLATE_NULL struct type_traits<long double> {
  typedef true_type has_trivial_default_constructor;
  typedef true_type has_trivial_copy_constructor;
  typedef true_type has_trivial_assignment_operator;
  typedef true_type has_trivial_destructor;
  typedef true_type is_pod_type;
};

template <typename T>
struct type_traits<T*> {
  typedef true_type has_trivial_default_constructor;
  typedef true_type has_trivial_copy_constructor;
  typedef true_type has_trivial_assignment_operator;
  typedef true_type has_trivial_destructor;
  typedef true_type is_pod_type;
};

template <typename T>
struct type_traits<const T*> {
  typedef true_type has_trivial_default_constructor;
  typedef true_type has_trivial_copy_constructor;
  typedef true_type has_trivial_assignment_operator;
  typedef true_type has_trivial_destructor;
  typedef true_type is_pod_type;
};

TEMPLATE_NULL struct type_traits<char*> {
  typedef true_type has_trivial_default_constructor;
  typedef true_type has_trivial_copy_constructor;
  typedef true_type has_trivial_assignment_operator;
  typedef true_type has_trivial_destructor;
  typedef true_type is_pod_type;
};

TEMPLATE_NULL struct type_traits<unsigned char*> {
  typedef true_type has_trivial_default_constructor;
  typedef true_type has_trivial_copy_constructor;
  typedef true_type has_trivial_assignment_operator;
  typedef true_type has_trivial_destructor;
  typedef true_type is_pod_type;
};

TEMPLATE_NULL struct type_traits<signed char*> {
  typedef true_type has_trivial_default_constructor;
  typedef true_type has_trivial_copy_constructor;
  typedef true_type has_trivial_assignment_operator;
  typedef true_type has_trivial_destructor;
  typedef true_type is_pod_type;
};
TEMPLATE_NULL struct type_traits<char const*> {
  typedef true_type has_trivial_default_constructor;
  typedef true_type has_trivial_copy_constructor;
  typedef true_type has_trivial_assignment_operator;
  typedef true_type has_trivial_destructor;
  typedef true_type is_pod_type;
};

TEMPLATE_NULL struct type_traits<unsigned char const*> {
  typedef true_type has_trivial_default_constructor;
  typedef true_type has_trivial_copy_constructor;
  typedef true_type has_trivial_assignment_operator;
  typedef true_type has_trivial_destructor;
  typedef true_type is_pod_type;
};

TEMPLATE_NULL struct type_traits<signed char const*> {
  typedef true_type has_trivial_default_constructor;
  typedef true_type has_trivial_copy_constructor;
  typedef true_type has_trivial_assignment_operator;
  typedef true_type has_trivial_destructor;
  typedef true_type is_pod_type;
};

template <typename T1, typename T2>
struct is_same {
  static constexpr bool value = false;
};

template <typename T>
struct is_same<T, T> {
  static constexpr bool value = true;
};

template <typename T1, typename T2>
constexpr bool is_same_v = is_same<T1, T2>::value;
};  // namespace gotostl
#endif