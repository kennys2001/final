#ifndef ENEMY_H
#define ENEMY_H
#include<position.h>
class enemy
{
public:
    enemy(position a);
    enemy();
    ~enemy();
    void move();
    void move1();
    int money;
    int life;
    //position seefuture(position c);
    double speed;
    position p;
};

#endif // ENEMY_H
