/**
 * This is the Hash Table Linear Probing cpp file for use in project 2 of ECE 250 by Devon Miller-Junk. It implements a hash table that uses open addressing
 * to handle collision.
*/

#include "HashTableLinProb.h"
#include <iostream>
#include <algorithm>
using namespace std;
#ifndef HASHTABLELINPROB_CPP
#define HASHTABLELINPROB_CPP

//Node Functions
//Constructors
Node::Node()
{
    value = 0;
    state = uninitialized;
}
Node::Node(const Node &node)
{
    this->value = node.value;
    this->state = node.state;
}

Node::Node(const int value)
{
    this->value = value;
    this->state = initialized;
}
//Destructor
Node::~Node()
{
    //Nothing necessary
}
//Operator overloaders
bool Node::operator==(const int value) const
{
    return this->state == initialized && this->value == value;
}

Node &Node::operator=(const int value)
{
    this->value = value;
    this->state = initialized;
}
//State checkers
bool Node::isInitialized() const
{
    return this->state == initialized;
}

bool Node::isUninitialized() const
{
    return this->state == uninitialized;
}
//delete the node
void Node::deletion()
{
    this->state = deleted;
}
//Getting values
int Node::getValue() const
{
    return this->value;
}

NodeState Node::getState() const
{
    return this->state;
}

//HashTable Functions
//Constructors
HashTableLinProb::HashTableLinProb()
{
    //Default size to 10
    table = new Node[10];
    size = 10;
    numElements = 0;
    for (int i = 0; i < 10; i++)
    {
        table[i] = Node();
    }
}

HashTableLinProb::HashTableLinProb(const int size)
{
    table = new Node[size];
    this->size = size;
    this->numElements = 0;
    for (int i = 0; i < size; i++)
    {
        table[i] = Node();
    }
}

HashTableLinProb::HashTableLinProb(const HashTableLinProb &hashTable)
{
    this->size = hashTable.size;
    this->numElements = numElements;
    delete[] table;
    table = new Node[size];
    for (int i = 0; i < size; i++)
    {
        table[i] = Node(hashTable.table[i]);
    }
}
//Destructor
HashTableLinProb::~HashTableLinProb()
{
    delete[] table;
}
//Hash function
int HashTableLinProb::hash(const int value) const
{
    return value % this->size;
}
//Main functions
bool HashTableLinProb::insert(const int value)
{
    if (this->numElements == this->size || !(this->search(value) == -1))
    {
        return false; //Array full or Element already in array
    }
    int location = this->hash(value);
    while (this->table[location].isInitialized()) //Search until you find an element that is deleted or uninitialized
    {
        location = this->hash(++location);
        if (this->hash(location) == this->hash(value)) //Failure hashtable is full (theoretically shouldn't happen)
        {
            return false;
        }
    }
    this->table[location] = value;
    numElements++;
    return true;
}

int HashTableLinProb::search(const int value) const
{
    int location = this->hash(value);
    while (!(this->table[location].isUninitialized() || (this->table[location] == value))) //Loop until you find the value or an uninitialized value
    {
        location = this->hash(++location);
        if (this->hash(location) == this->hash(value)) //Never found value and table is full
        {
            return -1;
        }
    }
    return (this->table[location].isInitialized() && this->table[location] == value) ? location : -1; //Either Found value, or reached an uninitialized value
}

bool HashTableLinProb::deletion(const int value)
{
    int location = this->hash(value);
    while (!(this->table[location].isUninitialized() || (this->table[location] == value))) //Loop until you find the value or an uninitialized value
    {
        location = this->hash(++location);
        if (this->hash(location) == this->hash(value)) //Never found value and table is full
        {
            return false;
        }
    }
    if (this->table[location] == value)
    {
        this->table[location].deletion(); //delete the value
        numElements--;
        return true;
    }
    return false; //Never found value before reaching an uninitialized node.
}
void HashTableLinProb::print() const
{
    for (int i = 0; i < this->size; i++)
    {
        cout << i << ": " << this->table[i].getValue() << " " << this->table[i].getState() << endl;
    }
}
#endif