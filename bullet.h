#ifndef BULLET_H
#define BULLET_H
#include<enemy.h>
#include<tower.h>
#include<position.h>
class bullet
{
public:
    bullet();
    bullet(tower a,position c);
    ~bullet();
    void move();
    int damage;
    position from;
    position to;

    double speed;
    position p;
};

#endif // BULLET_H
