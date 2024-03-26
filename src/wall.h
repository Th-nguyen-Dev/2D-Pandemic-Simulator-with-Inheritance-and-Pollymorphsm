//Chuong Dang, Hung Nguyen
//Edmonds College
//Project 7
///////////////////////////////////////////////////////////////////////////////////////////////
//This is the wall type.
//It does not move but wont allow other human types to cross.
#ifndef _WALL_H
#define _WALL_H
#include <iostream>
#include "humanSetting.h"
using namespace std;
class wall : public humanSetting {
public:
    //Empty instructor
    wall();
    //This function returns the type of the human
    virtual string getType();
    //This function returns the to string representation
    virtual string toString();
    //This returns the 0 as a moving direction
    virtual int getMove();
};
#endif