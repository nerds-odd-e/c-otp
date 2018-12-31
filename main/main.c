#include <stdio.h>
#include "birthday.h"
#include "rsa_token_dao.h"
#include "authentication_service.h"

int main() {
    printf("Hello, World!\n");
    printf("isValid: %d\n", isValid("joey", "91000000"));
    return 0;
}