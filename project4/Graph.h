/**
 * Graph class used for project 4 written by Devon Miller-Junk
*/
#ifndef GRAPH_H
#define GRAPH_H
#include "LinkedList.h"
#include "LinkedList.cpp"
#include "Vertex.h"
#include "Edge.h"
#include <string>
class Graph
{
private:
    LinkedList<Vertex> nodes;
    int numEdges;
    void resetPaths();
    bool relax(Vertex *source, Vertex *destination, double weight);

public:
    Graph();
    ~Graph();

    Node<Vertex> *search(string name);
    bool insert(Vertex *vertex);
    bool setPath(string vertex1, string vertex2, double length);
    void dijkstraShortPath(Vertex *vertex);
    double getDistance(string name);
    string getPath(Vertex *vertex);
    int getNumEdges() const;
    void print() const;
    int getSize() const;
};
#endif