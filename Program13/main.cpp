/*
 * Author: Maxwell McEwan
 * Assignment Title: Fibonacci Array
 * Assignment Description: Write a program that reads an integer N and
 *       print then prints the Nth value in the Fibonacci sequence.
 *       Remember that the first elements of the Fibonacci series are
 *       0 and 1 and each next term is the sum of the two preceding it.
 * Due Date: 10/6/2021
 * Date Created: 10/3/2021
 * Date Last Modified: 10/5/2021
 */

/*
 * Data Abstraction:
 *      Make an array of long longs because ints are not big enough for
 *      some of the values. Make i for index and n for number. numCases
 *      if the first number we read in and it tells us how many times to
 *      run a later loop.
 *
 * Input:
 * 		Ask the user for a number of cases then repeatedly ask the user
 *      for numbers to plug into the Fibonacci array.
 *
 * Process:
 * 		Our process section is setting index equal to 0.
 *
 * Output:
 * 		In output, we have to read in n check for n's range, and output
 *      an index in our array based on n. If n isn't in range, we give
 *      an error.
 *
 * Assumptions:
 * 		It is assumed that the user enters valid n numbers.
 *
 */

#include <iostream>

using namespace std;

const int SIZE = 91;

int main()
{
    // Data Abstraction
    long long fib[SIZE] = {0, 1};
    int i;
    int n;
    int numCases;

    // Input
    // fill the array
    for (i = 2; i < SIZE; i++)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    // read in the number of cases
    cin >> numCases;

    // Process
    // set i to 0
    i = 0;

    // Output
    // if i is less than case amount iterate
    while (i < numCases)
    {
        // read in the n
        cin >> n;

        if (n >= 0 && n <= 90)
        {
            // output the number at that storage location in the array
            cout << "Case " << i + 1 << ": Fib(" << n << ") = "<< fib[n]
                 << endl;
        }
        else
        {
            // print error is n is not within range
            cout << "Invalid input" << endl;
        }

        // increment i
        i++;
    }

    return 0;
}
