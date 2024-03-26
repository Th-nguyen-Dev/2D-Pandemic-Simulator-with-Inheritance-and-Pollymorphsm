//Chuong Dang, Hung Nguyen
//Edmonds College
//Project 7
///////////////////////////////////////////////////////////////////////////////////////////////

//Author: Hung Nguyen 

//This class represent the normal people
//They will die after getting infected and not getting cured
//and becomes immue after getting cured by the doctor
//They can get less likely to get infected if being eduacted.
#include "humanSetting.h"
#include <random>
#ifndef _normal_h
#define _normal_h
class normal : public humanSetting{
public:
    //The normal type accepts the integers of age, education and infectious status.
    normal(int age, int health, 
    int resistance, int infectious,int education);
    //This fucntion returns the type of the human class
    virtual string getType();
    //This return an integer indicating the next move direction
    virtual int getMove();
    //This function returns the string representation.
    virtual string toString();
};
#endif