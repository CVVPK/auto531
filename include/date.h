#include <stdio.h>
#include <time.h>

// Returns date received as seconds from Epoch (aka linux time)
// Expects day= day of month, month = month of year, year = year
long int getDate(int day, int month, int year);

// Returns the weeks passed since start to current
// 604800 is the number of seconds in a week
// Expects current and start to be values in seconds as returned by time()
int getWeek(int current, int start);