#ifndef GR2_DEEZER_MUSIC_H
#define GR2_DEEZER_MUSIC_H

#define MAXTITLE 50
#define MAXARTIST 30

struct song{
    // data
    char title[MAXTITLE];
    char artist[MAXARTIST];
    unsigned int duration;

    // lien, link
    struct song * next;
};

typedef struct song Song;

// print
void nowPlaying(Song * playlist);

// create a song
Song * createSong(char* title, char * artist, unsigned int duration);

// Add at the beginning
void addFirst(Song ** playlist, char* title, char * artist, unsigned int duration);

// Add at the end
void addLast(Song ** playlist, char* title, char * artist, unsigned int duration);


// free playlist
void deletePlaylist(Song ** playlist);

#endif
