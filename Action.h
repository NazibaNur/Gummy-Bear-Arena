#ifndef ACTION_H
#define ACTION_H

class GummyBear; 


class Action {
public:
    virtual ~Action() {}
    virtual void execute(GummyBear& executor, GummyBear& target) = 0;
};

#endif 

