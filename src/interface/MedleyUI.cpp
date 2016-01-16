#include "MedleyUI.h"
#include "ui_MedleyUI.h"

MedleyUI::MedleyUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MedleyUI)
{
    ui->setupUi(this);
}

MedleyUI::~MedleyUI()
{
    Player::destroyInstance();
    delete ui;
}

void MedleyUI::on_playButton_clicked()  {
    player = Player::getInstance();
    player->togglePause();
}
