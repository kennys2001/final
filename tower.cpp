#include<tower.h>
#include<QTimer>
#include<QDebug>
#include<QThread>
#include<QApplication>
tower::tower():p(position(400,400))
{
    level=1;
    CD=1000;
    range=300;
    canattack=1;
    damage=50;
}
tower::~tower()
{
    ;
}
void tower::change_state()
{
    canattack=canattack-CD*0.25;
}
tower::tower(position a):p(a)
{
    damage=100;
    level=1;
    CD=1000;
    range=300;
    canattack=1;
}
int tower::levelup()
{
    if(level==5)
    {
        return 1;
    }
    else
    {
        level++;
        damage=100*level;
        return 2;
    }
}
