#include "GummyBear.h"
#include <iostream>

GummyBear::GummyBear(int id, std::string n, int lvl, int hp, int atk, int def, int spd, int eng)
: unique_id(id), name(n), level(lvl), health(hp), attackPower(atk), defense(def), speed(spd), energy(eng) {}

void GummyBear::performAction(Action* action, GummyBear& target) {
    action->execute(*this, target);
}

void GummyBear::recharge() {
    energy = std::min(energy + 10, 100);
}

std::string GummyBear::getName() const { return name; }
void GummyBear::setName(const std::string& n) { name = n; }
int GummyBear::getUniqueId() const { return unique_id; }
int GummyBear::getLevel() const { return level; }
int GummyBear::getHealth() const { return health; }
void GummyBear::setHealth(int hp) { health = hp; }
int GummyBear::getAttackPower() const { return attackPower; }
int GummyBear::getDefense() const { return defense; }
int GummyBear::getSpeed() const { return speed; }
int GummyBear::getEnergy() const { return energy; }
