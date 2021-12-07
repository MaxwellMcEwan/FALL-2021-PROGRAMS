/*
* Author: Maxwell McEwan
* Assignment Title: C string functions
* Assignment Description: Implement each of the following
*       C-style string functions.
* Due Date: 10/22/2021
* Date Created: 10/17/2021
* Date Last Modified: 10/22/2021
 */

#ifndef MYFUNCTIONS_H_INCLUDED
#define MYFUNCTIONS_H_INCLUDED

/*
 * description: calculate the length of a string
 * return: Strlen
 * precondition: s1 is a valid c style string
 * postcondition: returns length of the string
 *
*/

int Strlen(const char s1[ ]);

/*
 * description: copy one string into another
 * return: none
 * precondition: both params are valid c style strings
 * postcondition: returns s2 copied into s1
 *
*/

void Strcpy(char s1[ ], const char s2[ ]);

/*
 * description: compare two strings
 * return: int
 * precondition: both params are valid c style strings
 * postcondition: returns the first letter difference
 *      in the strings, if there is none returns 0
 *
*/

int Strcmp(const char s1[ ], const char s2[ ]);

/*
 * description: adds two c style strings together
 * return: none
 * precondition: both params are valid c style strings
 * postcondition: s2 is added to the end of s1
 *
*/

void Strcat(char s1[ ], const char s2[ ]) ;

#endif // MYFUNCTIONS_H_INCLUDED
