#include <mars/runner/TestRunner.h>
#include <mars/startup/Startup.h>

void startup(int, char**) {
  TestRunner runner;
  runner.run();
}
