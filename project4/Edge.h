/**
 * Edge class used for project 4 written by Devon Miller-Junk
*/
#ifndef EDGE_H
#define EDGE_H
#include <string>
struct Edge
{
    double length;
    std::string destination;
    bool operator==(std::string name) { return this->destination == name; };
    void operator=(Edge edge)
    {
        this->length = edge.length;
        this->destination = edge.destination;
    };
    std::string print() { return this->destination; };
};

#endif