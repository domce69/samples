// Name: Thomas Andraos
// Student Code: TA952
// Student Number: 6280341
// Lab: Wednesday 15:30 - 17:30
#include "Header.h"
#include <iostream>
#include <random>
#include <time.h>
#include <vector>
using namespace std;

int main(int argc, char* argv[]) {
    
    srand (time(NULL));
    int teams = atoi(argv[1]); //taking in compiler arguments
    int meets = atoi(argv[2]);
    
    Season s1; //creating season, meet, and generating the simulation
    Meet m1;
    m1.generateMeets(meets, teams, s1.athletes);
    
    return 0;
}
