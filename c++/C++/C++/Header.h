//
//  Header.h
//  BOB
//
//  Created by Thomas Andraos on 30/8/20.
//  Copyright © 2020 Thomas Andraos. All rights reserved.
//

#ifndef Header_h
#define Header_h
#include <vector>
using namespace std;

struct Musician{ // creating structs
    string code;
    string type;
    int max;
    int impact;
    int variability;
};

struct Band{
    string name;
    string musicianCode;
    int potential;
    int variability;
};

struct Judge{
    string name;
    int toughness;
    int moodiness;
};

vector<Band> bands; //creating vectors
vector<Musician> musos;
vector<Judge> judges;

void getBandData(); // creating prototypes
void getMusicianData();
void getJudgeData();
int bandPotential(int bandNum);
int getBandVariability(int bandNum);
int performanceGenerator(int potential, int variability);
double judgesScore(int performanceScore, int bandNumb, string output);
string awardGiven(int award, string output);
void outputWriting(string output);

#endif /* Header_h */
