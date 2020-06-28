#ifndef ARCHER_H
#define ARCHER_H
#include<enemy.h>
#include<position.h>
#include<headquarter.h>
class archer:public enemy
{
public:

    ~archer();
    int range;
    archer();
    archer(position a);
    void change_state();
    int canattack;
    int CD;
};

#endif // ARCHER_H
