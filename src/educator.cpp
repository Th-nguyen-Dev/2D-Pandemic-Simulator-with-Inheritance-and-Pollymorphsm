//Chuong Dang, Hung Nguyen
//Edmonds College
//Project 7
///////////////////////////////////////////////////////////////////////////////////////////////

//Author: Hung Nguyen 

//This class creates the educator type.
//When they meeting other people
//They will educate others so they will less likely to get infected.
#include "educator.h" 
//The instructor gets integers of age, health, resistance, and infectious value;
  educator::educator(int age, int health, int resistance,int infectious){
    humanSetting::setAge(age);
    humanSetting::setHealth(health);
    humanSetting::setEducaton(5);
    humanSetting::setInfectious(infectious);
    humanSetting::setResistance(resistance);
    humanBase::setInfected(false);
  }
//This function returns moving direction of the human.
int  educator::getMove(){
  int ran = rand()%4+1;
  return ran;
}
//This function educate someone of methods of sanitizations so they will be less
//affected when a person is in contact with someone infected
void  educator::educate(humanBase* human){
    ((humanSetting*) human)->setEducaton(5);
}
//This function returns the educator type of the human
string  educator::getType(){
    return "educator";
}
//This function returns the string representation of the doctor type.
string  educator::toString(){
  //If they are infected it will be a red book 
    if (humanBase::getInfected()){
    return "\U0001F4D9";
    }
    //If they are immue it will be a blue book
    else if (humanBase::getImmue()){
        return "\U0001F4D8";
    }
    //else they will be a green book
    else {return "\U0001F4D7";}
}