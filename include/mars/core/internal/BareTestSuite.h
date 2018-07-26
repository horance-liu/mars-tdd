#ifndef HDB501FB4_B3A8_46C2_9D2A_3B5ADC996406
#define HDB501FB4_B3A8_46C2_9D2A_3B5ADC996406

struct Test;
struct TestResult;

struct BareTestSuite {
  virtual const Test& get() const = 0;
  virtual void runBare(TestResult&) = 0;

  virtual ~BareTestSuite() {}
};


#endif
