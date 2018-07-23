#include <mars/core/TestCase.h>
#include <mars/core/TestResult.h>

void TestCase::run(TestResult& result) {
  result.startTestCase();
  setUp();
  runTest();
  tearDown();
}
