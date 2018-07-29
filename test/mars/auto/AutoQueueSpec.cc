#define GTEST_DONT_DEFINE_TEST 1
#include <gtest/gtest.h>
#include <mars/def/FixtureDef.h>
#include <mars/def/TestDef.h>
#include <mars/core/TestResult.h>
#include <mars/listener/text/TextProgress.h>
#include <sstream>
#include <queue>

namespace {
  FIXTURE(QueueSpec) {
    std::queue<int> q;

    SETUP {
      q.push(1);
      q.push(2);
    }

    TEST("apply pop 0 time") {
      ASSERT_EQ(1, q.front());
      ASSERT_EQ(2, q.back());
    }

    TEST("apply pop 1 time") {
      q.pop();
      ASSERT_EQ(2, q.front());
      ASSERT_EQ(2, q.back());
    }

    TEST("apply pop 2 times"){
      q.pop();
      q.pop();
      ASSERT_TRUE(q.empty());
    }
  };

  struct AutoQueueSpec : testing::Test {
  protected:
    AutoQueueSpec() : progress(ss), root(suite()) {
      result.addListener(progress);
    }

    ~AutoQueueSpec() {
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

  ::Test* AutoQueueSpec::suite() {
    static QueueSpec dummy;
    TestFactory& factory = TestFixtureFactory<QueueSpec>::instance();
    return factory.make();
  }
}

TEST_F(AutoQueueSpec, run_queue_spec) {
  ASSERT_TRUE(root != nullptr);
  result.runRootTest(*root);
  assertOutput("starting...\n***\nend.\n");
}
