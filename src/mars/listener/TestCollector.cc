#include <mars/listener/TestCollector.h>

TestCollector::TestCollector()
  : numOfRuns(0) {}

int TestCollector::runCount() const {
  return numOfRuns;
}

void TestCollector::startTestCase(const Test&) {
  numOfRuns++;
}
