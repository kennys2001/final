#include<enemy.h>
#include<archer.h>
#include<position.h>
#include<headquarter.h>
archer::archer()
{
    canattack=1;
    range=100;
    CD=1000;
}
archer::~archer()
{
    ;
}
archer::archer(position a):enemy(a)
{
    canattack=1;
    range=100;
    CD=1000;
}
void archer::change_state()
{
    canattack=canattack-CD*0.25;
}
