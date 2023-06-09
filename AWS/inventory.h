#ifndef INVENTORY_H
#define INVENTORY_H
#include "armory.h"
#include "weapon.h"
#include <QList>
#include <QTextEdit>
#include <QPlainTextEdit>
class Inventory
{
public:
    Inventory();
    ~Inventory();
    Inventory(const Inventory& obj);
    void addItem(const Item& item);
    void removeItem(int index);
    inline const int& getNmrOfItems(){return this->nmrOfItems;}
    inline const Item* GetArrItem(int index){return this->itemArr[index];}
    Item& operator[](const int index);

    inline void debugPrint(QPlainTextEdit *a) const
    {
        a->insertPlainText("Inventory\n");
        for(int i = 0; i < nmrOfItems; i++)
        {
        a->insertPlainText(QString::number(i+1)+": "+itemArr[i]->GetName()+" ");
        }
        a->insertPlainText("\n");
    }
    void expand();
    void initialize(const int from=0);
private:
    int size;
    int nmrOfItems;
    Item** itemArr;

};

#endif // INVENTORY_H
