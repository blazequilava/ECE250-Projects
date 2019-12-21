/**
 * Polynomial Header File written by Devon Miller-Junk for the purposes of ECE250 Project 0 Fall 2019.
 * 
 * Implements a polynomial class which contains a pointer to a linked list. The linked list contains
 * the coefficients of the polynomial ordered from lowest degree to highest degree (i.e. the first node has the constant term)
 * 
 **/
#include "LinkedList.cpp"
#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
class Polynomial
{
private:
    //Note: Linked List organized from lowest to highest degree terms
    LinkedList *coefficients;

public:
    Polynomial(const int &size, const double coefficients[]);
    Polynomial();
    ~Polynomial();

    bool operator==(const Polynomial &polynomial) const; //Strict equality (same degree and coefficients)
    Polynomial &operator=(const Polynomial &polynomial);

    Polynomial operator+(const Polynomial &polynomial);
    Polynomial operator*(const Polynomial &polynomial);

    void set(const int &index, const double value); //Sets an individual value at index index
    double evaluate(const double value) const;      //Returns the evaluation of the polynomial at a point
    void print() const;                             //Just used for development/testing purposes
    void push(const double value);                  //Appends to a polynomial
};

#endif