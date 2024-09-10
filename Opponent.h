#ifndef OPPONENT_H
#define OPPONENT_H

#include "GummyBear.h"
#include <iostream>

class Opponent : public GummyBear {
public:
    using GummyBear::GummyBear; 

  
    void performAction(Action* action, GummyBear& target) override;
    void recharge() override;
};

#endif 
