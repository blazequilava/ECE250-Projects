/**
 * This is the playlist c++ file created to implement the playlist class for Project 1 of ECE 250.
 * Written by Devon Miller-Junk.
 * Uses a vector to implement a playlist of songs. Songs can be added, removed, and played. There can't be duplicates
 * of songs added.
**/
#include "Playlist.h"
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

#ifndef PLAYLIST_CPP
#define PLAYLIST_CPP

using namespace std;
//constructor
Playlist::Playlist()
{
    songs = vector<Song>();
}
//destructor
Playlist::~Playlist()
{
    songs.clear();
}
//Functions
bool Playlist::push(const Song song)
{
    //Appends to the end of the song vector if there is not a duplicate.
    vector<Song>::const_iterator location;
    location = find(songs.begin(), songs.end(), song);
    if (location == songs.end())
    {
        songs.push_back(song);
        return true;
    }
    return false;
}

Song Playlist::remove(const int index)
{
    //Removes the song at index index.
    if (index < 0 || index >= songs.size())
    {
        return Song();
    }
    Song result = songs[index];
    songs.erase(songs.begin() + index);
    return result;
}

Song Playlist::play(const int index) const
{
    //Returns the song at index index
    return index < 0 || index >= songs.size() ? Song() : songs[index];
}

Playlist Playlist::operator=(const Playlist playlist)
{
    //Overloading the equals operator
    songs.clear();
    songs = vector<Song>(playlist.songs);
}

#endif