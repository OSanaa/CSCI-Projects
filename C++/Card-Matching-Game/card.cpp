// Name: Sanaa Otgonbayar
//
// CSCI 3010

#include "matchwindow.h"
#include "ui_matchwindow.h"
#include "card.h"
#include <QPixmap>
#include <QDebug>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iostream>
#include <QtWidgets>
#include <QEvent>

// Default Card constructor
Card::Card(QPixmap p, const int x, const int y, int id){
    x_ = x;
    y_ = y;
    this->p_ = p;
    id_ = id;
}

// Factory Card Constructor
Card::Card(QPixmap p, std::string name,const int id, int points){
    this->p_ = p;
    id_ = id;
    points_ = points;
}

// When Deku card is matched, player gains 2 points.
Card* CardFactory::DekuCard(){
    QPixmap deku("/Users/sanaa/Desktop/Homework_5-master/deku_card.jpg");
    Card* Deku = new Card(deku,"Deku",2, 2);
    return Deku;
}

Card* CardFactory::GokuCard(){
    QPixmap goku("/Users/sanaa/Desktop/Homework_5-master/goku_card.png");
    Card* Goku = new Card(goku, "Goku", 4, 1);
    return Goku;
}

Card* CardFactory::NarutoCard(){
    QPixmap naruto("/Users/sanaa/Desktop/Homework_5-master/naruto_card.jpg");
    Card* Naruto = new Card(naruto,"Naruto",3, 1);
    return Naruto;
}

Card* CardFactory::TanjiroCard(){
    QPixmap tanjiro("/Users/sanaa/Desktop/Homework_5-master/tanjiro_card.jpg");
    Card* Tanjiro = new Card(tanjiro,"Tanjiro",4,1);
    return Tanjiro;
}

Card* CardFactory::JotaroCard(){
    QPixmap jotaro("/Users/sanaa/Desktop/Homework_5-master/jotaro_card.jpg");
    Card* Jotaro = new Card(jotaro,"Jotaro", 5,1);
    return Jotaro;
}

QRectF Card::boundingRect() const
{
    return QRectF(x_, y_, width_, height_);
}

QPainterPath Card::shape() const
{
    QPainterPath path;
    path.addRect(x_, y_, width_, height_);
    return path;
}

bool operator==(const Card &first, const Card &other) {
  return first.x_ == other.x_ && first.y_ == other.y_;
}

void Card::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);
    QBrush b = painter->brush();
    // update the line for setBrush to be this
    painter->drawRect(QRect(this->x_, this->y_, this->width_, this->height_));
    painter->setBrush(b);
    painter->drawPixmap(QRect(this->x_, this->y_, this->width_, this->height_), p_);
}

void Card::mousePressEvent(QGraphicsSceneMouseEvent* event){
    qsrand(static_cast<unsigned>(QTime::currentTime().msec()));

    QPixmap luffy("/Users/sanaa/Desktop/Homework_5-master/luffy_card.jpg");
    QPixmap deku("/Users/sanaa/Desktop/Homework_5-master/deku_card.jpg");
    QPixmap naruto("/Users/sanaa/Desktop/Homework_5-master/naruto_card.jpg");
    QPixmap goku("/Users/sanaa/Desktop/Homework_5-master/goku_card.png");
    QPixmap tanjiro("/Users/sanaa/Desktop/Homework_5-master/tanjiro_card.jpg");
    QPixmap jotaro("/Users/sanaa/Desktop/Homework_5-master/jotaro_card.jpg");
    QPixmap saitama("/Users/sanaa/Desktop/Homework_5-master/saitama_card.jpg");
    QPixmap natsu("/Users/sanaa/Desktop/Homework_5-master/natsu_card.png");
    QPixmap ichigo("/Users/sanaa/Desktop/Homework_5-master/ichigo_card.jpg");
    QPixmap inuyasha("/Users/sanaa/Desktop/Homework_5-master/inuyasha_card.jpg");
    QPixmap card_back("/Users/sanaa/Desktop/Homework_5-master/card_back.png");

    int r = 0;

    if(event->button() == Qt::LeftButton){
        qDebug() << "left button clicked!";
        r = rand() %  2;
        if(r == 0){
            this -> p_ = deku;
            this -> id_ = 2;
        }
        else if(r == 1){
            this -> p_ = naruto;
            this -> id_ = 3;
        }
        else if(r == 2){
            this -> p_ = goku;
            this -> id_ = 4;
        }
        else if(r == 3){
            this -> p_ = tanjiro;
            this -> id_ = 5;
        }
        else if(r == 4){
            this -> p_ = jotaro;
            this -> id_ = 6;
        }
//        else if(r == 5){
//            this -> p_ = saitama;
//            this -> id_ = 7;
//        }
//        else if(r == 8){
//            this -> p_ = natsu;
//            this -> id_ = 8;
//        }
//        else if(r == 9){
//            this -> p_ = ichigo;
//            this -> id_ = 9;
//        }
//        else if(r == 10){
//            this -> p_ = inuyasha;
//            this -> id_ = 10;
//        }
    }
    update();
    emit card_selected(this);
}
