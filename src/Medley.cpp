#include "interface/MedleyUI.h"
#include <QApplication>
#include "sound/Player.h"
#include <iostream>

int main(int argc, char* argv[]) {
    Player * player = Player::getInstance();
    player->setSong("/home/mustafa/Music/Cold Blood.mp3");
    player->pause();
    player->setVolume(75);
    QApplication appman(argc, argv);
    MedleyUI medley;
    medley.show();
    return appman.exec();
}