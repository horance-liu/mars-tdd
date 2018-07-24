#include <mars/core/TestCase.h>
#include <mars/core/TestResult.h>
#include <mars/except/AssertionError.h>

void TestCase::runBare(TestResult& result) {
  setUp();
  try {
    runTest();
  } catch (const AssertionError&) {
    result.addFailure();
  }
  tearDown();
}

void TestCase::run(TestResult& result) {
  result.startTestCase();
  runBare(result);
}

int TestCase::countTestCases() const {
  return 1;
}
