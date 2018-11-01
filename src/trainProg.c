#include "trainProg.h"

// Returns the training Max based on cycle
float cycleTmax(int tMax, int cycle)
{
    return tMax + ((tMax == SQUATTMAX || tMax == DEADLIFTTMAX ? 10 : 5) * (cycle - 1));
}

// Returns a struct Lift that corresponds to that specific day's lift based on day of the week, and week in the current cycle
Lift getLift(int day, int weekNum)
{
    int i;
    Lift r;
    int lifts[4] = {BENCHTMAX, SQUATTMAX, PRESSTMAX, DEADLIFTTMAX};
    char dailyLifts[4][6] = {"Bench", "Squat", "Press", "Deads"};
    strcpy(r.lift, dailyLifts[day == 5 ? 3 : day - 1]);
    int *wc;
    wc = getWeekCycle(weekNum, 3, 4, 1);
    r.cycle = *wc;
    r.week = *(wc + 1);
    r.tMax = cycleTmax(lifts[day == 5 ? 3 : day - 1], r.cycle);
    for (i = 0; i < 3; i++)
    {
        r.warmUp[i] = roundTo((int)(r.tMax * (0.4 + (0.1 * i))), 5);
        r.sets[i] = r.week != DELOADWEEK ? roundTo((int)(r.tMax * (0.60 + (0.05 * r.week) + (0.1 * i))), 5) : 0;
    }
    return r;
}

// Returns the number of cycles the given weeks
// Assumes even is the number of weeks in odd cycles and odd number of weeks in even cycles
int *getWeekCycle(int weeks, int odd, int even, int cycle)
{
    static int r[2];
    if (weeks > 0)
    {
        // Even weeks -cB (expected 4)
        if (cycle % 2 == 0)
        {
            getWeekCycle(weeks - even, odd, even, ++cycle);
        }

        // Odd weeks -cA (expected 3)
        else
        {
            getWeekCycle(weeks - odd, odd, even, ++cycle);
        }
    }
    else
    {
        r[0] = cycle - 1;
        r[1] = r[0] % 2 ? 3 + weeks : 4 + weeks;
        return r;
    }
}

// Returns an integer rounded to the nearest toNext
int roundTo(int num, int toNext)
{
    return num % toNext == 0 ? num : ((num / toNext) * toNext) + ((num % toNext) > ((toNext / 2) + (toNext % 1)) ? toNext : 0);
}