#include "Player.h"

Player* Player::instance;
// Constructor and Destructor
Player::Player() {
    lib = libvlc_new(0, 0);
    p = libvlc_media_player_new(lib);
}

Player::~Player() {
    libvlc_media_player_stop(p);
    libvlc_media_player_release(p);
    libvlc_release(lib);
}

Player* Player::getInstance() {
    if (!instance)
        instance = new Player();
    return instance;
}

void Player::destroyInstance() {
    if (instance)
        delete instance;
    return;
}

void Player::setSong(const char* songPath) {
    libvlc_media_t* song = libvlc_media_new_path(lib, songPath);
    libvlc_media_player_set_media(p, song);
    libvlc_media_release(song);
}

void Player::setTime(libvlc_time_t time) {
    libvlc_media_player_set_time(p, time);
}

void Player::setPercent(float percent) {
    libvlc_media_player_set_position(p, percent);
}

void Player::setVolume(int percent) {
    std::cout << "hello";
    libvlc_audio_set_volume(p, percent);
}

void Player::togglePause() {
    libvlc_media_player_pause(p);
}

void Player::pause() {
    libvlc_media_player_set_pause(p, 1);
}

void Player::play() {
    libvlc_media_player_play(p);
}

bool Player::isPlaying() {
    return libvlc_media_player_is_playing(p);
}

void Player::stop() {
    libvlc_media_player_stop(p);
}


libvlc_media_t* Player::getSong() {
    return libvlc_media_player_get_media(p);
}

libvlc_time_t Player::getTime() {
    return libvlc_media_player_get_time(p);
}

float Player::getPercent() {
    return libvlc_media_player_get_position(p);
}

libvlc_time_t Player::getLength() {
    return libvlc_media_player_get_length(p);
}
