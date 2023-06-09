#include "enemy.h"

Enemy::Enemy(int level,QString name)
{
    this->level = level;
    this->Name = name;
    this->MaxHp = level * 8;
    this->Hp = this->MaxHp;
    this->MinDMG = this->level*2-rand()%2;
    this->MaxDMG = this->level*2+rand()%3*level/2;
    this->defence = level*rand()%5;
    this->accuracy = 5;
}
Enemy::Enemy(const Enemy& en)
{
    this->level = en.level;
    this->Name = en.Name;
    this->MaxHp = level * 8;
    this->Hp = this->MaxHp;
    this->MinDMG = this->level*2-rand()%2;
    this->MaxDMG = this->level*2+rand()%3*level/2;
    this->defence = level*rand()%5;
    this->accuracy = 5;
}
Enemy::~Enemy()
{

}
QString Enemy::GetAsString()const
{
    return "Level: " + QString::number(this->level)+
            "\nHp: " + QString::number(this->Hp)+ "/" + QString::number(this->MaxHp)+
            "\nDamage: " + QString::number(this->MinDMG)+ "/" + QString::number(this->MaxDMG) +
            "\nDefence: " + QString::number(this->defence)+
            "\nAccuracy: " + QString::number(this->accuracy)+"\n";
}
