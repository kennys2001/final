#include<position.h>
#include<towering.h>
towering::towering()
{
    damage=2;
    range=50;
    p=position(0,0);
}
towering::towering(position a):p(a)
{
    damage=2;
    range=50;
}
towering::~towering()
{
    ;
}
int towering::levelup()
{
    if(level!=4)
    {
        level++;
        damage=level*5;
        return 2;
    }
    else return 1;
}
