#include <mars/core/TestResult.h>
#include <mars/except/AssertionError.h>
#include <mars/core/internal/TestCaseFunctor.h>
#include <mars/core/TestListener.h>
#include <algorithm>

void TestResult::addListener(TestListener& listener) {
  listeners.push_back(&listener);
}

void TestResult::startTestCase(const Test& test) {
  for (auto listener : listeners) {
    listener->startTestCase(test);
  }
}

int TestResult::failCount() const {
  return std::count_if(failures.begin(), failures.end(), [](auto f) {
    return f.isFailure();
  });
}

int TestResult::errorCount() const {
  return failures.size() - failCount();
}

const std::vector<TestFailure>& TestResult::getFailures() const {
  return failures;
}

inline void TestResult::addFailure(std::string&& msg) {
  failures.emplace_back(std::move(msg), true);
}

inline void TestResult::addError(std::string&& msg) {
  failures.emplace_back(std::move(msg), false);
}

namespace {
  inline std::string msg(const char* why, const char* where, const char* what) {
    return std::string(why) + ' ' + where + '\n' + what;
  }

  struct NilException {
    const char* what() const {
      return "";
    }
  } const e;
}

#define ON_FAIL(except)  addFailure(msg(except, f.where(), e.what()))
#define ON_ERROR(except) addError(msg(except, f.where(), e.what()))

bool TestResult::protect(const TestCaseFunctor& f) {
  try {
    return f();
  } catch (const AssertionError& e) {
    ON_FAIL("assertion fail");
  } catch (const std::exception& e) {
    ON_ERROR("uncaught std::exception");
  } catch (...) {
    ON_ERROR("uncaught unknown exception");
  }
  return false;
}
