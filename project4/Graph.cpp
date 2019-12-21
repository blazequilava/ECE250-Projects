#ifndef GRAPH_CPP
#define GRAPH_CPP
#include <string>
#include "Graph.h"
#include "LinkedList.h"
#include "LinkedList.cpp"
#include "Heap.h"
#include "Heap.cpp"
#include "HeapNode.h"
#include "Vertex.h"
#include "Edge.h"
using namespace std;
void Graph::resetPaths()
{
    if (this->nodes.getSize() == 0)
    {
        return;
    }
    Node<Vertex> *currentNode = this->nodes.getStart();
    while (currentNode->next != nullptr)
    {
        currentNode->value->unlocated = true;
        currentNode->value->parent = nullptr;
        currentNode->value->distance = 1000;
        currentNode = currentNode->next;
    }
    currentNode->value->unlocated = true;
    currentNode->value->distance = 1000;
    currentNode->value->parent = nullptr;
}
bool Graph::relax(Vertex *source, Vertex *destination, double weight)
{
    if (source->unlocated || weight < 0)
    {
        return false;
    }
    if (destination->unlocated || source->distance + weight < destination->distance)
    {
        destination->unlocated = false;
        destination->distance = source->distance + weight;
        destination->parent = source;
        return true;
    }
    return false;
}
Graph::Graph()
{
    this->numEdges = 0;
    this->nodes = LinkedList<Vertex>();
}

Graph::~Graph()
{
    //Not needed
}

Node<Vertex> *Graph::search(string name)
{
    return this->nodes.search(name);
}

bool Graph::insert(Vertex *vertex)
{
    if (this->search(vertex->name) == nullptr)
    {
        nodes.push(vertex);
        return true;
    }
    return false;
}

bool Graph::setPath(string vertex1, string vertex2, double length)
{
    Node<Vertex> *firstVertex = this->search(vertex1);
    Node<Vertex> *secondVertex = this->search(vertex2);
    if (firstVertex == nullptr || secondVertex == nullptr || secondVertex == firstVertex)
    {
        return false;
    }
    Node<Edge> *currentNode = firstVertex->value->paths->getStart();
    bool completed = false;
    while (currentNode != nullptr && !completed)
    {
        if (*(currentNode->value) == vertex2)
        {
            currentNode->value->length = length;
            completed = true;
        }
        currentNode = currentNode->next;
    }
    if (!completed)
    {
        //Inserting Edge
        this->numEdges = this->numEdges + 1;
        Edge *edge = new Edge();
        edge->length = length;
        edge->destination = secondVertex->value->name;
        firstVertex->value->paths->push(edge);
    }
    currentNode = secondVertex->value->paths->getStart();
    completed = false;
    while (currentNode != nullptr && !completed)
    {
        if (*(currentNode->value) == vertex1)
        {
            currentNode->value->length = length;
            completed = true;
        }
        currentNode = currentNode->next;
    }
    if (!completed)
    {
        //Inserting Edge
        Edge *edge = new Edge();
        edge->length = length;
        edge->destination = firstVertex->value->name;
        secondVertex->value->paths->push(edge);
    }
    return true;
}
void Graph::dijkstraShortPath(Vertex *vertex)
{
    this->resetPaths();
    vertex->distance = 0;
    vertex->parent = nullptr;
    vertex->unlocated = false;
    Heap<HeapNode> priorityQueue = Heap<HeapNode>(true, this->nodes.getSize());
    priorityQueue.insert(new HeapNode(vertex));
    while (!priorityQueue.isEmpty())
    {
        HeapNode currentNode = priorityQueue.remove(0);
        if (currentNode.getValue()->paths->getSize() > 0)
        {
            Node<Edge> *currentEdge = currentNode.getValue()->paths->getStart();
            Vertex *destination = this->nodes.search(currentEdge->value->destination)->value;
            if (this->relax(currentNode.getValue(), destination, currentEdge->value->length))
            {
                int index = priorityQueue.search(destination->name);
                if (index != -1)
                {
                    priorityQueue.remove(index);
                }
                priorityQueue.insert(new HeapNode(destination));
            }
            while (currentEdge->next != nullptr)
            {
                currentEdge = currentEdge->next;
                destination = this->nodes.search(currentEdge->value->destination)->value;
                if (this->relax(currentNode.getValue(), destination, currentEdge->value->length))
                {
                    int index = priorityQueue.search(destination->name);
                    if (index != -1)
                    {
                        priorityQueue.remove(index);
                    }
                    priorityQueue.insert(new HeapNode(destination));
                }
            }
        }
    }
}

double Graph::getDistance(string name)
{
    Node<Vertex> *vertex = this->search(name);
    if (vertex == nullptr)
    {
        return -1;
    }
    return vertex->value->distance;
}

string Graph::getPath(Vertex *vertex)
{
    if (vertex->parent == nullptr)
    {
        return vertex->name;
    }
    return getPath(vertex->parent) + " " + vertex->name;
}

int Graph::getNumEdges() const
{
    return this->numEdges;
}

void Graph::print() const
{
    return this->nodes.print();
}

int Graph::getSize() const
{
    return this->nodes.getSize();
}

#endif