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
void writeFile(int week, int cycle, char lift[], int tMax, int warmUp[], int sets[], char argv)
{
    FILE *fp;
    char oneLift[20] = "./script/lift.txt";
    char weekLift[20] = "./script/week.txt";
    fp = fopen((argv == 'w' ? weekLift : oneLift), (argv == 'w' ? "a" : "w"));
    fprintf(fp, "Subject: 5/3/1 %s Week: %d Cycle: %d\n\n", lift, week, cycle);
    fprintf(fp, "%s -- TMAX: %d lbs\n", lift, tMax);
    fprintf(fp, "Warm Up:\n");
    writeLift(1, week, warmUp, fp);
    fprintf(fp, "\n");
    fprintf(fp, "Work Sets:\n");
    writeLift(0, week, sets, fp);
    fprintf(fp, "\n");
    fclose(fp);
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