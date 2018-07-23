#include <mars/core/TestCase.h>

TestCase::TestCase(const std::string& name)
  : name(name) {}

const std::string& TestCase::getName() const {
  return name;
}

void TestCase::run() {
  setUp();
  runTest();
  tearDown();
}
