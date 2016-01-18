#ifndef MEDLEYUI_H
#define MEDLEYUI_H

#include <QMainWindow>
#include <QFileDialog>
#include <QString>
#include <QTimer>
#include <src/sound/Player.h>

namespace Ui {
class MedleyUI;
}

class MedleyUI : public QMainWindow {
    Q_OBJECT

public:
    explicit MedleyUI(QWidget *parent = 0);
    ~MedleyUI();

private slots:
    void on_seekSlider_sliderReleased();
    void updateGUI();
    void callNoteworthy();
    void open();
    void quit();
    void mute();
    void stop();
    void togglePlay();
    void on_playToggle_toggled(bool checked);

private:
    Ui::MedleyUI *ui;
    Player* player;
    QTimer *updateTimer;
    void initConnections();
    void play();
    void pause();
};

#endif // MEDLEYUI_H
