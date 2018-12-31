#include "gtest/gtest.h"
extern "C"
{
#include "../main/authentication_service.h"
#include "../main/rsa_token_dao.h"
#include "fff.h"
}

DEFINE_FFF_GLOBALS;
FAKE_VALUE_FUNC(int, getRandom, const char *, char *, size_t);

const char* stubRandomCode;
int getRandom_custom_fake(const char * userName, char * randomCode, size_t len) {
    sprintf(randomCode, "%s", stubRandomCode);
    return 0;
}

TEST(AuthenticationServiceTest, IsValid) {
    getRandom_fake.custom_fake = getRandom_custom_fake;
    stubRandomCode = "000000";

    ASSERT_TRUE(isValid("joey", "91000000"));
}


