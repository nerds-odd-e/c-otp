#include "profile_dao.h"
#include "map.h"
#include "stdio.h"

static map_str_t profiles;

char *getPassword(const char *userName) {
    map_init(&profiles);
    map_set(&profiles, "joey", "91");
    map_set(&profiles, "mei", "777");

    return *map_get(&profiles, userName);
}
