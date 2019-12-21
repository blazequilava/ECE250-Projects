/**
 * Linked List File written by Devon Miller-Junk for the purposes of ECE250 Fall 2019.
 * 
 * Defines the linked list class and all of it's functions. This linked list is a singly linked list with only a pointer to 
 * the start/head node. Each node has a double value and a pointer to the next node.
 * 
 * I chose to implement a completely separate linked list class in the hopes that it can be re-used 
 * in the future for any potential needs I have of a linked list class.
 * 
 **/

using namespace std;
#include "LinkedList.h"

#ifndef LINKEDLIST_CPP
#define LINKEDLIST_CPP

//Constructors
LinkedList::LinkedList(const int &size, const double coeff[])
{
    this->size = size;
    if (size == 0)
    {
        start = NULL;
        return;
    }
    Node *currentNode = new Node;
    this->start = currentNode;
    this->start->value = coeff[0];
    for (int i = 1; i < size; i++)
    {
        Node *temp = new Node;
        temp->value = coeff[i];
        currentNode->next = temp;
        currentNode = temp;
    }
    currentNode->next = NULL;
}

LinkedList::LinkedList()
{
    size = 0;
    start = NULL;
}

// destructor
LinkedList::~LinkedList()
{
    while (this->size != 0)
    {
        this->pop();
    }
}
//Functions
void LinkedList::push(const double value) //Appends to the end of the list
{
    this->size++;
    if (this->start == NULL)
    {
        this->start = new Node();
        this->start->value = value;
        return;
    }
    else
    {
        Node *currentNode = this->start;
        while (currentNode->next != NULL)
        {
            currentNode = currentNode->next;
        }
        Node *nextNode = new Node();
        nextNode->value = value;
        currentNode->next = nextNode;
    }
}

void LinkedList::pop() //Removes from the end of the list
{
    if (this->start == NULL)
    {
        this->size = 0;
        return;
    }
    this->size--;
    Node *currentNode = this->start;
    if (currentNode->next == NULL)
    {
        this->start = NULL;
        return;
    }
    while (currentNode->next->next != NULL)
    {
        currentNode = currentNode->next;
    }
    Node *temp = currentNode->next;
    currentNode->next = NULL;
    delete temp;
}

Node *LinkedList::getStart() const
{
    return this->start;
}

int LinkedList::getSize() const
{
    return this->size;
}

#endif