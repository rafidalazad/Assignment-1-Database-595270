#include "playlist.h"

int main() {
    Playlist* playlists = NULL; // Initialize to NULL for proper memory management

    while (1) {
        printf("\nOperations:\n");
        printf("1. Add a song to a playlist\n");
        printf("2. Remove a song from a playlist\n");
        printf("3. Calculate playlist similarity\n");
        printf("4. Print playlists\n");
        printf("0. Quit\n");

        int choice;
        scanf("%d", &choice);

        // Clearing input buffer to avoid any misreads
        while ((getchar()) != '\n');

        switch (choice) {
            case 1:
                // Code to add a song to a playlist
                // Ensure that memory is allocated and checked for both playlist and songs
                break;
            case 2:
                // Code to remove a song from a playlist
                break;
            case 3:
                // Code to calculate and display similarity between two playlists
                break;
            case 4:
                // Code to print all playlists
                break;
            case 0:
                // Code to free memory and exit
                free_playlists(playlists);
                return 0;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }
    return 0; // To satisfy the return type of main function
}

    return 0;
}  // this is the edited version
