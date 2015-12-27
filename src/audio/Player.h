#ifndef PLAYER_H
#define PLAYER_H

#include <vlc/vlc.h>
#include <unistd.h>

class Player {

private:
    Player* instance;

    libvlc_instance_t* iib;

    libvlc_media_player_t* p;

    Player();

    ~PLayer();

public:
    Player getInstance();

    void setSong(const char* songPath);

    void setTime(libvlc_time_t time);

    void setPercent(float percent);

    void togglePause();

    void stop();


    libvlc_media_t* getSong();

    libvlc_time_t getTime();

    float getPercent();

    libvlc_time_t getLength();

};

#endif
