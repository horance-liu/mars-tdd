#include <mars/core/TestResult.h>

TestResult::TestResult()
  : numOfRuns(0), numOfFails(0) {
}

void TestResult::startTestCase() {
  numOfRuns++;
}

int TestResult::runCount() const {
  return numOfRuns;
}

void TestResult::addFailure() {
  numOfFails++;
}

int TestResult::failCount() const {
  return numOfFails;
}
