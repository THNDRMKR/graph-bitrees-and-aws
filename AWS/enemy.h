#ifndef ENEMY_H
#define ENEMY_H
#include <QRandomGenerator>
#include <QString>
#include <QVector>
class Enemy
{
public:
    Enemy(int level = 0,QString name = "Mob");
    Enemy(const Enemy& en);
    virtual ~Enemy();

    inline bool isAlive() {return Hp>0;}
    QString GetAsString()const;
    inline const QString& GetName(){return this->Name;}
    void takeDamage(int damage) {this->Hp -= damage;}
    inline int getDamage()const {return rand()%(this->MaxDMG-MinDMG+1)+MinDMG;}
    inline int getExp()const{return this->level*(100+rand()%16);}
    inline int getLevel()const{return this->level;}
    inline int getHp()const{return this->Hp;}
    inline int getDefence()const{return this->defence;}
private:
    QString Name;
    int level;
    int Hp;
    int MaxHp;
    int MinDMG;
    int MaxDMG;
    int defence;
    int accuracy;

};

#endif // ENEMY_H
