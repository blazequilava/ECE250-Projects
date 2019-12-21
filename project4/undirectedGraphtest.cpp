/**
 * This is the test file for Project 4 of ECE 250 written by Devon Miller-Junk.
 * It takes inputs from cin and performs operations on a graph depending on the given input.
*/
#include <iostream>
#include <string>
#include "Graph.h"
#include "Graph.cpp"
#include "utils.cpp"
using namespace std;
int main()
{
    //Constants:
    const string success = "success";
    const string failure = "failure";
    const string found = "found";
    const string notFound = "not found";
    const string degree = "degree of";
    const string numNodes = "number of nodes";
    const string numEdges = "number of edges";
    const string dirdistance = "direct distance";
    const string shortdistance = "shortest distance";

    //Graph to use:
    Graph *graph = new Graph();

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
            Vertex *vertex = new Vertex();
            vertex->name = input;
            result = graph->insert(vertex) ? success : failure;
            cout << result << endl;
        }
        else if (command == "setd") //Set distance
        {
            string *information = separateByCommas(input, 3); //name1;name2;d
            result = graph->setPath(information[0], information[1], stod(information[2])) ? success : failure;
            delete[] information;
            cout << result << endl;
        }
        else if (command == "s") //Search
        {
            result = graph->search(input) == nullptr ? notFound : found + " " + input;
            cout << result << endl;
        }
        else if (command == "degree") //get degree
        {
            Node<Vertex> *node = graph->search(input);
            if (node == nullptr)
            {
                cout << notFound << endl;
            }
            else
            {
                cout << degree + " " + input + " " << node->value->paths->getSize() << endl;
            }
            //result = node == nullptr ? notFound : degree + " " + input + " " + to_string(node->value->paths->getSize());
        }
        else if (command == "graph_nodes") //graph nodes
        {
            cout << numNodes + " " << graph->getSize() << endl;
        }
        else if (command == "graph_edges") //graph edges
        {
            cout << numEdges + " " << graph->getNumEdges() << endl;
        }
        else if (command == "d") //Prints distance
        {
            string *information = separateByCommas(input, 2);
            Node<Vertex> *node = graph->search(information[0]);
            if (node == nullptr)
            {
                cout << failure << endl;
            }
            else
            {
                Node<Edge> *edge = node->value->paths->search(information[1]);
                if (edge == nullptr)
                {
                    cout << failure << endl;
                }
                else
                {
                    cout << dirdistance + " " + information[0] + " to " + information[1] + " " << edge->value->length << endl;
                }
            }
            delete[] information;
        }
        else if (command == "shortest_d") //find shortest distance
        {
            string *information = separateByCommas(input, 2);
            Node<Vertex> *node = graph->search(information[0]);
            Node<Vertex> *destination = graph->search(information[1]);
            if (node == nullptr || destination == nullptr)
            {
                cout << failure << endl;
            }
            else
            {
                graph->dijkstraShortPath(node->value);
                if (destination->value->unlocated)
                {
                    cout << failure << endl;
                }
                else
                {
                    cout << shortdistance + " " + information[0] + " to " + information[1] + " " << destination->value->distance << endl;
                }
            }
            delete[] information;
        }
        else if (command == "print_path") //print shortest path
        {
            string *information = separateByCommas(input, 2);
            Node<Vertex> *node = graph->search(information[0]);
            Node<Vertex> *destination = graph->search(information[1]);
            if (node == nullptr || destination == nullptr)
            {
                cout << failure << endl;
            }
            else
            {
                graph->dijkstraShortPath(node->value);
                if (destination->value->unlocated)
                {
                    cout << failure << endl;
                }
                else
                {
                    cout << graph->getPath(destination->value) << endl;
                }
            }
            delete[] information;
        }
        else if (command == "clear") //clear the tree
        {
            delete graph;
            graph = new Graph();
            cout << success << endl;
        }
        else
        {
            cout << failure << endl;
        }
    }
    delete graph;
};
