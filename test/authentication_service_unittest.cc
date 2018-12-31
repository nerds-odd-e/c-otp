#include "gtest/gtest.h"
extern "C"
{
#include "../main/authentication_service.h"
#include "stub_rsa_token_dao.h"
//#include "fff.h"
}

//DEFINE_FFF_GLOBALS;
//FAKE_VOID_FUNC(getRandom, char *, char *);

TEST(AuthenticationServiceTest, IsValid) {

    ASSERT_TRUE(isValid("joey", "91000000"));
}


