#ifndef MEDLEYUI_H
#define MEDLEYUI_H

#include <QMainWindow>
#include <QFileDialog>
#include <QString>
#include <src/sound/Player.h>

namespace Ui {
class MedleyUI;
}

class MedleyUI : public QMainWindow
{
    Q_OBJECT

public:
    explicit MedleyUI(QWidget *parent = 0);
    ~MedleyUI();

private slots:
    void on_playButton_clicked();
    void on_actionOpen_triggered();
    void on_actionExit_triggered();

private:
    Ui::MedleyUI *ui;
    Player* player;
};

#endif // MEDLEYUI_H
