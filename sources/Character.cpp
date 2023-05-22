#include "Character.hpp"

using namespace std;

Character::Character(string name, const Point &location, int hit_points)
    : _name(name), _location(location), _hit_points(hit_points) {}

bool Character::isAlive() { 
    if(_hit_points>0)
        return true;
    return false; 
}
double Character::distance(Character &other) {
    return _location.distance(other._location); 
}
void Character::hit(int damage) {
    _hit_points-=damage;
}

string Character::getName() {
    return _name; 
}
Point Character::getLocation() {
    return _location; 
}
int Character::gethitpoints() {
    return _hit_points; 
}
void Character::print() {
    cout << "the character name is: " << _name ;
    if(isAlive)
        cout << ", it got: " << _hit_points << "hit points "; 
    cout << "and and location is: ";
    _location.print();
    cout << endl; 
}
void Character::setLocation(Point point){
    _location=point;
}