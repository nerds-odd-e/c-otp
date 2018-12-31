#ifndef C_OTP_STUB_RSA_TOKEN_DAO_H
#define C_OTP_STUB_RSA_TOKEN_DAO_H

int getRandom(const char *userName, char *randomCode, size_t len) {
    sprintf(randomCode, "000000");
    return 0;
}

#endif //C_OTP_STUB_RSA_TOKEN_DAO_H
