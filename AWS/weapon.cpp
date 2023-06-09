#include "weapon.h"

Weapon::Weapon(int MinDMG, int MaxDMG, QString Name, int level, int rarity, int BuyVal, int SellVal)
    : Item(Name,level,rarity, BuyVal, SellVal)
{
    this->MinDMG = MinDMG;
    this->MaxDMG = MaxDMG;
}
QString Weapon::toString()
{
    return QString::number(this->MinDMG) + " " + QString::number(this->MaxDMG);
}

Weapon::~Weapon()
{

}
Weapon* Weapon::clone()const
{
    return new Weapon(*this);
}
