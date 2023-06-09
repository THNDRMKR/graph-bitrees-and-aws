#ifndef WEAPON_H
#define WEAPON_H
#include "item.h"


class Weapon : public Item
{
public:
    Weapon(int MinDMG=0, int MaxDMG=0,QString Name = "None",int level = 0,
           int rarity=0, int BuyVal=0, int SellVal=0);
    virtual ~Weapon();


    inline const int& GetMaxDMG(){return this->MaxDMG;}
    inline const int& GetMinDMG(){return this->MinDMG;}
    QString toString();

    virtual Weapon* clone()const;
private:
    int MinDMG;
    int MaxDMG;
};

#endif // WEAPON_H
