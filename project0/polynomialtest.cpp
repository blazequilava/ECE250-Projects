/**
 * Polynomial Test File written by Devon Miller-Junk for the purposes of ECE250 Project 0 Fall 2019.
 * 
 * Implements the functions and code to be able to read from the inputs and perform the corresponding operations.
 * This is the file that should be compiled and run while evaluating the polynomial class.
 * 
 **/

#include <iostream>
#include <string>
#include "Polynomial.h"
#include "Polynomial.cpp"
#include "LinkedList.h"
#include "LinkedList.cpp"
#include "utils.cpp"
using namespace std;

string getCommand(string input) //Gets the command from the line of input
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
void coefficientSplitter(string &input, Polynomial &polynomial) //Adds a single coefficients to the polynomial
{
    string part = input.substr(0, input.find(';'));
    polynomial.push(stod(part.substr(part.find(' ') + 1)));
    input = input.substr(input.find(';') + 1);
};
Polynomial toCoefficients(string input) //Creates the polynomial from the coefficients given in the line of input
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
    //Constants:
    const string success = "success";
    const string failure = "failure";

    //Polynomials to use:
    Polynomial p1;
    Polynomial p2;

    //Strings to use with parsing input
    string line;    //entire line
    string command; //command to use
    string result;  //output

    while (getline(cin, line))
    {
        command = getCommand(line);
        result = failure; //Default result to failure incase line is not parsed correctly/bad input
        if (command == "init")
        {
            result = success;
        }
        else if (command == "coeff_p1")
        {
            p1 = toCoefficients(line);
            result = success;
        }
        else if (command == "coeff_p2")
        {
            p2 = toCoefficients(line);
            result = success;
        }
        else if (command == "get")
        {
            result = (p1 == toCoefficients(line)) ? success : failure;
        }
        else if (command == "eval")
        {
            string secondPart = line.substr(line.find(' ') + 1);
            double firstValue = stod(secondPart.substr(0, line.find(' ')));
            double secondValue = stod(secondPart.substr(secondPart.find(' ') + 1));
            //Uses compare double function from the util file
            result = (equalDouble(p1.evaluate(firstValue), secondValue)) ? success : failure;
        }
        else if (command == "add")
        {
            result = ((p1 + p2) == toCoefficients(line)) ? success : failure;
        }
        else if (command == "mult")
        {
            result = ((p1 * p2) == toCoefficients(line)) ? success : failure;
        }
        cout << result << endl;
    }
};
