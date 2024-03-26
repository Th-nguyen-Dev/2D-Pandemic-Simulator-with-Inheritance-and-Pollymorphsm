
//Chuong Dang, Hung Nguyen
//Edmonds College
//Project 7
///////////////////////////////////////////////////////////////////////////////////////////////

//Author: Hung Nguyen and Chuong Dang

//This is the GUI class. 
//It brings the represeentations of the world grid and animate them
#ifndef _GUI_H
#define _GUI_H

#include "Gwindow.h"
#include "humanBase.h"
#include "worldModel.h"
#include <string>
#include <iostream>
using namespace std;
using namespace sgl;

class Gui{
public:
    //Costrcutor with its dimenesion, its worldMdoel, and its time per tick
    Gui(int width, int height, worldModel* model, int timeframe);
    //Update the GUI to animate them
    void draw();
    //void newCity(int x, int y, int size, int gate);
    
private:
    GWindow* window;
    worldModel* guiGrid;
};
#endif