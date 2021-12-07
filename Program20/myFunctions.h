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

#ifndef MYFUNCTIONS_H_INCLUDED
#define MYFUNCTIONS_H_INCLUDED

using namespace std;

/*
 * description: Function returns the value of the larger of two integers.
 * return: integer
 * precondition: two integer values exist
 * postcondition:
 *  The value of the largest integer is returned.
 *  The original integers are unchanged
 *  If the integers have the same value then the value of either integer
 *  is returned.
 *
*/

int max (int a, int b);

/*
 * description: Function returns the value of the larger of two double.
 * return: double
 * precondition: two double values exist
 * postcondition:
 *  The value of the largest double is returned.
 *  The original integers are unchanged
 *  If the integers have the same value then the value of either double
 *  is returned.
 *
*/

double max (double a, double b);

/*
 * description: Function returns the value of the largest integer in an array.
 * return: int
 * precondition: an array of integer values exist
 * postcondition:
 *  The largest value in the array is returned.
 *  The original array is unchanged
*/

int max (int m[ ], int n);

/*
 * description: Function returns the value of the largest doubles in an array.
 * return: int
 * precondition: an array of double values exist
 * postcondition:
 *  The largest value in the array is returned.
 *  The original array is unchanged
*/

double max (double m[ ], int n);

/*
 * description: Function returns the value of the smaller of two integers.
 * return: integer
 * precondition: two integer values exist
 * postcondition:
 *   The value of the smallest integer is returned.
 *   The original integers are unchanged
 *   If the integers have the same value then the value of either integer
 *   is returned.
*/

int min (int a, int b);

/*
 * description: Function returns the value of the smaller of two double.
 * return: double
 * precondition: two double values exist
 * postcondition:
 *   The value of the smallest double is returned.
 *   The original double are unchanged
 *   If the double have the same value then the value of either double
 *   is returned.
*/

double min (double a, double b);

/*
 * description: Function returns the value of the smallest integer in an array.
 * return: int
 * precondition: an array of integer values exist
 * postcondition:
 *   The smallest value in the array is returned.
 *   The original array is unchanged
*/

int min (int m[ ], int n);

/*
 * description: Function returns the value of the smallest double in an array.
 * return: double
 * precondition: an array of double values exist
 * postcondition:
 *   The smallest value in the array is returned.
 *   The original array is unchanged
*/

double min (double m[ ], int n);

/*
 * description: This function returns the absolute value of an integer
 * return: Integer
 * precondition: Some integer value exists
 * postcondition:
 *   Integer value is unchanged
*/

int absoluteValue (int a);

/*
 * description: This function returns the absolute value of an double
 * return: double
 * precondition: Some double value exists
 * postcondition:
 *   double value is unchanged
*/

double absoluteValue (double a);

/*
 * description: The function calculates factorial.
 * return: double
 * precondition: Some integer value N exists
 * postcondition:
 *   The value of the N unchanged
*/

double factorial(int a);

/*
 * description: The function calculates the number of combinations of
 *      M items taken N at a time.
 * return: The number of combinations of M items taken N at a time.
 * precondition: Two integer value M and N exists
 * postcondition:
 *   The value of the M and N unchanged
*/

double combination(int a, int b);

/*
 * description: The function calculates the number of permutations of
 *      M items taken N at a time.
 * return: The number of permutations of M items taken N at a time.
 * precondition: Two integer value M and N exists
 * postcondition:
 *   The value of the M and N unchanged
*/

double permutation(int a, int b);

#endif // MYFUNCTIONS_H_INCLUDED
