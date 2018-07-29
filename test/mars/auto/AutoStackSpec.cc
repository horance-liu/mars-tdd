#define GTEST_DONT_DEFINE_TEST 1
#include <gtest/gtest.h>
#include <mars/def/FixtureDef.h>
#include <mars/def/TestDef.h>
#include <mars/core/TestResult.h>
#include <mars/listener/text/TextProgress.h>
#include <stack>
#include <sstream>

namespace {
  FIXTURE(StackSpec) {
    std::stack<int> v;

    SETUP {
      v.push(1);
      v.push(2);
    }

    TEST("apply stack with pop 0 time") {
      ASSERT_EQ(2, v.top());
    }

    TEST("apply stack with pop 1 time") {
      v.pop();
      ASSERT_EQ(1, v.top());
    }

    TEST("apply stack with pop 2 times") {
      v.pop();
      v.pop();
      ASSERT_TRUE(v.empty());
    }
  };

  struct AutoStackSpec : testing::Test {
  protected:
    AutoStackSpec() : progress(ss), root(suite()) {
      result.addListener(progress);
    }

    ~AutoStackSpec() {
      delete root;
    }

    void assertOutput(const char* output) {
      ASSERT_EQ(ss.str(), output);
    }

  private:
    static ::Test* suite();

  protected:
    std::ostringstream ss;
    TestResult result;
    TextProgress progress;
    ::Test* root;
  };

  ::Test* AutoStackSpec::suite() {
    static StackSpec dummy;
    TestFactory& factory = TestFixtureFactory<StackSpec>::instance();
    return factory.make();
  }
}

TEST_F(AutoStackSpec, run_stack_spec) {
  result.runRootTest(*root);
  assertOutput("starting...\n***\nend.\n");
}
