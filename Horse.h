//
// Created by jshbs on 10/14/2021.
//

#ifndef PROJECT3_HORSE_H
#define PROJECT3_HORSE_H

#include <string>

using namespace std;

class Horse
{
    private:
        string name;
        string rider;
        int maxRunningDistPerSecond;
        int distanceTraveled;
        int racesWon = 0;
        bool hasFinnished = false;

    public:

        Horse(string, string);

        string getName() const{return name;}
        string getRider() const{return rider;}
        bool getHasFinnished() const{return hasFinnished;}
        int getMaxRunningDistPerSecond() const{return maxRunningDistPerSecond;}
        int getDistanceTraveled() const {return distanceTraveled;}
        int getRacesWon() const {return racesWon;}


        void setDistanceTraveled(int);
        void setRacesWon(int);

        void runASecond();
        void sendToGate();
        void displayHorse(int);




};

#endif //PROJECT3_HORSE_H
