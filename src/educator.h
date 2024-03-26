//Chuong Dang
//Edmonds College
//Project 7
///////////////////////////////////////////////////////////////////////////////////////////////

//Author: Hung Nguyen 

//This class creates the educator type.
//When they meeting other people
//They will educate others so they will less likely to get infected.
#include "humanSetting.h"
#ifndef _educator_h
#define _educator_h
class educator: public humanSetting{
public:
    //The instructor gets integers of age, health, resistance, and infectious value;
    educator(int age, int health, int resistance,int infectious);
    //This function returns moving direction of the human.
    virtual int getMove();
    //This function educate someone of methods of sanitizations so they will be less
    //affected when a person is in contact with someone infected
    void educate(humanBase* human);
    //This function returns the educator type of the human
    virtual string getType();
    //This function returns the string representation of the doctor type.
    virtual string toString();
};
#endif