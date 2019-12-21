/**
 * This is the Song c++ file created to implement the song struct for Project 1 of ECE 250.
 * Written by Devon Miller-Junk.
 * The song struct holds two strings, one with the name of the song and one with the name of the artist.
**/
#include "Song.h"
using namespace std;

#ifndef SONG_CPP
#define SONG_CPP

//Constructors
Song::Song()
{
    artist = "";
    name = "";
}

Song::Song(const Song &song)
{
    this->artist = song.artist;
    this->name = song.name;
}

Song::Song(const string artist, const string name)
{
    this->artist = artist;
    this->name = name;
}

//Operator Overloading
bool Song::operator==(cons t Song &song) const
{
    return (this->artist == song.artist && this->name == song.name);
}

Song &Song::operator=(const Song &song)
{
    this->artist = song.artist;
    this->name = song.name;
}
#endif