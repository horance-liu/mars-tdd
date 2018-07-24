#include <mars/core/TestCase.h>
#include <mars/core/TestResult.h>

void TestCase::runBare() {
  setUp();
  runTest();
  tearDown();
}

void TestCase::run(TestResult& result) {
  result.startTestCase();
  runBare();
}

int TestCase::countTestCases() const {
  return 1;
}
