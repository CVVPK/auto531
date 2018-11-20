#include <stdio.h>

// Writes a formatted version of sets[] to file fp
void getSets(int warmUp, int week, int sets[]);

// Creates output file and writes to it
void getSession(int week, int cycle, char lift[], int tMax, int warmUp[], int sets[]);

// Returns the corresponding reps for the workout based on the week and number "i" of set. You should pass warmUp = 0 if work set | warmUp = 1 if warm up set
int getReps(int week, int i, int warmUp);
