#ifndef AWS_H
#define AWS_H

#include <QMainWindow>
#include <cmath>

#include <hero.h>
#include <QWidget>
#include <QObject>
#include <QString>
#include <QPushButton>
#include <QVector>
#include <QFile>
#include <QDir>
#include <QTextStream>
#include <enemy.h>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class AWS; }
QT_END_NAMESPACE

class AWS : public QMainWindow
{
    Q_OBJECT

public:
    AWS(QWidget *parent = nullptr);
    ~AWS();

private:
    Ui::AWS *ui;
public:
    Hero Character;
    Inventory inv;
    QString savename;
    QTimer timer;
    QRandomGenerator qr;
    void DisplayMenu();
    void DisplayCharacterSheet();
    void DisplayInventory();
    void Travel(int choice);
    void EnemyEncounter(Enemy en);
public slots:
    void StartMenu();
    void MainMenu();
    void StartParty();
    void SaveCharacter();
    void LoadCharacter();
};
#endif // AWS_H
