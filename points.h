#pragma once
#include <cmath>

class Point {
protected:
    double x;
    double y;
    double z;
public:
    Point();
    Point(double, double, double);
    virtual double getX() const;
    virtual double getY() const;
    virtual double getZ() const;
    virtual void display();
    virtual ~Point();
};

class v3d : public Point{
public:
    v3d(double , double , double);
};