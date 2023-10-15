#pragma once
#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

class Character {
public:
    std::string name;
    int health;
    int damage;

    Character(const std::string& n, int h, int d);

    virtual void attack(Character& target);

    bool isAlive() const;

    virtual void displayInfo() const;
};

#endif
