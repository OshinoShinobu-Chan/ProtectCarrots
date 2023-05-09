
#include "tower.h"

Tower::Tower(int _type) : type(_type){}

Tower::~Tower(){}

int Tower::getLevel(){
    return level;
}

void Tower::setLevel(int _level){
    level = _level;
}

int Tower::getType(){
    return type;
}

void Tower::setTpye(int _type){
    type = _type;
}

double Tower::getHurt(){
    return hurt;
}

void Tower::setHurt(double _hurt){
    hurt = _hurt;
}

double Tower::getFreq(){
    return freq;
}

void Tower::setFreq(double _freq){
    freq = _freq;
}

int Tower::getTargetNum(){
    return targetNum;
}

void Tower::getTarget(Coordinate* dest){
    for(int i = 0; i < targetNum; i++){
        dest[i] = targets[i];
    }
    return;
}
