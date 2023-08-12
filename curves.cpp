#include "curves.h"

Circle::Circle() = default;
Circle::Circle(double _r) : center( Point(0, 0, 0) ), r(_r) {
    if (r < 0) r = 0;
}
Circle::Circle(Point _c, double _r) : center(_c), r(_r) {
    if (r < 0) r = 0;
}
Point Circle::getPoint(double t) const {
    double x = center.getX() + r * std::cos(t);
    double y = center.getX() + r * std::sin(t);
    double z = center.getZ();
    return Point(x, y, z);
}
v3d Circle::getVector(double t) const {
    double x = -(r * std::sin(t));
    double y = r * std::cos(t);
    double z = center.getZ();
    return v3d(x, y, z);
}
int Circle::getType() const {
    return 1;
}
double Circle::getRadius() const {
    return r;
}
Circle::~Circle() = default;


Ellipse::Ellipse() = default;
Ellipse::Ellipse(double _ra, double _rb) :  center(Point(0, 0, 0)), ra(_ra), rb(_rb) {
    if (ra < 0) ra = 0;
    if (rb < 0) rb = 0;
}
Point Ellipse::getPoint(double t) const{
    double x = center.getX() + ra * std::cos(t);
    double y = center.getX() + rb * std::sin(t);
    double z = center.getZ();
    return Point(x, y, z);
}
v3d Ellipse::getVector(double t) const {
    double x = -(ra * std::sin(t));
    double y = rb * std::cos(t);
    double z = center.getZ();
    return v3d(x, y, z);
}
int Ellipse::getType() const {
    return 2;
}

Helix::Helix() = default;
Helix::Helix(double _r, double _h) : center(Point(0, 0, 0)), r(_r), h(_h){
    if (r < 0) r = 0;
    if (h < 0) h = 0;
}
Point Helix::getPoint(double t) const{
    double x = center.getX() + r * std::cos(t);
    double y = center.getY() + r * std::sin(t);
    double z = center.getZ() + h * t;
    return Point(x, y, z);
}
v3d Helix::getVector(double t) const {
    double x = -(r * std::sin(t));
    double y = r * std::cos(t);
    double z = h;
    return v3d(x, y, z);
}
int Helix::getType() const {
    return 3;
}