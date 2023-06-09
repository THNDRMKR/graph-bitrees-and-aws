#include "hero.h"
#include <QtMath>

Hero::Hero()
{
    DistanceTravelled = 0;
    Name = "Bodya";
    Hp = 0;
    CurHp = Hp;
    Mp = 0;
    CurMp = Mp;
    Level = 0;
    CurEXP = 0;
    MaxEXP = 1000;
    gold = 0;
    this->Defence = 0;
    this->Accuracy = 0;
    this->CurEXP = 0;
    Strength = 0;
    Vitality = 0;
    Intelligence = 0;
    Agility =0;

    StatPoints = 0;
    SkillPoints = 0;

}
Hero::Hero(QString name, int Distance, int gold, int level, int exp,
           int Strength, int Vitality, int Intelligence, int Agility,
           int hp, int mp, int statPoints, int skillPoints)
{
    this->DistanceTravelled = Distance;
    this->Name = name;
    this->Hp = hp;
    this->CurHp = Hp;
    this->Mp = mp;
    this->CurMp = Mp;
    this->Level = level;
    this->gold = gold;
    MaxEXP = 1000;
    this->Defence = 0;
    this->Accuracy = 0;
    this->CurEXP = exp;
    this->Strength = Strength;
    this->Vitality = Vitality;
    this->Intelligence = Intelligence;
    this->Agility =Agility;

    this->StatPoints = statPoints;
    this->SkillPoints = skillPoints;
    this->UpdateStats();

}
Hero::Hero(const Hero& a)
{
    DistanceTravelled = a.DistanceTravelled;
    Name = a.Name;
    Hp = a.Hp;
    CurHp= a.CurHp;
    Mp = a.Mp;
    this->Defence =a.Defence;
    this->Accuracy = a.Accuracy;
    Level = a.Level;
    gold = a.gold;
    CurEXP = a.CurEXP;
    MaxEXP = a.MaxEXP;
    Strength = a.Strength;
    Vitality = a.Vitality;
    Intelligence = a.Intelligence;
    Agility =a.Agility;

    StatPoints = a.StatPoints;
    SkillPoints = a.SkillPoints;
}
//инициализация персонажа, при старте новой партии
void Hero::Initialize(QString name)
{
    DistanceTravelled = 0;
    Name = name;

    this->Strength = 5;
    this->Vitality = 5;
    this->Intelligence = 5;
    this->Agility =5;

    gold = 100;

    this->weapon = Weapon(1,2,"Sword");
    this->armor_chest = Armory(1,2, "Leather jacket");
    this->armor_head = Armory(2,2, "Iron opened helmet");
    this->armor_legs = Armory(3,2, "Iron sabatons");
    this->armor_arms = Armory(4,2, "Iron gauntlets");
    this->Level = 1;
    MaxEXP = 1000;
    this->Hp = this->Level*3+(this->Strength*2) +(this->Vitality*3)-2;
    this->CurHp = Hp;
    this->Mp = this->Agility+this->Intelligence*2;
    this->CurMp = Mp;
    this->MaxDMG = this->Strength+this->Agility/2 + this->weapon.GetMaxDMG();
    this->MinDMG = this->Strength + this->weapon.GetMinDMG();;
    this->Defence = this->Agility + this->Intelligence/2 + this->armor_chest.GetDefence()+
            this->armor_head.GetDefence() +this->armor_arms.GetDefence() +this->armor_legs.GetDefence();
    this->Accuracy = this->Agility*2 + this->Intelligence;
    this->CurEXP = 0;

    this->StatPoints = 0;
    this->SkillPoints = 0;

}

Hero::~Hero()
{
}
//автоматическое повышение уровня персонажа
void Hero::LvlUp()
{
    while(CurEXP>=MaxEXP)
    {
        CurEXP -= MaxEXP;
        Level++;
        MaxEXP = 700;
        this->Strength += 2;
        this->Vitality  += 1;
        this->Intelligence += 1;
        this->Agility += 2;
        this->Hp = this->Level*3+(this->Strength*2) +(this->Vitality*3)-2;
        this->CurHp = Hp;
        this->Mp = this->Agility+this->Intelligence*2;
        this->CurMp = Mp;

        this->StatPoints++;
        this->SkillPoints++;
    }
}
//обновление характеристик персонажа, необходимое для стабильной работы некоторых функций
void Hero::UpdateStats()
{
    this->Hp = this->Strength/2 +this->Vitality*2;
    this->CurHp = Hp;
    MaxEXP = 1000;
    this->Mp = this->Agility+this->Intelligence*2;
    this->CurMp = Mp;
    this->MaxDMG = this->Strength+this->Agility/2;
    this->MinDMG = this->Strength;
    this->Defence = this->Agility + this->Intelligence/2;
    this->Accuracy = this->Agility*2 + this->Intelligence;
}
//преобразование полей класса в строку для будущего вывода в файл сохранения
QString Hero::GetAsString() const
{
    return Name+ " "+ QString::number(DistanceTravelled)+ " " +QString::number(Level)+" " +QString::number(CurEXP)+" " +QString::number(Strength)+
            " " +QString::number(Vitality)+" " +QString::number(Agility)+" " +QString::number(Intelligence)+
            " " +QString::number(Hp)+" " +QString::number(Mp)+" " +QString::number(StatPoints)+
            " " +QString::number(SkillPoints)+" "+QString::number(gold);
}
