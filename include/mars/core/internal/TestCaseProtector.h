#ifndef H61339772_47AF_4DCC_B397_065FD9286858
#define H61339772_47AF_4DCC_B397_065FD9286858

struct TestCaseFunctor;

struct TestCaseProtector {
  virtual bool operator()(const TestCaseFunctor&) = 0;
  virtual ~TestCaseProtector() {}
};

#endif
