//Chuong Dang, Hung Nguyen
//Edmonds College
//Project 7
///////////////////////////////////////////////////////////////////////////////////////////////

//Author: Hung Nguyen 

//This class represent the normal people
//They will die after getting infected and not getting cured
//and becomes immue after getting cured by the doctor
//They can get less likely to get infected if being eduacted.
#include "normal.h"
//The normal type accepts the integers of age, education and infectious status.
normal::normal(int age, int health, 
            int resistance, int infectious,int education){
                humanSetting::setHealth(health);
                humanSetting::setInfectious(infectious);
                humanSetting::setEducaton(education);
                humanSetting::setResistance(resistance);
                humanBase::setInfected(false);
}
//This fucntion returns the type of the human class
string normal::getType(){
    return "normal";
}
//This return an integer indicating the next move direction
int normal::getMove(){
    int ran = rand()%4+1;
    return ran;
}
//This function returns the string representation.
string normal::toString(){
    //If they are infected they will be throwing up
    if (humanBase::getInfected()){
        return "\U0001F92E";
    }
    //If they are immue they will be laughing a wide smile
    else if (humanSetting::getImmue()){
        return "\U0001F606";
    }
    //If they are educated  (education > 3) they will wear a mask
    else if (humanSetting::getEducation()>=3){
        return "\U0001F637";
    }
    //else they will just be smiling lightly
    else {return "\U0001F642";}
}