#include <mars/core/TestCase.h>
#include <mars/core/TestResult.h>
#include <mars/except/AssertionError.h>
#include <gtest/gtest.h>
#include <mars/listener/collector/FailureList.h>
#include <mars/listener/collector/TestCollector.h>

struct TestCaseSpec : testing::Test {
protected:
  void run(::Test& test) {
    test.run(result);
  }

private:
  void SetUp() override {
    result.addListener(collector);
    result.addListener(list);
  }

protected:
  FailureList list;
  TestCollector collector;
  TestResult result;
};

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

  ASSERT_EQ(1, collector.failCount());
}

TEST_F(TestCaseSpec, extract_except_msg_on_running_test_failed) {
  FailureOnRunningTest test;
  run(test);

  list.foreach([&test](auto& fail){
    ASSERT_TRUE(fail.isFailure());
    ASSERT_EQ(test.expectMsg(), fail.getExceptionMsg());
  });
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

  ASSERT_EQ(1, collector.failCount());
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
  ASSERT_EQ(1, collector.failCount());
}

namespace {
  struct ErrorOnRunningTest : TestCase {
    const char* expectMsg() const {
      return "uncaught std::exception in the runTest\n"
              "std::exception";
    }

    void runTest() override {
      throw std::exception();
    }
  };
}

TEST_F(TestCaseSpec, throw_std_exception_on_run_test) {
  ErrorOnRunningTest test;
  run(test);
  ASSERT_EQ(1, collector.errorCount());
}

TEST_F(TestCaseSpec, extract_error_msgt_on_running_test_failed) {
  ErrorOnRunningTest test;
  run(test);

  list.foreach([&test](auto& error){
    ASSERT_FALSE(error.isFailure());
    ASSERT_EQ(test.expectMsg(), error.getExceptionMsg());
  });
}

namespace {
  struct NilException {};

  struct UnknownErrorOnRunningTest : TestCase {
    const char* expectMsg() const {
      return "uncaught unknown exception in the runTest\n";
    }

  private:
    void runTest() override {
      throw NilException();
    }
  };
}

TEST_F(TestCaseSpec, throw_unknown_exception_on_running_test) {
  UnknownErrorOnRunningTest test;
  run(test);
  ASSERT_EQ(1, collector.errorCount());
}

TEST_F(TestCaseSpec, extract_unknown_error_msg_on_running_test_failed) {
  UnknownErrorOnRunningTest test;
  run(test);

  list.foreach([&test](auto& error){
    ASSERT_FALSE(error.isFailure());
    ASSERT_EQ(test.expectMsg(), error.getExceptionMsg());
  });
}
