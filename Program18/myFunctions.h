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

/*
 * description: calculate total price of item with tax
 * return: double
 * precondition: price and tax are valid
 * postcondition: returns sum of price and tax
 *
*/

int Strlen(const char s1[ ]);

/*
 * description: calculate total price of item with tax
 * return: double
 * precondition: price and tax are valid
 * postcondition: returns sum of price and tax
 *
*/

void Strcpy(char s1[ ], const char s2[ ]);

/*
 * description: calculate total price of item with tax
 * return: double
 * precondition: price and tax are valid
 * postcondition: returns sum of price and tax
 *
*/

int Strcmp(const char s1[ ], const char s2[ ]);

/*
 * description: calculate total price of item with tax
 * return: double
 * precondition: price and tax are valid
 * postcondition: returns sum of price and tax
 *
*/

void Strcat(char s1[ ], const char s2[ ]) ;

#endif // MYFUNCTIONS_H_INCLUDED
