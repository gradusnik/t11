
#include <iostream>
#include "points.h"

Point::Point() : x(0), y(0), z(0) {}

Point::Point(double _x, double _y, double _z) : x(_x), y(_y), z(_z) { }

double Point::getX() const {
    return this->x;
}
double Point::getY() const {
    return this->y;
}
double Point::getZ() const {
    return this->z;
}
void Point::display() {
    std::cout << getX() << " _ " << getY() << " _ " << getZ() << std::endl;
}



Point::~Point() = default;

v3d::v3d(double _x, double _y, double _z = 0) : Point(double(), double(), double ())  {
    x = _x; y = _y; z = _z;
}
