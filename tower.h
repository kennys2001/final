#ifndef TOWER_H
#define TOWER_H
#include<position.h>
class tower
{
public:
    tower();
    tower(position a);
    ~tower();
    void change_state();
    int canattack;
    int level;
    int levelup();
    int damage;
    double range;
    int CD;
    position p;
};
#endif // TOWER_H
