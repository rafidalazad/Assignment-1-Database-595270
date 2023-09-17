#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

#include "playlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void add_song(Playlist* playlist, const char* song_name) {
    Song* new_song = (Song*)malloc(sizeof(Song));
    if (new_song == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }
    strcpy(new_song->name, song_name);
    new_song->next = playlist->songs;
    playlist->songs = new_song;
}

void remove_song(Playlist* playlist, const char* song_name) {
    Song* current = playlist->songs;
    Song* prev = NULL;

    while (current != NULL) {
        if (strcmp(current->name, song_name) == 0) {
            if (prev == NULL) {
                playlist->songs = current->next;
            }
            else {
                prev->next = current->next;
            }
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }

    printf("Song '%s' not found in playlist '%s'.\n", song_name, playlist->name);
}

float calculate_similarity(Playlist* playlist1, Playlist* playlist2) {
    int intersection = 0;
    int union_size = 0;

    Song* current1 = playlist1->songs;
    while (current1 != NULL) {
        union_size++;
        Song* current2 = playlist2->songs;
        while (current2 != NULL) {
            if (strcmp(current1->name, current2->name) == 0) {
                intersection++;
                break;
            }
            current2 = current2->next;
        }
        current1 = current1->next;
    }

    union_size += playlist2->songs ? 0 : 1;  // Add 1 if playlist2 is empty to avoid division by zero

    return (float)intersection / union_size;
}

void free_playlists(Playlist* playlists) {
    while (playlists != NULL) {
        Playlist* temp = playlists;
        playlists = playlists->next;

        Song* current_song = temp->songs;
        while (current_song != NULL) {
            Song* temp_song = current_song;
            current_song = current_song->next;
            free(temp_song);
        }

        free(temp);
    }
}

void print_playlists(Playlist* playlists) {
    while (playlists != NULL) {
        printf("Playlist: %s\n", playlists->name);
        Song* current_song = playlists->songs;
        while (current_song != NULL) {
            printf("  - %s\n", current_song->name);
            current_song = current_song->next;
        }
        playlists = playlists->next;
    }
}
