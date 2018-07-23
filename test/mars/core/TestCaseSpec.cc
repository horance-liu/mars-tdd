#include <mars/core/TestCase.h>
#include <mars/core/TestResult.h>
#include <gtest/gtest.h>

struct TestCaseSpec : testing::Test {
protected:
  void run(::Test& test) {
    test.run(result);
  }

protected:
  TestResult result;
};

TEST_F(TestCaseSpec, run_one_simple_test) {
  TestCase test;
  run(test);
  ASSERT_EQ(1, result.runCount());
}
