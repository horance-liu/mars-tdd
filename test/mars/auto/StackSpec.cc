#include <mars/core/TestFixture.h>
#include <mars/core/TestMethod.h>
#include <mars/core/TestSuite.h>
#include <mars/core/TestResult.h>
#include <mars/listener/text/TextProgress.h>
#include <mars/util/Self.h>
#include <mars/util/Singleton.h>
#include <mars/util/Keywords.h>
#include <gtest/gtest.h>
#include <stack>

namespace {
template<typename Fixture>
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

  struct AutoTestMethod {
    template <typename Fixture>
    AutoTestMethod(int id, const char* name, Method<Fixture> method) {
      auto& registry = TestMethodRegistry<Fixture>::instance();
      registry.put(id, new TestMethod<Fixture>(method, name));
    }
  };

struct TestFactory {
  virtual Test* make() = 0;
  virtual ~TestFactory() {}
};

SINGLETON(TestFactorySuite) EXTENDS(TestFactory) {
  void addFactory(TestFactory& f) {
    factories.push_back(&f);
  }

private:
  Test* make() override {
    auto suite = new TestSuite("All Tests");
    for (auto factory : factories) {
      suite->add(factory->make());
    }
    return suite;
  }

private:
  std::vector<TestFactory*> factories;
};

template<typename Fixture>
struct AutoTestFactory : TestFactory {
  Test* make() {
    // register all test methods to TestMethodRegistry.
    static Fixture dummy;
    return TestMethodRegistry<Fixture>::instance().suite();
  }
};

template<typename Fixture>
struct AutoTestSuite {
  AutoTestSuite() {
    TestFactorySuite::instance().addFactory(factory);
  }

private:
  AutoTestFactory<Fixture> factory;
};

  struct StackSpec;
  static AutoTestSuite<StackSpec> suite1;

  struct StackSpec : TestFixture {
    std::stack<int> v;

    void setUp() override {
      v.push(1);
      v.push(2);
    }

    void test1() {
      ASSERT_EQ(2, v.top());
    }

    AutoTestMethod m1{1, "apply pop 0 time", &StackSpec::test1};

    void test2() {
      v.pop();
      ASSERT_EQ(1, v.top());
    }

    AutoTestMethod m2{2, "apply pop 1 time", &StackSpec::test2};

    void test3() {
      v.pop();
      v.pop();
      ASSERT_TRUE(v.empty());
    }

    AutoTestMethod m3{3, "apply pop 2 times", &StackSpec::test3};
  };

  struct ManualRegisterSpec : testing::Test {
  protected:
    ManualRegisterSpec() : progress(ss), test(suite()) {
      result.addListener(progress);
    }

    ~ManualRegisterSpec() {
      delete test;
    }

    void assertOutput(const char* output) {
      ASSERT_EQ(ss.str(), output);
    }

  private:
    static ::Test* suite() {
      TestFactory& factory = TestFactorySuite::instance();
      return factory.make();
    }

  protected:
    std::ostringstream ss;
    TestResult result;
    TextProgress progress;
    ::Test* test;
  };
}

TEST_F(ManualRegisterSpec, manually_registering_test_cases) {
  result.runRootTest(*test);
  assertOutput("starting...\n***\nend.\n");
}
