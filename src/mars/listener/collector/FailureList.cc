#include <mars/listener/collector/FailureList.h>

void FailureList::addFailure(const TestFailure& f) {
  failures.push_back(&f);
}
