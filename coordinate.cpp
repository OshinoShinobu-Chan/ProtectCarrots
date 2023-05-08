
#include "coordinate.h"

Coordinate::Coordinate() : x(0), y(0){}

Coordinate::Coordinate(int _x, int _y) : x(_x), y(_y){}

Coordinate::~Coordinate(){}

Coordinate Coordinate::operator+(Coordinate a){
    Coordinate *result = new Coordinate(this -> x + a.x, this -> y + a.y);
    return *result;
}

Coordinate Coordinate::operator-(Coordinate a){
    Coordinate *result = new Coordinate(this -> x - a.x, this -> y - a.y);
    return *result;
}

Coordinate Coordinate::operator+=(Coordinate a){
    this -> x += a.x;
    this -> y += a.y;
    return *this;
}

Coordinate Coordinate::operator-=(Coordinate a){
    this -> x -= a.x;
    this -> y -= a.y;
    return *this;
}

void Coordinate::Moveup(double y){
    this -> y += y;
}

void Coordinate::Moveright(double x){
    this -> x += x;
}

double Coordinate::getX(){
    return this -> x;
}

double Coordinate::getY(){
    return this -> y;
}

