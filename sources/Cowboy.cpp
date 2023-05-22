#include "Cowboy.hpp"
#include "Character.hpp"
Cowboy::Cowboy(string name, const Point &location)
    : Character(name, location, 110), bullets(6) {}

void Cowboy::shoot(Character *enemy){
    if((this->isAlive())&&(this->hasBoolets())){
        enemy->hit(10);
        bullets--;
    }
}

bool Cowboy::hasBoolets(){ 
    if(bullets>0)
        return true;
    return false; 
}
void Cowboy::reload(){
    bullets=6;
}