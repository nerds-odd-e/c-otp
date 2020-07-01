#include "gtest/gtest.h"
extern "C"
{
#include "authentication_service.h"
#include "rsa_token_dao.h"
#include "logger.h"
#include "fff.h"
}

DEFINE_FFF_GLOBALS;
FAKE_VALUE_FUNC(int, getRandom, const char *, char *, size_t);
FAKE_VOID_FUNC(logMsg, const char *);

const char* stubRandomCode;
int getRandom_custom_fake(const char * userName, char * randomCode, size_t len) {
    sprintf(randomCode, "%s", stubRandomCode);
    return 0;
}

class AuthenticationServiceTest : public testing::Test {
protected:
    void SetUp() {
        RESET_FAKE(getRandom);
        RESET_FAKE(logMsg);
    }
    void givenRandomCode(const char * randomCode) {
        getRandom_fake.custom_fake = getRandom_custom_fake;
        stubRandomCode = randomCode;
    }
};

TEST_F(AuthenticationServiceTest, IsValid) {
    givenRandomCode("000000");

    ASSERT_TRUE(isValid("joey", "91000000"));
}

TEST_F(AuthenticationServiceTest, IsNotValid) {
    givenRandomCode("111111");

    ASSERT_FALSE(isValid("joey", "91000000"));
}

TEST_F(AuthenticationServiceTest, LogMsgWhenInvalid) {
    givenRandomCode("111111");

    isValid("joey", "91000000");
    ASSERT_EQ(logMsg_fake.call_count, 1);
    ASSERT_EQ(strcmp(logMsg_fake.arg0_val, "invalid login"), 0);
}
