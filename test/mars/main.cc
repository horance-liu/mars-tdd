#define GTEST_DONT_DEFINE_TEST 1
#include <gtest/gtest.h>
#include <mars/mars.h>

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  run_all_tests(argc, argv);
  return RUN_ALL_TESTS();
}
