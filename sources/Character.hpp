#pragma once

#include "Point.hpp"

using namespace std;

class Character {
  Point _location;
  string _name;
  int _hit_points;
  bool _is_cowboy=false;
  bool _is_active=false;

public:
  Character(string name,  const Point &location, int hit_points, bool is_cowboy);
  virtual ~Character() {}
  bool isAlive() const;
  double distance(const Character *other)const;
  void hit(int damage);
  string getName() const;
  Point getLocation() const;
  virtual string print() const =0;//because the override
  int gethitpoints() const;
  void setLocation(const Point &point);
  virtual void attack(Character* other)=0;//because the override
  bool IsCowboy() const;
  bool IsActive() const;
  void setActive();
};
