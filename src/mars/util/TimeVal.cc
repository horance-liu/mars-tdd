#include <mars/util/TimeVal.h>
#include <sys/time.h>
#include <sstream>

TimeVal::TimeVal() {
  tv_sec  = 0;
  tv_usec = 0;
}

void TimeVal::now() {
  gettimeofday(this, 0);
}

std::string TimeVal::toString() const {
  std::stringstream ss;
  if (tv_sec > 0) {
    ss << tv_sec << " s ";
  }
  ss << tv_usec << " us";
  return ss.str();
}

TimeVal& TimeVal::operator-=(const TimeVal& start) {
  while (tv_usec < start.tv_usec) {
    tv_usec += 1000000;
    tv_sec--;
  }
  tv_usec -= start.tv_usec;
  tv_sec  -= start.tv_sec;
  return *this;
}
