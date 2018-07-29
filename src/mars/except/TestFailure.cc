#include <mars/except/TestFailure.h>

TestFailure::TestFailure(const char* name, std::string&& msg, bool failure)
  : name(name), msg(std::move(msg)), failure(failure) {
}

const char* TestFailure::getTestName() const {
  return name;
}

bool TestFailure::isFailure() const {
  return failure;
}

const std::string& TestFailure::getExceptionMsg() const {
  return msg;
}
