#include <mars/except/AssertionError.h>

AssertionError::AssertionError
  ( const std::string& src
  , const std::string& msg)
  : msg(src + "\n" + msg) {
}

const char* AssertionError::what() const noexcept {
  return msg.c_str();
}
