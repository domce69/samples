//
//  implimentation2.cpp
//  BOB
//
//  Created by Thomas Andraos on 31/8/20.
//  Copyright © 2020 Thomas Andraos. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "Header.h"
#include <fstream>
#include <ostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <sstream>
#include <random>

using namespace std;

void getBandData(string bandData){
    
    ifstream inData;
    string bName;
    string bandMusoData;
    string temp;
    int i = 0;

    inData.open(bandData); // opening text file
    
    if(!inData){ //checking to see if we arent in the file
        
        cerr << "Error Opening File " + bandData + ". Please check your file name is correct" << endl;
        exit(0);
    }
    
    while(inData.good()){ // grabing data from the file and creating objects and putting in a vector
    
        getline(inData, bName, ':');
        getline(inData, bandMusoData, '.');
        getline(inData, temp);
        
        if (!bName.empty() && bName != "\n"){  //checking to make sure name is not empty
             bands.push_back(Band());
                  bands[i].name = bName;
                  bands[i].musicianCode = bandMusoData;
        }
        
        i++;
    }
    
    inData.close();
    
}

void getMusicianData(string musicianData){
    
    ifstream inData;
    string cod;
    string type;
    string strMax;
    string strImpact;
    string strVari;
    string temp;
    int max;
    int impact;
    int variability;
    int i = 0;
    
    inData.open(musicianData); // opening text file
    
    if(!inData){ //checking to see if we arent in the file
        
        cerr << "Error Opening File " + musicianData + ". Please check your file name is correct" << endl;
        exit(0);
    }
    
    while(!inData.eof()){ // grabing data from the file and creating objects and putting in a vector
        
        getline(inData, cod, ':');
        getline(inData, type, ':');
        getline(inData, strMax, ':');
        getline(inData, strImpact, ':');
        getline(inData, strVari, '.');
        getline(inData, temp); // grabbing the empty line and assigning to nothing

        max = stoi(strMax);
        impact = stoi(strImpact);
        variability = stoi(strVari);
        
        if(!type.empty() && type != "\n") {  //checking to make sure name is not empty
            if(!cod.empty() && cod != "\n") {
                musos.push_back(Musician());
                musos[i].code = cod;
                musos[i].type = type;
                musos[i].max = max;
                musos[i].impact = impact;
                musos[i].variability = variability;
            }
        }
        i++;
        if(inData.bad()){
            
            inData.clear();
            inData.ignore(100, '\n');
            break;
        }
    }
    
    inData.close();
}

void getJudgeData(string judgeData){
    
    ifstream inData;
    string name;
    string strTough;
    string temp;
    int toughness;
    string strMood;
    int moodiness;
    int i = 0;
    
    inData.open(judgeData); //opening text file
    
     if(!inData){ // checking that we are in the file
           
        cerr << "Error Opening File " + judgeData + ". Please check your file name is correct" << endl;
        exit(0);
       }
    
    while(inData.good()){ //grabbing data from the file and creating objects put into a vector
        
        if (inData.fail()) {
            
            inData.clear();
            inData.ignore(100, '\n');
        }
        
        getline(inData, name, ':');
        getline(inData, strTough, ':');
        getline(inData, strMood, '.');
        getline(inData, temp);
        
        toughness = stoi(strTough);
        moodiness = stoi(strMood);
        
        if(!name.empty() && name != "\n"){ //checking to make sure name is not empty
            judges.push_back(Judge());
            judges[i].name = name;
            judges[i].toughness = toughness;
            judges[i].moodiness = moodiness;
        }
        i++;
    }
    
    inData.close();
}

int bandPotential(int bandNumb){
    
    string musoCode;
    string musoAmount;
    int musoA;
    int potential = 30;
    
    for (int i = 0; i < bands[bandNumb].musicianCode.size(); i+=2){ // grabbing musician code and incrementing by 2
        
        musoCode = bands[bandNumb].musicianCode.at(i);          //getting musician type
        musoAmount = bands[bandNumb].musicianCode.at(i+1); // getting quantity
        musoA = stoi(musoAmount); // converting string to int

        for (int j =0; j<musos.size(); j++)
        {
            if(musos.at(j).code == musoCode)
            {
                potential += musos.at(j).impact * musoA; // calculating potential
            }
        }
        
        if (potential > 100) {  //making sure potential is always 100 if its > 100
            potential = 100;
        }
    }
    
    return potential;
}

int getBandVariability(int bandNum){
    
    string musoCode;
    string musoAmount;
    int musoA;
    int variability = 5;
    
    for (int i = 0; i < bands[bandNum].musicianCode.size(); i+=2){ //grabbing whole Musician code and incrementing by 2
        
        musoCode = bands[bandNum].musicianCode.at(i); //getting musician type
        musoAmount = bands[bandNum].musicianCode.at(i+1); // getting musician quantity
        musoA = stoi(musoAmount); // converting string to int
        
        for (int j = 0; j<musos.size(); j++){
            if(musos.at(j).code == musoCode){ // calculating variability
                variability += musos.at(j).variability * musoA;
            }
        }
        
    }
    return variability;
}

int performanceGenerator(int potential, int variability)
{   //performance generator based off of normal distribution using bands potential and variability
    static default_random_engine random(time(0));
    static normal_distribution<double> distribution(potential, variability);
    return distribution(random);
}



double judgesScore(int performanceScore, int bandNumb, string output)
{
    int toughness;
    int moodiness;
    int threshold;
    double passCount = 0;
    double failCount = 0;
    double award = 0;
    string passOrFail;
    string outcome;
    string temp;
    ofstream outData;
    
    outData.open(output, ios_base::app); //adding to text file
    outData << bands[bandNumb].name << ":" << bands[bandNumb].musicianCode << "." << endl;
    outData << "Performance score: " << performanceScore << "\n" << endl;
    
    for (int i = 0; i < judges.size(); i++) { //getting the toughness and moodiness from judges to create random threshold
                                            // using normal distribution
        toughness = judges[i].toughness;
        moodiness = judges[i].moodiness;
        
        static default_random_engine random(time(0));
        static normal_distribution<double> distribution(toughness, moodiness);
        threshold =  distribution(random);
        //checking if the band passes or fails and counting
        if (performanceScore >= threshold) {
            
            passOrFail = "You have Passed\n";
            passCount += 1;
        }
        
        else {
            
            passOrFail = "You have failed\n";
            failCount +=1;
            
        }
        
        temp = to_string(threshold);
        outcome = "Threshold: " + temp + "\n" + passOrFail; //getting result and outputting to file
        outData << outcome << endl;
        
    }
    
    award = (passCount * 100) / (failCount + passCount); //getting the % of passes
    outData.close();
    return award;
}

string awardGiven(int award, string output){ //getting the award level based off of passes and fails
    
    string awardLevel;
    ofstream outData;
    outData.open(output, ios_base::app); //amending the output file
    
    if (award == 100) {
        
        awardLevel = "Award Level: Platinum Award";
        
    }
    else if (award < 100 && award >= 80) {
        
        awardLevel = "Award Level: Gold Award";
    }
    
    else if (award < 80 && award >= 50) {
        awardLevel = "Award Level: Silver Award";
    }
    
    else if (award < 50 && award >= 20) {
        awardLevel = "Award Level: Bronze Award";
    }
    else {
        awardLevel = "Award Level: No Award";
    }
    
    outData << awardLevel << endl; //outputting results
    cout << awardLevel << endl;
    outData.close();
    return awardLevel;
}

void outputWriting(string output){ //printing with for loops to standard out and output file
    
    ofstream outData;
    outData.open(output);
    
    cout << "Band name:List of members." << endl;
    for(int i = 0; i < bands.size(); i++) {
        cout << bands[i].name << ":" << bands[i].musicianCode << "." << endl;
    }
    
    cout << "\n" << endl;
    
    cout << "Code:Name:Maximum:Impact:Variability." << endl;
    for(int i = 0; i < musos.size(); i++){
        cout << musos[i].code << ":" << musos[i].type << ":" << musos[i].max << ":" << musos[i].impact << ":" << musos[i].variability << "." << endl;
    }
    
    cout << "\n" << endl;
    
    cout << "Name:Toughness:Moodiness" << endl;
    for(int i = 0; i < judges.size(); i++){
        cout << judges[i].name << ":" << judges[i].toughness << ":" << judges[i].moodiness << "." << endl;
    }
    
   cout << "\n" << endl;
    
    for(int i = 0; i < bands.size(); i++){
        cout << bands[i].name << ":" << bands[i].musicianCode << "." << endl;
        cout << "Overall band potential = " << bandPotential(i) << "\n" << endl;
        
        outData << bands[i].name << ":" << bands[i].musicianCode << "." << endl;
        outData << "Overall band potential = " << bandPotential(i) << "\n" << endl;
    }
    
    cout << "\n" << endl;
    outData << "\n" << endl;
    
    for(int i = 0; i < bands.size(); i++){
        cout << bands[i].name << ":" << bands[i].musicianCode << "." << endl;
        cout << "Overall band variability = " << getBandVariability(i) << "\n" << endl;
        
        outData << bands[i].name << ":" << bands[i].musicianCode << "." << endl;
        outData << "Overall band variability = " << getBandVariability(i) << "\n" << endl;
    }
    
    cout << "\n" << endl;
    outData << "\n" << endl;
    
    cout << "******************************************" << endl;
    cout << "* Proportion of passes |  Award Level    *" << endl;
    cout << "*         0%           |  No Award       *" << endl;
    cout << "*         20%          |  Bronze Award   *" << endl;
    cout << "*         50%          |  Silver Award   *" << endl;
    cout << "*         80%          |  Gold Award     *" << endl;
    cout << "*         100          |  Platinum Award *" << endl;
    cout << "******************************************" << endl;
    
    outData << "******************************************" << endl;
    outData << "* Proportion of passes |  Award Level    *" << endl;
    outData << "*         0%           |  No Award       *" << endl;
    outData << "*         20%          |  Bronze Award   *" << endl;
    outData << "*         50%          |  Silver Award   *" << endl;
    outData << "*         80%          |  Gold Award     *" << endl;
    outData << "*         100          |  Platinum Award *" << endl;
    outData << "******************************************" << endl;
    
    for(int i = 0; i < bands.size(); i++){
        cout << bands[i].name << ":" << bands[i].musicianCode << "." << endl;
        awardGiven(judgesScore(performanceGenerator(bandPotential(i), getBandVariability(i)), i, output), output);
    }
    
    outData.close();
}
