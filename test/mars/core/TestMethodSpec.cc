#include <mars/core/TestMethod.h>
#include <gtest/gtest.h>

namespace {
  std::string result;

  struct WasRun : TestFixture {
    void testMethod() {
      result += "[runTest]";
    }

  private:
    void setUp() override {
      result += "[setUp]";
    }

    void tearDown() override {
      result += "[tearDown]";
    }
  };

  bool wasSucc;

  struct WasSucc : TestFixture {
    void testMethod() {
      wasSucc = true;
    }
  };

  struct TestMethodSpec : testing::Test {
  private:
    void SetUp() override {
      result.clear();
      wasSucc = false;
    }

  protected:
    void run(::Test& test) {
      test.run();
    }
  };
}

TEST_F(TestMethodSpec, full_life_cycle_for_test_case) {
  TestMethod<WasRun> test(&WasRun::testMethod);
  run(test);
  ASSERT_EQ("[setUp][runTest][tearDown]", result);
}


TEST_F(TestMethodSpec, make_sure_test_running_is_succ) {
  TestMethod<WasSucc> test(&WasSucc::testMethod);

  ASSERT_FALSE(wasSucc);
  run(test);
  ASSERT_TRUE(wasSucc);
}
