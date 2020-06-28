#ifndef POSITION_H
#define POSITION_H

class position
{
public:
    position(double a,double b);
    position();
    ~position();
    double get_positionX();
    double get_positionY();
    bool operator ==(position &pp);
    double length(position a);
    position seefuture(double speed,position c);
private:
    double x;
    double y;
};

#endif // POSITION_H
