// Polynomial.h
// Class interface/header file for  polynomial
// Author: Tiuley Alguindigue (Aug 2019)

#include <iostream>
using namespace std;

// Polynomial for single variable X

class Polynomial
{

    // class variables
private:
    double *coeff; // coefficients
    int size;      // degree + 1

    // class functions
public:
    Polynomial(const int &size_p, const double coeff_p[]);
    Polynomial();
    ~Polynomial();

    // copy constructor and equal operator
    Polynomial(const Polynomial &polynomial_to_copy);
    Polynomial &operator=(const Polynomial &other);

    /* comparison operator == and != */

    bool operator==(const Polynomial &right);
    bool operator!=(const Polynomial &right);

    // add and +
    Polynomial add(const Polynomial &right) const;
    Polynomial operator+(const Polynomial &right);

    //evaluate a polynomial
    double evaluate(const double &x) const;

    // print the polynomial
    void print();
};
