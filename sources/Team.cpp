#include "Team.hpp"
#include "Character.hpp"
#include <vector>
#include <float.h>

Team::Team(const Team &other) : leader(other.leader){}

Team::Team(Character *leader) : leader(leader){
  team.push_back(leader); 
}

Team::Team(Team &&other) noexcept{
  leader = other.leader;
  team = other.team;
}

Team &Team::operator=(const Team &other){
  team = other.team;
  leader = other.leader;
  return *this;
}

Team &Team::operator=( Team &&other) noexcept{
  team = other.team;
  leader = other.leader;
  return *this;
}

void Team::add(Character *teamate){
  if (team.size() < 10)
    team.push_back(teamate);
}

void Team::attack(Team *other){
  //if leader is alive
  if(other->leader->isAlive()){

  }
  else{
    double closest = DBL_MAX;
    for(int i=1;i<10;i++){
      if(team[i]->isAlive()){
        if((team[i]->getLocation().distance(leader->getLocation()))<DBL_MAX)
          other->leader=team[i];
      }
    }
  }
}

int Team::stillAlive(){
  return 0;
}

void Team::print(){}

Team::~Team(){}