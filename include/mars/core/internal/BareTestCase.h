#ifndef H1E0C0320_33BC_429C_AA0C_4699A3CBD7CF
#define H1E0C0320_33BC_429C_AA0C_4699A3CBD7CF

struct Test;
struct TestCaseProtector;

struct BareTestCase {
  virtual const Test& get() const = 0;
  virtual void runBare(TestCaseProtector&) = 0;

  virtual ~BareTestCase() {}
};

#endif
