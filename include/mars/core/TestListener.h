#ifndef H76B7D843_866D_47F0_A922_96F5E8E348E8
#define H76B7D843_866D_47F0_A922_96F5E8E348E8

struct Test;

struct TestListener {
  virtual void startTestCase(const Test&) {}
  virtual ~TestListener() {}
};

#endif
