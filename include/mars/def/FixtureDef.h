#ifndef HF5FAC4CC_C66E_4917_AFEE_AF3EC669FC88
#define HF5FAC4CC_C66E_4917_AFEE_AF3EC669FC88

#include <mars/auto/AutoTestSuite.h>
#include <mars/core/TestFixture.h>
#include <mars/util/Symbol.h>
#include <mars/util/Self.h>

#define FIXTURE(type)                                \
struct type;                                         \
static AutoTestSuite<type> UNIQUE_NAME(auto_suite_); \
struct type : TestFixture, Self<type>

#define SETUP    void setUp() override
#define TEARDOWN void tearDown() override

#define SUPER_SETUP(super)    super::setUp()
#define SUPER_TEARDOWN(super) super::tearDown()

#endif
