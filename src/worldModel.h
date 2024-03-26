//Chuong Dang, Hung Nguyen
//Edmonds College
//Project 7
///////////////////////////////////////////////////////////////////////////////////////////////

//Author: Hung Nguyen and Chuong Dang

//This is the worldModel class. 
//It manages the movement, animations, and the interactions between people on a 2D grid 
//The also ticks away and manage people status after generations. 
#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <ctime>
#include <cstdlib>
#include "normal.h"
#include "doctor.h"
#include "educator.h"
#include "wall.h"
#include "humanBase.h"
#include "humanSetting.h"
#ifndef _worldModel_h
#define _worldModel_h
using namespace std;
//Class WorldModel 
class worldModel{ 
    //Find the next tile coordinate according to the direction given by a human AI
    void move(int& x, int& y, int move, int col, int row);
    //Check neighboor at x and y coordinate
    bool checkNeighboor(int x, int y);
    //Check neighboor at x and y coordinate in the new world
    bool checkNeighboor(int x, int y, vector<vector<humanBase*>> newWorld);
    //Interactions between humans when they touch each other based on their role
    void interact(humanBase* human_1, humanBase* human_2);
    //Calculate the chance of a person infection when in contact with another person
    void rateChance(humanBase* human_get, humanBase* human_give);
    //Tick a new generation for all human to check their status
    void tick(humanBase* human);
    //Add a number of humans base on the counts
    void addHuman(const int& counts); 
    //A vector of vector representing a world grid containing humanBase pollymorphisms to each role 
    vector<vector<humanBase*>> world;
    //count of humans
    int counts;
    //dimensions
    int height;
    int width;
    //Rate of infection by a disease
    int rateInfect;
    //Rate of death by a disease 
    int rateDeath;
    //Number of beginning infected people
    int infected;
    public:
    //Return the number of human remaining at the end of the program
    int returnNumberHuman();
    //Add wall to represent city 
    void addWall();
    //Get the entire grid
    const vector<vector<humanBase*>> getGrid();
    //Constructor with counts of human, dimension, rate of infection, rate of death, and beginning number of infected people 
    worldModel(int counts,int height,int width,int rateInfect, int rateDeath, int infected);
    //Get dimensions
    int getHeight();
    int getWidth();
    //Construct a new grid of empty pouiters
    vector<vector<humanBase*>> newGrid();
    //Update the entire grind to a new grid
    void update();
    //Get the string representation of a memeber in the grid
    string stringRep(int x, int y);
};
//Out put the entire grid onto the console
ostream& operator <<(ostream& out, worldModel& world);
#endif