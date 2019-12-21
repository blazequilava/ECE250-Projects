/**
 * Heap class used for project 4 written by Devon Miller-Junk
*/

using namespace std;
#include <string>
#ifndef HEAP_H
#define HEAP_H
template <class T>
class Heap
{
private:
    bool min;
    T *heap;
    int size;
    int numElements;
    bool comparison(int a, int b) const;
    void swap(int a, int b);

public:
    Heap(bool min, int size);
    Heap(bool min, T *heap, int size);
    ~Heap();
    void heapify(int index);
    void upSort(int index);
    int search(string name) const;
    int length() const;
    bool isEmpty() const;
    double rootValue();
    bool insert(T *value);
    T remove(int index);
    void print() const;
};

#endif