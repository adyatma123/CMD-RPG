#pragma once
#ifndef ENEMY_H
#define ENEMY_H

#include "Character.h"
#include "Player.h"

#include <string>

class Enemy {
private:
    std::string name;
    int health;
    int damage;
    int dropChance;

public:
    Enemy(const std::string& n, int h, int d, int drop);

    bool shouldDropWeapon() const;

    int generateWeaponDamage() const;

    void attack(Character& target);

    void attack(Player& target); // Overloaded function

    void displayInfo() const;

    bool isAlive() const;
};

#endif
