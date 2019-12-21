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

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct Node //Node struct
{
    Node *next;
    Node *previous;
    int value;
};

class LinkedList //Linked List Class
{
private:
    Node *start; //Start of linked list
    Node *back;  //back of linked list
    int size;    //Number of nodes
public:
    LinkedList(const int &size, const int coeff[]); //Constructors and destructors
    LinkedList();
    ~LinkedList();

    void push(const int value); //Appends to the list
    void pop();                 //Removes the last node from the list
    void remove(Node *node);    //Remove the given node
    Node *getStart() const;     //Get functions
    Node *getBack() const;
    int getSize() const;
    void print() const;
};

#endif