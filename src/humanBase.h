//Chuong Dang, Hung Nguyen
//Edmonds College
//Project 7
///////////////////////////////////////////////////////////////////////////////////////////////

//Author: Hung Nguyen 

//This is the parent human class
//This creates different types of human with
//different immue, gender, and etc.
#include <string>
#include <iostream>
using namespace std;
#ifndef _humanBase_h
#define _humanBase_h
class humanBase{
public:
    //empty instructor
    humanBase();
    //This function returns the type
    virtual string getType() = 0;
    //This function returns the to string representation
    virtual string toString() = 0;
    //This function set the infection status of the human type.
    virtual void setInfected(bool input);
    //This function set the immue status of the human type.
    virtual void setImmue(bool input);
    //This fuunction returns true if the human is infected.
    virtual bool getInfected();
    //This function returns the move direction
    virtual int getMove() = 0;
    //This function return true if immue.
    virtual bool getImmue();
private:
    bool infected;
    bool immue;
    int death;
};
#endif