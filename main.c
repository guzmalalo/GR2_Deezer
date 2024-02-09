#include <stdio.h>
#include "music.h"
#include <stdlib.h>
#include <string.h>

int main() {

    Song * likedSongs= NULL;

    addFirst(&likedSongs,"Back in black","ACDC", 1);
    addLast(&likedSongs,"Waka waka", "Shakira", 1);
    addLast(&likedSongs,"Babe ...", "Britney",1);
    addFirst(&likedSongs,"Crusify your mind","Rodriguez", 1);
    addLast(&likedSongs,"Ce matin là", "AIR", 1);
    addFirst(&likedSongs,"Toxic", "Britney",1);
    addLast(&likedSongs,"Oops I did ..", "Britney",1);

    // premier affchage
    nowPlaying(likedSongs);

    // efface toutes les chansons de britney
    //deleteByArtist(&likedSongs,"Britney");
    //deleteByArtist(&likedSongs,"Shakira");

    // deuxième lecture
    //nowPlaying(likedSongs);

    deletePlaylist(&likedSongs);

    return 0;
}
