#include <enemy.h>
#include <giant.h>
#include <position.h>
#include <headquarter.h>
giant::giant()
{
    ;
}
giant::~giant()
{
    ;
}
giant::giant(position a):enemy(a)
{
     canattack=1;
     CD=1000;
     damage=50;
     range=50;
    life=500;
    money=2000;
    speed=1.5;
}
void giant::attack()
{
    ;
}
void giant::change_state()
{
    canattack=canattack-500;
}
