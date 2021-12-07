/*
* Author: Maxwell McEwan
* Assignment Title: Array Processing
* Assignment Description: implement a collection of functions
*       to refresh your C++ skills and strengthen your array
*       processing skills.
* Due Date: 10/27/2021
* Date Created: 10/24/2021
* Date Last Modified: 10/26/2021
 */

#include <vector>
#include <string>

#ifndef ARRAYCOUNT_H_INCLUDED
#define ARRAYCOUNT_H_INCLUDED

using namespace std;

/*
 * description: record the amount of times v appears in a
 * return: integer
 * precondition: a is a valid array and s holds the accurate size
 * postcondition: returns the frequency of the value v in the array a
 *
*/
int arrayCount(int a[ ], int s, int v);

/*
 * description: record the amount of times v appears in a
 * return: integer
 * precondition: a is a valid array and s holds the accurate size
 * postcondition: returns the frequency of the value v in the array a
 *
*/
int arrayCount(double a[ ], int s, double v);

/*
 * description: record the amount of times v appears in a
 * return: integer
 * precondition: a is a valid array and s holds the accurate size
 * postcondition: returns the frequency of the value v in the array a
 *
*/
int arrayCount(string a[ ], int s , string v);

/*
 * description: record the amount of times v appears in a
 * return: integer
 * precondition: a is a valid array
 * postcondition: returns the frequency of the value v in the array a
 *
*/
int arrayCount(char a[ ], char v);

/*
 * description: record the amount of times v appears in a
 * return: integer
 * precondition: a is a valid vector
 * postcondition: returns the frequency of the value v in the vector a
 *
*/
int arrayCount(vector<int> a, int v);

/*
 * description: record the amount of times v appears in a
 * return: integer
 * precondition: a is a valid vector
 * postcondition: returns the frequency of the value v in the vector a
 *
*/
int arrayCount(vector<string> a, string v);

/*
 * description: record the amount of times v appears in a
 * return: integer
 * precondition: a is a valid vector
 * postcondition: returns the frequency of the value v in the vector a
 *
*/
int arrayCount(vector<double> a, double v);

/*
 * description: record the amount of times v appears in a
 * return: integer
 * precondition: a is a valid vector
 * postcondition: returns the frequency of the value v in the vector a
 *
*/
int arrayCount(vector<char> a, char v);

#endif // ARRAYCOUNT_H_INCLUDED
