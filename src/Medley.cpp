#include "interface/MedleyUI.h"
#include <QApplication>
#include "sound/Player.h"
#include <iostream>

int main(int argc, char* argv[]) {
    QApplication appman(argc, argv);
    MedleyUI medley;
    medley.show();
    return appman.exec();
}