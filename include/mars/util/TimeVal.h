#ifndef HBAF08A00_274B_4C13_BB52_02A24AB72B6C
#define HBAF08A00_274B_4C13_BB52_02A24AB72B6C

#include <string>
#include <sys/time.h>
#include <mars/util/StructWrapper.h>

STRUCT_WRAPPER(TimeVal, timeval) {
  TimeVal();
  void now();

  std::string toString() const;
  TimeVal& operator-=(const TimeVal&);
};

#endif
