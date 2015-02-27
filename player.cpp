//Arman Farhangi
//January 30, 2015
// Kamehameha Attack!
//grid-based game

#include "player.h"
#include <QKeyEvent>
#include "beam.h"
#include <QGraphicsScene>
#include "stdlib.h"
#include <QPixmap>
#include "enemies.h"


/********************  GOKU  ********************/

Player::Player()
{
    //creates player
        setPixmap(QPixmap(":/Images/goku_stand.png"));
}

void Player::keyPressEvent(QKeyEvent *event){
    //able to move left as long as top left of Goku is right of platform edge
    if (event->key() == Qt::Key_Left){
        if (x() > 90)
            setPos(x() - 10, y());
    }
    //able to move right as long as top left of goku is left of platform edge
    else if (event->key() == Qt::Key_Right){
        if (x()  < 570)
            setPos(x() + 10, y());
    }
    //able to move up as long as goku is under top platform edge
    else if (event->key() == Qt::Key_Up){ //-10 to go up because y axis is inverted
        if (y() > 50)
            setPos(x(), y() - 10);
    }
    //able to move down as long as goku is above bottom platform edge
    else if (event->key() == Qt::Key_Down){//same reason for down being +10
        if (y() < 510)
            setPos(x(), y() + 10);
    }
    //space will shoot upwards
    else if (event->key() == Qt::Key_Space){
        //create beam, center it on player, and include it to player's/game's scene
        Beam* beam = new Beam;
        beam->setPos(x() + 40, y() - 40);
        scene()->addItem(beam);
    }
}

