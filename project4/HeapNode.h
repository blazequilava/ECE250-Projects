/**
 * Heap class used for project 4 written by Devon Miller-Junk
*/
#ifndef HEAPNODE_H
#define HEAPNODE_H
#include "Vertex.h"
struct HeapNode
{
private:
    Vertex *vertex;

public:
    HeapNode(Vertex *vertex) { this->vertex = vertex; };
    HeapNode() { this->vertex = new Vertex(); };
    bool operator==(HeapNode node)
    {
        if (this->vertex->unlocated && node.vertex->unlocated)
        {
            return true;
        }
        else if (this->vertex->unlocated || node.vertex->unlocated)
        {
            return false;
        }
        return this->vertex->distance == node.vertex->distance;
    };
    bool operator>(HeapNode node)
    {
        if (this->vertex->unlocated)
        {
            return true;
        }
        else if (node.vertex->unlocated)
        {
            return false;
        }
        return this->vertex->distance > node.vertex->distance;
    };
    bool operator<(HeapNode node)
    {
        if (this->vertex->unlocated)
        {
            return true;
        }
        else if (node.vertex->unlocated)
        {
            return false;
        }
        return this->vertex->distance < node.vertex->distance;
    };
    void operator=(HeapNode *node)
    {
        this->vertex = node->vertex;
    };
    string print()
    {
        return this->vertex->print();
    }
    Vertex *getValue() { return this->vertex; };
};
#endif