#include <mars/listener/FailureLister.h>

void FailureLister::addFailure(const TestFailure& f) {
  failures.push_back(&f);
}
