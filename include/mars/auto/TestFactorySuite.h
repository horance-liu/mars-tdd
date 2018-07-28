#ifndef HE2AE949F_5E90_487E_A4EF_C86A24FB7A98
#define HE2AE949F_5E90_487E_A4EF_C86A24FB7A98

#include <mars/util/Singleton.h>
#include <mars/util/Keywords.h>
#include <mars/auto/TestFactory.h>
#include <vector>

SINGLETON(TestFactorySuite) EXTENDS(TestFactory) {
  ~TestFactorySuite();
  void addFactory(TestFactory*);

private:
  template <typename F>
  void foreach(F f) const;

private:
  Test* make() override;

private:
  std::vector<TestFactory*> factories;
};

#endif
