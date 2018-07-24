#include <mars/core/TestCase.h>
#include <mars/core/TestResult.h>
#include <mars/except/AssertionError.h>
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

namespace {
  struct FailureOnRunTest : TestCase {
  private:
    void runTest() override {
      throw AssertionError("product.cc:57", "expected value == 2, but got 3");
    }
  };
}

TEST_F(TestCaseSpec, throw_assertion_error_on_run_test) {
  FailureOnRunTest test;
  run(test);

  ASSERT_EQ(1, result.failCount());
}

namespace {
  struct FailureOnSetUp : TestCase {
    bool wasRun = false;

  private:
    void setUp() override {
      throw AssertionError("product.cc:57", "expected value == 2, but got 3");
    }

    void runTest() override {
      wasRun = true;
    }
  };
}

TEST_F(TestCaseSpec, throw_assertion_error_on_setup) {
  FailureOnSetUp test;
  run(test);

  ASSERT_EQ(1, result.failCount());
  ASSERT_FALSE(test.wasRun);
}

namespace {
  struct FailureOnTearDown : TestCase {
    void tearDown() override {
      throw AssertionError("product.cc:57", "expected value == 2, but got 3");
    }
  };
}

TEST_F(TestCaseSpec, throw_assertion_error_on_tear_down) {
  FailureOnTearDown test;
  run(test);
  ASSERT_EQ(1, result.failCount());
}

namespace {
  struct ErrorOnRunningTest : TestCase {
    void runTest() override {
      throw std::exception();
    }
  };
}

TEST_F(TestCaseSpec, throw_std_exception_on_run_test) {
  ErrorOnRunningTest test;
  run(test);
  ASSERT_EQ(1, result.errorCount());
}
