#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

#pragma once
#ifndef PLAYLIST_H
#define PLAYLIST_H

typedef struct Song {
    char name[100];
    struct Song* next;
} Song;

typedef struct Playlist {
    char name[100];
    Song* songs;
    struct Playlist* next;
} Playlist;

void add_song(Playlist* playlist, const char* song_name);
void remove_song(Playlist* playlist, const char* song_name);
float calculate_similarity(Playlist* playlist1, Playlist* playlist2);
void free_playlists(Playlist* playlists);
void print_playlists(Playlist* playlists);

#endif
