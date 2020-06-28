
#include<position.h>
#include<math.h>
position::position()
{
    x=0;
    y=0;
}
position::position(double a,double b)
{
    x=a;
    y=b;
}
position::~position()
{
    ;
}
double position::get_positionX()
{
    return x;
}
double position::get_positionY()
{
    return y;
}
bool position::operator==(position &a)
{
    if(a.get_positionX()==x&&a.get_positionY()==y)
        return true;
    else return false;
}
double position::length(position a)
{
    double i,j,k;
    i=a.get_positionX()-x;
    j=a.get_positionY()-y;
    k=sqrt(i*i+j*j);
    return k;
}
position position::seefuture(double speed,position c)
{
    position a;
    double l=this->length(c);
    double i=l/20;
    if(c.get_positionY()<150)
    {
        a=position(c.get_positionX()-1.0*i*speed,c.get_positionY()+1.0*i*speed/10);
    }
    else if(c.get_positionY()>=150&&c.get_positionY()<=500)
    {
        a=position(c.get_positionX()+i*speed/1.2,c.get_positionY()+i*speed/1.414);
    }
    else a=position(c.get_positionX()-i*speed*1.0,c.get_positionY());
    return a;

}
