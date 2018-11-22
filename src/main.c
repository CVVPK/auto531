/*
    This program is used to automate the process of calculating the main lifts for the 5/3/1 training program. It outputs the planned warm up and work sets to stdout. It requires to set the starting date of the program and starting training maxes (90% of actual 1RM as described in the book) for all 4 lifts.
*/

#include <stdio.h>
#include "trainProg.h"
#include "write.h"
#include "date.h"

int main(int argc, char *argv[])
{
    Lift todayLift; // Actually tomorrowLift because date->tm_wday +1
    time_t rawtime;
    struct tm *date;
    int current = time(&rawtime);
    date = localtime(&rawtime);

    if (argc == 1)
    {
        todayLift = getLift(date->tm_wday + 1, getWeek(current, START));
        getSession(todayLift.week, todayLift.cycle, todayLift.lift, todayLift.tMax, todayLift.warmUp, todayLift.sets); // **
    }
    else if (argv[1][0] == 'w')
    {
        cleanWeek();
        for (int i = 1; i < 5; i++)
        {
            todayLift = getLift(i, getWeek(current, START));
            getSession(todayLift.week, todayLift.cycle, todayLift.lift, todayLift.tMax, todayLift.warmUp, todayLift.sets);
        }
    }

    return 0;
}