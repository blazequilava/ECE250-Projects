/**
 * This is the test file for Project 3 of ECE 250 written by Devon Miller-Junk.
 * It takes inputs from cin and performs operations on a binary tree depending on the given input.
*/
#include <iostream>
#include <string>
#include "QuadTree.cpp"
#include "utils.cpp"
using namespace std;
int handleTraversal(string input, QuadTree *tree, Type type) //Handles the traversal of the tree to find the min/max/total of a value
{
    string *information = separateByCommas(input, 4);
    double location[2];
    location[0] = stod(information[0]);
    location[1] = stod(information[1]);
    Node *node = tree->search(location);
    if (node == nullptr)
    {
        return -1;
    }
    Attribute attr = information[3] == "p" ? population : information[3] == "c" ? costOfLiving : averageNetSalary;
    int direction = getDirection(information[2]);
    if (direction < 0 || node->children[direction] == nullptr)
    {
        return -1;
    }
    return node->children[direction]->traversal(attr, type);
}

int main()
{
    //Constants:
    const string success = "success";
    const string failure = "failure";
    const string found = "found";
    const string notFound = "not found";
    const string maxResponse = "max";
    const string minResponse = "min";
    const string totalResponse = "total";
    const string size = "tree size";

    //Tree to use:
    QuadTree *tree = new QuadTree();

    //Strings to use with parsing input
    string line;    //entire line
    string command; //command to use
    string input;   //Inputs for the command
    string result;  //output

    while (getline(cin, line))
    {
        //Initial input string handling
        line = removeNewLine(line); //Removing the end of line character if there is one
        command = getCommand(line); //Separating out the command vs input section
        input = getInputs(line);

        //Set result to failure by default
        result = failure;

        //Case selection based on the command entered
        if (command == "i") //Insert
        {
            string *information = separateByCommas(input, 6);
            double location[2];
            location[0] = stod(information[1]);
            location[1] = stod(information[2]);
            Node *node = new Node(information[0], location, stoi(information[3]), stoi(information[4]), stoi(information[5]));
            result = tree->insert(node) ? success : failure;
        }
        else if (command == "s") //Search
        {
            string *information = separateByCommas(input, 2);
            double location[2];
            location[0] = stod(information[0]);
            location[1] = stod(information[1]);
            Node *node = tree->search(location);
            result = node == nullptr ? notFound : found + " " + node->name;
        }
        else if (command == "q_max") //Find max
        {
            Type type = maxType;
            long int value = handleTraversal(input, tree, type);
            result = value < 0 ? failure : maxResponse + " " + to_string(value);
        }
        else if (command == "q_min") //Find min
        {
            Type type = minType;
            long int value = handleTraversal(input, tree, type);
            result = value < 0 ? failure : minResponse + " " + to_string(value);
        }
        else if (command == "q_total") //Find total
        {
            Type type = totalType;
            long int value = handleTraversal(input, tree, type);
            result = value < 0 ? failure : totalResponse + " " + to_string(value);
        }
        else if (command == "print") //Print cities in order
        {
            result = tree->print();
        }
        else if (command == "clear") //Clear tree
        {
            tree->clear();
            result = success;
        }
        else if (command == "size") //Give the size of the tree
        {
            result = size + " " + to_string(tree->size);
        }
        cout << result << endl;
    }
};
