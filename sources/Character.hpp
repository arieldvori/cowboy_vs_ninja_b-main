#pragma once

#include "Point.hpp"

using namespace std;

class Character {
  Point _location;
  string _name;
  int _hit_points;

public:
  Character(string name,  const Point &location, int hit_points);
  bool isAlive();
  double distance(Character &other);
  void hit(int damage);
  string getName();
  Point getLocation();
  void print();
  int gethitpoints();
  void setLocation(Point point);
};
