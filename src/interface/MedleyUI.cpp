#include <QtCore/qcoreapplication.h>
#include "MedleyUI.h"
#include "ui_MedleyUI.h"

MedleyUI::MedleyUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MedleyUI) {
    player = Player::getInstance();
    player->setVolume(50);
    ui->setupUi(this);
}

MedleyUI::~MedleyUI() {
    Player::destroyInstance();
    delete ui;
}

void MedleyUI::on_playToggle_clicked() {
    if (!player->isPlaying())
        player->play();
    else
        player->togglePause(); 
}

void MedleyUI::on_actionOpen_triggered() {
    QString file = QFileDialog::getOpenFileName(this,
                                                    tr("Select a Song"),
                                                    "/home/",
                                                    tr("Songs (*.mp3)"));
    if (!file.isNull()) {
        player->stop();
        player->setSong(file.toStdString().c_str());
        player->play();
    }
}

void MedleyUI::on_actionExit_triggered() {
    QCoreApplication::quit();
}

void MedleyUI::on_volumeSlider_valueChanged(int percent) {
    player->setVolume(percent);
}

