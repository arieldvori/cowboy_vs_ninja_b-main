#include "SmartTeam.hpp"
#include "Character.hpp"
#include <vector>

SmartTeam::SmartTeam(Character *leader) : Team(leader){}

void SmartTeam::attack(Team *other) {
  if(other == this)
    throw runtime_error("cant attack itself");

  if(other == nullptr)
    throw invalid_argument("can't attack nothing");

  if(other->stillAlive() == 0)
    throw runtime_error("dead Team can't be attacked");

  if(this->stillAlive() == 0)
    throw runtime_error("dead Team can't attack");
    
  setLeader(findAlive(this));
  Character *victim = this->findvictim(other);
  for( Character *teamate : *(this->getTeam())){
    if(other->stillAlive() == 0)
      return;
    //if they are all dead
    if(victim->isAlive())
      teamate->attack(victim);
    else{
      victim = this->findvictim(other);
      teamate->attack(victim);
    }
  }
}

void SmartTeam::print() const{
  for(Character *teamate: *(this->getTeam())){
      teamate->print();
      cout << endl;
  }
}
