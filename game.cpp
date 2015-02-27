//Arman Farhangi
//January 30, 2015
// Kamehameha Attack!
//grid-based game

#include "game.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include "player.h"
#include "enemies.h"


Game::Game(QWidget*)
{
    //create the scene (which is the abstract graphic space)
    QGraphicsScene* scene = new QGraphicsScene;
    //create the player, a graphic item
    Player* player = new Player();
    scene->addItem(player);
    //set scene and its items into the view
    this->setScene(scene);
    //to set focus on player item automatically
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    //no scroll bars
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //Set sizes of scene(abstract space for graphic objects) and view (what user actually sees)
    this->setFixedSize(657, 670);
    scene->setSceneRect(56, 0, 657, 670); //specific numbers so I could perfectly fit view/scene to background

    //background
    scene->setBackgroundBrush(QBrush(QImage(":/Images/background.png")));

    //set initial player position
    player->setPos(340, 270);

    //spawn enemies
    Enemy* top_enemy1 = new Enemy(player, -10);
    Enemy* top_enemy2 = new Enemy(player, -10);
    Enemy* bottom_enemy1 = new Enemy(player, 590);
    Enemy* bottom_enemy2 = new Enemy(player, 590);
    scene->addItem(top_enemy1);
    scene->addItem(top_enemy2);
    scene->addItem(bottom_enemy1);
    scene->addItem(bottom_enemy2);
}
