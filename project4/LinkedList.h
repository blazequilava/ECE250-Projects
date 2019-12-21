/**
 * Linked List File written by Devon Miller-Junk for the purposes of ECE250 Fall 2019.
 * 
 * Defines the linked list class and all of it's functions. This linked list is a doubly linked list with a pointer to 
 * the start/head node and the back/end node. Each node has a Templated value, a pointer to the previous node and a pointer to the next node.
 * 
 * I chose to implement a completely separate linked list class in the hopes that it can be re-used 
 * in the future for any potential needs I have of a linked list class.
 **/
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"
#include <string>
using namespace std;
template <class T>
class LinkedList //Linked List Class
{
private:
    Node<T> *start; //Start of linked list
    Node<T> *back;  //back of linked list
    int size;       //Number of nodes
public:
    LinkedList();
    ~LinkedList();

    void operator=(LinkedList<T> list);
    void push(T *value);               //Appends to the list
    void pop();                        //Removes the node at the back
    void remove(Node<T> *currentNode); //Remove the given node
    Node<T> *getStart() const;
    Node<T> *getBack() const;
    int getSize() const;
    void print() const;
    Node<T> *search(string name);
};

#endif