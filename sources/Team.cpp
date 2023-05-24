#include "Team.hpp"
#include "Character.hpp"
#include <vector>
#include <float.h>

Team::Team(const Team &other) : leader(other.leader){
  throw runtime_error("cant be on more than one team");
}

Team::Team(Character *leader) : leader(leader){
  if(leader->IsActive())
    throw runtime_error("cant be on more than one team");
  team.push_back(leader); 
  leader->setActive();
}

Team::Team(Team &&other) noexcept{
  leader = other.leader;
  team = other.team;
}

Character *Team::findAlive(Team *other) {
  if(other->leader->isAlive()==false){
    double closest = DBL_MAX;
    Character *result = NULL;
    for (Character *teamate : other->team)
      if (teamate->isAlive() && other->leader->distance(teamate) < closest) {
        closest = other->leader->distance(teamate);
        result = teamate;
      }
    return result;
  }
  return other->leader;
}

Character *Team::findvictim(Team *other) {
    double closest = DBL_MAX;
    Character *result = NULL;
    for (Character *teamate : other->team)
      if (teamate->isAlive() && this->leader->distance(teamate) < closest) {
        closest = this->leader->distance(teamate);
        result = teamate;
      }
    return result;
}


Team &Team::operator=(const Team &other){
  throw runtime_error("cant be on more than one team");
}

Team &Team::operator=( Team &&other) noexcept{
  team = other.team;
  leader = other.leader;
  return *this;
}

void Team::add(Character *teamate){
  if (team.size() == 10)
      throw runtime_error("maximum size of group is 10");
  if (teamate->IsActive())
      throw runtime_error("a player can be member of one team only");
  if (teamate == nullptr)
      throw invalid_argument("can't add nulptr to team");
  if (team.size() < 10){
    team.push_back(teamate);
    teamate->setActive();
  }
}

void Team::attack(Team *other){
  if(other == nullptr)
      throw invalid_argument("can't attack nothing");

  if(other == this)
      throw runtime_error("cant attack yourself");

  if(this->stillAlive() == 0)
      throw runtime_error("dead Team can't attack");

  if(other->stillAlive() == 0)
      throw runtime_error("dead Team can't be attacked");
  this->leader = findAlive(this);
  Character *victim = this->findvictim(other);
  for(Character *teamate : team){
    if(other->stillAlive() == 0)
      return;
    if(teamate->IsCowboy()){
      if(victim->isAlive())
        teamate->attack(victim);
      else{
        victim = this->findvictim(other);
        teamate->attack(victim);
      }
    }
  }
  for( Character *teamate : team){
    if(other->stillAlive() == 0)
      return;
    if(!teamate->IsCowboy()){
      if(victim->isAlive())
        teamate->attack(victim);
      else{
        victim = this->findvictim(other);
        teamate->attack(victim);
      }
    }
  }
}

int Team::stillAlive()const{
  int alive_count=0;
  for(Character *teamate: team){
    if(teamate->isAlive())
      alive_count++;
  }
  return alive_count;
}

void Team::print()const{
  for(Character *teamate: team){
    if(teamate->IsCowboy()){
      cout << teamate->print();
      cout << endl;
    }
  }
  for(Character *teamate: team){
    if(!teamate->IsCowboy()){
      cout << teamate->print();
      cout << endl;
    }
  }
}

void Team::setLeader(Character *other){
  this->leader=other;
}

vector<Character *> const *Team::getTeam() const{
  return &this->team;
}

Team::~Team(){
  for(Character *teamate: this->team)
    delete teamate;
  team.clear();
}