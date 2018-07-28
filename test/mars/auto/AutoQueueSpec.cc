//#include <mars/core/TestResult.h>
//#include <mars/listener/text/TextProgress.h>
//#include <sstream>
//#include "QueueSpec.h"
//
//namespace {
//  struct AutoQueueSpec : testing::Test {
//  protected:
//    AutoQueueSpec() : progress(ss), root(suite()) {
//      result.addListener(progress);
//    }
//
//    ~AutoQueueSpec() {
//      delete root;
//    }
//
//    void assertOutput(const char* output) {
//      ASSERT_EQ(ss.str(), output);
//    }
//
//  private:
//    static ::Test* suite();
//
//  protected:
//    std::ostringstream ss;
//    TestResult result;
//    TextProgress progress;
//    ::Test* root;
//  };
//
//  ::Test* AutoQueueSpec::suite() {
//    QueueSpec dummy;
//    return TestMethodRegistry<QueueSpec>::instance().suite();
//  }
//}
//
//TEST_F(AutoQueueSpec, run_queue_spec) {
//  ASSERT_TRUE(root != nullptr);
//  result.runRootTest(*root);
//  assertOutput("starting...\n***\nend.\n");
//}
