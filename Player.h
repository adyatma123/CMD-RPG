#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"

#include "Enemy.h"

#include <string>

class Player {
private:
    std::string name;
    int health;
    int damage;
    int experience;
    int level;
    int equippedWeaponDamage;

public:
    Player(const std::string& n, int h, int d);

    void attack(Character& target);

    void equipWeapon(int weaponDamage);

    void displayInfo() const;

    bool isAlive() const;
};

#endif
