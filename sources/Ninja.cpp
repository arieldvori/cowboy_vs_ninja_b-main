#include "Ninja.hpp"
#include "Character.hpp"

Ninja::Ninja(string name, const Point &location, int life, int speed)
    : Character(name, location, life), speed(speed) {}

void Ninja::move(Character *enemy) {
    this->setLocation(this->getLocation().moveTowards(this->getLocation(),enemy->getLocation(),this->speed));
}

void Ninja::slash(Character *enemy) {
    if((this->isAlive())&&((this->getLocation().distance(enemy->getLocation()))<1)){
        enemy->hit(40);
    }
}

void Ninja::print(){
    if(isAlive()){
        cout << "Type: N, ";
        this->print();
    }
}
