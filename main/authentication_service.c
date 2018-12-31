#include <stdlib.h>
#include <string.h>
#include "authentication_service.h"
#include "profile_dao.h"
#include "rsa_token_dao.h"
#include <stdio.h>

bool isValid(char *userName, char *password) {
    char * basePassword = getPassword(userName);

    char * randomCode;
    getRandom(randomCode, userName);

    char *validPassword = (char *)malloc(sizeof(basePassword) + sizeof(randomCode) + 1);
    if (validPassword == NULL)
        return false;

    strcat(validPassword, basePassword);
    strcat(validPassword, randomCode);

    bool isValid = password == validPassword;

    free(validPassword);

    if (isValid) {
        return true;
    } else {
        return false;
    }
}
