#include <iostream>
#include "GameManager.h"
#include "Player.h"
#include "Enemy.h"

using namespace std;

void GameManager::runGame() {
    srand(static_cast<unsigned>(time(nullptr)));

    cout << "Welcome to the RPG game!" << endl;

    while (true) {
        string playerName;
        cout << "Enter your character's name: ";
        cin >> playerName;

        Player player(playerName, 100, 20);
        Enemy enemy("Dragon", 200, 30, 50); // Enemy has a 50% chance to drop a weapon

        while (player.isAlive() && enemy.isAlive()) {
            cout << endl;
            player.displayInfo();
            enemy.displayInfo();
            cout << "Choose an action:" << endl;
            cout << "1. Attack" << endl;
            cout << "2. Run away" << endl;
            int choice;
            cin >> choice;

            if (choice == 1) {
                player.attack(enemy);
                if (enemy.isAlive()) {
                    enemy.attack(player);
                }
                else {
                    if (enemy.shouldDropWeapon()) {
                        int weaponDamage = enemy.generateWeaponDamage();
                        player.equipWeapon(weaponDamage);

                        // Ask the player if they want to continue or end the game
                        cout << "Do you want to search for the next battle? (yes/no): ";
                        string searchChoice;
                        cin >> searchChoice;

                        if (searchChoice != "yes") {
                            cout << "Thank you for playing! Goodbye." << endl;
                            return; // End the game
                        }
                    }
                }
            }
            else if (choice == 2) {
                cout << "You ran away from the battle!" << endl;
                break;
            }
            else {
                cout << "Invalid choice. Try again." << endl;
            }
        }

        if (player.isAlive()) {
            cout << "Congratulations! You defeated the enemy!" << endl;
        }
        else {
            cout << "Game over! The enemy defeated you." << endl;
            cout << "Do you want to play again? (yes/no): ";
            string playAgain;
            cin >> playAgain;

            if (playAgain != "yes") {
                cout << "Thank you for playing! Goodbye." << endl;
                return; // Exit the game loop if the player doesn't want to play again
            }
        }
    }
}
