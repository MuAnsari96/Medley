#include "Player.h"

// Constructor and Destructor
Player::Player() {
    lib = libvlc_new();
    p = libvlc_media_player_new(instance);
}

Player::~PLayer() {
    libvlc_media_player_stop(p);
    libvlc_media_player_release(p);
    libvlc_release(lib);
}

Player Player::getInstance() {
    if (!instance)
        instance = new Player();
    return instance;
}

void setSong(const char* songPath) {
    libvlc_media song = libvlc_media_new_path(lib, songPath);
    libvlc_media_set_media(p, song);
    libvlc_media_release(song);
}

void setTime(libvlc_time_t time) {
    libvlc_media_player_set_time(p, time);
}

void setPercent(float percent) {
    libvlc_media_player_set_position(p, percent);
}

void togglePause() {
    libvlc_media_player_pause(p);
}

void stop() {
    libvlc_media_player_stop(p);
}


libvlc_media_t* getSong() {
    return libvlc_media_player_get_media(p);
}

libvlc_time_t getTime() {
    return libvlc_media_player_get_time(p);
}

float getPercent() {
    return libvlc_media_player_get_position(p);
}

libvlc_time_t getLength() {
    return libvlc_media_player_get_length(p);
}
