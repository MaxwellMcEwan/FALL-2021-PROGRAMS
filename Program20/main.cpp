/*
* Author: Maxwell McEwan
* Assignment Title:  Pascal's Triangle
* Assignment Description: program that asks the user to enter the number
*       of rows (N) and then prints the first N rows of Pascal's Triangle,
*       one row per line.
* Due Date: 10/29/2021
* Date Created: 10/25/2021
* Date Last Modified: 10/28/2021
 */

/*
 * Data Abstraction:
 *      Make an array of size 10000 to hold our values to later print out in
 *      our output
 * Input:
 * 	Prompt the user for input on the number of rows to build and output
 * Process:
 * 	Make a nested loop to call combination with the proper values of
 *      j and k
 * Output:
 *      Iterate through all of our array and print out the calculated values
 *      but this time, formatted properly.
 * Assumptions:
 * 	It is assumed that the user enters a number of rows that our array
 *      can hold all the combinations calculated
 */

#include <iostream>
#include <iomanip>
#include "myFunctions.h"

using namespace std;

int main()
{
    //Data Abstraction
    int a[10000];
    int n;
    int i = 0;

    //Input
    // prompt user for number of rows
    cout << "Please Enter The Number of Rows: ";
    cin >> n;
    // echo print number of rows
    cout << n << endl << endl;

    //Process
    // make a loop to iterate through all values of the triangle at spots
    // 0C0, 1C0, 1C1, etc... Where j Combination k
    for(int j = 0; j < n; j++)
    {
        for(int k = 0; k <= j; k++)
        {
            // calculate the combination and enter it into our array
            a[i] = static_cast<int>(combination(j, k));
            // increment into the next array position
            i++;
        }
    }

    //Output
    // set i back to zero
    i = 0;
    // don't print any decimals
    for(int j = 0; j < n; j++)
    {
        // at the beginning of each row center the numbers
        for(int spaces = 0; spaces < n-j-1; spaces++)
        {
            // print the offset
            cout << "     ";
        }
        for(int k = 0; k <= j; k++)
        {
            // print each number in the array
            cout << setw(4) << a[i] << "      ";
            // increment i
            i++;
        }
        // skip to the next row in output
        cout << endl;
    }

    return 0;
}
