//#include <mars/core/TestFixture.h>
//#include <mars/core/TestMethod.h>
//#include <mars/core/TestSuite.h>
//#include <mars/core/TestResult.h>
//#include <mars/listener/text/TextProgress.h>
//#include <mars/util/Self.h>
//#include <mars/util/Singleton.h>
//#include <mars/util/Keywords.h>
//#include <mars/util/Symbol.h>
//
//#define GTEST_DONT_DEFINE_TEST 1
//#include <gtest/gtest.h>
//
//#include <stack>
//#include <map>
//
//#define DEF_FIXTURE(fixture, ...)                      \
//struct fixture;                                        \
//static AutoTestSuite<fixture> UNIQUE_NAME(auto_suite); \
//struct fixture : __VA_ARGS__
//
//#define FIXTURE(fixture)  DEF_FIXTURE(fixture, TestFixture, Self<fixture>)
//
//#define SETUP    void setUp() override
//#define TEARDOWN void tearDown() override
//
//#define SUPER_SETUP(super)    super::setUp()
//#define SUPER_TEARDOWN(super) super::tearDown()
//
//#define __TEST_NAME(id) JOIN(test_, id)
//#define __AUTO_TEST_METHOD(id)
//
//#define __DEF_TEST(id, name)               \
//private:                                   \
//AutoTestMethod JOIN(auto_test_method_, id) \
//  {id, name, &self_type::__TEST_NAME(id)}; \
//public:                                    \
//void __TEST_NAME(id)()
//
//#define TEST(name) __DEF_TEST(UNIQUE_ID, name)
//
//namespace {
//  GENERIC_SINGLETON(TestMethodRegistry, Fixture) {
//    void put(int id, Test* test) {
//      if (!exist(id)) {
//        registry.emplace(id, test);
//      }
//    }
//
//    Test* suite() const {
//      auto suite = new TestSuite();
//      for (auto& test : registry) {
//        suite->add(test.second);
//      }
//      return suite;
//    }
//
//  private:
//    bool exist(int id) const {
//      return registry.find(id) != registry.end();
//    }
//
//  private:
//    std::map<int, Test*> registry;
//  };
//
//  struct AutoTestMethod {
//    template <typename Fixture>
//    AutoTestMethod(int id, const char* name, Method<Fixture> method) {
//      auto& registry = TestMethodRegistry<Fixture>::instance();
//      registry.put(id, new TestMethod<Fixture>(method, name));
//    }
//  };
//
//struct TestFactory {
//  virtual Test* make() = 0;
//  virtual ~TestFactory() {}
//};
//
//SINGLETON(TestFactorySuite) EXTENDS(TestFactory) {
//  void addFactory(TestFactory& f) {
//    factories.push_back(&f);
//  }
//
//private:
//  Test* make() override {
//    auto suite = new TestSuite("All Tests");
//    for (auto factory : factories) {
//      suite->add(factory->make());
//    }
//    return suite;
//  }
//
//private:
//  std::vector<TestFactory*> factories;
//};
//
//template<typename Fixture>
//struct AutoTestFactory : TestFactory {
//  Test* make() {
//    // register all test methods to TestMethodRegistry.
//    static Fixture dummy;
//    return TestMethodRegistry<Fixture>::instance().suite();
//  }
//};
//
//template<typename Fixture>
//struct AutoTestSuite {
//  AutoTestSuite() {
//    TestFactorySuite::instance().addFactory(factory);
//  }
//
//private:
//  AutoTestFactory<Fixture> factory;
//};
//
//  FIXTURE(StackSpec) {
//    std::stack<int> v;
//
//    SETUP {
//      v.push(1);
//      v.push(2);
//    }
//
//    TEST("apply pop 0 time") {
//      ASSERT_EQ(2, v.top());
//    }
//
//    TEST("apply pop 1 time") {
//      v.pop();
//      ASSERT_EQ(1, v.top());
//    }
//
//    TEST("apply pop 2 times") {
//      v.pop();
//      v.pop();
//      ASSERT_TRUE(v.empty());
//    }
//  };
//
//  struct ManualRegisterSpec : testing::Test {
//  protected:
//    ManualRegisterSpec() : progress(ss), test(suite()) {
//      result.addListener(progress);
//    }
//
//    ~ManualRegisterSpec() {
//      delete test;
//    }
//
//    void assertOutput(const char* output) {
//      ASSERT_EQ(ss.str(), output);
//    }
//
//  private:
//    static ::Test* suite() {
//      TestFactory& factory = TestFactorySuite::instance();
//      return factory.make();
//    }
//
//  protected:
//    std::ostringstream ss;
//    TestResult result;
//    TextProgress progress;
//    ::Test* test;
//  };
//}
//
//TEST_F(ManualRegisterSpec, manually_registering_test_cases) {
//  result.runRootTest(*test);
//  assertOutput("starting...\n***\nend.\n");
//}

#include <gtest/gtest.h>
#include <mars/auto/AutoTestFactory.h>
#include <mars/core/TestMethod.h>
#include <mars/core/TestSuite.h>
#include <mars/core/TestFixture.h>
#include <mars/core/TestResult.h>
#include <mars/listener/text/TextProgress.h>
#include <mars/auto/TestMethodRegistry.h>
#include <mars/auto/AutoTestMethod.h>
#include <mars/auto/TestFactorySuite.h>
#include <stack>
#include <queue>
#include <sstream>

namespace {
  struct StackSpec : TestFixture {
    std::stack<int> v;

    void setUp() override {
      v.push(1);
      v.push(2);
    }

    void apply_pop_0_time() {
      ASSERT_EQ(2, v.top());
    }

    AutoTestMethod m1{1, "apply_pop_0_time", &StackSpec::apply_pop_0_time};

    void apply_pop_1_time() {
      v.pop();
      ASSERT_EQ(1, v.top());
    }

    AutoTestMethod m2{2, "apply_pop_1_time", &StackSpec::apply_pop_1_time};

    void apply_pop_2_times() {
      v.pop();
      v.pop();
      ASSERT_TRUE(v.empty());
    }

    AutoTestMethod m3{3, "apply_pop_0_time", &StackSpec::apply_pop_2_times};
  };

  struct QueueSpec : TestFixture {
    std::queue<int> q;

    void setUp() override {
      q.push(1);
      q.push(2);
    }

    void apply_pop_0_time() {
      ASSERT_EQ(1, q.front());
      ASSERT_EQ(2, q.back());
    }

    AutoTestMethod m1{1, "apply_pop_0_time", &QueueSpec::apply_pop_0_time};

    void apply_pop_1_time() {
      q.pop();
      ASSERT_EQ(2, q.front());
      ASSERT_EQ(2, q.back());
    }

    AutoTestMethod m2{2, "apply_pop_1_time", &QueueSpec::apply_pop_1_time};

    void apply_pop_2_times() {
      q.pop();
      q.pop();
      ASSERT_TRUE(q.empty());
    }

    AutoTestMethod m3{3, "apply_pop_2_times", &QueueSpec::apply_pop_2_times};
  };

  struct AutoRegisterSpec : testing::Test {
  protected:
    AutoRegisterSpec() : progress(ss), root(suite()) {
      result.addListener(progress);
    }

    ~AutoRegisterSpec() {
      delete root;
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
    ::Test* root;
  };
}

TEST_F(AutoRegisterSpec, manually_registering_test_cases) {
  result.runRootTest(*root);
  assertOutput("starting...\n******\nend.\n");
}
