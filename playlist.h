#pragma once

// Necessary system headers are included
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definition of the Song structure
typedef struct Song {
    char *name; // dynamic string
    struct Song* next;
} Song;

// Definition of the Playlist structure
typedef struct Playlist {
    char *name; // dynamic string
    Song* songs;
    struct Playlist* next;
} Playlist;

// Function declarations for playlist operations
void add_song(Playlist* playlist, const char* song_name);
void remove_song(Playlist* playlist, const char* song_name);
float calculate_similarity(Playlist* playlist1, Playlist* playlist2);
void free_playlists(Playlist* playlists);
void print_playlists(Playlist* playlists);
