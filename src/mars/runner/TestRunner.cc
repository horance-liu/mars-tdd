#include <mars/runner/TestRunner.h>
#include <mars/factory/TestSuiteFactory.h>
#include <mars/core/Test.h>

namespace {
  TestFactory& root() {
    return TestSuiteFactory::root();
  }

  Test* make() {
    return root().make();
  }
}

TestRunner::TestRunner(std::ostream& os)
  : printer(os), root(make()) {
  result.addListener(printer);
}

TestRunner::~TestRunner() {
  delete root;
}

void TestRunner::run() {
  result.runRootTest(*root);
}
