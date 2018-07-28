#ifndef H485D38B2_DA23_42D6_9553_CF1919A5634D
#define H485D38B2_DA23_42D6_9553_CF1919A5634D

#include <mars/core/TestSuite.h>
#include <mars/util/Singleton.h>
#include <map>
#include <iostream>

GENERIC_SINGLETON(TestMethodRegistry, Fixture) {
  void put(int id, Test* test) {
    if (!exist(id)) {
      std::cout << id << ":" << test->getName() << std::endl;
      registry.emplace(id, test);
    }
  }

  Test* suite() const {
    std::cout << "TestMethodRegistry::suite: staring" << std::endl;
    auto suite = new TestSuite();
    std::cout << ((Test&)(*suite)).countTestCases() << std::endl;
    std::cout << registry.size() << std::endl;

    for (auto& test : registry) {
      suite->add(test.second);
    }

    std::cout << "TestMethodRegistry::suite: end" << std::endl;
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
