#include "matchwindow.h"
#include "ui_matchwindow.h"
#include "card.h"
#include "player.h"
#include <QPixmap>
#include <QDebug>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iostream>
#include <QtWidgets>

Player::Player(int score, int turn, bool match)
{
    score_ = score;
    turn_ = turn;
    match_ = match;
}
