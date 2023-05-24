#pragma once
#include "Character.hpp"

class Cowboy : public Character {
  int bullets = 6;

public:
  Cowboy(string name,const Point &location);
  void shoot(Character* enemy);
  bool hasboolets() const;
  void reload();
  string print()const override;
  void attack(Character *enemy) override;
};