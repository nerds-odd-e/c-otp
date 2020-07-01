#ifndef C_OTP_STUB_TODAY_PROVIDER_H
#define C_OTP_STUB_TODAY_PROVIDER_H

#include "time.h"

struct tm today;

void setToday(int month, int day) {
    time_t now = time(0);
    localtime_r(&now, &today);
    today.tm_mon = month - 1;
    today.tm_mday = day;
}

struct tm getToday() {
    return today;
}
#endif //C_OTP_STUB_TODAY_PROVIDER_H
