#include <iostream>
#include <ctime>
#include <vector>
#include "Horse.h"

int getNumberOfHorses();

vector<Horse*> * getHorses(int , int*);

void race(vector<Horse*>*, int*);



bool checkForWinner(vector<Horse*>*);

void declareWinner(vector<Horse*>*);

using namespace std;

int main() {


    //will hold pointer to the vector holding all the horseys
    vector<Horse*> *horsesVectorPtr = nullptr;

    unsigned seed = time(0);
    srand(seed);

    char userChoice;
    int numOfHorses = 0;
    int trackLength = 0;

    //get the number of horses from the user
    numOfHorses = getNumberOfHorses();

    //get the horse names and rider names from user
    horsesVectorPtr = getHorses(numOfHorses, &trackLength);

    cout << "The start!"<<endl;
    do {


        //race until there is a winner
        while (!checkForWinner(horsesVectorPtr)) {
            race(horsesVectorPtr, &trackLength);

        }

        declareWinner(horsesVectorPtr);




        cout << "Do you wish to continue?: "<<endl;
        cin >> userChoice;

        if (tolower(userChoice) == 'y')
        {
            for (int i = 0; i < horsesVectorPtr->size(); ++i)
            {
                horsesVectorPtr->at(i)->sendToGate();
            }
        }

    } while (tolower(userChoice) == 'y');


    return 0;
}

void race(vector<Horse*> *horsesPointer, int* goalLength) {

    char userInput;

    //display all the horses and their positions
    for (int i = 0; i < horsesPointer->size(); ++i)
    {
        horsesPointer->at(i)->displayHorse(*goalLength);
    }

    //ask user if they want to continue, only accept y or n
    do {
        cout << "Are you ready for the next second?(y/n): "<<endl;
        cin >> userInput;
        userInput = tolower(userInput);
    } while (tolower(userInput) != 'y' && tolower(userInput) != 'n');

    //if they do want to continue have the horses move
    if (tolower(userInput) == 'y')
    {
        for (int i = 0; i < horsesPointer->size(); i++) {
            horsesPointer->at(i)->runASecond();
        }
    }
    else
    {
        exit(EXIT_SUCCESS);
    }





}




//get the rider and horse names also track distance from the user add them to vector
vector<Horse*>* getHorses(int numOfHorses, int *goalLength)
{

    vector<Horse*>* horsesPtr; // pointer to a vector of horse pointers

    horsesPtr = new vector<Horse*>;


    for (int i = 0; i < numOfHorses; ++i)
    {
        string horseName, riderName;
        cout << "Please give me the name of horse " << i+1 << ": "<<endl;
        cin >> horseName;
        cout << "Please give me the name of rider " << i+1 << ": "<<endl;
        cin >> riderName;


        horsesPtr->push_back(new Horse(horseName, riderName));


    }

    do {
        cout << "Please enter the distance of the race(>2): " << endl;
        cin >> *goalLength;
    } while (*goalLength < 2 );

    return horsesPtr;

}

//get the number of horses from the user
int getNumberOfHorses() {
    int numOfHorses = 0;

    do {

        cout << "How many horses are in the race: "<<endl;
        cin >> numOfHorses;

        if (numOfHorses < 0 || numOfHorses > 10)
        {
            cout << "Please enter a number between 1 and 10"<<endl;
        }

    } while (numOfHorses < 1 || numOfHorses > 10);
    return numOfHorses;
}

//this just sees if a horse has finished the race
bool checkForWinner(vector<Horse*> *horseVector)
{


    for (int i = 0; i < horseVector->size(); ++i)
    {
        if (horseVector->at(i)->getHasFinnished())
        {
            return true;
        }
    }

    return false;
}

//checks which horse is the winner
void declareWinner(vector<Horse*> *horseVector)
{
    //raceFinishers list incase more than one horse finishes at once
    vector<Horse*> raceFinishers;
    Horse * winner = nullptr;

    //gets which horses has finished the race and adds them to vector
    for (int i = 0; i < horseVector->size(); ++i)
    {
        if (horseVector->at(i)->getHasFinnished())
        {
            raceFinishers.push_back(horseVector->at(i));
        }
    }

    //if there is only one horse that has finished then it won
    if (raceFinishers.size() == 1)
    {
        winner = raceFinishers.at(0);

    }
    else  //more than one horse finished break tie by distance traveled
    {
        vector<Horse*> tiedHorses;          //this will hold horses with same highest distance traveled


        winner = raceFinishers.at(0);   //start with the first horse
        for (int i = 0; i < raceFinishers.size(); ++i)
        {

            if (winner->getDistanceTraveled() < raceFinishers.at(i)->getDistanceTraveled())
            {
                winner = raceFinishers.at(i);
            }

        }

        //check if there are any horses with same distance traveled as the winner put them in a tied vector
        tiedHorses.push_back(winner);
        for (int i = 0; i < raceFinishers.size(); ++i)
        {

            if (winner->getDistanceTraveled() == raceFinishers.at(i)->getDistanceTraveled()
                && winner->getName() != raceFinishers.at(i)->getName())
            {
                tiedHorses.push_back(raceFinishers.at(i));
            }
        }

        //there are horses with same distance traveled as winner pick a random winner
        if (tiedHorses.size() > 1)
        {
            int randomIndex = (rand() % tiedHorses.size());
            winner = tiedHorses.at(randomIndex);

        }



    }

    if (winner != nullptr)
        winner->setRacesWon(1);

    for (int i = 0; i < horseVector->size(); ++i)
    {
        cout<< horseVector->at(i)->getName() << " has won " << horseVector->at(i)->getRacesWon() << " races."<<endl;
    }


}


