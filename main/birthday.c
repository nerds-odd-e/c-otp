#include "birthday.h"
#include "today_provider.h"

bool isBirthday() {
    struct tm today = getToday();
    return today.tm_mon + 1 == 4 && today.tm_mday == 9;
}
