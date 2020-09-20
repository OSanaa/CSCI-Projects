// Name: Sanaa Otgonbayar
//
// CSCI 3010

#ifndef MATCHWINDOW_H
#define MATCHWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include <QMouseEvent>
#include <QLabel>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QDebug>
#include <QTime>
#include "card.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MatchWindow; }
QT_END_NAMESPACE

class MatchWindow : public QMainWindow
{
    Q_OBJECT

public:
    MatchWindow(QWidget *parent = nullptr);
    ~MatchWindow();

    void prompt_card_text(int id1);
    void game_time(int index1, int index2);

    int count;
    int game_over;
    int player1_score;
    int player2_score;
    int turn_count;

private slots:
    void card_selectedSlot(Card * c);

private:
    QGraphicsScene *scene;
    Ui::MatchWindow *ui;
    int card1_index;
    int card2_index;
};
#endif // MATCHWINDOW_H
