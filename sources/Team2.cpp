#include "Team2.hpp"
#include "Character.hpp"
#include <vector>

Team2::Team2(Character *leader) : Team(leader){}

void Team2::attack(Team *other) {
  if(other == this)
    throw runtime_error("cant attack itself");

  if(other == nullptr)
    throw invalid_argument("can't attack nothing");

  if(other->stillAlive() == 0)
    throw runtime_error("dead Team can't be attacked");

  if(this->stillAlive() == 0)
    throw runtime_error("dead Team can't attack");
    
  setLeader(findAlive(this));
  Character *victim = findAlive(other);
  for( Character *teamate : *(this->getTeam())){
    //if they are all dead
    if(other->stillAlive()==false){
      return;
    }
    if(victim->isAlive())
      teamate->attack(victim);
    victim = findAlive(other);
  }
}

void Team2::print() const{
  for(Character *teamate: *(this->getTeam())){
      teamate->print();
      cout << endl;
  }
}
