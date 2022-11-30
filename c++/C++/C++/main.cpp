//
//  main.cpp
//  BOB
//
//  Created by Thomas Andraos on 30/8/20.
//  Copyright © 2020 Thomas Andraos. All rights reserved.
//

#include <iostream>
#include "implimentation2.cpp"
#include <fstream>
using namespace std;

int main(int argc, char* argv[]) {
    // calling functions
    getBandData(argv[1]);
    getMusicianData(argv[2]);
    getJudgeData(argv[3]);
    bandPotential(0);
    getBandVariability(0);
    judgesScore(performanceGenerator(bandPotential(0), getBandVariability(0)), 0, argv[4]);
    outputWriting(argv[4]);
    return 0;
}
