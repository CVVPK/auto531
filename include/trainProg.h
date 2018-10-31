#include <stdio.h>
#include <string.h>

#define SQUATTMAX 203
#define DEADLIFTTMAX 248
#define BENCHTMAX 115
#define PRESSTMAX 75
#define DELOADWEEK 4
#define START 1537156800 // 5/3/1 Starting point in seconds as returned by getDate(17,9,2018) equivalent to Sept 17 2018 00:00:00

typedef struct lift
{
    int week;
    int cycle;
    char lift[5];
    float tMax;
    int sets[3];
    int warmUp[3];
} Lift;

// Returns the training Max based on cycle
float cycleTmax(int tMax, int cycle);

// Returns the number of cycles the given weeks
// Assumes even is the number of weeks in odd cycles and odd number of weeks in even cycles
int *getWeekCycle(int weeks, int odd, int even, int cycle);

// Returns a struct Lift that corresponds to that specific day's lift based on day of the week, and week in the current cycle
Lift getLift(int day, int weekNum);

// Returns an integer rounded to the nearest toNext
int roundTo(int num, int toNext);