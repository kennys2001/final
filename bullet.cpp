#include<enemy.h>
#include<bullet.h>
#include<math.h>
bullet::bullet():p(position(0,0))
{

    damage=0;
    speed=0;
}
bullet::~bullet()
{
    ;
}

bullet::bullet(tower a,position c):p(a.p),to(c)
{
    from=a.p;
    damage=a.damage;
    speed=20;
}
void bullet::move()
{
    double h,g,length;
    h=from.get_positionX()-to.get_positionX();
    g=from.get_positionY()-to.get_positionY();
    length=sqrt(h*h+g*g);
    p=position(p.get_positionX()-(from.get_positionX()-to.get_positionX())/length*speed,p.get_positionY()-(from.get_positionY()-to.get_positionY())/length*speed);
}
