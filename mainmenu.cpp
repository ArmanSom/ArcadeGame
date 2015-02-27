//Arman Farhangi
//January 30, 2015
// Kamehameha Attack!
//grid-based game

#include "mainmenu.h"
#include <QLabel>
#include <QHBoxLayout>
#include <QRadioButton>
#include <QHBoxLayout>
#include <QButtonGroup>
#include "game.h"
#include "player.h"
#include "enemies.h"


//creates the main window
MainMenu::MainMenu(QWidget*)
{
    //Title of game
    QLabel* heading = new QLabel("<h1>KAMEHAMEHA ATTACK!</h1>");
    heading->setAlignment(Qt::AlignCenter);

    //Choose character instruction
    QLabel* pick_char = new QLabel("<h2>Pick your character:</h2>");
    pick_char->setAlignment(Qt::AlignCenter);

    //Character select images
    QLabel* goku_label = new QLabel;
    QString fileName(":/Images/Goku_select.png");
    QPixmap* goku_image = new QPixmap(fileName);
    goku_label->setPixmap(*goku_image);
    QLabel* hercule_label = new QLabel;
    fileName = ":/Images/Hercule_select.png";
    QPixmap* hercule_image = new QPixmap(fileName);
    hercule_label->setPixmap(*hercule_image);
    QLabel* saiyaman_label = new QLabel;
    fileName = ":/Images/Saiyaman_select.png";
    QPixmap* saiyaman_image = new QPixmap(fileName);
    saiyaman_label->setPixmap(*saiyaman_image);
    QHBoxLayout* char_images = new QHBoxLayout;
    char_images->addWidget(goku_label);
    char_images->addWidget(hercule_label);
    char_images->addWidget(saiyaman_label);
    char_images->setAlignment(Qt::AlignCenter);

    //Character select buttons
    QRadioButton* goku_button = new QRadioButton("Goku");
    QRadioButton* hercule_button = new QRadioButton("Hercule");
    QRadioButton* saiyaman_button = new QRadioButton("Saiyaman");
    QHBoxLayout* char_buttons = new QHBoxLayout;
    char_buttons->addWidget(goku_button);
    char_buttons->addWidget(hercule_button);
    char_buttons->addWidget(saiyaman_button);
    char_buttons->setAlignment(Qt::AlignCenter);
    //So char buttons don't share toggle with difficulty select
    QButtonGroup* char_select = new QButtonGroup;
    char_select->addButton(goku_button);
    char_select->addButton(hercule_button);
    char_select->addButton(saiyaman_button);

    //Select difficulty text
    QLabel* choose_difficulty = new QLabel("<h2>Choose Difficulty:</h2>");
    choose_difficulty->setAlignment(Qt::AlignCenter);

    //Difficulty select buttons
    QRadioButton* easy = new QRadioButton("Human");
    QRadioButton* medium = new QRadioButton("Saiyan");
    QRadioButton* hard = new QRadioButton("Super Saiyan");
    QVBoxLayout* difficulties = new QVBoxLayout;
    difficulties->addWidget(easy);
    difficulties->addWidget(medium);
    difficulties->addWidget(hard);
    difficulties->setAlignment(Qt::AlignCenter);
    //So difficulty buttons don't share toggle with char buttons
    QButtonGroup* difficulty_select = new QButtonGroup;
    difficulty_select->addButton(easy);
    difficulty_select->addButton(medium);
    difficulty_select->addButton(hard);

    //BATTLE! button
    battle = new QPushButton("BATTLE!");

    //Organizing all the previous elements vertically
    QVBoxLayout* vlay = new QVBoxLayout;
    vlay->addWidget(heading);
    vlay->addWidget(pick_char);
    vlay->addLayout(char_images);
    vlay->addLayout(char_buttons);
    vlay->addWidget(choose_difficulty);
    vlay->addLayout(difficulties);
    vlay->addWidget(battle);

    //Set organized elements to the menu window
    this->setLayout(vlay);

    QObject::connect(hercule_button, SIGNAL(clicked()), this, SLOT(hercule_set()));
    QObject::connect(saiyaman_button, SIGNAL(clicked()), this, SLOT(saiyaman_set()));
}

void MainMenu::hercule_set()
{
    character = 1;
}

void MainMenu::saiyaman_set()
{
    character = 2;
}

//slot that starts the game after player clicks BATTLE!
void MainMenu::new_game()
{
    QGraphicsView* view = new QGraphicsView;
    //create the scene (which is the abstract graphic space)
    QGraphicsScene* scene = new QGraphicsScene;
    //create the player, a graphic item
    Player* player = new Player(character);
    scene->addItem(player);
    //set scene and its items into the view
    view->setScene(scene);
    //to set focus on player item automatically
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    //no scroll bars
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //Set sizes of scene(abstract space for graphic objects) and view (what user actually sees)
    view->setFixedSize(657, 670);
    scene->setSceneRect(56, 0, 657, 670); //specific numbers so I could perfectly fit view/scene to background

    //background
    scene->setBackgroundBrush(QBrush(QImage(":/Images/background.png")));

    //spawn enemies
    Enemy* top_enemy1 = new Enemy(player, -10);
    Enemy* top_enemy2 = new Enemy(player, -10);
    Enemy* bottom_enemy1 = new Enemy(player, 590);
    Enemy* bottom_enemy2 = new Enemy(player, 590);
    scene->addItem(top_enemy1);
    scene->addItem(top_enemy2);
    scene->addItem(bottom_enemy1);
    scene->addItem(bottom_enemy2);

    view->show();
}
