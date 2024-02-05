#include <stdio.h>
#include "music.h"
#include <stdlib.h>
#include <string.h>

int main() {

    Song * likedSongs= NULL;

    addLast(&likedSongs,"Waka waka", "Shakira", 3);
    addFirst(&likedSongs,"Back in black","ACDC", 2);
    addFirst(&likedSongs,"Crusify your mind","Rodriguez", 2);
    addLast(&likedSongs,"Ce matin là", "AIR", 3);

    nowPlaying(likedSongs);

    deletePlaylist(&likedSongs);

    return 0;
}
