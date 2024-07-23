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

}  // namespace test_goto_stl