#pragma once

#include <iterator>
#include "points.h"

class Circle {
    Point const center;
    double r = 0;
public:
    Circle();
    Circle(Point _c, double _r);
    Circle  (double  _r);
    virtual Point getPoint (double t) const;
    virtual v3d getVector (double t) const;
    virtual int getType() const;
    virtual double getRadius() const;
    virtual ~Circle();
};

class Ellipse: public Circle{
    Point  const center;
    double ra = 0;
    double rb = 0;
public:
    Ellipse();
    Ellipse(double, double);
    Point getPoint(double) const override;
    v3d getVector(double) const override;
    int getType() const override;
};

class Helix: public Circle {
    Point const center;
    double r;
    double h;
public:
    Helix();
    Helix(double , double);
    Point getPoint(double ) const override;
    v3d getVector(double) const override;
    int getType() const override;
};
