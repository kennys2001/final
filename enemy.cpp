#include<enemy.h>
enemy::enemy(position a):p(a)
{
    life=200;
    speed=3;
    money=500;
}
enemy::enemy()
{
    p=position(0,0);

}
enemy::~enemy()
{
    ;
}
void enemy::move()
{
    if(p.get_positionX()>430&&p.get_positionY()==140)
    {
        p=position(p.get_positionX()-speed,p.get_positionY());
    }
    else if(p.get_positionX()<=470&&p.get_positionY()<=260&&p.get_positionY()>=140)
    {
        p=position(p.get_positionX()+speed/3.1622,p.get_positionY()+speed*3/3.1622);
    }
    else if(p.get_positionX()>=467&&p.get_positionX()<=710&&p.get_positionY()>=260&&p.get_positionY()<=340)
    {
         p=position(p.get_positionX()+speed*25/26.24,p.get_positionY()+speed*8/26.24);
    }
    else if(p.get_positionX()>=650&&p.get_positionX()<=715&&p.get_positionY()>=340&&p.get_positionY()<=430)
    {
        p=position(p.get_positionX()-speed*5/10.29,p.get_positionY()+speed*9/10.29);
    }
    else if(p.get_positionX()<=665&&p.get_positionX()>=370&&p.get_positionY()>=350&&p.get_positionY()<=435&&p.get_positionY()/p.get_positionX()>0.65)
    {
        p=position(p.get_positionX()-speed*7/7.28,p.get_positionY()-speed*2/7.28);
    }
    else  p=position(p.get_positionX()-speed,p.get_positionY());

}
void enemy::move1()
{

    if(p.get_positionY()<=210&&p.get_positionX()==510)
    {
        p=position(p.get_positionX(),p.get_positionY()+speed);

    }
    else if(p.get_positionX()<=512&&p.get_positionY()>=210&&p.get_positionX()>=360&&p.get_positionY()<=290)
    {
        p=position(p.get_positionX()-15.0/17*speed,p.get_positionY()+8.0/17*speed);
    }
    else if(p.get_positionX()>=360&&p.get_positionY()<=400&&p.get_positionY()>=260&&p.get_positionX()<=387)
    {
        p=position(p.get_positionX(),p.get_positionY()+speed);

    }

    else if(p.get_positionX()>=365&&p.get_positionY()>=400&&p.get_positionX()<=700&&p.get_positionY()<=420)
    {
        p=position(p.get_positionX()+31/31.064*speed,p.get_positionY()+2/31.064*speed);

    }
    else if(p.get_positionX()>=700&&p.get_positionX()<=780)
    {
        p=position(p.get_positionX()+speed*8/10.63,p.get_positionY()-7/10.63*speed);

    }
   else p=position(p.get_positionX()+speed,p.get_positionY());
}


