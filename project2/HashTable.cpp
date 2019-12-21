/**
 * This is the Hash Table cpp file for use in project 2 of ECE 250 by Devon Miller-Junk. It implements a hash table that uses chaining
 * to handle collision.
*/

#include "HashTable.h"
#include <iostream>
#include <algorithm>

#ifndef HASHTABLE_CPP
#define HASHTABLE_CPP

//HashTable Functions

//Constructors
HashTable::HashTable()
{
    //Default size to 10
    table = new LinkedList[10];
    size = 10;
    for (int i = 0; i < 10; i++)
    {
        table[i] = LinkedList();
    }
}

HashTable::HashTable(const int size)
{
    table = new LinkedList[size];
    this->size = size;
    for (int i = 0; i < size; i++)
    {
        table[i] = LinkedList();
    }
}
//Destructor
HashTable::~HashTable()
{
    delete[] table;
}
//The hash function
int HashTable::hash(const int value) const
{
    return value % this->size;
}
//Main functions
bool HashTable::insert(const int value)
{
    int location = this->hash(value);
    if (this->table[location].getStart() != nullptr)
    {
        Node *currentNode = this->table[location].getStart();
        while (currentNode->value != value && currentNode->next != nullptr) //repeat until end of linked list
        {
            currentNode = currentNode->next;
        }
        if (currentNode->value == value)
        {
            return false;
        }
    }
    this->table[location].push(value); //Insert if not already in the linked list
    return true;
}

int HashTable::search(const int value) const
{
    int location = this->hash(value);
    if (this->table[location].getStart() != nullptr)
    {
        Node *currentNode = this->table[location].getStart();
        while (currentNode->value != value && currentNode->next != nullptr) //Search through the linked list linearly
        {
            currentNode = currentNode->next;
        }
        if (currentNode->value == value)
        {
            return location;
        }
    }
    return -1;
}

bool HashTable::deletion(const int value)
{
    int location = this->hash(value);
    if (this->table[location].getStart() != nullptr)
    {
        Node *currentNode = this->table[location].getStart();
        while (currentNode->value != value && currentNode->next != nullptr) //Search through linked list for element
        {
            currentNode = currentNode->next;
        }
        if (currentNode->value == value)
        {
            this->table[location].remove(currentNode);
            return true;
        }
    }
    return false;
}
void HashTable::print() const //Used for developmental purposes
{
    for (int i = 0; i < this->size; i++)
    {
        cout << i << ": ";
        this->table[i].print();
    }
}
#endif