#ifndef HEFDACB16_C7B4_4F48_917D_0207BB3BA714
#define HEFDACB16_C7B4_4F48_917D_0207BB3BA714

#include <string>

struct Test {
  explicit Test(const std::string& = "");
  const std::string& getName() const;

  virtual void run() = 0;
  virtual ~Test() {}

private:
  std::string name;
};

#endif
