#ifndef ITEM_H
#define ITEM_H
#include <QString>


class Item
{
public:
    Item();
    Item(QString name, int level, int rarity, int buy, int sell);
    ~Item();

    inline const QString& GetName() const {return this->Name;}
    inline const int& GetLevel() const {return this->level;}
    inline const int& GetBuyVal() const {return this->BuyVal;}
    inline const int& GetSellVal() const {return this->SellVal;}
    inline const int& GetRarity() const {return this->rarity;}
    virtual Item* clone()const = 0;
private:
    QString Name;
    int BuyVal;
    int SellVal;
    int level;
    int rarity;

};

#endif // ITEM_H
