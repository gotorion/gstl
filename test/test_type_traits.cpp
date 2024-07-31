#include <gtest/gtest.h>
#include "goto_type_traits.h"
namespace test_goto_stl {
TEST(TestTypeTraits, CharIsPodType) {
  bool compare_type =
      gotostl::is_same_v<gotostl::type_traits<char>::is_pod_type,
                         gotostl::true_type>;
  EXPECT_TRUE(compare_type);
}

TEST(TestTypeTraits, CharIsTrivialConstructable) {
  bool compare_type = gotostl::is_same_v<
      gotostl::type_traits<char>::has_trivial_default_constructor,
      gotostl::true_type>;
  EXPECT_TRUE(compare_type);
}

TEST(TestTypeTraits, RemoveReference) {
  bool is_removed = gotostl::is_same_v<int, gotostl::remove_reference_t<int&>>;
  EXPECT_TRUE(is_removed);
}

TEST(TestTypeTraits, RemoveRReference) {
  bool is_removed = gotostl::is_same_v<int, gotostl::remove_reference_t<int&&>>;
  EXPECT_TRUE(is_removed);
}

TEST(TestTypeTraits, ConditionalTrue) {
  using t = gotostl::conditional_t<true, int, double>;
  bool compare = gotostl::is_same_v<int, t>;
  EXPECT_TRUE(compare);
}

TEST(TestTypeTraits, ConditionalFalse) {
  using t = gotostl::conditional_t<false, int, double>;
  bool compare = gotostl::is_same_v<double, t>;
  EXPECT_TRUE(compare);
}

TEST(TestTypeTraits, RemoveCV) {
  bool is_same =
      gotostl::is_same_v<int, gotostl::remove_cv<int const volatile>::type>;
  EXPECT_TRUE(is_same);
}

TEST(TestTypeTraits, AddRValueReference) {
  bool is_same =
      gotostl::is_same_v<int&&, gotostl::add_rvalue_reference_t<int>>;
  EXPECT_TRUE(is_same);
}

TEST(TestTypeTraits, Move) {
  int val = 10;
  bool is_same = gotostl::is_same_v<int&&, decltype(gotostl::move(val))>;
  EXPECT_TRUE(is_same);
}

TEST(TestTypeTraits, ForwardLeftValue) {
  int val = 10;
  int& rval = val;
  bool is_same =
      gotostl::is_same_v<int&,
                         decltype(gotostl::forward<decltype(rval)>(rval))>;
  EXPECT_TRUE(is_same);
}

}  // namespace test_goto_stl