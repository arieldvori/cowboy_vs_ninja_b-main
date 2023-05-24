#include "Ninja.hpp"
#include "Character.hpp"

using namespace std;

Ninja::Ninja(string name, const Point &location, int life, int speed)
    : Character(name, location, life, false), speed(speed) {
    }

void Ninja::move(const Character *enemy){
    if(isAlive()){
        this->setLocation(Point::moveTowards(this->getLocation(),enemy->getLocation(),this->speed));
    }
}

void Ninja::slash(Character *enemy) const{
    if(isAlive()==false)
        throw runtime_error("dead ninja cant slash");
    if(enemy->isAlive()==false)
        throw runtime_error("dead enemy cant get hit again");
    if(enemy==this)
        throw runtime_error("cant slash himself");

    if(distance(enemy)<1){
        enemy->hit(40);
    }
}

string Ninja::print()const{
    string str;
    str = "Type: N, the character name is: " + this->getName() ;
    if(isAlive())
        str = str + ", it got: " + to_string(this->gethitpoints()) + "hit points "; 
    str= str + "and and location is: ";
    str= str+this->getLocation().print();
    return str;
}
void Ninja::attack(Character *enemy){
    if(isAlive()){
        if(distance(enemy)<1)
            slash(enemy);
        else 
            move(enemy);
    }   
}