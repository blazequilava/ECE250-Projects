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
#ifndef LINKEDLIST_CPP
#define LINKEDLIST_CPP
using namespace std;
#include "LinkedList.h"
#include "Node.h"
#include <string>
#include <iostream>
//Constructors
template <class T>
LinkedList<T>::LinkedList()
{
    this->size = 0;
    this->start = nullptr;
    this->back = nullptr;
}

// destructor
template <class T>
LinkedList<T>::~LinkedList()
{
    while (this->size > 0)
    {
        this->pop();
    }
}
//Functions
template <class T>
void LinkedList<T>::operator=(LinkedList<T> list) //Equate two linked lists
{
    while (this->size != 0)
    {
        this->pop();
    }
    this->start = nullptr;
    this->back = nullptr;
    if (list.start == nullptr)
    {
        return;
    }
    Node<T> *currentNode = list.start;
    this->push(currentNode->value);
    while (currentNode->next != nullptr)
    {
        this->push(currentNode->value);
        currentNode = currentNode->next;
    }
}
template <class T>
void LinkedList<T>::push(T *value) //Appends to the end of the list
{
    this->size++;
    if (this->start == nullptr)
    {
        this->start = new Node<T>();
        *(this->start) = value;
        this->start->next = nullptr;
        this->start->previous = nullptr;
        this->back = this->start;
    }
    else
    {
        this->back->next = new Node<T>();
        this->back->next->previous = this->back;
        this->back = this->back->next;
        *(this->back) = value;
    }
}
template <class T>
void LinkedList<T>::pop() //Removes from the end of the list
{
    if (this->back == nullptr)
    {
        this->size = 0;
        return;
    }
    this->size--;
    if (this->back->previous == nullptr)
    {
        delete this->start;
        this->start = nullptr;
        this->back = nullptr;
        this->size = 0;
    }
    else
    {
        this->back = this->back->previous;
        delete this->back->next;
        this->back->next = nullptr;
    }
}
template <class T>
void LinkedList<T>::remove(Node<T> *currentNode) //Removes the node given in the parameter
{
    this->size--;
    if (currentNode == this->start && currentNode == this->back)
    {
        this->start = nullptr;
        this->back = nullptr;
        this->size = 0;
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
template <class T>
Node<T> *LinkedList<T>::getStart() const //get values
{
    return this->start;
}
template <class T>
Node<T> *LinkedList<T>::getBack() const
{
    return this->back;
}
template <class T>
int LinkedList<T>::getSize() const
{
    return this->size;
}
template <class T>
void LinkedList<T>::print() const
{
    if (this->start == nullptr)
    {
        cout << "[]" << endl;
        return;
    }
    cout << "[";
    Node<T> *currentNode = this->start;
    cout << currentNode->value->print();
    while (currentNode->next != nullptr)
    {
        currentNode = currentNode->next;
        cout << "," << currentNode->value->print();
    }
    cout << "]" << endl;
}

template <class T>
Node<T> *LinkedList<T>::search(string name)
{
    if (this->size < 1)
    {
        return nullptr;
    }
    Node<T> *currentNode = this->start;
    while (currentNode->next != nullptr)
    {
        if (*(currentNode->value) == name)
        {
            return currentNode;
        }
        currentNode = currentNode->next;
    }
    if (*(currentNode->value) == name)
    {
        return currentNode;
    }
    return nullptr;
}

#endif