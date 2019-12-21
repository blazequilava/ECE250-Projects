// Polynomial.cpp - implementation file for Polynomial class
// Author: Tiuley Alguindigue (Aug 2019)

#include <algorithm> // std::max
#include <iostream>
using namespace std;

#include "PolynomialFromClass.h"

// constructors

Polynomial::Polynomial(const int &size_p, const double coeff_p[])
{
	size = size_p;
	coeff = new double[size];

	for (int i = 0; i < size_p; i++)
	{
		coeff[i] = coeff_p[i];
	}
}

Polynomial::Polynomial()
{
	coeff = 0;
	size = 0;
}

// copy constructor
Polynomial::Polynomial(const Polynomial &polynomial_to_copy)
{
	this->size = polynomial_to_copy.size;
	coeff = new double[size];

	for (int i = 0; i < size; i++)
	{
		this->coeff[i] = polynomial_to_copy.coeff[i];
	}
}

// destructor
Polynomial::~Polynomial()
{
	delete[] coeff; // delete array that starts at address stored in coeff
}

//
// assignment operator that is exception safe - uses the copy-swap idiom
Polynomial &Polynomial::operator=(const Polynomial &other) // copy assignment
{
	// make a copy of th eright hand side
	Polynomial temp(other);

	//Now, swap the data members with the temporary
	std::swap(size, temp.size);
	std::swap(coeff, temp.coeff);

	return *this;
}

// == operator  and != for comparison
bool Polynomial::operator==(const Polynomial &right)
{
	if (right.size == size)
	{
		for (int i = 0; i < right.size; ++i)
		{
			if (right.coeff[i] != coeff[i])
				return false;
		}
		return true;
	}

	return false;
}

bool Polynomial::operator!=(const Polynomial &right)
{
	return !(*this == right);
}

Polynomial Polynomial::add(const Polynomial &right) const
{
	int temp_size = max(this->size, right.size);

	double *temp = new double[temp_size]; // allocate temp array

	int t_max;
	// if degree of right is the largest
	if (right.size > this->size)
	{

		t_max = this->size;

		for (int i = 0; i < t_max; i++)
		{
			temp[i] = this->coeff[i] + right.coeff[i];
		}

		for (int i = t_max; i < right.size; i++)
		{
			temp[i] = right.coeff[i];
		}
	}

	else //if degree of this-> is the largest
		if (right.size <= this->size)
	{

		t_max = right.size;

		for (int i = 0; i < t_max; i++)
		{
			temp[i] = this->coeff[i] + right.coeff[i];
		}

		for (int i = t_max; i < this->size; i++)
		{
			temp[i] = this->coeff[i];
		}
	}

	Polynomial p(temp_size, temp);

	delete[] temp; // delete temp array

	return p;
}

Polynomial Polynomial::operator+(const Polynomial &right)
{
	int temp_size = max(this->size, right.size);

	double *temp = new double[temp_size]; // allocate temp array

	int t_max;
	// if degree of right is the largest
	if (right.size > this->size)
	{

		t_max = this->size;

		for (int i = 0; i < t_max; i++)
		{
			temp[i] = this->coeff[i] + right.coeff[i];
		}

		for (int i = t_max; i < right.size; i++)
		{
			temp[i] = right.coeff[i];
		}
	}

	else							  //if degree of this-> is the largest
		if (right.size <= this->size) //this->property for pointers, this.property for val
	{								  //*this is value of curretnt objects. this is a pointer to the currrent object.

		t_max = right.size;

		for (int i = 0; i < t_max; i++)
		{
			temp[i] = this->coeff[i] + right.coeff[i];
		}

		for (int i = t_max; i < this->size; i++)
		{
			temp[i] = this->coeff[i];
		}
	}

	Polynomial p(temp_size, temp);

	delete[] temp; // delete temp array

	return p;
}

void Polynomial::print()
{
	for (int i = 0; i < size; i++)
	{
		cout << coeff[i] << " ";
	}

	cout << endl;
}

double Polynomial::evaluate(const double &x) const //First constant: don't change the pointer that is the parameter, second const means don't change this object
{
	double sum = 0.0;
	for (int i = 0; i < size; i++)
	{
		sum += coeff[i] * pow(x, i);
	}
	return sum;
}
