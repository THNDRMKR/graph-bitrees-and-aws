#ifndef HERO_H
#define HERO_H
#include <QString>
#include <inventory.h>
#include <QRandomGenerator>

class Hero
{
public:
    Hero();
    Hero(QString name, int Distance, int gold, int level, int exp,
             int Strength, int Vitality, int Intelligence, int Agility,
             int hp, int stamina, int statPoints, int skillPoints);
    Hero(const Hero& a);
    void Initialize(QString name);
    ~Hero();
    void LvlUp();
    QString GetAsString() const;
    void GainExp(const int& a) {this->CurEXP+=a;}
    void GainGold(const int& a) {this->gold+=a;}
    void UpdateStats();
    inline void takeDamage(int a) {this->CurHp-=a;}
    inline void Blessing() {this->CurHp=Hp;}
    int Attack(){return rand()%(this->MaxDMG-this->MinDMG+1)+this->MinDMG;}
    int SkillAttack(){return Attack()*(10/(this->Strength+this->Intelligence));}
    void SkillUse(){this->CurMp-=2;}

    inline const QString& GetName() {return this->Name;}
    inline const QString& GetWeaponName() {return this->weapon.GetName();}
    inline const QString& GetChestName() {return this->armor_chest.GetName();}
    inline const QString& GetHeadName() {return this->armor_head.GetName();}
    inline const QString& GetArmsName() {return this->armor_arms.GetName();}
    inline const QString& GetLegsName() {return this->armor_legs.GetName();}
    inline const int& GetDistTravelled(){return this->DistanceTravelled;}
    inline const int& GetLvl(){return this->Level;}
    inline const int& GetExp(){return this->CurEXP;}
    inline const int& GetMaxExp(){return this->MaxEXP;}
    inline const int& GetCurHp(){return this->CurHp;}
    inline const int& GetMaxHp(){return this->Hp;}
    inline const int& GetMaxMp(){return this->Mp;}
    inline const int& GetCurMp(){return this->CurMp;}
    inline const int& GetMaxDMG(){return this->MaxDMG;}
    inline const int& GetMinDMG(){return this->MinDMG;}
    inline const int& GetDefence(){return this->Defence;}
    inline const int& GetAccuracy(){return this->Accuracy;}
    inline const int& GetStrength(){return this->Strength;}
    inline const int& GetIntelligence(){return this->Intelligence;}
    inline const int& GetVitality(){return this->Vitality;}
    inline const int& GetAgility(){return this->Agility;}
    inline const int& GetStatPoints(){return this->StatPoints;}
    inline const int& GetSkillPoints(){return this->SkillPoints;}


     inline void SetName(QString name) {this->Name=name;}
     inline void SetDistTravelled(int a) {this->DistanceTravelled=a;}
     inline void Travel() {this->DistanceTravelled++;}
     inline void SetLevel(int a) {this->Level=a;}
     inline void SetExp(int a) {this->CurEXP=a;}
     inline void SetMaxExp(int a) {this->MaxEXP=a;}
     inline void SetStrength(int a) {this->Strength=a;}
     inline void SetIntelligence(int a) {this->Intelligence=a;}
     inline void SetVitality(int a) {this->Vitality=a;}
     inline void SetAgility(int a) {this->Agility=a;}
     inline void SetStatPoints(int a) {this->StatPoints=a;}
     inline void SetSkillPoints(int a) {this->SkillPoints=a;}

protected:
    int DistanceTravelled;

    Inventory inventory;
    Weapon weapon;
    Armory armor_chest;
    Armory armor_arms;
    Armory armor_head;
    Armory armor_legs;

    QString Name;
    int Hp, CurHp, Mp, CurMp;

    int gold;

    int MaxDMG, MinDMG;
    int Defence;
    int Accuracy;

    int Level;
    int CurEXP, MaxEXP = 1000;

    int Strength;
    int Vitality;
    int Intelligence;
    int Agility;

    int StatPoints;
    int SkillPoints;
};

#endif // HERO_H
