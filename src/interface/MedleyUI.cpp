#include <QtCore/qcoreapplication.h>
#include "MedleyUI.h"
#include "ui_MedleyUI.h"

MedleyUI::MedleyUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MedleyUI) {
    player = Player::getInstance();
    player->setVolume(50);
    ui->setupUi(this);
    initConnections();
}

MedleyUI::~MedleyUI() {
    player->stop();
    Player::destroyInstance();
    delete ui;
}

void MedleyUI::initConnections() {
    updateTimer = new QTimer(this);
    connect(updateTimer, SIGNAL(timeout()), this, SLOT(updateGUI()));
    updateTimer->start(1000);

    connect(ui->noteworthyBox, SIGNAL(returnPressed()), this, SLOT(callNoteworthy()));
    connect(ui->noteworthyButton, SIGNAL(clicked()), this, SLOT(callNoteworthy()));
}

void MedleyUI::updateGUI() {
    if (!ui->seekSlider->isSliderDown())
        ui->seekSlider->setValue(player->getPercent());
}

void MedleyUI::on_playToggle_clicked() {
    if (!player->isPlaying())
        player->play();
    else
        player->togglePause();
}

void MedleyUI::on_actionOpen_triggered() {
    QString file = QFileDialog::getOpenFileName(this, tr("Select a Song"),
                                                "/home/", tr("Songs (*.mp3)"));
    if (!file.isNull()) {
        ui->seekSlider->setValue(0);
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

void MedleyUI::on_seekSlider_sliderReleased() {
    player->setPercent(ui->seekSlider->value());
}

void MedleyUI::callNoteworthy() {
    // Placeholder until Noteworthy works
    QString query = ui->noteworthyBox->text();
    std::cout << query.toStdString() << std::endl;
}