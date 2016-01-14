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
    delete ui;
}
