/**
 * Playlist Test File written by Devon Miller-Junk for the purposes of ECE250 Project 1 Fall 2019.
 * 
 * Implements the functions and code to be able to read from the inputs and perform the corresponding operations.
 * This is the file that should be compiled and run while evaluating the playlist class.
 **/

#include <iostream>
#include <string>
#include "Playlist.cpp"
using namespace std;
string removeNewLine(string input)
{
    //Removes any newline characters from the strings
    string result;
    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] != '\n' && input[i] != '\r' && input[i] != '\0')
        {
            result += input[i];
        }
    }
    return result;
}
string getCommand(string input) //Gets the command from the line (the command is before the first space)
{
    return input.substr(0, input.find(' '));
};
string getInputs(string input) //Gets the inputs from the line (the inputs are after the first space)
{
    return input.substr(input.find(' ') + 1, input.length());
};
int main()
{
    //Constants:
    const string success = "success";
    const string failure = "failure";

    //Playlist to use:
    Playlist playlist;

    //Strings to use with parsing input
    string line;    //entire line
    string command; //command to use
    string input;   //Inputs for the command
    string result;  //output

    while (getline(cin, line))
    {
        line = removeNewLine(line); //Removing the end of line character if there is one
        command = getCommand(line); //Separating out the command vs input section
        input = getInputs(line);
        result = failure; //Default result to failure incase line is not parsed correctly/bad input.
        //Note: Even though the failure option is not in the desired output, having the default output be an error
        //alerts the user that there was an error with the input.
        if (command == "i")
        {
            //Insert command
            string artist = input.substr(input.find(';') + 1, input.length());
            string name = input.substr(0, input.find(';'));
            result = playlist.push(Song(artist, name)) ? success : "can not insert " + name + ";" + artist;
        }
        else if (command == "p")
        {
            //Play command
            Song toPlay = playlist.play(stoi(input) - 1);
            //Note: Song() returns the default null song. This is checking if the song could not be played
            result = (toPlay == Song()) ? "could not play " + input : "played " + input + " " + toPlay.name + ";" + toPlay.artist;
        }
        else if (command == "e")
        {
            //Erase command
            Song toPlay = playlist.remove(stoi(input) - 1);
            //Note: Song() returns the default null song. This is checking if the song could not be removed
            result = (toPlay == Song()) ? "could not erase " + input : success;
        }
        cout << result << endl;
    }
};
