//Chuong Dang, Hung Nguyen
//Project 7
///////////////////////////////////////////////////////////////////////////////////////////////

#include "city.h"
#include <iostream>
#include <vector>

city::city(int cities){
    srand(time(0));
    for (int i = 1; i <= cities; i++){
        int x = rand() % 1500; 
        int y = rand() % 600;
        int width = rand() % 200 + 50;
        int move =  rand() % 4 + 1;
        x_c.push_back(x);
        y_c.push_back(y);
        size.push_back(width);
        direction.push_back(move);
    }
}

vector<int> city::x(){
    return x_c;
}

vector<int> city::y(){
    return y_c;
}

vector<int> city::move(){
    return direction;
}

vector<int> city::getSize(){
    return size;
}
