/*
* Author: Maxwell McEwan
* Assignment Title: My Functions
* Assignment Description: In this programming assignment you will be asked
*       to implement a number of useful functions using a header file and an
*       implementation file. You will place the prototypes for your function in
*       a .h file, and implement these functions in a .cpp file. You will need
*       to write a driver (a program designed to test programs) to test your
*       functions before you upload them.
* Due Date: 10/20/2021
* Date Created: 10/17/2021
* Date Last Modified: 10/19/2021
 */

#include "myFunctions.h"

int max (int a, int b)
{

    if(a < b)
    {
        a = b;
    }

    return a;
}

double max (double a, double b)
{

    if(a < b)
    {
        a = b;
    }

    return a;
}

int max (int m[ ], int n)
{

    int currMax;

    currMax = m[0];

    for(int i = 1; i < n; i++)
    {
        if(static_cast<int>(m[i]) > currMax)
        {
            currMax = m[i];
        }
    }

    return currMax;
}

double max (double m[ ], int n)
{
    double currMax;

    currMax = m[0];

    for(int i = 1; i < n; i++)
    {
        if(static_cast<double>(m[i]) > currMax)
        {
            currMax = m[i];
        }
    }

    return currMax;
}

int min (int a, int b)
{

    if(a > b)
    {
        a = b;
    }

    return a;
}

double min (double a, double b)
{

    if(a > b)
    {
        a = b;
    }

    return a;
}

int min (int m[ ], int n)
{
    int currMin;

    currMin = m[0];

    for(int i = 1; i < n; i++)
    {
        if(static_cast<int>(m[i]) < currMin)
        {
            currMin = m[i];
        }
    }

    return currMin;
}

double min (double m[ ], int n)
{
    double currMin;

    currMin = m[0];

    for(int i = 1; i < n; i++)
    {
        if(static_cast<double>(m[i]) < currMin)
        {
            currMin = m[i];
        }
    }

    return currMin;
}

int absoluteValue (int a)
{

    if(a < 0)
    {
        a *= -1;
    }

    return a;
}

double absoluteValue (double a)
{
    if(a < 0)
    {
        a *= -1;
    }

    return a;
}

double factorial(int a)
{
    double fact = 1;
    for(int i = a; i > 1; i--)
    {
        fact *= i;
    }

    return fact;
}

double combination(int a, int b)
{
    return factorial(a) / (factorial(b) * factorial(a - b));
}

double permutation(int a, int b)
{
    return factorial(a) / factorial(a - b);
}
