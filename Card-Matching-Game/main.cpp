// Name: Sanaa Otgonbayar
//
// CSCI 3010

#include "matchwindow.h"
#include <QPixmap>
#include <QMouseEvent>
#include <QLabel>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MatchWindow w;
    w.show();
    return a.exec();
}
