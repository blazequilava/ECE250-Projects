#ifndef VERTEX_H
#define VERTEX_H
#include "LinkedList.h"
#include "LinkedList.cpp"
#include "Edge.h"
#include <string>
struct Vertex
{
    //Data to use in Path Finding
    bool unlocated;
    double distance;
    Vertex *parent;
    //Rest of the data
    std::string name;
    LinkedList<Edge> *paths;
    Vertex()
    {
        this->unlocated = true;
        this->distance = 100;
        this->parent = nullptr;
        this->paths = new LinkedList<Edge>();
    }
    ~Vertex()
    {
        delete paths;
    }
    bool operator==(std::string name) { return this->name == name; };
    void operator=(Vertex vertex)
    {
        this->name = vertex.name;
    };
    std::string print() { return this->name.length() > 0 ? this->name : "NULL"; };
};
#endif