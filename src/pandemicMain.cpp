#include <iostream>
#include <string>
#include "worldModel.h"
#include "GUI.h"

using namespace std;

void greeting(){
    cout << "Welcome to the game-of-death." << endl;
    cout << "This game simulates the spread of a new virus." << endl;
    cout << "If one normal person gets infected, " << endl;
    cout << "they must encouter a doctor to get cure or they will die." << endl;
    cout << "If they encouter an educator, they will become educated," << endl;
    cout << "and having less chances if getting infected" << endl;
    cout << "Note:" << endl;
    cout << "*A doctor is represented a medical gear." << endl;
    cout << "*The normal people are represented by various variations of faces" << endl;
    cout << "*An educator is represented by a various variations of books" << endl;
}
void inputLimit(int& input, int limitLow, int limitHigh){
     cin >> input;
     while (input<limitLow || input>limitHigh){
         cout << "Input out of bound, please enter again: ";
         cin >> input;
    }
}
void input(int& time, int& people, int& width,int& rateInfect,int& rateDeath, int& infected){
    cout << "Please input the grid size (maximum 1020 pixels): ";
    inputLimit(width,0,1020);
    cout << "Please enter the timeframe (maximum 1000 ms): ";
    inputLimit(time,0,1000);
    cout << "Please enter the number of people (maximum "<< width*width / 400<<" people): ";
    inputLimit(people,0,width*width /400);
    cout << "Please enter the number of infected people (maximum "<< width*width / 400<<" people): ";
    inputLimit(infected,0,width*width / 400);
    cout << "Please enter the disease level of infectiousness"<<endl;
    cout << "Any number over 5 may lead to mass infection: ";
    inputLimit(rateInfect,0,100);
    cout << "Pleaser enter the disease level of deadliness"<<endl;
    cout << "Any number over 5 may lead to mass instinction: ";
    inputLimit(rateDeath,0,100);

}

void main(){
    int people;
    int width;
    int time;
    int rateInfect;
    int rateDeath;
    int infected;
    greeting();
    input(time, people, width, rateInfect, rateDeath, infected);
    worldModel* model = new worldModel(people,width/20,width/20,rateInfect,rateDeath, infected);
    Gui* display = new Gui(width, width, model, time);
    string wait;
    cin >> wait;
    cout<< model->returnNumberHuman();
}