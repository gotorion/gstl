#include "goto_construct.h"
#include "goto_type_traits.h"
#include "gtest/gtest.h"
namespace test_goto_stl {

struct TestType {
  int x{};
  int y{};
  ~TestType() {
    x = 0;
    y = 0;
  }
};

TEST(TestConstruct, ConstructBuildInType) {
  double* ptr = new double();
  gotostl::construct(ptr, 3.1415);
  EXPECT_EQ(*ptr, 3.1415);
  delete ptr;
}

TEST(TestConstruct, ConstructUserDefinedType) {
  TestType* ptr = new TestType();
  gotostl::construct(ptr, TestType{9, 10});
  EXPECT_TRUE(ptr->x == 9 && ptr->y == 10);
  delete ptr;
}

TEST(TestDestroy, DestroyTrivialType) {
  long* ptr = new long();
  gotostl::construct(ptr, 3);
  gotostl::destroy(ptr);
  EXPECT_EQ(*ptr, 3);  // trivial type will do nothing
  delete ptr;
}

TEST(TestDestroy, DestroyNonTrivialType) {
  bool isTrivialType =
      gotostl::is_same_v<gotostl::type_traits<TestType>, gotostl::true_type>;
  EXPECT_FALSE(isTrivialType);

  TestType* ptr = new TestType();
  gotostl::construct(ptr, TestType{9, 10});
  gotostl::destroy(ptr);
  EXPECT_TRUE(ptr->x == 0 && ptr->y == 0);
  delete ptr;
}

}  // namespace test_goto_stl