#ifndef H485D38B2_DA23_42D6_9553_CF1919A5634D
#define H485D38B2_DA23_42D6_9553_CF1919A5634D

#include <mars/core/TestSuite.h>
#include <mars/util/Singleton.h>
#include <map>

GENERIC_SINGLETON(TestMethodRegistry, Fixture) {
  void put(int id, Test* test) {
    if (!exist(id)) {
      registry.emplace(id, test);
    }
  }

  Test* suite() const {
    auto suite = new TestSuite();
    for (auto& test : registry) {
      suite->add(test.second);
    }
    return suite;
  }

private:
  bool exist(int id) const {
    return registry.find(id) != registry.end();
  }

private:
  std::map<int, Test*> registry;
};

#endif
