#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "GummyBear.h"
#include "Opponent.h"
#include "FileManagement.h"
#include "AttackAction.h"  
#include <iostream>
#include <string>

class GameManager {
private:
    GummyBear player;
    Opponent opponent;
    BasicAttack basicAttack;  
    PowerAttack powerAttack;  

public:
    GameManager();
    void startGame();
    void mainMenu();
    void battle();
    void train();
    void saveGame();
    void loadGame();
};

#endif 

