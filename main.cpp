#include <iostream>
#include "GummyBear.h"
#include "Opponent.h"
#include "GameManager.h"
#include "FileManagement.h"

int main() {
    std::cout << "Welcome to Gummy Bear Arena!" << std::endl;

    GameManager gameManager;
    gameManager.startGame();

    return 0;
}
