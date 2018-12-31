#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "rsa_token_dao.h"

int getRandom(const char *userName, char *randomCode, size_t len) {
    if (len < 7) {
        return -1;
    }
    int returnCode = snprintf(randomCode, len, "%06ld", random() % 1000000);
    if (returnCode < 0)
        return -1;
    printf("randomCode: %s\n", randomCode);
    return 0;
}
