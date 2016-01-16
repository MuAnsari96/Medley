#ifndef MEDLEYUI_H
#define MEDLEYUI_H

#include <QMainWindow>
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

private:
    Ui::MedleyUI *ui;
    Player* player;
};

#endif // MEDLEYUI_H
