#ifndef GUMMYBEAR_H
#define GUMMYBEAR_H

#include <string>
#include "Action.h"

class GummyBear {
protected:
    int unique_id;
    std::string name;
    int level;
    int health;
    int attackPower;
    int defense;
    int speed;
    int energy;

public:
    GummyBear(int id, std::string n, int lvl, int hp, int atk, int def, int spd, int eng);
    virtual ~GummyBear() {}

    virtual void performAction(Action* action, GummyBear& target);
    virtual void recharge();

    std::string getName() const;
    void setName(const std::string& n);
    int getUniqueId() const;
    int getLevel() const;
    int getHealth() const;
    void setHealth(int hp);
    int getAttackPower() const;
    int getDefense() const;
    int getSpeed() const;
    int getEnergy() const;
};

#endif 
