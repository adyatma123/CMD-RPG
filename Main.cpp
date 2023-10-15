#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Player.h"
#include "Enemy.h"
#include "GameManager.h"

using namespace std;

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    cout << "Welcome to the RPG game!" << endl;

    // Game logic using Player and Enemy classes

    GameManager gameManager;
    gameManager.runGame();

    return 0;
}
