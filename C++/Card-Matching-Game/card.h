// Name: Sanaa Otgonbayar
//
// CSCI 3010

#ifndef CARD_H
#define CARD_H

#include <QMainWindow>
#include <QGraphicsRectItem>
#include <QGraphicsItem>

QT_BEGIN_NAMESPACE
namespace Ui { class MatchWindow; }
QT_END_NAMESPACE

class Card : public QObject, public QGraphicsItem{
    Q_OBJECT

public:
    QPixmap p_;
    Card(); // Default Card Constructor
    Card(QPixmap p, const int x, const int y, int id); // Card Constructor with id
    Card(QPixmap p, std::string name,const int id, int points); // Factory Method constructor
    int get_x() const {return x_;}
    int get_y() const {return y_;}
    int get_id() const {return id_;}
    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    bool flipped = false;

private:
    int x_;
    int y_;
    int id_;
    int points_;
    static const int width_ = 100;
    static const int height_ = 150;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget) override;
    int card_num;
    friend bool operator==(const Card &first, const Card &other);

signals:
    void card_selected(Card *c);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent* event) override;\
};

// Factory method 
class CardFactory {
public:
    static Card* DekuCard();
    static Card* GokuCard();
    static Card* NarutoCard();
    static Card* TanjiroCard();
    static Card* JotaroCard();

};
#endif // CARD_H
