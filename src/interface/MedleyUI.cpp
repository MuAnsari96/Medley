#include <QtCore/qcoreapplication.h>
#include "MedleyUI.h"
#include "ui_MedleyUI.h"

MedleyUI::MedleyUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MedleyUI) {
    player = Player::getInstance();
    player->stop();
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

    connect(ui->actionExit, SIGNAL(triggered()), this, SLOT(quit()));
    connect(ui->actionOpen, SIGNAL(triggered()), this, SLOT(open()));

    connect(ui->actionMute, SIGNAL(triggered()), this, SLOT(mute()));
    connect(ui->actionStop, SIGNAL(triggered()), this, SLOT(stop()));

    connect(ui->actionPlayPause, SIGNAL(triggered()), this, SLOT(togglePlay()));
}

void MedleyUI::quit() {
    QCoreApplication::quit();
}

void MedleyUI::updateGUI() {
    if (!ui->seekSlider->isSliderDown())
        ui->seekSlider->setValue(player->getPercent());
}

void MedleyUI::open() {
    QString file = QFileDialog::getOpenFileName(this, tr("Select a Song"),
                                                "/home/", tr("Songs (*.mp3)"));
    if (!file.isNull()) {
        ui->seekSlider->setValue(0);
        player->setSong(file.toStdString().c_str());
        play();
    }
}

void MedleyUI::togglePlay() {
    if (player->isPaused())
        play();
    else if (player->isPlaying())
        pause();
}

void MedleyUI::play() {
    ui->playToggle->setChecked(true);
    ui->actionPlayPause->setEnabled(true);
    ui->actionPlayPause->setText(tr("Pause"));
    ui->seekSlider->setEnabled(true);
    ui->playToggle->setEnabled(true);
    player->play();
}

void MedleyUI::pause() {
    ui->playToggle->setChecked(false);
    ui->actionPlayPause->setEnabled(true);
    ui->actionPlayPause->setText(tr("Play"));
    player->pause();
}

void MedleyUI::on_playToggle_toggled(bool checked) {
    if (checked)
        play();
    else
        pause();
}

void MedleyUI::mute() {
    ui->volumeSlider->setValue(0);
    player->setVolume(0);
}

void MedleyUI::stop() {
    pause();
    player->stop();
    ui->playToggle->setEnabled(false);
    ui->actionPlayPause->setEnabled(false);
    ui->seekSlider->setValue(0);
    ui->seekSlider->setEnabled(false);
    ui->playToggle->setEnabled(false);
}

void MedleyUI::on_seekSlider_sliderReleased() {
    player->setPercent(ui->seekSlider->value());
}

void MedleyUI::callNoteworthy() {
    // Placeholder until Noteworthy works
    QString query = ui->noteworthyBox->text();
    std::cout << query.toStdString() << std::endl;
}
