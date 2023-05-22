#pragma once
#include "Character.hpp"

class Cowboy : public Character {
  int bullets = 6;

public:
  Cowboy(string name,const Point &location);
  void shoot(Character* enemy);
  bool hasBoolets();
  void reload();
};