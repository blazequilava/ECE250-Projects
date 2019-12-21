/**
 * Utils File written by Devon Miller-Junk for the purposes of ECE250 Project 0 Fall 2019.
 * 
 * This is the utility file I will be using for the project. It includes any common functions to be used across all files
 * In this case only one function is being used, to determine if two doubles are "Equal" (accounts for errors in the propogation of calculations)
 **/

#ifndef UTILS
#define UTILS

/**
 * Takes 2 doubles and compares their values to see if they are about equal
 **/
bool equalDouble(double a, double b)
{
    const double first = a < 0 ? -1 * a : a;
    const double second = b < 0 ? -1 * b : b;
    const double margin = 0.001;
    //Use to differenct margin check because percent margin is
    //better for large values, but realMargin is better for small values
    const double realMargin = first > second ? first - second : second - first;
    const double percentMargin = first > second ? ((first - second) / first) : ((second - first) / second);
    return percentMargin < margin || realMargin < margin;
};
#endif
