#include <mars/listener/text/TextProgress.h>
#include <mars/core/TestResult.h>
#include <mars/core/TestCase.h>
#include <mars/core/TestSuite.h>
#include <mars/except/AssertionError.h>
#include <gtest/gtest.h>
#include <sstream>

namespace {
  struct TextProgressSpec : testing::Test {
  protected:
    TextProgressSpec() : progress(ss) {
      result.addListener(progress);
    }

    void run(::Test& test) {
      result.startTestRun(test);
      test.run(result);
      result.endTestRun(test);
    }

    void assertOutput(const char* output) {
      ASSERT_EQ(ss.str(), output);
    }

  protected:
    TestResult result;
    std::ostringstream ss;
    TextProgress progress;
  };
}

TEST_F(TextProgressSpec, single_test_case_is_successful) {
  TestCase test;
  run(test);
  assertOutput("starting...\n*\nend.\n");
}

TEST_F(TextProgressSpec, all_of_test_cases_are_successful) {
  TestSuite suite;
  suite.add(new TestCase);
  suite.add(new TestCase);

  run(suite);
  assertOutput("starting...\n**\nend.\n");
}

namespace {
  struct FailureOnRunningTest : TestCase {
  private:
    void runTest() override {
      throw AssertionError("product.cc:57", "expected value == 2, but got 3");
    }
  };
}

TEST_F(TextProgressSpec, contains_failed_test_case) {
  TestSuite suite;
  suite.add(new TestCase);
  suite.add(new FailureOnRunningTest);

  run(suite);
  assertOutput("starting...\n**F\nend.\n");
}

namespace {
  struct ErrorOnRunningTest : TestCase {
   void runTest() override {
      throw std::exception();
    }
  };
}

TEST_F(TextProgressSpec, contains_error_test_case) {
  TestSuite suite;
  suite.add(new TestCase);
  suite.add(new ErrorOnRunningTest);

  run(suite);
  assertOutput("starting...\n**E\nend.\n");
}
