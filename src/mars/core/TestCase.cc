#include <mars/core/TestCase.h>
#include <mars/core/TestResult.h>
#include <mars/except/AssertionError.h>

bool TestCase::protect(TestResult& result, Method method) {
  bool succ = false;
  try {
    (this->*method)();
    succ = true;
  } catch (const AssertionError&) {
    result.addFailure();
  }
  return succ;
}

void TestCase::runBare(TestResult& result) {
  if (protect(result, &TestCase::setUp)) {
    protect(result, &TestCase::runTest);
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
