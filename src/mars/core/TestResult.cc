#include <mars/core/TestResult.h>
#include <mars/except/AssertionError.h>
#include <mars/core/internal/TestCaseFunctor.h>

TestResult::TestResult()
  : numOfRuns(0), numOfFails(0), numOfErrors(0) {
}

void TestResult::startTestCase() {
  numOfRuns++;
}

int TestResult::runCount() const {
  return numOfRuns;
}

int TestResult::failCount() const {
  return numOfFails;
}

int TestResult::errorCount() const {
  return numOfErrors;
}

inline void TestResult::addFailure() {
  numOfFails++;
}

inline void TestResult::addError() {
  numOfErrors++;
}

bool TestResult::protect(const TestCaseFunctor& f) {
  try {
    return f();
  } catch (const AssertionError&) {
    addFailure();
  } catch (const std::exception&) {
    addError();
  } catch (...) {
    addError();
  }
  return false;
}
