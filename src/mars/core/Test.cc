#include <mars/core/Test.h>

Test::Test(const std::string& name)
 : name(name) {}

const std::string& Test::getName() const {
  return name;
}
