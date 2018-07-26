#include <mars/core/TestResult.h>
#include <mars/core/TestListener.h>
#include <mars/core/internal/TestCaseFunctor.h>
#include <mars/except/AssertionError.h>

void TestResult::addListener(TestListener& listener) {
  listeners.push_back(&listener);
}

#define BOARDCAST(action) \
  for (auto listener : listeners) listener->action

void TestResult::startTestRun(const Test& test) {
  BOARDCAST(startTestRun(test));
}

void TestResult::endTestRun(const Test& test) {
  BOARDCAST(endTestRun(test));
}

void TestResult::startTestCase(const Test& test) {
  BOARDCAST(startTestCase(test));
}

void TestResult::endTestCase(const Test& test) {
  BOARDCAST(endTestCase(test));
}

void TestResult::addFailure(std::string&& msg, bool failure) {
  failures.emplace_back(std::move(msg), failure);
  BOARDCAST(addFailure(failures.back()));
}

namespace {
  std::string msg(const char* why, const char* where, const char* what) {
    return std::string(why) + ' ' + where + '\n' + what;
  }

  struct NilException {
    const char* what() const {
      return "";
    }
  } const e;
}

#define ON_FAIL(except)  addFailure(msg(except, f.where(), e.what()), true)
#define ON_ERROR(except) addFailure(msg(except, f.where(), e.what()), false)

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
