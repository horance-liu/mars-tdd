#ifndef HEBF15E7D_D122_42D4_B25F_D1D468AFF133
#define HEBF15E7D_D122_42D4_B25F_D1D468AFF133

#include <mars/core/Test.h>
#include <vector>

struct TestSuite : Test {
  TestSuite(const std::string& = "");
  ~TestSuite();

  void add(Test* test);
  const std::string& getName() const;

private:
  void run() override;

private:
  template <typename F>
  void foreach(F f) const;

private:
  std::string name;
  std::vector<Test*> tests;
};

#endif
