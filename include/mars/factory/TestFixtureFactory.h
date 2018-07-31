#ifndef H485D38B2_DA23_42D6_9553_CF1919A5634D
#define H485D38B2_DA23_42D6_9553_CF1919A5634D

#include <mars/factory/TestMethodFactory.h>
#include <mars/factory/TestSuiteFactory.h>
#include <unordered_map>

template <typename Fixture>
struct TestFixtureFactory : TestSuiteFactory {
  using TestSuiteFactory::TestSuiteFactory;

  void add(int id, const char* name, Method<Fixture> method) {
    if (!exist(id)) {
      registry.insert({id, {name, method}});
      TestSuiteFactory::add(registry.at(id));
    }
  }

  static TestFixtureFactory<Fixture>& instance(const char* name = "") {
    static TestFixtureFactory<Fixture> inst(name);
    return inst;
  }

private:
  Test* make() const override {
    static Fixture dummy; // register all test methods to registry.
    return TestSuiteFactory::make();
  }

private:
  bool exist(int id) const {
    return registry.find(id) != registry.end();
  }

private:
  std::unordered_map<int, TestMethodFactory<Fixture>> registry;
};

#endif
