#pragma once
#include "Ninja.hpp"
namespace ariel{
    class YoungNinja : public Ninja {

    public:
    YoungNinja(string name, const Point &location)
    : Ninja(std::move(name), location, Y_life, Y_speed) {}
    };
}