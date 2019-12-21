/**
 * This is the Song header file created to implement the song struct for Project 1 of ECE 250.
 * Written by Devon Miller-Junk.
 * The song struct holds two strings, one with the name of the song and one with the name of the artist.
**/

#include <iostream>
#include <string>

#ifndef SONG_H
#define SONG_H

struct Song
{
    std::string artist;
    std::string name;

    Song();                                                 //Null constructor
    Song(const Song &song);                                 //Equality constructor
    Song(const std::string artist, const std::string name); //Parameter passing constructor
    bool operator==(const Song &song) const;                //Overloading the equality operator
    Song &operator=(const Song &song);                      //Overloading the equals operator
};

#endif