#pragma once
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include <vector>

namespace ariel {};

class Team {
  Character *leader;
  vector<Character *> team;

public:
  Team(const Team& other);
  Team(Character *leader);
  Team(Team&& other)noexcept;
  Team& operator=(const Team& other);
  Team& operator=( Team&& other)noexcept;
  void add(Character *teamate);
  void attack(Team *oponnent);
  int stillAlive();
  void print();
  ~Team();
};
