#include "music.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


void nowPlaying(Song * playlist){
    int choix =0;
    while(playlist!=NULL) {
        // playing
        printf("\nNow playing \n");
        printf("%s \n", playlist->title);
        printf("%s \n", playlist->artist);
        //sleep(playlist->duration);
        printf("1: next, 2: previous 3: exit \n");
        scanf("%d", &choix);
        switch (choix) {
            case 1:
                playlist = playlist->next;
                break;
            case 2:
                playlist = playlist->prev;
                break;
            case 3:
                return;
            default:
                break;
        }

    }

    printf(" Fin de la playlist \n ");
    printf("========================");

}

Song * createSong(char* title, char * artist, unsigned int duration){
    // Allocation
    Song * newSong = (Song *) malloc(sizeof(Song));

    // Initialisation data
    newSong->duration = duration;
    strcpy(newSong->artist, artist);
    strcpy(newSong->title, title);

    // initialisation des liens
    newSong->next = NULL;
    newSong->prev = NULL;

    return newSong;
}

void addFirst(Song ** playlist, char* title, char * artist, unsigned int duration){
    // create a new song
    Song * newSong  = createSong(title, artist, duration);

    if(*playlist == NULL){
        *playlist = newSong;
    }else {
        // link the song at the beginning
        newSong->next = *playlist;
        (*playlist)->prev = newSong;
        *playlist = newSong;
    }
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
        newSong->prev = lastSong;
        lastSong = lastSong->next;
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


