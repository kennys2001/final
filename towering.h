#ifndef TOWERING_H
#define TOWERING_H
#include<position.h>
class towering
{
public:
    int range;
    position p;
    int damage;
    int level;
    int levelup();
    towering();
    towering(position a);
    ~towering();
};

#endif // TOWERING_H
