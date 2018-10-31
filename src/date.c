#include "date.h"

// Returns date received as seconds from Epoch (aka linux time)
// Expects day= day of month, month = month of year, year = year
long int getDate(int day, int month, int year)
{
    time_t rt;
    struct tm *timeinfo;
    time(&rt);
    timeinfo = localtime(&rt);
    timeinfo->tm_mday = day;
    timeinfo->tm_year = year - 1900;
    timeinfo->tm_mon = month - 1;
    timeinfo->tm_sec = 0;
    timeinfo->tm_min = 0;
    timeinfo->tm_hour = 0;
    return mktime(timeinfo);
}

// Returns the weeks passed since start to current
// 604800 is the number of seconds in a week
// Expects current and start to be values in seconds as returned by time()
int getWeek(int current, int start)
{
    return ((int)difftime(current, start) / 604800) + 1;
}
