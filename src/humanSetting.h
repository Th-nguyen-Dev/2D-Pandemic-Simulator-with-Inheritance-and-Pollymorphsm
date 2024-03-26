//Chuong Dang, Hung Nguyen
//Edmonds College
//Project 7
///////////////////////////////////////////////////////////////////////////////////////////////

//Author: Hung Nguyen 

//This is the sub class of the humanBase class
//it adds more specific functions.
//Overall, it still responsibles for inputing the health and infection values of each human.
#include "humanBase.h"
#ifndef _humanSetting_h
#define _humanSetting_h
class humanSetting : public humanBase{
public:
    //empty instructor.
    humanSetting();
    //Return the type of the human.
    virtual string getType();
    //This function returns string representaion of the human type.
    virtual string toString();
    //This function set the age of the people.
    virtual void setAge(int input);
    //This function set the heatlth status of the human type.
    virtual void setHealth(int input);
    //This function set the education status of the human.
    virtual void setEducaton(int input);
    //This function sets a person's base chance
    //of infecting something to someone
    virtual void setInfectious(int input);
    //This function set the resistance status to the virus of the human type.
    virtual void setResistance(int input);
    //Returns true if the human is dealth
    virtual bool getDeath();
    //This function returns the health status of the humam.
    virtual int getHealth();
    //This function returns a number of a person's base chance
    //of infecting something to someone
    virtual int getInfectious();
    //This function returns a int from 1 to 5 
    //indicating the resistance to getting infected
    virtual int getResistance();
    //This fucntion returns the age
    virtual int getAge();
    ////This function returns the move direction
    virtual int getMove();
    //This function returns the eduaction level.
    virtual int getEducation();
private:
    int resistance;
    int infectious;
    int education;
    int health;
    int age;
};
#endif

