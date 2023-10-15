#include "Player.h"
#include "Character.h"

Player::Player(const std::string& n, int h, int d) : Character(n, h, d), experience(0), level(1), equippedWeaponDamage(0) {}

void Player::attack(Character& target) {
    Character::attack(target);
    if (target.isAlive()) {
        std::cout << target.name << " has " << target.health << " health left." << std::endl;
    }
    else {
        std::cout << target.name << " has been defeated!" << std::endl;
        int xpEarned = 10; // Earn 10 XP for defeating an enemy
        experience += xpEarned;

        // Check for level up
        int nextLevelXP = level * 100; // For example, level 2 requires 200 XP, level 3 requires 300 XP, and so on
        if (experience >= nextLevelXP) {
            level++;
            std::cout << "Congratulations! You leveled up to level " << level << "!" << std::endl;

            // Increase player stats upon leveling up (for simplicity, just increase damage)
            damage += 5;
        }
    }
}

void Player::equipWeapon(int weaponDamage) {
    equippedWeaponDamage = weaponDamage;
    damage += equippedWeaponDamage;
    std::cout << "You have equipped a weapon with +" << equippedWeaponDamage << " damage." << std::endl;
}

void Player::displayInfo() const {
    std::cout << "Player Info: ";
    Character::displayInfo();
    std::cout << "Level: " << level << ", Experience Points: " << experience << std::endl;
    std::cout << "Equipped Weapon Damage: " << equippedWeaponDamage << std::endl;
}

bool Player::isAlive() const {
    return health > 0;
}
