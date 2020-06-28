#ifndef GIANT_H
#define GIANT_H
#include<enemy.h>
#include<headquarter.h>
class giant:public enemy
{
public:
    giant();
    ~giant();
    giant(position a);
    int damage;
    int range;
    int canattack;
    int CD;
    void attack();
    void change_state();
};

#endif // GIANT_H
