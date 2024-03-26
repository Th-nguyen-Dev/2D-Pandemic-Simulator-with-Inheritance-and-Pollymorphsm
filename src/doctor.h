//Chuong Dang
//Edmonds College
//Project 7
///////////////////////////////////////////////////////////////////////////////////////////////
//This class creates a doctor type
//when the doctor type encouters other human type,
//if the human is infected with virus, they will get cure and becomes immune.
#include "humanSetting.h"
#include "humanBase.h"
#ifndef _doctor_h
#define _doctor_h
class doctor: public humanSetting{
public:
    //This instructor accepts integers of age, health, and infectious value;
    doctor(int age, int health, int infectious);
    //This function returns moving direction of the human.
    virtual int getMove();
    //This function cures a person if they are infected
    void cure(humanBase* human);
    //This function returns the type of the humam
    virtual string getType();
    //This function returns the string representation of the doctor type.
    virtual string toString();
};
#endif