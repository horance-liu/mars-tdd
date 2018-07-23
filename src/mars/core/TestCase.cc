#include <mars/core/TestCase.h>

void TestCase::run() {
  setUp();
  runTest();
  tearDown();
}
