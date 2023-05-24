#include "Character.hpp"

using namespace std;

Character::Character(string name, const Point &location, int hit_points, bool is_cowboy)
    : _name(name), _location(location), _hit_points(hit_points), _is_cowboy(is_cowboy) {}

bool Character::isAlive() const{ 
    if(_hit_points>0)
        return true;
    return false; 
}
double Character::distance(const Character *other) const{
    return this->_location.distance(other->_location); 
}
void Character::hit(int damage) {
    if(damage<0)
        throw invalid_argument("cant add hp when damage is neg");
    _hit_points-=damage;
}

string Character::getName() const{
    return _name; 
}
Point Character::getLocation() const{
    return _location; 
}
int Character::gethitpoints() const{
    return _hit_points; 
}
void Character::setLocation(const Point & point){
    _location=point;
}
bool Character::IsCowboy() const{return _is_cowboy;}
bool Character::IsActive() const{return _is_active;}
void Character::setActive(){this->_is_active=true;}