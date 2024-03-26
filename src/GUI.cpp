
//Chuong Dang
//Edmonds College
//Project 6

///////////////////////////////////////////////////////////////////////////////////////////////
#include "GUI.h"

Gui::Gui(int width, int height, worldModel* model, int timeframe){
    guiGrid = model;
    window = new GWindow(width, height);
    window->setFont("Arial-15-bold");
    window->setBackground("black");
    window->setExitOnClose(true);
    window->setRepaintImmediately(false);
    window-> setLocation(300, 10);
    window->toFront();
    window->setVisible(true);
    window->toFront();
    window->setTimerListener(timeframe,[this]{
        this->draw();
    });
}


void Gui::draw(){
    window->clearCanvas();
    for(int x = 0; x< guiGrid->getHeight();x++){
        for (int y = 0; y<guiGrid->getWidth();y++){
            if (guiGrid->getGrid()[x][y] != nullptr){
                humanBase* people= guiGrid->getGrid()[x][y];
                string type = people->getType();
                if(type == "wall"){
                    window->setColor("purple");
                    window->fillRect(x*20, y*20, 20, 20);
                } 
                else {
                   window->drawString(people->toString(),x*20,y*20); 
                } 
        }
    }
    }
    window->repaint();
    guiGrid->update();
}
