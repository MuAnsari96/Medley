#ifndef MEDLEYUI_H
#define MEDLEYUI_H

#include <QMainWindow>

namespace Ui {
class MedleyUI;
}

class MedleyUI : public QMainWindow
{
    Q_OBJECT

public:
    explicit MedleyUI(QWidget *parent = 0);
    ~MedleyUI();

private:
    Ui::MedleyUI *ui;
};

#endif // MEDLEYUI_H
