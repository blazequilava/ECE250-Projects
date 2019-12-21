#include <iostream>
#include <string>
#include "HashTable.cpp"
#include "utils.cpp"
using namespace std;
int main()
{
    //Constants:
    const string success = "success";
    const string failure = "failure";

    //HashTable to use:
    HashTable *hashTable;

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
        result = failure;
        if (command == "n")
        {
            hashTable = new HashTable(stoi(input));
            result = success;
        }
        else if (command == "i")
        {
            result = hashTable->insert(stoi(input)) ? success : failure;
        }
        else if (command == "s")
        {
            int location = hashTable->search(stoi(input));
            result = location == -1 ? "not found" : "found in " + to_string(location);
        }
        else if (command == "d")
        {
            result = hashTable->deletion(stoi(input)) ? success : failure;
        }
        cout << result << endl;
    }
};
