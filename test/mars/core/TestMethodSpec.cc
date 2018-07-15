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
}

TEST(WasRunSpec, full_life_cycle_for_test_case) {
  TestMethod<WasRun> test(&WasRun::testMethod);
  test.run();
  ASSERT_EQ("[setUp][runTest][tearDown]", result);
}

namespace {
  bool wasSucc = false;

  struct WasSucc : TestFixture {
    void testMethod() {
      wasSucc = true;
    }
  };
}

TEST(WasSuccSpec, make_sure_test_running_is_succ) {
  TestMethod<WasSucc> test(&WasSucc::testMethod);

  ASSERT_FALSE(wasSucc);
  test.run();
  ASSERT_TRUE(wasSucc);
}
