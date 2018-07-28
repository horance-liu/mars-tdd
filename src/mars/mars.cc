#include <mars/mars.h>
#include <mars/core/TestResult.h>
#include <mars/listener/text/TextProgress.h>
#include <mars/auto/TestFactorySuite.h>
#include <iostream>

namespace {
  struct ScopedRuntime {
    ScopedRuntime(TestFactory& factory)
      : root(factory.make()) {}

    void run(TestResult& result) {
      result.runRootTest(*root);
    }

    ~ScopedRuntime() {
      //delete root;
    }

  private:
    Test* root;
  };
}

int run_all_tests(int, char**) {
  TestResult result;
  TextProgress progress(std::cout);

  result.addListener(progress);
  ScopedRuntime runtime(TestFactorySuite::instance());
  runtime.run(result);

  return 0;
}
