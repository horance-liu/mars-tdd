#include <mars/except/TestFailure.h>
#include <mars/listener/text/TextProgress.h>

TextProgress::TextProgress(std::ostream& out)
  : out(out) {}

void TextProgress::startTestRun(const Test&) {
  out << "starting..."
      << std::endl;
}


void TextProgress::startTestCase(const Test&) {
  out << '*';
}

void TextProgress::addFailure(const TestFailure& f) {
  out << (f.isFailure() ? 'F' : 'E');
}

void TextProgress::endTestRun(const Test&) {
  out << std::endl
      << "end."
      << std::endl
      << std::flush;
}
