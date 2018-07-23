#include <mars/core/TestSuite.h>
#include <mars/core/TestCase.h>
#include <gtest/gtest.h>

TEST(NamedTestSpec, named_test_case) {
  TestCase test("test case");
  ASSERT_EQ("test case", test.getName());
}

TEST(NamedTestSpec, named_test_suite) {
  TestSuite suite("test suite");
  ASSERT_EQ("test suite", suite.getName());
}
