#include "MedleyUI.h"
#include "ui_MedleyUI.h"

MedleyUI::MedleyUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MedleyUI)
{
    player = Player::getInstance();
    player->setSong("/home/mustafa/Music/a.mp3");
    player->setVolume(50);
    ui->setupUi(this);
}

MedleyUI::~MedleyUI()
{
    Player::destroyInstance();
    delete ui;
}

void MedleyUI::on_playButton_clicked()  {
    if (!player->isPlaying())
        player->play();
    else
        player->togglePause();

}
