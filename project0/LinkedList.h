/**
 * Linked List Header File written by Devon Miller-Junk for the purposes of ECE250 Fall 2019.
 * 
 * Defines the linked list class and all of it's functions. This linked list is a singly linked list with only a pointer to 
 * the start/head node. Each node has a double value and a pointer to the next node.
 * 
 * I chose to implement a completely separate linked list class in the hopes that it can be re-used 
 * in the future for any potential needs I have of a linked list class.
 * 
 **/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

//TODO: Implement as a Template to use with future projects where they might not need doubles
struct Node
{
    Node *next;
    double value;
};

class LinkedList
{
private:
    Node *start;
    int size; //Number of nodes
public:
    LinkedList(const int &size, const double coeff[]);
    LinkedList();
    ~LinkedList();

    void push(const double value); //Appends to the list
    void pop();                    //Removes the last node from the list
    Node *getStart() const;
    int getSize() const;
};

#endif