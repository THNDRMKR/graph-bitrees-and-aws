#include "event.h"

Event::Event()
{
    this->nmrOfEvents = 2;
}
Event::~Event()
{

}
void Event::generateEvent()
{
    int i = rand() %this->nmrOfEvents+1;

    switch(i)
    {
    case 0:
        enemyEncounter();
        break;
    case 1:
        break;
    case 2:
        break;
    default:
        break;
    }
}
void Event::enemyEncounter()
{
    Enemy en;
    while(en.isAlive() && )
}
