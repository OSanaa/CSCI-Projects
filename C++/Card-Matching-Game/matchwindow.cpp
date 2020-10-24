// Name: Sanaa Otgonbayar
//
// CSCI 3010

#include "matchwindow.h"
#include "ui_matchwindow.h"
#include <QPixmap>
#include <QMouseEvent>
#include <QLabel>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QDebug>
#include <QTime>
#include <QTimer>
#include <vector>
#include <iostream>
#include <string>

#include "card.h"

std::vector<Card*> cards;

void delay(){
    QTime dieTime= QTime::currentTime().addSecs(2);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

MatchWindow::MatchWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MatchWindow)
{
    ui->setupUi(this);
    qsrand(static_cast<unsigned>(QTime::currentTime().msec()));
    QGraphicsView * view = ui -> graphicsView;
    scene = new QGraphicsScene;
    view -> setScene(scene);
    view -> setSceneRect(0,0,view->frameSize().width(),view->frameSize().height());
    QPixmap pix("/Users/sanaa/Desktop/Homework_5-master/card_back.png");
    QPixmap natsu("/Users/sanaa/Desktop/Homework_5-master/natsu_card.png");
    QPixmap ichigo("/Users/sanaa/Desktop/Homework_5-master/ichigo_card.jpg");

    count = 0;
    card1_index = 0;
    card2_index = 0;
    game_over = 0;
    player1_score = 0;
    player2_score = 0;
    turn_count = 2;
    int i = 15;
    while(i < frameSize().width() && cards.size() != 24){
        Card *c = new Card(pix, i, 15, 0);
        cards.push_back(c);
        Card *c2 = new Card(pix, i, 185, 0);
        cards.push_back(c2);
        Card *c3 = new Card(pix, i, 355, 0);
        cards.push_back(c3);
        scene -> addItem(c);
        scene -> addItem(c2);
        scene -> addItem(c3);
        i = i + 120;
    }
    for(int j = 0; j < cards.size(); j++){
        connect(cards[j], &Card::card_selected, this, &MatchWindow::card_selectedSlot);
    }
}


void MatchWindow::card_selectedSlot(Card *c){
    count++;
    for(int i = 0; i < cards.size(); i++){
        if(cards[i]->get_x() == c->get_x() && cards[i]->get_y() == c->get_y()){
            cards[i] = c;
            cards[i]->flipped = true;
            if(card1_index == 0){
                card1_index = i;
            }
            else{
                card2_index = i;
            }
        }
    }

    if(count == 2){
        count = 0;
        qDebug() << "Indexes: " << card1_index << card2_index;
        delay();
        game_time(card1_index, card2_index);
    }
}

void MatchWindow::prompt_card_text(int id1){
    if(id1 == 2){
        std::string prompted2 = "LEGENDARY DEKU HAS BEEN MATCHED";
        QString prompted2_(prompted2.c_str());
        ui->card_label->setText(prompted2_);
        std::string val2 = "Card Worth: 2";
        QString val2_(val2.c_str());
        ui->cardVal_label->setText(val2_);
    }
    if(id1 == 3){
        std::string prompted3 = "Naruto has been matched";
        QString prompted3_(prompted3.c_str());
        ui->card_label->setText(prompted3_);
        std::string val3 = "Card Worth: 1";
        QString val3_(val3.c_str());
        ui->cardVal_label->setText(val3_);
    }
    if(id1 == 4){
        std::string prompted4 = "Goku has been matched";
        QString prompted4_(prompted4.c_str());
        ui->card_label->setText(prompted4_);
        std::string val4 = "Card Worth: 1";
        QString val4_(val4.c_str());
        ui->cardVal_label->setText(val4_);
    }
    if(id1 == 5){
        std::string prompted5 = "Tanjiro has been matched";
        QString prompted5_(prompted5.c_str());
        ui->card_label->setText(prompted5_);
        std::string val5 = "Card Worth: 1";
        QString val5_(val5.c_str());
        ui->cardVal_label->setText(val5_);
    }
    if(id1 == 6){
        std::string prompted6 = "jotaro";
        QString prompted6_(prompted6.c_str());
        ui->card_label->setText(prompted6_);
        std::string val6 = "Card Worth: 1";
        QString val6_(val6.c_str());
        ui->cardVal_label->setText(val6_);
    }
}

// game_time(int index, int index2)
// Calls prompt_card_text() given the players selection and increases the points based on the
// index of the card. If Deku card is matched, player gains 2 points compared to normal cards,
// which only gain 1 point.

void MatchWindow::game_time(int index, int index2){
    // CardFactory of specific cards
    Card *deku = CardFactory::DekuCard();
    Card *goku = CardFactory::GokuCard();
    Card *naruto = CardFactory::NarutoCard();
    Card *tanjiro= CardFactory::TanjiroCard();
    Card *jotaro = CardFactory::JotaroCard();
    card1_index = 0;
    card2_index = 0;
    QPixmap pix("/Users/sanaa/Desktop/Homework_5-master/card_back.png");
    qDebug() << cards[index]->get_id() << " " << "Deku ID: " << deku->get_id();
    if(cards[index]->get_id() == cards[index2]->get_id()){
        qDebug() << "Removed" << cards[index]->get_id() << cards[index2]->get_id();
        game_over++;
        if(turn_count % 2 == 0){
            if (cards[index]->get_id() == deku->get_id()){
                player1_score = player1_score + 2;
                std::string p1 = "Player 1: " + std::to_string(player1_score) + " Points";
                QString ps1(p1.c_str());
                ui->player1->setText(ps1);
                prompt_card_text(cards[index]->get_id());
            }
            else{
                player1_score++;
                std::string p1 = "Player 1: " + std::to_string(player1_score) + " Points";
                QString ps1(p1.c_str());
                ui->player1->setText(ps1);
                prompt_card_text(cards[index]->get_id());
            }
        }
        else{
            if (cards[index]->get_id() == deku->get_id()){
                player2_score = player2_score + 2;
                std::string p2 = "Player 2: " + std::to_string(player2_score) + " Points";
                QString ps2(p2.c_str());
                ui->player2->setText(ps2);
                prompt_card_text(cards[index]->get_id());
            }
            else{
                player2_score++;
                std::string p2 = "Player 2: " + std::to_string(player2_score) + " Points";
                QString ps2(p2.c_str());
                ui->player2->setText(ps2);
                prompt_card_text(cards[index]->get_id());
            }
        }
        scene -> removeItem(cards[index]);
        scene -> removeItem(cards[index2]);
    }
    else if(cards[index]->get_id() != cards[index2]->get_id()){
        scene -> removeItem(cards[index]);
        scene -> removeItem(cards[index2]);
        cards[index]->p_ = (pix);
        cards[index2]->p_ = (pix);
        cards[index]->flipped == false;
        cards[index2]->flipped == false;
        scene -> addItem(cards[index]);
        scene -> addItem(cards[index2]);
        qDebug() << "Stays" << cards[index]->get_id() << cards[index2]->get_id();
    }

    if(turn_count % 2 == 0){
        ui->turn->setText("Turn: Player 2");
        turn_count++;
    }
    else{
        ui->turn->setText("Turn: Player 1");
        turn_count++;
    }

    if(game_over == 12){
        if(player1_score > player2_score){
            scene -> addText("Player 1 Wins!\n");
        }
        else if(player1_score == player2_score){
            scene -> addText("It was a tie! Play again?\n");
        }
        else if(player1_score < player2_score){
            scene -> addText("Player 2 Wins!\n");
        }
    }
}

MatchWindow::~MatchWindow()
{
    delete ui;
}

