/**
 * This is the playlist header file created to implement the playlist class for Project 1 of ECE 250.
 * Written by Devon Miller-Junk.
 * Uses a vector to implement a playlist of songs. Songs can be added, removed, and played. There can't be duplicates
 * of songs added.
**/
#include "Song.cpp"
#include <vector>
#include <iostream>
#ifndef PLAYLIST_H
#define PLAYLIST_H

class Playlist
{
private:
    //Vector holding the songs
    std::vector<Song> songs;

public:
    Playlist();
    ~Playlist();
    bool push(const Song song);                  //Appends the song if not already in the playlist
    Song remove(const int index);                //Removes the song at index index
    Song play(const int index) const;            //Returns the song at index index
    Playlist operator=(const Playlist playlist); //Overloading the equality operator
};
#endif