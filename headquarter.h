#ifndef HEADQUARTER_H
#define HEADQUARTER_H
#include<position.h>
#include<tower.h>
class headquarter:public tower
{
public:
    headquarter(position a);
    headquarter();
    int health;
    int shield;
};

#endif // HEADQUARTER_H
