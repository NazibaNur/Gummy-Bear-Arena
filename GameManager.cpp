#include "GameManager.h"
#include <cstdlib>  
#include <ctime>    
#include <iostream>

GameManager::GameManager()
    : player(1, "PlayerBear", 1, 100, 20, 10, 15, 100),
      opponent(2, "EnemyBear", 1, 100, 15, 5, 12, 100) {
    srand(time(NULL)); 
}

void GameManager::startGame() {
    std::string playerName;
    std::cout << "Enter your Gummy Bear's name: ";
    getline(std::cin, playerName);
    player.setName(playerName.empty() ? "PlayerBear" : playerName);
    std::cout << "Welcome, " << player.getName() << "! Starting a new game...\n";
    mainMenu();
}

void GameManager::mainMenu() {
    int choice;
    do {
        std::cout << "\n1. Battle\n2. Train\n3. Save Game\n4. Load Game\n5. Exit\nEnter your choice: ";
        std::cin >> choice;
        switch(choice) {
            case 1:
                battle();
                break;
            case 2:
                train();
                break;
            case 3:
                saveGame();
                break;
            case 4:
                loadGame();
                break;
            case 5:
                std::cout << "Exiting game...\n";
                return;
            default:
                std::cout << "Invalid choice, please try again.\n";
        }
    } while (choice != 5);
}

void GameManager::battle() {
    BasicAttack basicAttack;
    PowerAttack powerAttack;
    Action* currentAction = &basicAttack;  

    while (player.getHealth() > 0 && opponent.getHealth() > 0) {
        std::cout << "Choose your action: 1. Basic Attack, 2. Power Attack\n";
        int actionChoice;
        std::cin >> actionChoice;

        if (actionChoice == 2) {
            currentAction = static_cast<Action*>(&powerAttack);
        } else {
            currentAction = static_cast<Action*>(&basicAttack);
        }

        player.performAction(currentAction, opponent);
        if (opponent.getHealth() <= 0) {
            std::cout << opponent.getName() << " is defeated!" << std::endl;
            break;
        }

        
        currentAction = (rand() % 2) ? static_cast<Action*>(&powerAttack) : static_cast<Action*>(&basicAttack);
        opponent.performAction(currentAction, player);
        if (player.getHealth() <= 0) {
            std::cout << player.getName() << " is defeated!" << std::endl;
            break;
        }
    }

    player.setHealth(100);  
    opponent.setHealth(100);
}

void GameManager::train() {
    int healthBoost = rand() % 20 + 10;  
    player.setHealth(player.getHealth() + healthBoost);
    std::cout << "Training complete. Health increased by " << healthBoost << ".\n";
}

void GameManager::saveGame() {
    FileManagement::saveGame(player);
    std::cout << "Game saved successfully.\n";
}

void GameManager::loadGame() {
    player = FileManagement::loadGame("savegame.txt");
    std::cout << "Game loaded successfully.\n";
}
