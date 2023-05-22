#pragma once

#include <string>
#include <iostream>

class Point{
    double xval;
    double yval;

public:
    Point(double xval, double yval);//constructor who gets 2 coordinates
    double distance(const Point& other);//calculate the distance between 2 points
    void print();
    static Point moveTowards(Point src, Point des, double dis);
};
