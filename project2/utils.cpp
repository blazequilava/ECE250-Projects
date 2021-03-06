/**
 * Utils File written by Devon Miller-Junk for the purposes of ECE250 Project 2 Fall 2019.
**/
#include <string>
#ifndef UTILS
#define UTILS
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
#endif
