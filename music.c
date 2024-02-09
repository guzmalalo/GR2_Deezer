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
        newSong->next = newSong;
        newSong->prev = newSong;
    }else {

        newSong->next = *playlist;
        newSong->prev = (*playlist)->prev;
        // (*playlist->prev = newSong;
        newSong->next->prev = newSong;
        newSong->prev->next = newSong;

        *playlist = newSong;
    }
}

void deletePlaylist(Song ** playlist){

    if(*playlist !=NULL) {
        Song *toDelete = NULL;
        Song *current = (*playlist)->next;

        while(current!= *playlist){
            toDelete = current;
            current= current->next;
            free(toDelete);
        }

        // on efface la tete
        free(*playlist);
        *playlist = NULL;
    }

}

// Add at the end
void addLast(Song ** playlist, char* title, char * artist, unsigned int duration){
    // create a new song
    Song * newSong  = createSong(title, artist, duration);

    if(*playlist == NULL){
        *playlist = newSong;
        newSong->next = newSong;
        newSong->prev = newSong;
    }else {

        newSong->next = *playlist;
        newSong->prev = (*playlist)->prev;
        // (*playlist->prev = newSong;
        newSong->next->prev = newSong;
        newSong->prev->next = newSong;

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


