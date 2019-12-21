// polynomialtest.cpp - Test file  Polynomial class (as array)
// Author: Tiuley Alguindigue (Aug 2019)

#include <iostream>
using namespace std;

#include "PolynomialFromClass.h" // Class to represent polynomials

int main()
{

	double p1_array[] = {0.0, 1.0, 3.0};
	Polynomial p1(3, p1_array); // 3 -terms - 0 + X + 3X**2
	cout << "p1: " << endl;
	p1.print();
	cout << endl;

	double p2_array[] = {1.0, 0.0, 1.0, 2.0};
	Polynomial p2(4, p2_array); //4-terms  1 + X**2 + 2X**3
	cout << "p2: " << endl;
	p2.print();
	cout << endl;

	Polynomial p3; // emptty polynomial
	cout << "p3: " << endl;
	p3.print();
	cout << endl;

	Polynomial p1copy(p1); // declaring polynomial with value of p1
	cout << "p1copy: " << endl;
	p1copy.print();
	cout << endl;

	Polynomial p4;
	p4 = p1.add(p2); // needs = operator
	cout << "p4 = p1 + p2:  " << endl;
	p4.print();
	cout << endl;

	// adding with "+"
	Polynomial p5;
	p5 = p1 + p2;
	cout << "p5 = p1 + p2: " << endl;
	p5.print();
	cout << endl;

	/*
		Add here your code to test other methids you implement
		Examples:

		- evaluate  (returns the value of polynomial at given x)
		- derivative (returns the polynomial representing the derivative)
		- diff (you could alternatively overraide "-" )
		- mult  (you could alternatively overraide "*" )


		*/

	return 0;
}
