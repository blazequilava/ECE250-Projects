/**
 * This is the Hash Table Linear Probing header file for use in project 2 of ECE 250 by Devon Miller-Junk. It implements a hash table that uses open addressing
 * to handle collision.
*/

#include <iostream>

#ifndef HASHTABLELINPROB_H
#define HASHTABLELINPROB_H
enum NodeState //Different states that a node can take on
{
    initialized,
    deleted,
    uninitialized
};
struct Node //Node Struct
{
private:
    int value;
    NodeState state;

public:
    Node(); //Constructors
    Node(const Node &node);
    Node(const int value);
    ~Node();                                //destructor
    bool operator==(const int value) const; //Operator overloading
    Node &operator=(const int value);
    bool isInitialized() const; //State checkers
    bool isUninitialized() const;
    void deletion();      //Deleting the node
    int getValue() const; //Get values
    NodeState getState() const;
};
class HashTableLinProb //Hash table Class
{
private:
    int size;                        //Size of hash table
    int numElements;                 //Number of elements in the hash table
    Node *table;                     //array of nodes (the table)
    int hash(const int value) const; //hash function

public:
    HashTableLinProb(); //constructors
    HashTableLinProb(const int size);
    HashTableLinProb(const HashTableLinProb &hashTable);
    ~HashTableLinProb();               //destructor
    bool insert(const int value);      //Insert into next deleted/uninitialized space
    int search(const int value) const; //search for node
    bool deletion(const int value);    //Delete if node found
    void print() const;                //print function used for developmental purposes
};

#endif