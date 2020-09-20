#ifndef CELL_H
#define CELL_H

#include <QColor>
#include <QGraphicsItem>

// any object that inherits from QObject can emit signals
// things that inherit from QGraphicsItem can be added to QGraphicScenes
class Player : public QObject, public QGraphicsItem {

    // this makes it so that we can emit signals
    Q_OBJECT

public:
    Player(int score, int turn);  // constructor

    int get_score();  // gets the players score
    int set_score(int score) { score_ = score; }  // sets the players score
    int get_turn() { return turn_; }  // gets the players turn
    int set_turn(int turn) { turn_ = turn; }  // sets the players turn
    int get_match() { return match_; }  // gets match
    int set_match(int match) { match_ = match; }  // sets match

signals:

    //void aliveCell(Cell * c);
    //void deadCell(Cell * c);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

private:
  int score_;
  int turn_;
  bool match_;

  friend bool operator==(const Player &first, const Player &other);
};  // class Player

#endif // Cell_H
