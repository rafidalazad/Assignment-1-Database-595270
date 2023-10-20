#include "playlist.h"

// Function to add a song to the playlist
void add_song(Playlist* playlist, const char* song_name) {
    Song* new_song = (Song*)malloc(sizeof(Song));
    if (new_song == NULL) {
        fprintf(stderr, "Memory allocation for new song failed.\n");
        exit(EXIT_FAILURE);
    }

    new_song->name = strdup(song_name); 
    if (new_song->name == NULL) {
        fprintf(stderr, "Memory allocation for song name failed.\n");
        exit(EXIT_FAILURE);
    }

    new_song->next = playlist->songs;
    playlist->songs = new_song;
}

// Function to remove a song from the playlist
void remove_song(Playlist* playlist, const char* song_name) {
    Song* current = playlist->songs;
    Song* prev = NULL;

    while (current != NULL) {
        if (strcmp(current->name, song_name) == 0) {
            if (prev == NULL) {
                playlist->songs = current->next;
            } else {
                prev->next = current->next;
            }
            free(current->name); // Free memory for song name
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }

    printf("Song '%s' not found in playlist '%s'.\n", song_name, playlist->name);
}

// Function to calculate the similarity between two playlists
float calculate_similarity(Playlist* playlist1, Playlist* playlist2) {
    // Implement the logic for calculating similarity
    // This is a placeholder; you'll need to implement according to your logic and requirements.
    // ...
}

// Function to free the memory used by playlists
void free_playlists(Playlist* playlists) {
    while (playlists != NULL) {
        Playlist* temp = playlists;
        playlists = playlists->next;

        Song* current_song = temp->songs;
        while (current_song != NULL) {
            Song* temp_song = current_song;
            current_song = current_song->next;
            free(temp_song->name); // Free memory for song name
            free(temp_song);
        }

        free(temp->name); // Free memory for playlist name
        free(temp);
    }
}

// Function to print the songs in the playlists
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
