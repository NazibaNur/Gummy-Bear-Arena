#include "FileManagement.h"
#include <iostream>

void FileManagement::saveGame(const GummyBear& bear) {
    std::ofstream file("savegame.txt");
    if (file) {
        file << bear.getUniqueId() << std::endl;
        file << bear.getName() << std::endl;
        file << bear.getLevel() << std::endl;
        file << bear.getHealth() << std::endl;
        file << bear.getAttackPower() << std::endl;
        file << bear.getDefense() << std::endl;
        file << bear.getSpeed() << std::endl;
        file << bear.getEnergy() << std::endl;
        file.close();
        std::cout << "Game saved successfully.\n";
    } else {
        std::cout << "Failed to save the game.\n";
    }
}

GummyBear FileManagement::loadGame(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Unable to open file for loading.\n";
        return GummyBear(1, "DefaultBear", 1, 100, 20, 10, 15, 100);
    }
    int id, lvl, hp, atk, def, spd, eng;
    std::string name;
    file >> id >> name >> lvl >> hp >> atk >> def >> spd >> eng;
    return GummyBear(id, name, lvl, hp, atk, def, spd, eng);
}
