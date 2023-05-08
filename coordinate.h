
#ifndef COORDINATE_H
#define COORDINATE_H




class Coordinate
{
public:
    Coordinate();
    Coordinate(int _x, int _y);
    ~Coordinate();
    Coordinate operator+(Coordinate a);
    Coordinate operator-(Coordinate a);
    Coordinate operator+=(Coordinate a);
    Coordinate operator-=(Coordinate a);
    void Moveup(double y);
    void Moveright(double x);
    double getX();
    double getY();

private:
    double x;
    double y;
};

#endif // COORDINATE_H
