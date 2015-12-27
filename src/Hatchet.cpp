#include "audio/Player.h"
#include <string>
#include <iostream>


int main(int argc, char* argv[]) {
    std::cout << "Welcome to Hatchet pre-pre-pre-Alpha!\n";
    std::cout << "Enter the path for your music directory:  ";
    std::string filepath;
    std::cin >> filepath;
    std::cout << filepath << std::endl;
    bool thing = true;
    Player* player = Player::getInstance();

    while (thing) {
        std::cout << "Enter a song name:    ";
        std::string song;
        std::cin >> song;

        player->setSong((filepath+song).c_str());
        player->play();
        std::string cont = "";
        while (cont != "n") {
            std::cin >> cont;
            player->pause();
        }

    }
    return 0;

}