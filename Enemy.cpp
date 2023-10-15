#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Enemy.h"
#include "Character.h"

Enemy::Enemy(const std::string& n, int h, int d, int drop) : Character(n, h, d), dropChance(drop) {}

bool Enemy::shouldDropWeapon() const {
    return rand() % 100 < dropChance;
}

int Enemy::generateWeaponDamage() const {
    return rand() % 10 + 1; // Generate weapon damage between 1 and 10
}

void Enemy::attack(Character& target) {
    Character:attack(target);
}

void Enemy::displayInfo() const {
    Character:displayInfo();
}

bool Enemy::isAlive() const {
    return health > 0;
}
