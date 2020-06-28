#include<headquarter.h>
#include<position.h>
headquarter::headquarter(position a):tower(a)
{
    health=100;
    shield=100;
}
headquarter::headquarter():tower(position(0,0))
{
    health=100;
    shield=100;
}
