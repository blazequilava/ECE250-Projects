#include "Heap.h"
#ifndef HEAP_CPP
#define HEAP_CPP
#include <iostream>
using namespace std;
template <class T>
bool Heap<T>::comparison(int a, int b) const
{
    if (this->min)
    {
        return ((!(this->heap[a] == T())) && (this->heap[b] > this->heap[a] || this->heap[b] == T()));
    }
    else
    {
        return ((!(this->heap[a] == T())) && this->heap[a] > this->heap[b]);
    }
}

template <class T>
void Heap<T>::swap(int a, int b)
{
    T temp = this->heap[a];
    this->heap[a] = this->heap[b];
    this->heap[b] = temp;
}

template <class T>
void Heap<T>::heapify(int index)
{
    if (index >= this->size)
    {
        return;
    }
    int selection = index;
    if (2 * index + 2 < this->size)
    {
        selection = this->comparison(2 * index + 2, selection) ? 2 * index + 2 : selection;
    }
    if (2 * index + 1 < this->size)
    {
        selection = this->comparison(2 * index + 1, selection) ? 2 * index + 1 : selection;
    }
    if (selection != index)
    {
        this->swap(selection, index);
        this->heapify(selection);
    }
}

template <class T>
void Heap<T>::upSort(int index)
{
    if (index == 0 || index >= this->size || this->heap[index] == T())
    {
        return;
    }
    else if (this->comparison(index, (index - 1) / 2))
    {
        this->swap(index, (index - 1) / 2);
        this->upSort((index - 1) / 2);
    }
}

//Constructors
template <class T>
Heap<T>::Heap(bool min, int size)
{
    this->min = min;
    this->size = size;
    this->numElements = 0;
    this->heap = new T[size];
    for (int i = 0; i < size; i++)
    {
        heap[i] = T();
    }
}

template <class T>
Heap<T>::Heap(bool min, T *heap, int size)
{
    this->min = min;
    this->size = size;
    this->heap = new T[size];
    this->numElements = 0;
    for (int i = 0; i < size; ++i)
    {
        this->heap[i] = heap[i];
        if (heap[i] != T())
        {
            ++this->numElements;
        }
    }
    for (int i = this->size / 2; i >= 0; --i)
    {
        this->heapify(i);
    }
}

//Destructor
template <class T>
Heap<T>::~Heap()
{
    delete[] heap;
}

//Other Functions
template <class T>
int Heap<T>::search(string name) const
{
    for (int i = 0; i < this->size; ++i)
    {
        if (*(this->heap[i].getValue()) == name)
        {
            return i;
        }
    }
    return -1;
}

template <class T>
int Heap<T>::length() const
{
    return this->size;
}

template <class T>
bool Heap<T>::isEmpty() const
{
    return this->numElements == 0;
}

template <class T>
double Heap<T>::rootValue()
{
    return this->heap[0];
}

template <class T>
bool Heap<T>::insert(T *value)
{
    for (int i = 0; i < this->size; ++i)
    {
        if (this->heap[i] == T())
        {
            this->heap[i] = value;
            this->numElements++;
            this->upSort(i);
            return true;
        }
    }
    return false;
}

template <class T>
T Heap<T>::remove(int index)
{
    if (index < 0 || index >= this->numElements)
    {
        return T();
    }
    T result = this->heap[index];
    if (!(result == T()))
    {
        this->numElements--;
        this->heap[index] = T();
        this->heapify(index);
    }
    return result;
}

template <class T>
void Heap<T>::print() const
{
    cout << "[";
    for (int i = 0; i < this->size; ++i)
    {
        cout << this->heap[i].print();
        if (i + 1 != this->size)
        {
            cout << ",";
        }
    }
    cout << "]" << endl;
}
#endif