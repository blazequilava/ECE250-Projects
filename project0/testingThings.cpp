#include <iostream>
#include <string>
#include "Polynomial.h"
#include "Polynomial.cpp"
#include "LinkedList.h"
#include "LinkedList.cpp"
#include "utils.cpp"
using namespace std;

string getCommand(string input)
{
    string result;
    int i = 0;
    while (input[i] != '\0')
    {
        if (input[i] == ' ')
        {
            return result;
        }
        result += input[i];
        i++;
    }
    return result;
};
void coefficientSplitter(string &input, Polynomial &polynomial)
{
    string part = input.substr(0, input.find(';'));
    polynomial.push(stod(part.substr(part.find(' ') + 1)));
    input = input.substr(input.find(';') + 1);
};
Polynomial toCoefficients(string input)
{
    string polynomialPart = input.substr(input.find(' ') + 1);
    Polynomial result = Polynomial();
    int i = 0;
    while (polynomialPart.find(';') != string::npos)
    {
        coefficientSplitter(polynomialPart, result);
    }
    coefficientSplitter(polynomialPart, result);
    return result;
};
int main()
{

    //POlynomials to use:
    //Polynomial p2;
    double coefficients[5] = {1.0, 2.0, 3.0, 4.0, 5.0};
    Polynomial p1(5, coefficients);
    p1.print();
};
