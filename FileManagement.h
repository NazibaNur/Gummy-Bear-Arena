#ifndef FILEMANAGEMENT_H
#define FILEMANAGEMENT_H

#include "GummyBear.h"
#include <string>
#include <fstream>

class FileManagement {
public:
    static void saveGame(const GummyBear& bear);
    static GummyBear loadGame(const std::string& filename);
};

#endif 
