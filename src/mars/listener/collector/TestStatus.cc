#include <mars/listener/collector/TestStatus.h>

TestStatus::TestStatus() : succ(true) {
}

bool TestStatus::successful() const {
  return succ;
}

void TestStatus::addFailure(const TestFailure&) {
  succ = false;
}
