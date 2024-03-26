//Chuong Dang, Hung Nguyen
//Edmonds College
//Project 7
/*
Author: Hung Nguyen 
This class is the base for all types of humans. 
The class is called humanBase. It stores the infected, immue status of the person
*/
///////////////////////////////////////////////////////////////////////////////////////////////
#include "humanBase.h"
humanBase::humanBase(){}
//Set infection status base on true or false 
void humanBase::setInfected(bool input){
    infected = input;
    //If the person is immue infection will always fail
    if (immue){infected = false;}
}
//Set immue status base on true or false 
void humanBase::setImmue(bool input){
    immue = input;
}
//Return the infection status
bool humanBase::getInfected(){
    return infected;
}
//Return the immue status
bool humanBase::getImmue(){
    return immue;
}