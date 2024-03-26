//Chuong Dang, Hung Nguyen
//Edmonds College
//Project 7
///////////////////////////////////////////////////////////////////////////////////////////////

//Author: Hung Nguyen and Chuong Dang

//This is the worldModel class. 
//It manages the movement, animations, and the interactions between people on a 2D grid 
//The also ticks away and manage people status after generations. 
#include "worldModel.h"
//Constructor
worldModel::worldModel(int counts,int height,int width,int rateInfect, int rateDeath, int infected) : height(height), width(width){
    this->rateInfect = rateInfect;
    this->rateDeath = rateDeath;
    this->infected = infected;
    //Add new grid of null pinter
    world = newGrid();
    //Add number of humans
    addHuman(counts);
    //Add city
}


int worldModel::getHeight(){
    return world.size();
}
int worldModel::getWidth(){
    return world.size();
}
//Return a grid of null pointers
vector<vector<humanBase*>> worldModel::newGrid(){
    vector<vector<humanBase*>> result;
    for(int row = 0; row < height; row++){
        vector<humanBase*> humans;
        for (int col = 0; col < width; col++){
            humans.push_back(nullptr);
        }
        result.push_back(humans);
    }
    return result;
}

//Add a number of humans base on the counts
void worldModel::addHuman(const int& counts){
    //Get the number of infected people at the start 
    int infectCount = infected;

    //Generate coordiante until a empty coordinate is founded
    for (int times = 1; times <= counts; times++){
        int row = rand()%height;
        int col = rand()%width;
        while((world)[row][col] != nullptr){
            row = rand()%height;
            col = rand()%width;
        }
        //Generate their stat 
        int age = rand() % 1000+1;
        int health = rand()%90+10;
        int resistance = rand()%6;
        int infectious = rand()%6;
        int education = rand()%6;
        //If they are 20 and up and they have 5 resistance, they become a doctor
        if (age>=20 && resistance >= 5 ){
            world[row][col] = new doctor(age,health,infectious);
        }
         //If they are 20 and up and they have 5 education, they become an educator
        else if (age>=20 && education >= 5){
            world[row][col] = new educator(age,health,resistance,infectious);
        }
         //else they become normal people
        else{
            world[row][col] = new normal(age,health,resistance,infectious,education);
        }
        //Set these people to infected until the number of infected people has been achieved 
        if (infectCount >0){
            world[row][col]->setInfected(true);
            infectCount--;
        }
    }
    
}
//Tick a new generation for all human to check their status
void worldModel::tick(humanBase* human){
    //Get the age to age them every tick
    int age = ((humanSetting*)human)->getAge();
    ((humanSetting*)human)->setAge(age+1);
    //Get if the person is infected, closely decrease their health after time
    //If it's a doctor they will automatically become immue 
    if (human->getInfected()){
        int ran = rand() % rateDeath;
        int health = ((humanSetting*)human)->getHealth();
        ((humanSetting*)human)->setHealth(health-ran);
        if (human->getType() == "doctor"){
            human->setImmue(true);
        }
    }
}
//Calculate the rate of infection base on the human getting it and the human giving it 
void worldModel::rateChance(humanBase* human_get, humanBase* human_give){
    int resistance = ((humanSetting*)human_get)->getResistance();
    int educationGet = ((humanSetting*)human_get)->getEducation();
    int infectious = ((humanSetting*)human_get)->getInfectious();
    int educationGive = ((humanSetting*)human_get)->getEducation();
    int rate = (infectious  + rateInfect)*2 - (resistance + educationGet + educationGive);
    int ran = rand()%10+1;
    if (ran <rate){
        human_get->setInfected(true);
    }
    else {
    }
}
//Interractionz between human 1 and human 2 when they comes in contact 
void worldModel::interact(humanBase* human_1, humanBase* human_2){
    string human_1Type = human_1->getType();
    string human_2Type = human_2->getType();
    //They cure if they are a doctor
    if (human_1Type == "doctor" || human_2Type == "doctor"){
        if (human_1Type == "doctor"){
            ((doctor*)human_1)->cure(human_2);
        }
        else {((doctor*)human_2)->cure(human_1);}

    }
    //They educate if they are a doctor
    else if (human_1Type == "educator" || human_2Type == "educator"){
        if (human_1Type == "educator"){
            ((educator*)human_1)->educate(human_2);
        }
        else {((educator*)human_2)->educate(human_1);}
    }
    //Calculate the chance of infection
    if (human_1->getInfected()|| human_2->getInfected()){
        if (human_2->getInfected()){
            rateChance(human_1,human_2);
        }
        else {
            rateChance(human_2,human_1);
        }
    }

}
bool worldModel::checkNeighboor(int x, int y){
    return (world[x][y] != nullptr);
}
bool worldModel::checkNeighboor(int x, int y, vector<vector<humanBase*>> newWorld){
    return (newWorld[x][y] != nullptr);
}
void worldModel::move(int& x, int& y, int move, int col, int row){
    if (move == 4){ //west
        x = (col - 1 + width) % width;
        y = row;
    } else if (move == 2){ //east
        x = (col + 1) % width;
        y = row;
    } else if (move == 1){ //north
        y = (row - 1 + height) % height;
        x = col;
    } else if (move == 3){ //south
        y = (row + 1) % height;
        x = col;
    }
}

ostream& operator << (ostream& out, worldModel& world){
    for(int x = 0; x < world.getHeight(); x++){
        for( int y = 0; y < world.getWidth(); y++){
            out << world.stringRep(x,y);
        }
        out <<endl;
    }
    return out;
}
//Update the entire grind to a new grid
void worldModel::update(){
    vector<vector<humanBase*>> newWorld = newGrid();
    for(int row = 0; row < height; row++){
        for (int col = 0; col < width; col++){
            if (world[row][col] != nullptr){
                //If it's a wall they will be copied over
                if (world[row][col]->getType() == "wall"){
                    newWorld[row][col] = world[row][col];
                } else {
                    //Tick forward the entity
                    tick(world[row][col]);
                    humanBase* people = world[row][col];
                    //Update their death
                    if (!((humanSetting*)people)->getDeath()){
                        int getMove = people->getMove();
                        int x;
                        int y;
                        //Get their next coordinate
                        move(y, x, getMove, col, row);
                        //If they meet something they will interact with it 
                        //Except when it is a wall
                        if (checkNeighboor(x,y)){
                            if (world[x][y]->getType() != "wall"){
                                //interactions occurs
                                interact(world[row][col],world[x][y]);
                            }
                            //
                            newWorld[row][col] = people;
                        }
                        //check other entity on the tile in the new map
                        else if(checkNeighboor(x,y,newWorld)){
                            newWorld[row][col] = people;
                        }
                        else {
                            newWorld[x][y] = people; 
                        }
                    }
                }
            }
        }
    }
    world = newWorld;
}

const vector<vector<humanBase*>> worldModel::getGrid(){
    return world;
}
int worldModel::returnNumberHuman(){
    int count;
    for(int row = 0; row < getHeight(); row++){
        for (int col = 0; col < getWidth(); col++){
            if (world[row][col] != nullptr){
                count++;
            }
        }
}
return count;
}
string worldModel::stringRep(int x, int y){
    if (world[x][y] == nullptr) {
        return "-";
    }
    else {return world[x][y]->toString();}
}


