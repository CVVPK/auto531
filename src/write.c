#include "write.h"

// Writes a formatted version of sets[] to file fp
void getSets(int warmUp, int week, int sets[])
{
    int i;
    for (i = 0; i < 3; i++)
    {
        printf("%d x %d lbs\n", getReps(week, i, warmUp), sets[i]);
    }
}

// Creates output file and writes to it
void getSession(int week, int cycle, char lift[], int tMax, int warmUp[], int sets[])
{
    printf("\n");
    printf("%s -- TMAX: %d lbs\n", lift, tMax);
    printf("Week: %d Cycle: %d\n\n", week, cycle);
    printf("Warm Up:\n");
    getSets(1, week, warmUp);
    printf("\n");
    printf("Work Sets:\n");
    getSets(0, week, sets);
    printf("\n");
    printf("=====================\n");
}

// Returns the corresponding reps for the workout based on the week and number "i" of set. You should pass warmUp = 0 if work set | warmUp = 1 if warm up set
int getReps(int week, int i, int warmUp)
{
    int reps;
    reps = 5;
    if (week == 2 && !warmUp)
    {
        reps = 3;
    }
    else if (week == 3 && !warmUp)
    {
        reps = 5 - (i * 2);
    }
    else if (warmUp && i == 2)
    {
        reps = 3;
    }
    return reps;
}