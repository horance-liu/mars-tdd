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
  struct FailureOnRunningTest : TestCase {
    const char* expectMsg() const {
      return "assertion fail in the runTest\n"
              "product.cc:57\n"
              "expected value == 2, but got 3";
    }

  private:
    void runTest() override {
      throw AssertionError("product.cc:57", "expected value == 2, but got 3");
    }
  };
}

TEST_F(TestCaseSpec, throw_assertion_error_on_run_test) {
  FailureOnRunningTest test;
  run(test);

  ASSERT_EQ(1, result.failCount());
}

TEST_F(TestCaseSpec, assert_except_msg_on_running_test_failed) {
  FailureOnRunningTest test;
  run(test);

  auto& fails = result.getFailures();
  ASSERT_EQ(1, fails.size());
  ASSERT_EQ(test.expectMsg(), fails[0]);
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

namespace {
  struct NilException {};

  struct UnknownErrorOnRunningTest : TestCase {
  private:
    void runTest() override {
      throw NilException();
    }
  };
}

TEST_F(TestCaseSpec, throw_unknown_exception_on_running_test) {
  UnknownErrorOnRunningTest test;
  run(test);
  ASSERT_EQ(1, result.errorCount());
}
