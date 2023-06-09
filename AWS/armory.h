#ifndef ARMORY_H
#define ARMORY_H
#include "item.h"

class Armory : public Item
{
public:
    Armory(int type=0, int defence=0,QString Name = "None",int level = 0,
           int rarity=0, int BuyVal=0, int SellVal=0);
    virtual ~Armory();

    QString toString();

     inline const int& GetType(){return this->type;}
     inline const int& GetDefence(){return this->defence;}

    Armory* clone()const;
private:
    int type;
    int defence;
};

#endif // ARMORY_H
