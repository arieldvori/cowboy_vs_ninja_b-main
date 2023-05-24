#pragma once
#include "Team.hpp"
#include <vector>

namespace ariel {};

class Team2:public Team{

public:
  Team2(Character *leader);
  void attack(Team *other);
  void print()const;
};
