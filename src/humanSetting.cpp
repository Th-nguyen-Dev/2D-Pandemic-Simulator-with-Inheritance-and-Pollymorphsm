//Chuong Dang, Hung Nguyen
//Edmonds College
//Project 7
///////////////////////////////////////////////////////////////////////////////////////////////

//Author: Hung Nguyen 

//This is the sub class of the humanBase class
//it adds more specific functions storing what's the person health, age, infectiousness, and resistance
//Overall, it still responsibles for inputing the health and infection values of each human.
#include "humanSetting.h"
//empty instructor.
humanSetting::humanSetting(){}
//Return the type of the human.
string humanSetting::getType(){
    return "default";
}
//This function set the age of the people.
void humanSetting::setAge(int input){
    age = input;
}
//This function set the heatlth status of the human type.
void humanSetting::setHealth(int input){
    health = input;
}
//Returns true if the human is dealth
bool humanSetting::getDeath(){
    //if age increse 1000 or health decrease to 0, a person passes away
    if (age >= 1000 || health <= 0){
        return true;
    }
    else {return false;}
}
//This function returns the health status of the humam.
int humanSetting::getHealth(){
    return health;
}
//This fucntion returns the age
int humanSetting::getAge(){
    return age; 
}
////This function returns the move direction
int humanSetting::getMove(){
    return 0;
}
//This function returns string representaion of the human type.
string humanSetting::toString(){
    return "B";
}
//This function sets a person's base chance
//of infecting something to someone
void humanSetting::setInfectious(int input){
    infectious = input;
    if(infectious>5){infectious = 5;}
}
//This function returns a number of a person's base chance
//of infecting something to someone
int humanSetting::getInfectious(){
    return infectious;
}
//This function set the resistance status to the virus of the human type.
void humanSetting::setResistance(int input){
    resistance = input;
    if (resistance >5){resistance = 5;}
}
int humanSetting::getResistance(){
    return resistance;
}
//This function set the education status of the human.
void humanSetting::setEducaton(int input){
    education = input;
    if(education>5){education  = 5;}
}
//This function returns the eduaction level.
int humanSetting::getEducation(){
    return education;
}