#include <mars/runner/TestRunner.h>
#include <mars/factory/TestFactory.h>
#include <mars/core/Test.h>

TestRunner::TestRunner(TestListener& listener, TestFactory& factory)
  : root(factory.make()) {
  result.addListener(listener);
}

TestRunner::~TestRunner() {
  delete root;
}

void TestRunner::run() {
  result.runRootTest(*root);
}
