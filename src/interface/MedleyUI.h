#ifndef MEDLEYUI_H
#define MEDLEYUI_H

#include <QMainWindow>
#include <QFileDialog>
#include <QString>
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
    void on_playToggle_clicked();
    void on_actionOpen_triggered();
    void on_actionExit_triggered();
    void on_volumeSlider_valueChanged(int percent);
    void on_seekSlider_sliderReleased();
    void on_noteworthyButton_clicked();
    void on_noteworthyBox_returnPressed();

private:
    Ui::MedleyUI *ui;
    Player* player;
    void callNoteworthy();
};

#endif // MEDLEYUI_H
