#pragma once
#include "Team.hpp"
#include <unistd.h>

namespace ariel {};

class SmartTeam : public Team {

public:
  SmartTeam(Character *leader);
  void attack(Team *other);
  void print() const;
};

