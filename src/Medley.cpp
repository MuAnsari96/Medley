#include "sound/Player.h"

int main(int argc, char* argv[]) {
    Player* player = Player::getInstance();
    Player::destroyInstance();
    return 0;

}