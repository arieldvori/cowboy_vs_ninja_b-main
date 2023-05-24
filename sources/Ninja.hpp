#pragma once
#include "Character.hpp"

const int Y_life = 100;
const int Y_speed = 14;
const int O_life = 150;
const int O_speed = 8;
const int T_life = 120;
const int T_speed = 12;

class Ninja : public Character {
  int speed;

public:
  Ninja(string name, const Point &location, int life, int speed);
  void move(const Character *enemy);
  void slash(Character *enemy)const;
  string print() const override;
  void attack(Character *enemy) override;
};
