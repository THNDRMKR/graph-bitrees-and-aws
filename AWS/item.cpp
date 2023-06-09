#include "item.h"

Item::Item(QString name, int level, int rarity, int buy, int sell)
{
    this->Name = name;
    this->BuyVal = buy;
    this->SellVal = sell;
    this->level=level;
    this->rarity=rarity;
}
Item::Item()
{
    this->Name = "name";
    this->BuyVal = 0;
    this->SellVal = 0;
    this->level=0;
    this->rarity=0;
}
Item::~Item()
{

}
