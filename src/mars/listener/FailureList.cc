#include <mars/listener/FailureList.h>

void FailureList::addFailure(const TestFailure& f) {
  failures.push_back(&f);
}
