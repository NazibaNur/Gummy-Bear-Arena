#include "Opponent.h"
#include <iostream>

void Opponent::performAction(Action* action, GummyBear& target) {
    std::cout << getName() << " (Opponent) uses a strategy to perform action!" << std::endl;
    GummyBear::performAction(action, target);
}

void Opponent::recharge() {
    energy += 15;
    if (energy > 100) energy = 100;
    std::cout << getName() << " (Opponent) recharges strategically." << std::endl;
}

