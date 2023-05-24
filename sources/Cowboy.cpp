#include "Cowboy.hpp"
#include "Character.hpp"

using namespace std;

Cowboy::Cowboy(string name, const Point &location)
    : Character(name, location, 110, true), bullets(6){}

void Cowboy::shoot(Character *enemy){
    if (this->isAlive()==false)
        throw runtime_error("dead Cowboy can't shoot");

    if (enemy->isAlive()==false)
        throw runtime_error("dead Character can't be shooted at");

    if (enemy == this)
        throw runtime_error("cant hit itself");
        
    if((this->hasboolets())){
        enemy->hit(10);
        bullets--;
    }
}

bool Cowboy::hasboolets()const{ 
    if(bullets>0)
        return true;
    return false; 
}
void Cowboy::reload(){
    if(this->isAlive()==false)
        throw runtime_error("dead cowboy cant reload");
    bullets=6;
}
string Cowboy::print()const{
    string str;
    str = "Type: C, the character name is: " + this->getName() ;
    if(isAlive())
        str = str + ", it got: " + to_string(this->gethitpoints()) + "hit points "; 
    str= str + "and and location is: ";
    str= str+this->getLocation().print();
    return str;
}
void Cowboy::attack(Character *enemy){
    if(isAlive()){
        if(hasboolets())
            shoot(enemy);
        else
            reload();
    }
    
}
