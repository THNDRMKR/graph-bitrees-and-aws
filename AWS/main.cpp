#include "aws.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AWS w;
    w.show();
    return a.exec();
}
