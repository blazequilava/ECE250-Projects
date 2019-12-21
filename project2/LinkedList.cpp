/**
 * Linked List File written by Devon Miller-Junk for the purposes of ECE250 Fall 2019.
 * 
 * Defines the linked list class and all of it's functions. This linked list is a doubly linked list with a pointer to 
 * the start/head node and the back/end node. Each node has a int value, a pointer to the previous node and a pointer to the next node.
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
LinkedList::LinkedList(const int &size, const int coeff[])
{
    this->size = size;
    if (size == 0)
    {
        start = nullptr;
        back = nullptr;
        return;
    }
    Node *currentNode = new Node();
    this->start = currentNode;
    this->start->value = coeff[0];
    this->start->previous = nullptr;
    for (int i = 1; i < size; i++)
    {
        Node *temp = new Node();
        temp->value = coeff[i];
        currentNode->next = temp;
        temp->previous = currentNode;
        currentNode = temp;
    }
    currentNode->next = nullptr;
    this->back = currentNode;
}

LinkedList::LinkedList()
{
    size = 0;
    start = nullptr;
    back = nullptr;
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
void LinkedList::push(const int value) //Appends to the end of the list
{
    this->size++;
    if (this->back == nullptr)
    {
        this->start = new Node();
        this->start->value = value;
        this->start->next = nullptr;
        this->start->previous = nullptr;
        this->back = this->start;
        return;
    }
    else
    {
        this->back->next = new Node();
        this->back->next->previous = this->back;
        this->back = this->back->next;
        this->back->value = value;
    }
}

void LinkedList::pop() //Removes from the end of the list
{
    if (this->back == nullptr)
    {
        this->size = 0;
        return;
    }
    this->size--;
    this->back = this->back->previous;
    if (this->back == nullptr)
    {
        delete this->start;
        this->start = nullptr;
        this->size = 0;
    }
    else
    {
        delete this->back->next;
        this->back->next = nullptr;
    }
}

void LinkedList::remove(Node *currentNode) //Removes the node given in the parameter
{
    this->size--;
    if (currentNode == this->start && currentNode == this->back)
    {
        this->start = nullptr;
        this->back = nullptr;
    }
    else if (currentNode == this->start)
    {
        this->start = currentNode->next;
        currentNode->next->previous = nullptr;
    }
    else if (currentNode == this->back)
    {
        this->back = currentNode->previous;
        currentNode->previous->next = nullptr;
    }
    else
    {
        currentNode->previous->next = currentNode->next;
        currentNode->next->previous = currentNode->previous;
    }
    delete currentNode;
}

Node *LinkedList::getStart() const //get values
{
    return this->start;
}

Node *LinkedList::getBack() const
{
    return this->back;
}
int LinkedList::getSize() const
{
    return this->size;
}
void LinkedList::print() const
{
    if (this->start == nullptr)
    {
        cout << "Empty list" << endl;
        return;
    }
    Node *currentNode = this->start;
    cout << currentNode->value << ",";
    while (currentNode->next != nullptr)
    {
        currentNode = currentNode->next;
        cout << currentNode->value << ",";
    }
    cout << endl;
}

#endif