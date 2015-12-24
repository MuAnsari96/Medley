#include <vlc/vlc.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    libvlc_instance_t* instance = libvlc_new(0, NULL);
    libvlc_media_t* media= libvlc_media_new_path(instance, "/home/mustafa/Music/Cold Blood.mp3");
    libvlc_media_player_t* player = libvlc_media_player_new_from_media(media);
    
    libvlc_media_release(media);

    libvlc_media_player_play(player);
    sleep(10);

    libvlc_media_player_stop(player);

    libvlc_media_player_release(player);

    libvlc_release(instance);
    return 0;
}
