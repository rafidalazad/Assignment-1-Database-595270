// playlist_tests.c
#include <assert.h>
#include <stdio.h>
#include "playlist.h"

void test_add_song() {
    Playlist test_playlist;
    strcpy(test_playlist.name, "Test Playlist");
    test_playlist.songs = NULL;  // Initially, no songs

    add_song(&test_playlist, "Song 1");
    assert(test_playlist.songs != NULL && strcmp(test_playlist.songs->name, "Song 1") == 0);

    add_song(&test_playlist, "Song 2"); // Add another song, check if the list is updated
    assert(test_playlist.songs != NULL);
    assert(strcmp(test_playlist.songs->name, "Song 2") == 0 || strcmp(test_playlist.songs->next->name, "Song 2") == 0);

    printf("test_add_song passed!\n");
}

void test_remove_song() {
    Playlist test_playlist;
    strcpy(test_playlist.name, "Test Playlist");
    test_playlist.songs = NULL;

    // Setup: Add some songs
    add_song(&test_playlist, "Song 1");
    add_song(&test_playlist, "Song 2");

    remove_song(&test_playlist, "Song 1");

    // Either the song isn't in the list, or the list is empty, meaning the song was successfully removed
    assert(test_playlist.songs == NULL || strcmp(test_playlist.songs->name, "Song 1") != 0);

    printf("test_remove_song passed!\n");
}

void test_calculate_similarity() {
    Playlist test_playlist1, test_playlist2;

    // Setup: Initialize playlists
    strcpy(test_playlist1.name, "Test Playlist 1");
    test_playlist1.songs = NULL;
    strcpy(test_playlist2.name, "Test Playlist 2");
    test_playlist2.songs = NULL;

    // Add different songs to the playlists
    add_song(&test_playlist1, "Song A");
    add_song(&test_playlist1, "Song B");
    add_song(&test_playlist2, "Song A");

    float similarity = calculate_similarity(&test_playlist1, &test_playlist2);
    assert(similarity > 0);  // As there is at least one common song, similarity should not be zero

    printf("test_calculate_similarity passed!\n");
}

int main() {
    test_add_song();
    test_remove_song();
    test_calculate_similarity();

    printf("All tests passed!\n");

    return 0;
}
