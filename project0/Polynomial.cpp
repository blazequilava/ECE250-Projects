/**
 * Polynomial File written by Devon Miller-Junk for the purposes of ECE250 Project 0 Fall 2019.
 * 
 * Implements a polynomial class which contains a pointer to a linked list. The linked list contains
 * the coefficients of the polynomial ordered from lowest degree to highest degree (i.e. the first node has the constant term)
 * 
 **/

#include <iostream>
#include <math.h>
#include <algorithm>

#include "Polynomial.h"
#include "LinkedList.h"
#include "LinkedList.cpp"
#include "utils.cpp"

using namespace std;

#ifndef POLYNOMIAL_CPP
#define POLYNOMIAL_CPP

// constructors
Polynomial::Polynomial(const int &size, const double coefficients[])
{
    this->coefficients = new LinkedList(size, coefficients);
}

Polynomial::Polynomial()
{
    coefficients = new LinkedList();
}

// destructor
Polynomial::~Polynomial()
{
    delete this->coefficients;
}

//Functions

//Sets the value at index to the passed in value
void Polynomial::set(const int &index, const double value)
{
    if (index >= this->coefficients->getSize())
    {
        return;
    }
    Node *currentNode = this->coefficients->getStart();
    for (int i = 0; i < index; i++)
    {
        currentNode = currentNode->next;
    }
    currentNode->value = value;
}

//Strict equality (same size and coefficients)
bool Polynomial::operator==(const Polynomial &polynomial) const
{
    int size = this->coefficients->getSize();
    int secondSize = polynomial.coefficients->getSize();
    if (size != secondSize)
        return false;
    Node *currentNode = this->coefficients->getStart();
    Node *secondCurrentNode = polynomial.coefficients->getStart();
    for (int i = 0; i < size; i++)
    {
        //Uses double comparison function from utility file
        if (!equalDouble(currentNode->value, secondCurrentNode->value))
        {
            return false;
        }
        currentNode = currentNode->next;
        secondCurrentNode = secondCurrentNode->next;
    }
    return true;
}

Polynomial &Polynomial::operator=(const Polynomial &polynomial)
{
    delete coefficients;
    const int size = polynomial.coefficients->getSize();
    double *newCoefficients = new double[size];
    Node *currentNode = polynomial.coefficients->getStart();
    for (int i = 0; i < size; i++)
    {
        newCoefficients[i] = currentNode->value;
        currentNode = currentNode->next;
    }
    this->coefficients = new LinkedList(size, newCoefficients);
    delete[] newCoefficients;
}

Polynomial Polynomial::operator+(const Polynomial &polynomial)
{
    int newSize = max(this->coefficients->getSize(), polynomial.coefficients->getSize());
    double *coefficients = new double[newSize];
    for (int i = 0; i < newSize; i++)
    {
        coefficients[i] = 0;
    }
    //Go through first polynomial
    int size = this->coefficients->getSize();
    Node *currentNode = this->coefficients->getStart();
    for (int i = 0; i < size; i++)
    {
        coefficients[i] += currentNode->value;
        currentNode = currentNode->next;
    }

    //Go through second polynomial
    size = polynomial.coefficients->getSize();
    currentNode = polynomial.coefficients->getStart();
    for (int i = 0; i < size; i++)
    {
        coefficients[i] += currentNode->value;
        currentNode = currentNode->next;
    }

    Polynomial result(newSize, coefficients);

    delete[] coefficients;

    return result;
}

Polynomial Polynomial::operator*(const Polynomial &polynomial)
{
    int newSize = this->coefficients->getSize() + polynomial.coefficients->getSize() - 1;
    double *coefficients = new double[newSize];
    for (int i = 0; i < newSize; i++)
    {
        coefficients[i] = 0;
    }
    int size = this->coefficients->getSize();
    int secondSize = polynomial.coefficients->getSize();
    Node *currentNode = this->coefficients->getStart();
    Node *secondCurrentNode = new Node;
    for (int i = 0; i < size; i++)
    {
        secondCurrentNode = polynomial.coefficients->getStart();
        for (int j = 0; j < secondSize; j++)
        {
            coefficients[i + j] += currentNode->value * secondCurrentNode->value;
            secondCurrentNode = secondCurrentNode->next;
        }
        currentNode = currentNode->next;
    }

    Polynomial result(newSize, coefficients);

    delete[] coefficients;

    return result;
}

double Polynomial::evaluate(const double value) const
{
    //TODO: Use Horner's method to implement an evaluation method that prevents overflow
    double output = 0.0;
    int size = this->coefficients->getSize();
    Node *currentNode = this->coefficients->getStart();
    for (int i = 0; i < size; i++)
    {
        output += currentNode->value * pow(value, i);
        if (i != size - 1)
        {
            currentNode = currentNode->next;
        }
    }
    return output;
}

void Polynomial::print() const //Just used for developmental and testing purposes
{
    int size = this->coefficients->getSize();
    cout << "p(x)=";
    if (size == 0)
    {
        cout << "0+";
    }
    else
    {
        Node *currentNode = this->coefficients->getStart();
        for (int i = 0; i < size; i++)
        {
            cout << currentNode->value << "x^" << i << "+";
            currentNode = currentNode->next;
        }
    }
    cout << "\b \b" << endl;
}

void Polynomial::push(const double value) //Appends to the polynomial (increases degree by one)
{
    this->coefficients->push(value);
}

#endif