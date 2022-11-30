#define Header
#include <vector>
#include <string>
using namespace std;

class Athlete;
class Event;
class Track;
class Field;
class Location;
class Season;
class Weather;
class Award;
class Manager;
class SupportMember;
class Psychologist;
class Physiotherapist;
class SupportCrew;
class Trainer;
class Meet;

// Creating classes, structs, functions, and variables

class Team {
protected:
    string name;
    Manager* manager;
    SupportCrew* supportCrew;
public:
    Team(string, Athlete, Athlete, Manager, SupportCrew);
    vector<Athlete>athletes;
    vector<SupportCrew>supportCrews;
    vector<Manager>managers;
    Athlete getAthlete(int);

    
};

struct Result{
    string name;
    float result;
    
    bool operator<(const Result &a) const //defining sort
    {
        return result < a.result;
    }
    string getName();
    float getPoints();
};

class Athlete {
protected:
    string name;
    string gender;
    int points;
    int healthLevel;
    bool isInjured;
    int physicalLevel;
    int consistancyLevel;
    int strength;
    int speed;
    int teamId;
    
public:
    Athlete(string, string, int, int, bool, float, int, int, int, int);
    vector<string>maleNames{"Tom", "Jared", "Lachlan", "Mike", "James", "Keanu", "Nik", "Harro"};
    vector<string>femaleNames{"Lili", "Cassandra", "Teneal", "Elli", "Bethany", "Claudia", "Amelia", "Taylah"};
    void generateAthletes();
    void setData(int);
    int randomNumbGen(int, int);
    int randomNormalDistribution(int, int);
    string getName();
    int getHealthLevel();
    void setHealthLevel(int);
    float getPhysicalLevel();
    void setPhysicalLevel(float);
    int getConsistancyLevel();
    void setConsistancyLevel(int);
    int getPoints();
    void setPoints(int);
    string getGender();
    float randomFloatGen(float,float);
    bool getIsInjured();
    void setIsInjured(bool);
    float calcTrackPerformanceLevel();
    float calcFieldPerformanceLevel();
    int getSpeed();
    void setSpeed(int);
    int getStrength();
    void setStrength(int);
    int getTeamId();
    void setTeamId(int);
    
    bool operator<(const Athlete &a) const //defining sorts
    {
        return points < a.points;
    }
};

class Event {
protected:
    string name;
    int featureImpact;
    int weatherImpact;
public:
    int generateRandomResult(int, int);
    void setLocationImpact(int);
    int getFeatureImpact();
    string getName();
    vector<Result>results;
};

class Track : public Event {
protected:
    int metres;
    double timeTaken;
public:
    Track(string, int, int, int);
    void setName(string);
    void setMetres(int);
    void printTrackEventData();
    string getName();
    int getMetres();
    void generateTrackEvent(vector<Athlete>, int, string);
    
};

class Field : public Event {
    int distance;
public:
    Field(string, int, int, int);
    void setName(string);
    void setDistance(int);
    void printFieldEventData();
    string getName();
    int getDistance();
    void generateFieldEvent(vector<Athlete>, int, string);
    
};

class Location {
protected:
    string name;
    string feature;
    int id;
public:
    void generateLocation(int index);
    string getName();
    string getFeature();
    int generateLocationImpact();
    void setLocationsImpact(Location, vector<Event>);
    vector<string>locationName{"Wollongong","Dapto","Figtree","Bulli","Fairy Meadow","Liverpool","Corimal","Berry"};
    vector<string>specialFeatures{"100 Meter: Slopped", "Discus: Small Field", "Javlin: Downhill ", "110 Hurdles: Tall", "400 Meter: Sandy ", "Longjump: Gravel Pit", "HighJump: Bent Pole", "1500 Meter: Bumpy" };
    
};

class Season {
    
protected:
    
public:
    vector<Team>teams;
    vector<Athlete>athletes;
    vector<Trainer>trainers;
    vector<Psychologist>psychs;
    vector<Physiotherapist>physios;
    vector<Location>locations;
    vector<Event>events;
    void generateTeams(int);
    void awardTrackResults(vector<Result>, int, int, int, string);
    void awardFieldResults(vector<Result>, int, int, int, string);
    int returnAthleteIndex(string name);
    void generateSupportCrewImpact();
    void generateWear();
    float awardTrackPoints(float, float, float, float);
    float awardFieldPoints(float, float, float, float);
    void reportOnAthletes();
};

class Weather {
protected:
    int degrees;
    int windSpeed;
    bool isRaining;
    int impact;
public:
    void generateWeather();
    int randomGenerator(int, int);
    string weatherReport();
    int getDegrees();
    int getWindSpeed();
    bool getIsRaining();
    void setImpact(int);
    int getImpact();
    
};

class Award {
protected:
    string athleteName;
    string awardLevel;
    int awardScore;
public:
    void generateAwards(vector<Athlete>);
    vector<Award>awards;
    void generateSeasonTrophy(vector<Athlete>);
    
};

class Manager {
protected:
    string name;
public:
    void setName(string);
    string getName();
    vector<string>names{"Victor", "Darius", "Fiora", "Mundo", "Xin", "Kayne", "Dominik", "Robbeh"};
    
};

class SupportMember {
protected:
    string name;
    int teamId;
    int ability;
public:
    void setName(string);
    string getName();
    int getTeamId();
    void setTeamId(int);
    int getAbility();
    void setAbility(int);
    vector<string>names{"Sandra","Paul","Kelly","Margret","Pierre","Phill","Kerry","Alex","Tim","Tony","Rosa","Rebecca", "Daniela", "Mig", "Triggeh", "Loggeh" ,"Pud" ,"Karen"};
};

class Psychologist : public SupportMember {
protected:
public:
    Psychologist(string, int, int);
    int generatePsychology(vector<Athlete>, int);
    
};

class Physiotherapist : public SupportMember {
protected:
public:
    Physiotherapist(string, int, int);
    int generatePhysiotherapy(vector<Athlete>, int);
    
};

class SupportCrew {
protected:
    
public:
    SupportCrew(Physiotherapist, Psychologist, Trainer, Trainer); //if using field and track trainer classes change constructor
    Trainer getTrainer();
};

class Trainer {
protected:
    string name;
    string specialty;
    int teamId;
    int ability;
public:
    Trainer(string, string, int);
    void setName(string);
    string getName();
    string getSpecialty();
    vector<string>names{"Kyle", "Stephanie", "Andrew", "Krystal", "Carlo", "Lana", "Marco", "Riley", "Emily", "Annelise", "Grace" ,"Tammy" ,"Toneh" ,"Jayden" ,"Jack" ,"John"};
    int generateFieldTraining(vector<Athlete>, int);
    int generateTrackTraining(vector<Athlete>, int);
    int getTeamId();
    void setTeamId(int);
    int genAbility(vector<Trainer>trainers, vector<Athlete>, string, int);
    int getAbility();
    void setAbility(int);
};

class Meet{
protected:
public:
    void generateMeets(int meets, int teams, vector<Athlete>);
    void meetGap();
};


