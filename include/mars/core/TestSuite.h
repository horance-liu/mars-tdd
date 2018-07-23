#ifndef HEBF15E7D_D122_42D4_B25F_D1D468AFF133
#define HEBF15E7D_D122_42D4_B25F_D1D468AFF133

#include <vector>

struct TestCase;

struct TestSuite {
  ~TestSuite();

  void add(TestCase* test);
  void run();

private:
  template <typename F>
  void foreach(F f) const;

private:
  std::vector<TestCase*> tests;
};

#endif
