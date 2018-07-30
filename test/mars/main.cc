#include <gtest/gtest.h>
#include <mars/startup/Startup.h>

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  startup(argc, argv);
  return RUN_ALL_TESTS();
}
