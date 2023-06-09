#include "aws.h"
#include "ui_aws.h"


AWS::AWS(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::AWS)
{
    inv.initialize();
    inv.addItem(Weapon(1,2,"Sword"));
    QFont textfont = QFont();
    textfont.setPointSize(12);
    ui->setupUi(this);
    ui->MainPlain->insertPlainText("Do you wish to:\n"
                                   "1. start new game\n"
                                   "2. load old one");
    this->setMinimumSize(800,600);
    ui->MainPlain->setFont(textfont);
    ui->pushButton->setText(tr("Enter"));
    ui->pushButton->setFont(textfont);
    ui->pushButton->setStyleSheet("QPushButton:selected, QPushButton:hover{background-color: rgb(37,109,165); color: White;} "
                                  "QPushButton:pressed{background-color: rgb(48,146,220);} "
                                  "QPushButton{height: 30px; width: 30px; background-color: lightBlue; border-right, border-bottom: 4px solid Gray;}");
    connect(ui->pushButton,&QPushButton::clicked,this,&AWS::StartMenu);
}

AWS::~AWS()
{
    delete ui;
}
//Стартовое меню
void AWS::StartMenu()
{
    if(ui->plainEdit->toPlainText()==QString("1"))
    {
        ui->MainPlain->clear();
        ui->MainPlain->insertPlainText("On starful lately night You enter the tavern full of young adventurers like you. A stunted old man with threatening aura makes a speech:\n'According to an ancient legend,"
                                       " one day when the evil race of Ulva from underground catacombs will try to interrupt our peace, the Hero of great destiny shall arise and save us!' Lately when everyone left tavern in seek of their destiny he sees you\n"
                                       "'I feel something strange about your path. What is your name adventurer?'");
        disconnect(ui->pushButton,&QPushButton::clicked,this,&AWS::StartMenu);
        connect(ui->pushButton,&QPushButton::clicked,this,&AWS::StartParty);
    }
    else if(ui->plainEdit->toPlainText()==QString("2"))
    {
        LoadCharacter();
        ui->MainPlain->clear();
        DisplayMenu();
        disconnect(ui->pushButton,&QPushButton::clicked,this,&AWS::StartMenu);
        connect(ui->pushButton,&QPushButton::clicked,this,&AWS::MainMenu);
    }
    else ui->MainPlain->insertPlainText("Type right answer!");
    ui->plainEdit->clear();
}
//Начало новой партии
void AWS::StartParty()
{
    if(ui->plainEdit->toPlainText().length()!=0)
    {
        Character.Initialize(ui->plainEdit->toPlainText());
        disconnect(ui->pushButton,&QPushButton::clicked,this,&AWS::StartParty);
        connect(ui->pushButton,&QPushButton::clicked,this,&AWS::MainMenu);
        ;
        DisplayMenu();
    }
    else
    {
        ui->MainPlain->setPlainText("Type name correctly!");
    }
}
//фцнкциональная часть основного меню
void AWS::MainMenu()
{
    if(ui->plainEdit->toPlainText()==QString("1"))DisplayCharacterSheet();
    if(ui->plainEdit->toPlainText()==QString("2")){qr.bounded(1,100);Travel(qr.generate()%100);}
    if(ui->plainEdit->toPlainText()==QString("3")){;}
    if(ui->plainEdit->toPlainText()==QString("4")) DisplayInventory();
    if(ui->plainEdit->toPlainText()==QString("5")) {LoadCharacter();}
    if(ui->plainEdit->toPlainText()==QString("6")) SaveCharacter();
    if(ui->plainEdit->toPlainText()==QString("9")) this->close();
    DisplayMenu();
}
//вывод основного меню
void AWS::DisplayMenu()
{
    if(Character.GetExp()>Character.GetMaxExp())ui->MainPlain->insertPlainText("LEVEL UP IS AVAILABLE\n");
    ui->MainPlain->insertPlainText("==MAIN MENU==\n"
                                   "1: Character Sheet\n"
                                   "2: Travel\n"
                                   "3: Shop\n"
                                   "4:Rest\n"
                                   "5:Load\n"
                                   "6:Save\n"
                                   "9:Quit\n");
    ui->plainEdit->clear();
}
//Вывод листа персонажа
void AWS::DisplayCharacterSheet()
{
    ui->MainPlain->clear();
    ui->MainPlain->insertPlainText("==Hero Info==\n==Name: "
                                   + Character.GetName() +" ==\n"+
                                   "==Level: "
                                   + QString::number(Character.GetLvl())+" ==\n"
                                                                         "==Hp: "
                                   + QString::number(Character.GetCurHp())+"/"+QString::number(Character.GetMaxHp()) + "==\n"
                                                                                                                       "==Mp "
                                   + QString::number(Character.GetCurMp())+"/"+QString::number(Character.GetMaxMp()) + "==\n"
                                                                                                                       "==Current Exp: "
                                   + QString::number(Character.GetExp())+" ==\n"
                                                                         "==Exp to the next Level: "
                                   + QString::number(Character.GetMaxExp()-Character.GetExp())+" ==\n"
                                                                                               "==Damage(Min/Max): "
                                   + QString::number(Character.GetMinDMG())+"/" + QString::number(Character.GetMaxDMG()) + " ==\n"
                                                                                                                           "==Defence: "
                                   + QString::number(Character.GetDefence())+" ==\n"
                                                                             "==Accuracy: "
                                   + QString::number(Character.GetAccuracy())+" ==\n"
                                                                              "==Strength: "
                                   + QString::number(Character.GetStrength())+" ==\n"
                                                                              "==Intelligence: "
                                   + QString::number(Character.GetIntelligence())+" ==\n"
                                                                                  "==Vitality: "
                                   + QString::number(Character.GetVitality())+" ==\n"
                                                                              "==Agility: "
                                   + QString::number(Character.GetAgility())+" ==\n"
                                                                             "==StatPoints: "
                                   + QString::number(Character.GetStatPoints())+" ==\n"
                                                                                "==SkillPoints: "
                                   + QString::number(Character.GetSkillPoints())+" ==\n" + "==============\n\n"
                                   );

    ui->plainEdit->clear();
}
//вывод инвенторя персонажа и надетого снаряжения
void AWS::DisplayInventory()
{
    ui->MainPlain->clear();
    ui->MainPlain->insertPlainText("You have in your inventory:\n");
    this->inv.debugPrint(ui->MainPlain);
    ui->MainPlain->insertPlainText("You hold your " + this->Character.GetWeaponName() +
                                   ". You wear " + this->Character.GetChestName() + " on your chest, "
                                   + this->Character.GetHeadName() + " on your head, " + this->Character.GetArmsName() +
                                   " on your arms, " + this->Character.GetLegsName() + "\n");
}
//Сохрание в файл
void AWS::SaveCharacter()
{


    QFile file("./save.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;

    QTextStream out(&file);

    out << this->Character.GetAsString() << "\n";
}
//Загрузка из файла
void AWS::LoadCharacter()
{
    QString name="";
    int Distance=0;
    int gold=0;
    int level=0;
    int exp=0;
    int strength=0;
    int vitality=0;
    int intelligence=0;
    int agility=0;
    int hp=0;
    int mp=0;
    int statPoints=0;
    int skillPoints=0;
    QFile file("./save.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream in(&file);
    while(!file.atEnd())
    {
        in >> name;
        in >> Distance;
        in >> level;
        in >> exp;
        in >> strength;
        in >> vitality;
        in >> agility;
        in >> intelligence;
        in >> hp;
        in >> mp;
        in >> statPoints;
        in >> skillPoints;
        in >> gold;
        Hero temp(name,Distance,gold,level,exp,strength,vitality,intelligence,agility,hp,mp,statPoints,skillPoints);
        this->Character = temp;
    }
}
//"Путешествие". Возможность встретить врагов или встретить случайные события, происходящие в мире
void AWS::Travel(int choice)
{

    if(choice>=95)
    {EnemyEncounter(Enemy(rand()%11+this->Character.GetLvl()+5,"Ulva general"));}
    else if(choice >= 80)
    {EnemyEncounter(Enemy(rand()%8+this->Character.GetLvl()+2,"Ulva warrior"));}
    else if(choice >= 60)
        { EnemyEncounter(Enemy(rand()%6+this->Character.GetLvl()+2,"Ulva miner"));}
    else if(choice >= 30)
         {EnemyEncounter(Enemy(rand()%4+this->Character.GetLvl()+1,"Ulva farmer"));}
    else
        { EnemyEncounter(Enemy(rand()%3+1+this->Character.GetLvl()-1,"Ulva worker"));}

}
//Встреча врага и бой с ним
void AWS::EnemyEncounter(Enemy en)
{
    ui->MainPlain->clear();

    ui->MainPlain->insertPlainText("You've met " + en.GetName() + " and he's really angry\n");
    ui->MainPlain->insertPlainText(en.GetAsString());
    int cooldown = rand()%2;
    while(en.isAlive() && this->Character.GetCurHp()>0)
    {
        int HeroDMG = rand()%(this->Character.GetMaxDMG()-this->Character.GetMinDMG()+1)+this->Character.GetMinDMG();
        int skillDMG = HeroDMG*(10/(this->Character.GetStrength()+this->Character.GetIntelligence()));
        if(cooldown>0)
        {
            en.takeDamage(HeroDMG);
            ui->MainPlain->insertPlainText("You strike with your weapon: dealt " + QString::number(HeroDMG) + " damage. enemy's left hp" + QString::number(en.getHp()) + "\n");
        }
        else
        {
            en.takeDamage(skillDMG);
            ui->MainPlain->insertPlainText("Your weapon lights up with blue flame: dealt " + QString::number(skillDMG) + " damage enemy's left hp" + QString::number(en.getHp()) + "\n");
            cooldown = 2;
        }
        if(en.isAlive()) this->Character.takeDamage(en.getDamage());
        ui->MainPlain->insertPlainText(en.GetName() + " deals " + QString::number(en.getDamage()) + " damage\n");
        cooldown--;
    }
    //В случае победы персонажу начисляются: опыт, золото, снаяряжение
    if(this->Character.GetCurHp()>0)
    {
        int EXP = 100*(10+en.getLevel()-this->Character.GetLvl())/(10+this->Character.GetLvl());
        ui->MainPlain->insertPlainText("You win!!! left hp" + QString::number(Character.GetCurHp()) + "/" + QString::number(Character.GetMaxHp())+"\nThe Goddess heals your wounds, now you have maximum HP\nYou got " + QString::number(EXP) + " exp\n");
        this->Character.GainExp(EXP);
        this->Character.LvlUp();
        this->Character.GainGold(en.getLevel()*15);
        this->Character.Blessing();
    }
    else
    {
        ui->MainPlain->insertPlainText("You lost, but Goddess won't let you die! Seek you destiny and try to improve\n");
        this->Character.Blessing();
    }
}
