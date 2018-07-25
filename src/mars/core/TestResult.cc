#include <mars/core/TestResult.h>
#include <mars/except/AssertionError.h>
#include <mars/core/internal/TestCaseFunctor.h>

TestResult::TestResult() : numOfRuns(0) {
}

void TestResult::startTestCase() {
  numOfRuns++;
}

int TestResult::runCount() const {
  return numOfRuns;
}

int TestResult::failCount() const {
  return failures.size();
}

int TestResult::errorCount() const {
  return errors.size();
}

inline void TestResult::addFailure(std::string&& msg) {
  failures.emplace_back(std::move(msg), true);
}

inline void TestResult::addError(std::string&& msg) {
  errors.emplace_back(std::move(msg), false);
}

bool TestResult::protect(const TestCaseFunctor& f) {
  try {
    return f();
  } catch (const AssertionError& e) {
    addFailure(std::string("assertion fail") + ' ' + f.where() + '\n' + e.what());
  } catch (const std::exception& e) {
    addError(std::string("uncaught std::exception") + ' ' + f.where() + '\n' + e.what());
  } catch (...) {
    addError(std::string("uncaught unknown exception") + " " + f.where() + "\n" + "");
  }
  return false;
}

const std::vector<TestFailure>& TestResult::getFailures() const {
  return failures;
}

const std::vector<TestFailure>& TestResult::getErrors() const {
  return errors;
}
