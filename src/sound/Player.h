#ifndef PLAYER_H
#define PLAYER_H

#include <vlc/vlc.h>
#include <unistd.h>
#include <iostream>

class Player {

private:
    static Player* instance;

    libvlc_instance_t* lib;

    libvlc_media_player_t* p;

    Player();

    ~Player();

public:
    static Player* getInstance();

    static void destroyInstance();

    void setSong(const char* songPath);

    void setTime(libvlc_time_t time);

    void setPercent(float percent);

    void setVolume(int percent);

    void togglePause();

    void pause();

    void stop();

    void play();


    libvlc_media_t* getSong();

    libvlc_time_t getTime();

    float getPercent();

    libvlc_time_t getLength();

};



#endif
