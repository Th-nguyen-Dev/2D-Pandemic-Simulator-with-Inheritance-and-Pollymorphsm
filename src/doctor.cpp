//Chuong Dang, Hung Nguyen
//Project 7
///////////////////////////////////////////////////////////////////////////////////////////////
#include "doctor.h"
//This instructor accepts integers of age, health, and infectious value;
doctor::doctor(int age, int health, int infectious){
    humanBase::setInfected(false);
    humanSetting::setAge(age);
    humanSetting::setHealth(health);
    humanSetting::setInfectious(infectious);
    //A doctor default education is 5 and resisrance is 5 
    //Because they will always be on their guard
    humanSetting::setEducaton(5);
    humanSetting::setResistance(5);
    
} 
//This function returns moving direction of the human.
int doctor::getMove(){
    int ran = rand()%4+1;
    return ran;
}
//This function cures a person if they are infected
void doctor::cure(humanBase* human){
    if (human->getInfected()){
        //That person will be immue afterward
        human->setImmue(true);
    }
}
//This function returns the type of the humam
string doctor::getType(){
    return "doctor";
}
//This function returns the string representation of the doctor type.
string doctor::toString(){
    return "\U0001FA7A";
}