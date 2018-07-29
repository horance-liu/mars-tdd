#ifndef HF5FAC4CC_C66E_4917_AFEE_AF3EC669FC88
#define HF5FAC4CC_C66E_4917_AFEE_AF3EC669FC88

#include <mars/auto/AutoTestFixture.h>
#include <mars/core/TestFixture.h>
#include <mars/util/Symbol.h>
#include <mars/util/Self.h>

#define FIXTURE(type)                        \
struct type;                                 \
static AutoTestFixture<type>                 \
  UNIQUE_NAME(auto_suite_)(STRINGIZE(type)); \
struct type : TestFixture, Self<type>

#define SETUP    void setUp() override
#define TEARDOWN void tearDown() override

#define SUPER_SETUP(super)    super::setUp()
#define SUPER_TEARDOWN(super) super::tearDown()

#endif
