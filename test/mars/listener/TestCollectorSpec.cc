#include <mars/listener/TestCollector.h>
#include <mars/core/TestResult.h>
#include <mars/core/TestCase.h>
#include <mars/except/AssertionError.h>
#include <gtest/gtest.h>
#include <mars/core/TestSuite.h>

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

namespace {
  struct Success : TestCase {};
}

TEST_F(TestCollectorSpec, count_single_test_case) {
  Success test;
  run(test);
  ASSERT_EQ(1, collector.runCount());
}

namespace {
  struct FailureOnRunningTest : TestCase {
  private:
    void runTest() override {
      throw AssertionError("product.cc:57", "expected value == 2, but got 3");
    }
  };
}

TEST_F(TestCollectorSpec, throw_assertion_error_on_run_test) {
  FailureOnRunningTest test;
  run(test);

  ASSERT_EQ(1, collector.failCount());
}

namespace {
  struct ErrorOnRunningTest : TestCase {
   void runTest() override {
      throw std::exception();
    }
  };
}

TEST_F(TestCollectorSpec, throw_std_exception_on_run_test) {
  ErrorOnRunningTest test;
  run(test);
  ASSERT_EQ(1, collector.errorCount());
}

TEST_F(TestCollectorSpec, count_test_cases_from_collector) {
  TestSuite suite;
  suite.add(new TestCase);
  suite.add(new FailureOnRunningTest);

  run(suite);

  ASSERT_EQ(2, collector.runCount());
  ASSERT_EQ(1, collector.passCount());
  ASSERT_EQ(1, collector.failCount());
}
