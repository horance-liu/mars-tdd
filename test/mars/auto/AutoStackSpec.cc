#include "StackSpec.h"
#include <mars/core/TestResult.h>
#include <mars/listener/text/TextProgress.h>
#include <sstream>

namespace {
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
    std::cout << "AutoStackSpec: begin register" << std::endl;
    StackSpec dummy;
    std::cout << "AutoStackSpec: end register" << std::endl;
    return TestMethodRegistry<StackSpec>::instance().suite();
  }
}

TEST_F(AutoStackSpec, run_stack_spec) {
  result.runRootTest(*root);
  assertOutput("starting...\n***\nend.\n");
}

#include "QueueSpec.h"

namespace {
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
    QueueSpec dummy;
    return TestMethodRegistry<QueueSpec>::instance().suite();
  }
}

TEST_F(AutoQueueSpec, run_queue_spec) {
  ASSERT_TRUE(root != nullptr);
  result.runRootTest(*root);
  assertOutput("starting...\n***\nend.\n");
}
