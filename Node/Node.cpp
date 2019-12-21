//Implements Node Class for Project 0.

#include <algorithm> // std::max
#include <iostream>
using namespace std;
#include "Node.h"
template <class T>

// constructors

Node<T>::Node(const T value)
{
	this->value = value;
	next = NULL;
}

Node<T>::Node()
{
	next = NULL;
}

// destructor
Node<T>::~Node()
{
	delete next;
}

double Node<T>::getValue()
{
	return this->value;
}

void Node<T>::setValue(const T value)
{
	this->value = value;
}

Node<T> Node<T>::getNext()
{
	return this->next;
}

void Node<T>::setNext(Node<T> next)
{
	this->next = &next;
}
