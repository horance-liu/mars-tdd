#ifndef HBAF08A00_274B_4C13_BB52_02A24AB72B6C
#define HBAF08A00_274B_4C13_BB52_02A24AB72B6C

#include <time.h>
#include <mars/util/StructWrapper.h>

STRUCT_WRAPPER(TimeVal, timeval) {
  TimeVal();
  void now();

  bool operator<(const TimeVal&) const;
  TimeVal& operator-=(const TimeVal&);
};

#endif
