#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Character.h"

Character::Character(const std::string& n, int h, int d) : name(n), health(h), damage(d) {}

void Character::attack(Character& target) {
    int hitPoints = rand() % damage + 1;
    std::cout << name << " attacks " << target.name << " for " << hitPoints << " damage." << std::endl;
    target.health -= hitPoints;
}

bool Character::isAlive() const {
    return health > 0;
}

void Character::displayInfo() const {
    std::cout << "Name: " << name << ", Health: " << health << ", Damage: " << damage << std::endl;
}
