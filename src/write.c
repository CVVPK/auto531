#include "write.h"

// Writes a formatted version of sets[] to file fp
void writeLift(int warmUp, int week, int sets[], FILE *fp)
{
    int i;
    for (i = 0; i < 3; i++)
    {
        fprintf(fp, "%d x %d lbs\n", getReps(week, i, warmUp), sets[i]);
    }
}

// Creates output file and writes to it
void writeFile(int week, int cycle, char lift[], int tMax, int warmUp[], int sets[])
{
    FILE *fp;
    fp = fopen("../liftTomorrow.txt", "w");
    fprintf(fp, "Subject: 5/3/1 %s Week: %d Cycle: %d\n\n", lift, week, cycle);
    fprintf(fp, "%s -- TMAX: %d lbs\n", lift, tMax);
    fprintf(fp, "Warm Up:\n");
    writeLift(1, week, warmUp, fp);
    fprintf(fp, "\n");
    fprintf(fp, "Work Sets:\n");
    writeLift(0, week, sets, fp);
    fclose(fp);
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