#ifndef ATTACK_ACTIONS_H
#define ATTACK_ACTIONS_H

#include "Action.h"
#include "GummyBear.h"  

class BasicAttack : public Action {
public:
    void execute(GummyBear& executor, GummyBear& target) override {
        int damage = executor.getAttackPower() - target.getDefense();
        damage = std::max(0, damage);
        target.setHealth(target.getHealth() - damage);
        std::cout << executor.getName() << " hits " << target.getName() << " for " << damage << " damage!" << std::endl;
    }
};

class PowerAttack : public Action {
public:
    void execute(GummyBear& executor, GummyBear& target) override {
        int damage = int(executor.getAttackPower() * 1.5) - target.getDefense();
        damage = std::max(0, damage);
        target.setHealth(target.getHealth() - damage);
        std::cout << executor.getName() << " powerfully strikes " << target.getName() << " for " << damage << " damage!" << std::endl;
    }
};

#endif 
