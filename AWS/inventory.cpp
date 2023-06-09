#include "inventory.h"

Inventory::Inventory()
{
    this->size =5;
     this->nmrOfItems = 0;
     this->itemArr = new Item*[this->size];
    this->initialize();
}
Inventory::~Inventory()
{
    delete[] itemArr;
}
Inventory::Inventory(const Inventory& obj)
{
    this->size =obj.size;
     this->nmrOfItems = obj.nmrOfItems;
     this->itemArr = new Item*[this->size];
    for(int i =0; i < this->nmrOfItems;i++)
    {
        this->itemArr[i] = obj.itemArr[i]->clone();
    }
    this->initialize(this->nmrOfItems);
}
void Inventory::expand()
{
    this->size *=2;
    Item** tmp = new Item*[size];

    for(int i =0;i < this->nmrOfItems;i++)
    {
        tmp[i] = this->itemArr[i];
    }
    delete[] this->itemArr;

    this->itemArr = tmp;
    this->initialize(this->nmrOfItems);
}
void Inventory::initialize(const int from)
{
    for(int i = from; i <= size;i++)
    {
        itemArr[i]= nullptr;
    }
}
Item& Inventory::operator[](const int index)
{
    if(index < 0 || index >=this->nmrOfItems)throw("BAD INDEX");
    return *this->itemArr[index];
}
void Inventory::addItem(const Item& item)
{
    if(this->nmrOfItems>= this->size) expand();
    this->itemArr[this->nmrOfItems++] = item.clone();
}
void Inventory::removeItem(int index)
{

}
