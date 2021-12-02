//
// Created by jshbs on 10/14/2021.
//

#include "Horse.h"
#include <ctime>
#include <iostream>
#include <random>

using namespace std;

//constructor
Horse::Horse(string newname, string newrider)
{

    name = newname;
    rider = newrider;
    distanceTraveled = 0;




}








void Horse::setDistanceTraveled(int distTrav)
{
    distanceTraveled = distTrav;

}

void Horse::setRacesWon(int wonRaces)
{
    racesWon += wonRaces;
}

void Horse::runASecond()
{


    distanceTraveled += (rand() % maxRunningDistPerSecond);
}

void Horse::sendToGate()
{
    distanceTraveled = 0;
    hasFinnished = false;
}

void Horse::displayHorse(int goalLength)
{

    // i dont know how to scale goalLength
    if (goalLength >= 91)
    {
        goalLength = 90;
    }

    maxRunningDistPerSecond = (rand() % goalLength) + 1;

    string horseDisplay = "";

    horseDisplay.push_back('|');

    for (int i = 0; i < distanceTraveled; ++i) {
        horseDisplay.push_back(' ');
    }

    horseDisplay.push_back('>');


    for (int i = distanceTraveled; i < goalLength; ++i)
    {
        horseDisplay.push_back(' ');
    }


    if (distanceTraveled < goalLength) {
        cout << horseDisplay << "| " << name << ", ridden by " << rider << endl;
    } else{
        //distanceTraveled = goalLength;
        hasFinnished = true;
        string winningDisplay = "";

        winningDisplay.push_back('|');

        for (int i = 0; i <= goalLength; ++i) {
            winningDisplay.push_back(' ');
        }

        cout << winningDisplay << "|> " << name << ", ridden by " << rider <<endl;

    }


}


