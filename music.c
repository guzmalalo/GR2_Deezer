#include "music.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


void nowPlaying(Song * playlist){
    while(playlist!=NULL) {
        // playing
        printf(" \n Now playing \n");
        printf("%s \n", playlist->title);
        printf("%s \n", playlist->artist);
        sleep(playlist->duration);

        // update to the next song
        playlist= playlist->next;
    }

    printf(" Fin de la playlist \n ");
    printf("========================");

}

Song * createSong(char* title, char * artist, unsigned int duration){
    // Allocation
    Song * newSong = (Song *) malloc(sizeof(Song));

    // Initialisation
    newSong->duration = duration;
    strcpy(newSong->artist, artist);
    strcpy(newSong->title, title);

    newSong->next = NULL;

    return newSong;
}

void addFirst(Song ** playlist, char* title, char * artist, unsigned int duration){
    // create a new song
    Song * newSong  = createSong(title, artist, duration);

    // link the song at the beginning
    newSong->next =  *playlist;
    *playlist= newSong;

}

void deletePlaylist(Song ** playlist){
    Song * temp= NULL;

    while(*playlist!=NULL){
        temp= (*playlist)->next;
        free(*playlist);
        *playlist= temp;

    }

}

// Add at the end
void addLast(Song ** playlist, char* title, char * artist, unsigned int duration){
    // create a new song
    Song * newSong  = createSong(title, artist, duration);
    Song * lastSong=  *playlist;

    if (*playlist ==NULL){
        *playlist = newSong;
    }else {
        // parcourir la chaine
        while (lastSong->next != NULL) {
            lastSong = lastSong->next;
        }

        // ca y est on a trouvé le derniere
        lastSong->next = newSong;
    }

}

void deleteByArtist(Song ** playlist, char * artistName){
    // si la liste est vide on retourne au main
    if (*playlist == NULL){
        printf("Your playlist is empty");
        return;
    }

    // si non, on sait qu'il y a un moins une chanson
    Song * prev = *playlist;
    Song * current = (*playlist)->next;

    // on cherche à partir du deuxième maillon
    while (current!=NULL){
        if(strcmp(current->artist,artistName) == 0){
            prev->next = current->next;
            free(current);
            current = prev->next;
        }else{
            prev = current;
            current= current->next;
        }
    }

    //et si le premier est l'artiste qu'on cherche ?
    if(strcmp((*playlist)->artist,artistName) == 0){
        current = *playlist;
        *playlist= (*playlist)->next;
        free(current);
    }

}


