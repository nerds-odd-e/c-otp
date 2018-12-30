#include "today_provider.h"

struct tm getToday() {
    time_t t = time(NULL);
    return *localtime(&t);
}
