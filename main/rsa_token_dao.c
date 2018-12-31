#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "rsa_token_dao.h"

void getRandom(char *randomCode, char *userName) {
    sprintf(randomCode, "%06ld", random() % 1000000);
    printf("randomCode: %s\n", randomCode);
}
