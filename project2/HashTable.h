/**
 * This is the Hash Table header file for use in project 2 of ECE 250 by Devon Miller-Junk. It implements a hash table that uses chaining
 * to handle collision.
*/

#include <iostream>
#include "LinkedList.cpp"
#ifndef HASHTABLE
#define HASHTABLE
class HashTable
{
private:
    int size;                        //Size of the hash table
    LinkedList *table;               //Array of linked lists
    int hash(const int value) const; //Hash function

public:
    HashTable(); //Constructors
    HashTable(const int size);
    ~HashTable();                      //Destructors
    bool insert(const int value);      //Insert into index if not already there
    int search(const int value) const; //Search for value
    bool deletion(const int value);    //Delete value if there
    void print() const;                //Print out hash table, used for developmental purposes
};

#endif