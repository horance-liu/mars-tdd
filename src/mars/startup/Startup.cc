#include <mars/startup/Startup.h>
#include <mars/listener/text/ColorfulPrinter.h>
#include <mars/factory/TestSuiteFactory.h>
#include <mars/runner/TestRunner.h>

void startup(int, char**) {
  ColorfulPrinter printer;
  TestRunner runner(printer, TestSuiteFactory::root());
  runner.run();
}
