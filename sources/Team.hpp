#pragma once
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "OldNinja.hpp"
#include "TrainedNinja.hpp"
#include "YoungNinja.hpp"
#include <vector>

namespace ariel {};

class Team {
  Character *leader;
  vector<Character *> team;

public:
  Team(const Team& other);
  Team(Character *leader);
  Team(Team&& other)noexcept;
  Character *findAlive(Team *other);
  Character *findvictim(Team *other);
  Team& operator=(const Team& other);
  Team& operator=( Team&& other)noexcept;
  void add(Character *teamate);
  void attack(Team *other);
  int stillAlive() const;
  void print() const;
  void setLeader(Character * other);
  vector<Character *> const *getTeam() const;
  virtual ~Team();
};
