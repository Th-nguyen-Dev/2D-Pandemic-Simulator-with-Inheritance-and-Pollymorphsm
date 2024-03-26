//Chuong Dang
//Edmonds College
//Project 7
///////////////////////////////////////////////////////////////////////////////////////////////
//This city class creates cities in form of squares
//The class inputs a number of city,
//and the many cities will be generated on the gui,
//at random spots and with random sizes;
#ifndef _CITY_H
#define _CITY_H

#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;

class city{
public:
    //The instructor the accepts a number of cities.
    //Generates the cities at random spot and sizes
    //Then it stores these values into different vectors.
    city(int cities);

    //This returns the vector of x-coordnates
    vector<int> x();

    //This returns the vector of y-coordnates
    vector<int> y();

    //This returns the vector of the open direction
    vector<int> move();

    //This returns the vector of sizes
    vector<int> getSize();
private:
    //This vector stores the x_coordnates
    vector<int> x_c;
    //This vector stores the y_coordnates
    vector<int> y_c;
    //This vector stores the size
    vector<int> size;
    //This vector stores the open direction
    vector<int> direction;
};

#endif