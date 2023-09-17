#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>
#include "playlist.h"

int main() {
    Playlist* playlists = NULL;

    while (1) {
        printf("\nOperations:\n");
        printf("1. Add a song to a playlist\n");
        printf("2. Remove a song from a playlist\n");
        printf("3. Calculate playlist similarity\n");
        printf("4. Print playlists\n");
        printf("0. Quit\n");

        int choice;
        scanf("%d", &choice);

        if (choice == 0) {
            // Exit the program
            free_playlists(playlists);
            break;
        }
        else if (choice == 1) {
            // Add a song to a playlist
            char playlist_name[100];
            char song_name[100];
            printf("Enter playlist name: ");
            scanf("%s", playlist_name);
            printf("Enter song name: ");
            scanf("%s", song_name);

            // Find or create the playlist
            Playlist* playlist = playlists;
            Playlist* prev = NULL;
            while (playlist != NULL && strcmp(playlist->name, playlist_name) != 0) {
                prev = playlist;
                playlist = playlist->next;
            }
            if (playlist == NULL) {
                // Playlist does not exist, create a new one
                playlist = (Playlist*)malloc(sizeof(Playlist));
                if (playlist == NULL) {
                    fprintf(stderr, "Memory allocation failed.\n");
                    exit(1);
                }
                strcpy(playlist->name, playlist_name);
                playlist->songs = NULL;
                playlist->next = NULL;
                if (prev == NULL) {
                    playlists = playlist;
                }
                else {
                    prev->next = playlist;
                }
            }

            // Add the song to the playlist
            add_song(playlist, song_name);
        }
        else if (choice == 2) {
            // Remove a song from a playlist
            char playlist_name[100];
            char song_name[100];
            printf("Enter playlist name: ");
            scanf("%s", playlist_name);
            printf("Enter song name: ");
            scanf("%s", song_name);

            // Find the playlist
            Playlist* playlist = playlists;
            while (playlist != NULL && strcmp(playlist->name, playlist_name) != 0) {
                playlist = playlist->next;
            }
            if (playlist == NULL) {
                printf("Playlist '%s' not found.\n", playlist_name);
            }
            else {
                // Remove the song from the playlist
                remove_song(playlist, song_name);
            }
        }
        else if (choice == 3) {
            // Calculate playlist similarity
            char playlist_name1[100];
            char playlist_name2[100];
            printf("Enter first playlist name: ");
            scanf("%s", playlist_name1);
            printf("Enter second playlist name: ");
            scanf("%s", playlist_name2);

            // Find the playlists
            Playlist* playlist1 = playlists;
            Playlist* playlist2 = playlists;
            while (playlist1 != NULL && strcmp(playlist1->name, playlist_name1) != 0) {
                playlist1 = playlist1->next;
            }
            while (playlist2 != NULL && strcmp(playlist2->name, playlist_name2) != 0) {
                playlist2 = playlist2->next;
            }
            if (playlist1 == NULL || playlist2 == NULL) {
                printf("One or both playlists not found.\n");
            }
            else {
                // Calculate and print playlist similarity
                float similarity = calculate_similarity(playlist1, playlist2);
                printf("Playlist similarity: %.2f\n", similarity);
            }
        }
        else if (choice == 4) {
            // Print playlists
            print_playlists(playlists);
        }
        else {
            printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}
