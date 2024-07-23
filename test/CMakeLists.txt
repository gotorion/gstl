enable_testing()
file(GLOB HEADERS
    ${CMAKE_SOURCE_DIR}/src
)
message("--- ${HEADERS}")
add_executable(
  test_gotostl
  test_type_traits.cpp
)

target_include_directories(
    test_gotostl PUBLIC ${HEADERS}
)
target_link_libraries(
  test_gotostl
  GTest::gtest_main
)


include(GoogleTest)
gtest_discover_tests(test_gotostl)