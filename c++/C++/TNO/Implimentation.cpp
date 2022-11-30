// Name: Thomas Andraos
// Student Code: TA952
// Student Number: 6280341
// Lab: Wednesday 15:30 - 17:30

#include "Header.h"
#include <vector>
#include <string>
#include <iostream>
#include <random>
#include <algorithm>
#include <cmath>

using namespace std;

//Team Functions

Team::Team(string tname, Athlete ath1, Athlete ath2, Manager man1, SupportCrew sup1){ //constructer
    
    name = tname;
    athletes.push_back(ath1);
    athletes.push_back(ath2);
    managers.push_back(man1);
    supportCrews.push_back(sup1);
}


Athlete Team::getAthlete(int index){ //returning athletes index
    return athletes[index];
}

//Athlete
//constructor for athlete
Athlete::Athlete(string aName, string aGender, int aPoints, int health, bool injury, float performance, int consistancy, int aStrength, int aSpeed, int id){
    
    name = aName;
    gender = aGender;
    points = aPoints;
    healthLevel = health;
    isInjured = injury;
    physicalLevel = performance;
    consistancyLevel = consistancy;
    strength = aStrength;
    speed = aSpeed;
    teamId = id;
}
//getters and setters
int Athlete::getTeamId(){
    return teamId;
}

void Athlete::setTeamId(int id){
    teamId = id;
}

string Athlete::getGender(){
    return gender;
}

void Athlete::setPoints(int point){
    points = points + point;
}

int Athlete::getPoints(){
    return points;
}

string Athlete::getName(){
    return name;
}

int Athlete::getHealthLevel(){
    return healthLevel;
}

void Athlete::setHealthLevel(int health){
    healthLevel = health;
}

float Athlete::getPhysicalLevel(){
    return physicalLevel;
}

void Athlete::setPhysicalLevel(float physical){
    physicalLevel = physical;
}

int Athlete::getConsistancyLevel(){
    return consistancyLevel;
}

void Athlete::setConsistancyLevel(int consistancy){
    consistancyLevel = consistancy;
}

bool Athlete::getIsInjured(){
    return isInjured;
}

void Athlete::setIsInjured(bool injured){
    isInjured = injured;
}

int Athlete::getSpeed(){
    return speed;
}

void Athlete::setSpeed(int newSpeed){
    speed = newSpeed;
}

int Athlete::getStrength(){
    return strength;
}

void Athlete::setStrength(int newStrength){
    strength = newStrength;
}

//setting the data with controlled random values for the athletes
void Athlete::setData(int index){
    string retrivedName;
    
    if(gender == "Male"){
        retrivedName = maleNames[index];
    }
    else {
        retrivedName = femaleNames[index];
    }
    
    name = retrivedName; //revise how stats are generated
    points = 0; //stays 0
    healthLevel = randomNumbGen(50, 25);
    isInjured = false; //stays 0
    physicalLevel = randomFloatGen(20, 0); //out of 100
    consistancyLevel = randomFloatGen(10, 0);
    strength = randomFloatGen(10, 0);
    speed = randomFloatGen(10, 0);
}

int Athlete::randomNumbGen(int max, int min){ //random number gens
    
    return rand() % max + min;
}

float Athlete::randomFloatGen(float max, float min){
    
    float random = ((float) rand()) / (float) RAND_MAX;
        float diff = max - min;
        float r = random * diff;
        return min + r;
}


int Athlete::randomNormalDistribution(int variability, int mean){
    
    static default_random_engine random(time(0));
    static normal_distribution<double> distribution(mean, variability);
    return distribution(random);
}

float Athlete::calcTrackPerformanceLevel(){  //calc methods for field and track
    
    return healthLevel + physicalLevel + (speed * 2) + consistancyLevel;
}

float Athlete::calcFieldPerformanceLevel(){
    
    return healthLevel + physicalLevel + (strength * 2) + consistancyLevel;
}



//Events

int Event::generateRandomResult(int max, int min){ //random number gen and gets and sets
    
    return rand() % max + min;
}

string Event::getName(){
    return name;
}

void Event::setLocationImpact(int impact){
    featureImpact = impact;
}

int Event::getFeatureImpact(){
    return featureImpact;
}
//Support Crew

SupportCrew::SupportCrew(Physiotherapist, Psychologist, Trainer, Trainer){} //constructor

//Track

Track::Track(string tname, int tmetres, int weatherImp, int featureImp){ //constructor
    name = tname;
    metres = tmetres;
    weatherImpact = weatherImp;
    featureImpact = featureImp;
}

string Track::getName(){ //getters and setters
    return name;
}

int Track::getMetres(){
    return metres;
}

void Track::setName(string name){
    name = name;
}

void Track::setMetres(int metres){
    metres = metres;
}

void Track::printTrackEventData(){ //printing event data
    
    cout << "\nEvent Name: " << name << endl;
    cout << "Metres: " << metres << "m" << endl;
}

void Track::generateTrackEvent(vector<Athlete> athlete, int eventStandard, string metric){ //generating event

    for (int i = 0; i < athlete.size(); i ++){
        
        float result;
        float temp;
        float temp1;
        string name;
        float performance = athlete[i].calcTrackPerformanceLevel(); //calculating end result
        temp = eventStandard * performance / 100 + weatherImpact + featureImpact;
        temp1 = eventStandard - temp;
        
        result = eventStandard + temp1;
        
        
        name = athlete[i].getName();
        cout << name << "'s Result: " << result << metric << "\n" << endl;
        //generateWear(athlete[i]); //fix
        
        Result r1; //vreating result object and pushing to array
        r1.name = name;
        r1.result = result;
        results.push_back(r1);
    }
}

//Field functions
Field::Field(string fname, int fdistance, int weatherImp, int specialImp){ //constructor
    name = fname;
    distance = fdistance;
    weatherImpact = weatherImp;
    featureImpact = specialImp;
}

string Field::getName(){ //getters and setters
    return name;
}

int Field::getDistance(){
    return distance;
}
void Field::setName(string name){
    name = name;
}

void Field::setDistance(int distance){
    distance = distance;
}

void Field::printFieldEventData(){ //printing event data
    
    cout << "\nEvent Name: " << name << endl;
    cout << "Metres: " << distance << endl;
}

void Field::generateFieldEvent(vector<Athlete> athlete, int eventStandard, string metric){ //generating field events
        
        for (int i = 0; i < athlete.size(); i ++){
            
            float result;
            int temp;
            int temp1;
            string name;
            int performance = athlete[i].calcFieldPerformanceLevel();
            temp = eventStandard * performance / 100 - weatherImpact - featureImpact; //calc performance
            temp1 = eventStandard - temp;
            
            result = eventStandard - temp1;
            
            name = athlete[i].getName();
            cout << name << "'s Result: " << result << metric << "\n" << endl;
            
            Result r1;
            r1.name = name;
            r1.result = result;
            results.push_back(r1); //creating result object and pushing to array
        }
}

//Location functions

string Location::getName(){ //getters and setters
    return name;
}

string Location::getFeature(){
    return feature;
}

void Location::generateLocation(int index){ //location generation
    name = locationName[index];
    feature = specialFeatures[index];
    id = index;
}

int Location::generateLocationImpact(){ //generating controlled random location impact
    return rand() % 3 + 1;
}

void Location::setLocationsImpact(Location location, vector<Event>events){ //setting the impact of special features on their events
    
    int impact = location.generateLocationImpact();
    
    for(int i = 0; i < events.size(); i++){
        
        if (location.getName() == locationName[i]) {
            events[i].setLocationImpact(impact);
        }
    }
}

//Weather functions
int Weather::getDegrees(){ //getters and setters
    return degrees;
}

int Weather::getWindSpeed(){
    return windSpeed;
}

bool Weather::getIsRaining(){
    return isRaining;
}

int Weather::getImpact(){
    return impact;
}

void Weather::setImpact(int newImpact){
    impact = newImpact;
}

int Weather::randomGenerator(int high, int low){ //random number generator
    
    int weather = rand() % high + low;
    return weather;
}

void Weather::generateWeather(){ //generating weather based off of controlled random values
    
    degrees = randomGenerator(32, 12);
    windSpeed = randomGenerator(50, 0);
    
    if(degrees < 15 && windSpeed > 1){
        isRaining = true;
    }
    else {
        isRaining = false;
    }
}

string Weather::weatherReport(){ //reporting on the weather and setting impact based off of the conditions
    
    int degrees = getDegrees();
    int wind = getWindSpeed();
    bool rain = getIsRaining();
    string condition = "";
    
    cout << "Tempreture: " << degrees << endl;
    cout << "Wind Speed: " << wind << endl;
    cout << "Is it raining ? " << rain << endl;
    
    if(wind > 40 && rain){
       
        condition = "Due to the high wind speed and rain, the weather condition is bad.";
        setImpact(2);
    }
    else if (wind > 40 && !rain){
        condition = "Due to the high wind speed the weather condition is moderate.";
        setImpact(1);
    }
    else if (wind < 40 && rain) {
        condition = "Due to the rain, the weather condition is bad.";
        setImpact(2);
    }
    else {
        condition = "With low wind speed and no rain, todays weather condition is good!";
        setImpact(0);
    }
    
    return condition;
    
}

//Meet Functions

void Meet::generateMeets(int meets, int teams, vector<Athlete>athletes){ //generating the season
    Season s1;
    s1.generateTeams(teams); //generating teams

    for(int k = 0; k < meets; k++) {
        
        cout << "==========  Meet " << k + 1 << "  ==========" << endl;
        Location l1;
        l1.generateLocation(k); //generating location
        cout << "\nLocation: " << l1.getName() << endl;
        cout << "\nSpecial Feature: " << l1.getFeature() << endl;
        for(int i = 1; i <= 2; i++){
            //run fuctions for day generations
            switch(i){
                case 1:{
                    cout << "Day " << i << endl; //meet day
                    Weather w1;
                    w1.generateWeather(); //generating weather
                    
                    cout << w1.weatherReport() << endl; //printing weather report

                    Track hundredMetre("100 Metre Running Race.", 100, w1.getImpact(), 0); //creating day 1 events and pushing to array
                    s1.events.push_back(hundredMetre);
                    Field discus("Discus Throw", 1000, w1.getImpact(), 0);
                    s1.events.push_back(discus);
                    Field f1("Javelin Throw", 1000, w1.getImpact(), 0);
                    s1.events.push_back(f1);
                    Track t1("110 Metre Hurdles", 14, w1.getImpact(), 0);
                    s1.events.push_back(t1);
                    l1.setLocationsImpact(l1, s1.events);
                    
                    
                    hundredMetre.printTrackEventData(); //printing event data, generating results and printing
                    hundredMetre.generateTrackEvent(s1.athletes, 10.395, " seconds");
                    s1.awardTrackResults(hundredMetre.results, 25.4347, 18, 1.81, " seconds");
                    s1.generateWear();
                    
                    //event results here
                    
                    discus.printFieldEventData();
                    discus.generateFieldEvent(s1.athletes, 56.17, "m");
                    s1.awardFieldResults(discus.results, 12.91, 4, 1.1, "m");
                    s1.generateWear();
                    //event results here
                    
                    
                    f1.printFieldEventData();
                    f1.generateFieldEvent(s1.athletes, 77.19, "m");
                    s1.awardFieldResults(f1.results, 10.14, 7, 1.08, "m");
                    s1.generateWear();
                    
                    //event results here
                    t1.printTrackEventData();
                    t1.generateTrackEvent(s1.athletes, 13.8, " seconds");
                    s1.awardTrackResults(t1.results, 5.74352, 28.5, 1.92," seconds");
                    s1.generateWear();
                    //event results here
                    
                    
                    break;
                }
                case 2:{
                    cout << "Day " << i << endl;
                    Weather w2;
                    w2.generateWeather();
                    cout << w2.weatherReport() << endl;
                    Track t2("400 Metre", 400, w2.getImpact(), 0);
                    s1.events.push_back(t2);
                    Field f2("Long Jump", 200, w2.getImpact(), 0);
                    s1.events.push_back(f2);
                    Field highJump("High Jump", 4, w2.getImpact(), 0);
                    s1.events.push_back(highJump);
                    Track fifteenHundred("1500 Metre Running Race", 1500, w2.getImpact(), 0);
                    s1.events.push_back(fifteenHundred);
                    l1.setLocationsImpact(l1, s1.events);
                    
                    t2.printTrackEventData();
                    t2.generateTrackEvent(s1.athletes, 46.17, " seconds");
                    s1.awardTrackResults(t2.results, 1.53775, 82, 1.81, " seconds");
                    s1.generateWear();
                    
                    //event results here
                    
                    f2.printFieldEventData();
                    f2.generateFieldEvent(s1.athletes, 776, "cm");
                    s1.awardFieldResults(f2.results, 0.14354, 220, 1.4, "cm");
                    s1.generateWear();
                    
                    //event results here
                    
                    
                    highJump.printFieldEventData();
                    highJump.generateFieldEvent(s1.athletes, 220, "cm");
                    s1.awardFieldResults(highJump.results, 0.8465, 75, 1.42,"cm");
                    s1.generateWear();
                    //event results here
                    
                    
                    fifteenHundred.printTrackEventData();
                    fifteenHundred.generateTrackEvent(s1.athletes, 3.5379, " minutes");
                    s1.awardTrackResults(fifteenHundred.results, 0.03768, 480, 1.85, " minutes");
                    s1.generateWear();
                    //event results here
                    Award a2;
                    a2.generateAwards(s1.athletes);
                    
                    break;
                }
            }
        }
        
        if(k + 1 != meets){
            meetGap(); //generating meet gap
            cout << endl;
            s1.reportOnAthletes(); //reporting on the athletes stats
            s1.generateSupportCrewImpact(); //generating between meet recovery/training
            cout << "The support crew have helped recover the athlets stats." << endl;
            s1.reportOnAthletes(); //reporting on the recovery/training
        }
    }
    
    
    Award a1;
    a1.generateSeasonTrophy(s1.athletes); // awarding season trophy
}

void Meet::meetGap(){ //generating meet gap
    
    int gap = rand()%(7 - 5 + 1) + 5;
    cout << gap << " days till the next meet." << endl;
    
}

//Trainer Functions

Trainer::Trainer(string tName, string tSpecialty, int id){ //constructor
    
    name = tName;
    specialty = tSpecialty;
    teamId = id;
}

int Trainer::getTeamId(){ //getter and setters
    return teamId;
}

void Trainer::setTeamId(int id){
    teamId = id;
}

void Trainer::setName(string newName){
  
    name = newName;
}

string Trainer::getName(){
    return name;
}

string Trainer::getSpecialty(){
    return specialty;
}

int Trainer::genAbility(vector<Trainer>trainers, vector<Athlete>athletes, string area, int index){ //generatingh athletes ability
    int abilityTemp;
    for(int i = 0; i < trainers.size(); i++){
        if(teamId == athletes[index].getTeamId() && specialty == area){
            abilityTemp = ability;
        }
    }
    return ability;
}

int Trainer::getAbility(){ //gets and sets
    return ability;
}

void Trainer::setAbility(int newAbility){
    ability = newAbility;
}

int Trainer::generateFieldTraining(vector<Athlete>athletes, int ability){ //generating training for specified type
    int strengthTemp = 0;
    for (int i = 0; i < athletes.size(); i++) {
        strengthTemp = athletes[i].getStrength() + rand() % ability * 0.5 + 1;
    }
    return strengthTemp;
}

int Trainer::generateTrackTraining(vector<Athlete>athletes, int ability){
    int speedTemp = 0;
    for (int i = 0; i < athletes.size(); i++) {
        speedTemp = athletes[i].getSpeed() + rand() % ability * 0.5 + 1;
    }
    return speedTemp;
}

//Support Member functions

string SupportMember::getName(){ //getters and setters
    return name;
}

void SupportMember::setName(string sName){
    name = sName;
}

int SupportMember::getTeamId(){
    return teamId;
}

void SupportMember::setTeamId(int id){
    teamId = id;
}

int SupportMember::getAbility(){
    return ability;
}

void SupportMember::setAbility(int newAbility){
    ability = newAbility;
}


//Manager Functions

string Manager::getName(){ //getters and setters
    return name;
}

void Manager::setName(string mName){
    name = mName;
}

//Season Functions

float Season::awardTrackPoints(float a, float b, float c, float p){ //awarding points equations for specified events
    
    return pow(a * (b - p), c);
}

float Season::awardFieldPoints(float a, float b, float c, float p){
    return pow(a * (p - b), c);
}

void Season::generateWear(){ //generating wear for the athletes after each event
    
    int health;
    int performance;
    int strength;
    int speed;
    int consistancy;
    
    for(int i = 0; i < athletes.size(); i++){
        
        health = athletes[i].getHealthLevel() - rand() % 2;
        performance = athletes[i].getPhysicalLevel() - rand() % 2;
        strength = athletes[i].getStrength() - rand() % 1;
        speed = athletes[i].getSpeed() - rand() % 1;
        consistancy = athletes[i].getConsistancyLevel() - rand() % 2;
        
        athletes[i].setHealthLevel(health);
        athletes[i].setPhysicalLevel(performance);
        athletes[i].setStrength(strength);
        athletes[i].setSpeed(speed);
        athletes[i].setConsistancyLevel(consistancy);
        
        if(!athletes[i].getIsInjured() && health + performance < 35){
            athletes[i].setIsInjured(true);
            athletes[i].setHealthLevel(health * 0.5);
            cout << athletes[i].getName() << " has been injured! " << athletes[i].getGender() << " current health level is: " << athletes[i].getHealthLevel() << endl;
        }
    }
}

int Season::returnAthleteIndex(string name){ //returning an athletes index in the array
  
    int index = 0;
    for (int i = 0; i < athletes.size(); i++){
        
        if (athletes[i].getName() == name){
            index = i;
        }
        
    }
    return index;
}

void Season::awardTrackResults(vector<Result> results, int a, int b, int c, string metric){ //awarding results for track events
    
    int gainedPoints;
    int currentPoints;
    string place;
    
    sort(results.begin(), results.end());
    for(int i = 0; i < 3; i++){
        
        if(i == 0){
            place = " won with a time of: ";
        }
        else if (i == 1) {
            place = " came second with a time of: ";
        }
        else{
            place = " came third with a time of: ";
        }
        
        cout << results[i].name << place << results[i].result << metric << endl;
        int ath1 = returnAthleteIndex(results[i].getName());
        gainedPoints = awardTrackPoints(a, b, c, results[i].getPoints());
        currentPoints = athletes[ath1].getPoints();
        athletes[ath1].setPoints(currentPoints + gainedPoints);
        cout << results[i].name << " gained " << gainedPoints << " points!" << "\n" << endl;
        }
    
    results.clear();
}

void Season::awardFieldResults(vector<Result>results, int a, int b, int c, string metric){ //awarding results for field events
    
    float gainedPoints;
    float currentPoints;
    float result;
    string place;
    int size = results.size() - 1;
    
    sort(results.begin(), results.end());
    for (int i = size; i > size-3; i--){
        
        if(i == size){
            place = " won with a distance of: ";
        }
        else if (i == size-1) {
            place = " came second with a distance of: ";
        }
        else if (i == size-2){
            place = " came third with a distance of: ";
        }
        
        cout << results[i].name << place << results[i].result << metric << endl;
        int ath1 = returnAthleteIndex(results[i].getName());
        result = results[i].getPoints();
        gainedPoints = awardFieldPoints(a, b, c, result);
        currentPoints = athletes[ath1].getPoints();
        athletes[ath1].setPoints(currentPoints + gainedPoints);
        cout << results[i].name << " gained " << gainedPoints << " points!" << "\n" << endl;
        
    }
    
    results.clear();
}

void Season::generateTeams(int teamsAmount){ //creating teams
    
    int count = 0;
    
    for(int j = 0; j < teamsAmount; j++){
    
        Athlete m1("", "Male", 0, 0, 0, 0, 0, 0, 0, j);
        m1.setData(j);
        Athlete f1("", "Female", 0, 0, 0, 0, 0, 0, 0, j);
        f1.setData(j);
    
        Manager man1;
        man1.setName(man1.names[j]);
        
        Physiotherapist ph1("", 0 , 0);
        ph1.setName(ph1.names[count]);
        ph1.setTeamId(j);
        ph1.setAbility(rand() % 4 + 2);
    
        
        Trainer trainer1("","Field", j);
        trainer1.setName(trainer1.names[count++]);
        trainer1.setAbility(rand() % 3 + 1);
        
        Psychologist psy1("", 0 , 0);
        psy1.setName(psy1.names[count]);
        psy1.setTeamId(j);
        psy1.setAbility(rand() % 4 + 2);
        
        Trainer trainer2("","Track", j);
        trainer2.setName(trainer2.names[count++]);
        trainer2.setAbility(rand() % 3 + 1);
        
        SupportCrew sc1(ph1, psy1, trainer1, trainer2);
        Team t1("pp", m1, f1, man1, sc1);
        //reporting on team
        cout << "Athlete's Name: " << m1.getName() << endl;
        cout << "Health Level: " << m1.getHealthLevel() << endl;
        cout << "Physical Level: " << m1.getPhysicalLevel() << endl;
        cout << "Strength Level: " << m1.getStrength() << endl;
        cout << "Speed Level: " << m1.getSpeed() << endl;
        cout << "Consistancy Level: " << m1.getConsistancyLevel() << "\n" << endl;
        
        cout << "Athlete's Name: " << f1.getName() << endl;
        cout << "Health Level: " << f1.getHealthLevel() << endl;
        cout << "Physical Level: " << f1.getPhysicalLevel() << endl;
        cout << "Strength Level: " << f1.getStrength() << endl;
        cout << "Speed Level: " << f1.getSpeed() << endl;
        cout << "Consistancy Level: " << f1.getConsistancyLevel() << "\n" << endl;
    
        
        cout << "Trainer Name: " << trainer1.getName() << endl;
        cout << "Trainer Specailty: " << trainer1.getSpecialty() << endl;
        cout << "Trainer Impact: " << trainer1.getAbility() << "\n" << endl;
    
        cout << "Trainer Name: " << trainer2.getName() << endl;
        cout << "Trainer Specailty: " << trainer2.getSpecialty() << endl;
        cout << "Trainer Impact: " << trainer1.getAbility() << "\n" << endl;
    
        cout << "Psychologist Name: " << psy1.getName() << endl;
        cout << "Psychologist Impact: " << psy1.getAbility() << "\n" << endl;
        
        cout << "Physiotherapist Name: " << ph1.getName() << endl;
        cout << "Physiotherapist Impact: " << ph1.getAbility() << "\n" << endl;
    
        cout << "Manager Name: " << man1.getName() << "\n" << endl;
        
        
        teams.push_back(t1); //pushing back objects to arrays
        athletes.push_back(m1);
        athletes.push_back(f1);
        trainers.push_back(trainer1);
        trainers.push_back(trainer2);
        psychs.push_back(psy1);
        physios.push_back(ph1);
    }
}

void Season::generateSupportCrewImpact(){ //generating training/ recovery for support crew
    
    int fieldAbility = 0;
    int trackAbility = 0;
    int physicalAbility = 0;
    int healthAbility;
    int strengthTemp;
    int speedTemp;
    int healthTemp;
    int physicalTemp;
    int consistancyTemp;
    
    for (int i = 0; i < athletes.size(); i++) {
        
        strengthTemp = athletes[i].getStrength();
        speedTemp = athletes[i].getSpeed();
        healthTemp = athletes[i].getHealthLevel();
        physicalTemp = athletes[i].getPhysicalLevel();
        consistancyTemp = athletes[i].getConsistancyLevel();
        
        fieldAbility = trainers[i].genAbility(trainers, athletes, "Field", i);
        athletes[i].setStrength(strengthTemp + trainers[i].generateFieldTraining(athletes, fieldAbility) * 0.5);
        
        trackAbility = trainers[i].genAbility(trainers, athletes, "Track", i);
        athletes[i].setSpeed(speedTemp + trainers[i].generateTrackTraining(athletes, trackAbility) * 0.5);
        
        consistancyTemp += fieldAbility + trackAbility * 0.75;
        athletes[i].setConsistancyLevel(consistancyTemp);
        
        if (athletes[i].getIsInjured() == true && athletes[i].getHealthLevel() > 30) {
            athletes[i].setIsInjured(false);
            
        }
    }
    
    for(int j = 0; j < physios.size(); j++){
        
        physicalAbility = physios[j].getAbility();
        athletes[j].setPhysicalLevel(physios[j].generatePhysiotherapy(athletes, physicalAbility) * 0.5);
        
        healthAbility = psychs[j].getAbility();
        athletes[j].setHealthLevel(psychs[j].generatePsychology(athletes, healthAbility) * 0.5);
        
        physicalAbility = physios[j].getAbility();
        athletes[j+ 1].setPhysicalLevel(physios[j].generatePhysiotherapy(athletes, physicalAbility)* 0.5);
        
        healthAbility = psychs[j].getAbility();
        athletes[j+ 1].setHealthLevel(psychs[j].generatePsychology(athletes, healthAbility) * 0.3);
        
    }
}


void Season::reportOnAthletes(){ //reporting on athletes
    for (int i = 0; i < athletes.size(); i++){
        cout << "Athlete's Name: " << athletes[i].getName() << endl;
        cout << "Health Level: " << athletes[i].getHealthLevel() << endl;
        cout << "Physical Level: " << athletes[i].getPhysicalLevel() << endl;
        cout << "Strength Level: " << athletes[i].getStrength() << endl;
        cout << "Speed Level: " << athletes[i].getSpeed() << endl;
        cout << "Consistancy Level: " << athletes[i].getConsistancyLevel() << "\n" << endl;
    }
}


//Award Functions

void Award::generateAwards(vector<Athlete>athletes){ //generationg awards
    
    sort(athletes.begin(), athletes.end());
    int size = athletes.size() -1;
    
    if(athletes[size].getPoints() > athletes[size -1].getPoints() && athletes[size-1].getPoints() > athletes[size-2].getPoints()){
        
        Award a1;
        a1.athleteName = athletes[size].getName();
        a1.awardLevel = "Gold Medal";
        cout << "Congrats " << athletes[size].getName()<< "! you have won this meets " << a1.awardLevel << endl;
        
        Award a2;
        a2.athleteName = athletes[size-1].getName();
        a2.awardLevel = "Silver Medal";
        cout << "Congrats " << athletes[size-1].getName()<< "! you have won this meets " << a2.awardLevel << endl;
        
        Award a3;
        a3.athleteName = athletes[size-2].getName();
        a3.awardLevel = "Bronze Medal";
        cout << "Congrats " << athletes[size-2].getName()<< "! you have won this meets " << a3.awardLevel << endl;
        
        awards.push_back(a1);
        awards.push_back(a2);
        awards.push_back(a3);
    }
    
    else if (athletes[size].getPoints() == athletes[size-1].getPoints() && athletes[size-1].getPoints() > athletes[size-2].getPoints()){
        
        Award a1;
        a1.athleteName = athletes[size].getName();
        a1.awardLevel = "Gold Medal";
        cout << "Congrats " << athletes[size].getName()<< "! you have won this meets " << a1.awardLevel << endl;
        
        Award a2;
        a2.athleteName = athletes[size-1].getName();
        a2.awardLevel = "Gold Medal";
        cout << "Congrats " << athletes[size-1].getName()<< "! you have also won this meets " << a2.awardLevel << endl;
        
        Award a3;
        a3.athleteName = athletes[size-2].getName();
        a3.awardLevel = "Bronze Medal";
        cout << "Congrats " << athletes[size-2].getName()<< "! you have won this meets " << a3.awardLevel << endl;
        
        awards.push_back(a1);
        awards.push_back(a2);
        awards.push_back(a3);
    }
    
    else if (athletes[size].getPoints() > athletes[size-1].getPoints() && athletes[size-1].getPoints() == athletes[size-2].getPoints()){
        
        Award a1;
        a1.athleteName = athletes[size].getName();
        a1.awardLevel = "Gold Medal";
        cout << "Congrats " << athletes[size].getName()<< "! you have won this meets " << a1.awardLevel << endl;
        
        Award a2;
        a2.athleteName = athletes[size-1].getName();
        a2.awardLevel = "Silver Medal";
        cout << "Congrats " << athletes[size-1].getName()<< "! you have won this meets " << a2.awardLevel << endl;
        
        Award a3;
        a3.athleteName = athletes[size-2].getName();
        a3.awardLevel = "Silver Medal";
        cout << "Congrats " << athletes[size-2].getName()<< "! you have also won this meets " << a3.awardLevel << endl;
        
        awards.push_back(a1);
        awards.push_back(a2);
        awards.push_back(a3);
    }
    else {
        
        Award a1;
        a1.athleteName = athletes[size].getName();
        a1.awardLevel = "Gold Medal";
        cout << "Congrats " << athletes[size].getName()<< "! you have won this meets " << a1.awardLevel << endl;
        
        Award a2;
        a2.athleteName = athletes[size-1].getName();
        a2.awardLevel = "Gold Medal";
        cout << "Congrats " << athletes[size-1].getName()<< "! you have also won this meets " << a2.awardLevel << endl;
        
        Award a3;
        a3.athleteName = athletes[size-2].getName();
        a3.awardLevel = "Gold Medal";
        cout << "Congrats " << athletes[size-2].getName()<< "! you have also won this meets " << a3.awardLevel << endl;
        
        awards.push_back(a1);
        awards.push_back(a2);
        awards.push_back(a3);
    }
    cout << endl;
    int index = athletes.size() - 1;
    for (int i = index; i > 0; i--) {
        cout << athletes[i].getName() << " Total Points: " << athletes[i].getPoints() << endl;
    }
    cout << endl;
}

void Award::generateSeasonTrophy(vector<Athlete>athletes){ //generating season trophy
    
    vector<Result>results;
    string femaleName = "";
    string maleName = "";
    int totalMalePoints = 0;
    int totalFemalePoints = 0;


    for(int i = 0; i < athletes.size(); i++){
        if (athletes[i].getGender() == "Male") {
            if (athletes[i].getPoints() > totalMalePoints){
                totalMalePoints = athletes[i].getPoints();
                maleName = athletes[i].getName();
            }
            
        } else {
            
            if (athletes[i].getPoints() > totalFemalePoints){
                
                totalFemalePoints = athletes[i].getPoints();
                femaleName = athletes[i].getName();
            }
        }
    }

    cout << "The male season winner is " << maleName << "! Congratulations. you have been awarded a trophy" << endl;
    
    cout << "The female season winner is " << femaleName << "! Congratulations. you have been awarded a trophy" << endl;
    
}

//Results

string Result::getName(){ //gets and sets
    return name;
}

float Result::getPoints(){
    return result;
}

//Physiotherapist Functions
Physiotherapist::Physiotherapist(string pName, int id, int pAbility){ //constructor
    name = pName;
    teamId = id;
    ability = pAbility;
}


int Physiotherapist::generatePhysiotherapy(vector<Athlete>athletes, int ability){ //generating abilty
    int physicalTemp = 0;
    for (int i = 0; i < athletes.size(); i++) {
        physicalTemp = athletes[i].getPhysicalLevel() + rand() % ability * 0.5 + 1;
    }
    return physicalTemp;
}

//Psychologist Functions

Psychologist::Psychologist(string pName, int id, int pAbility){
    name = pName;
    teamId = id;
    ability = pAbility;
}

int Psychologist::generatePsychology(vector<Athlete>athletes, int ability){
    int healthTemp = 0;
    for (int i = 0; i < athletes.size(); i++) {
        healthTemp = athletes[i].getHealthLevel() + rand() % ability * 0.5 + 1;
    }
    return healthTemp;
}


