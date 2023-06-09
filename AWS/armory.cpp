#include "armory.h"

Armory::Armory(int type, int defence, QString Name, int level, int rarity, int BuyVal, int SellVal)
    : Item(Name,level,rarity, BuyVal, SellVal)
{
    this->type = type;
    this->defence = defence;
}
QString Armory::toString()
{
    return QString::number(this->type) + " " + QString::number(this->defence);
}
Armory::~Armory()
{

}
Armory* Armory::clone()const
{
    return new Armory(*this);
}
