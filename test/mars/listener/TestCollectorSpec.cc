#include <mars/listener/TestCollector.h>
#include <mars/core/TestResult.h>
#include <mars/core/TestCase.h>
#include <gtest/gtest.h>

namespace {
  struct TestCollectorSpec : testing::Test {
  protected:
    void run(::Test& test) {
      test.run(result);
    }

  private:
    void SetUp() override {
      result.addListener(collector);
    }

  protected:
    TestResult result;
    TestCollector collector;
  };
}

TEST_F(TestCollectorSpec, count_single_one_test_case) {
  TestCase test;
  run(test);
  ASSERT_EQ(1, collector.runCount());
}
