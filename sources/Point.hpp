#pragma once

#include <string>
#include <iostream>

using namespace std;

class Point{
    double xval;
    double yval;

public:
    Point(double xval, double yval);//constructor who gets 2 coordinates
    double distance(const Point& other)const;//calculate the distance between 2 points
    double getxval();
    double getyval();
    string print() const;
    static const Point moveTowards(const Point& src,const Point& des,double dis);
};
