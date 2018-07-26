#include <mars/core/TestSuite.h>
#include <mars/core/TestCase.h>
#include <mars/core/TestResult.h>
#include <gtest/gtest.h>
#include <mars/listener/collector/TestCollector.h>

namespace {
  struct TestSuiteSpec : testing::Test {
  protected:
    void run(::Test& test) {
      test.run(result);
    }

    int countTestCases(::Test& test) {
      return test.countTestCases();
    }

  private:
    void SetUp() override {
      result.addListener(collector);
    }

  protected:
    TestCollector collector;
    TestResult result;
  };
}

TEST_F(TestSuiteSpec, count_test_cases_from_result) {
  TestSuite suite;
  suite.add(new TestCase);
  suite.add(new TestCase);

  run(suite);

  ASSERT_EQ(2, collector.runCount());
}

TEST_F(TestSuiteSpec, count_test_cases_from_tree) {
  TestSuite suite;
  suite.add(new TestCase);
  suite.add(new TestCase);

  ASSERT_EQ(2, countTestCases(suite));
}

TEST_F(TestSuiteSpec, package_sub_test_suite_into_outter_test_suite) {
  auto inner = new TestSuite;
  inner->add(new TestCase);

  TestSuite outter;
  outter.add(new TestCase);
  outter.add(inner);

  run(outter);

  ASSERT_EQ(2, collector.runCount());
}

