//Arman Farhangi
//January 30, 2015
// Kamehameha Attack!
//grid-based game

#ifndef MAINMENU
#define MAINMENU

#include <QWidget>
#include <QPushButton>
#include <QObject>
#include <QString>
#include <QGraphicsView>
#include <QGraphicsScene>
#include "player.h"

/**
 * @brief Contains main menu, battle screen, lose menu, and win screen functionality
 */
class Game : public QWidget {
    Q_OBJECT
public:
    Game(QWidget* parent=0);
    int enemy_count;
    int wave_count;
    int character;
    int difficulty;
    QGraphicsView* view;
    QGraphicsScene* scene;
    void game_over();
    Player* player;
    bool speed_out;
    bool burst_out;
    QTimer* check_powerups_timer;
    QTimer* powerup_speed_timer;
    QTimer* powerup_burst_timer;
    bool player_dead;
public slots:
    void goku_set();
    void hercule_set();
    void saiyaman_set();
    void easy_set();
    void medium_set();
    void hard_set();
    void start_battle();
    void show_instructions();
    void new_wave_or_win();
    void check_powerups();
    void spawn_speed_powerup();
    void spawn_burst_powerup();
};

#endif // MAINMENU

