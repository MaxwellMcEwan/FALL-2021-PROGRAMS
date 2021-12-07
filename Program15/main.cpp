/*
* Author: Maxwell McEwan
* Assignment Title:  Square Matrix
* Assignment Description: Write a program that reads an integer number
*   N (0 < N < 100) that corresponds to the order of a two dimensional
*   array of integers, and builds the array.
* Due Date: 10/13/2021
* Date Created: 10/9/2021
* Date Last Modified: 10/13/2021
 */

/*
 * Data Abstraction:
 *      Make a 100 x 100 two dimensional array.
 *      Size is also needed as we are dealing with an array
 * Input:
 * 	read in the size of the matrix table to build and calculate
 *     the matrix
 * Process:
 * 	We build an array based off of the minimum of the row, column,
 *      and size - row (or column) + 1.
 * Output:
 * 	Iterate through the entire matrix printing the values as we go,
 *      separate the rows by new lines and the columns by commas.
 * Assumptions:
 * 		It is assumed that the user enters a number greater than -1 and
 *      less than 101
 */

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int minimum(int c, int r, int size)
{
    // we make a temp variable here because we don't want to use c or r
    // to store the min so that we can compare them to these first functions
    int min;

    if(size - r + 1 < size - c + 1)
    {
        min = size - r + 1;
    }
    else
    {
        min = size - c + 1;
    }

    // check if row is less
    if(r < min)
    {
        min = r;
    }

    // check is column is less
    if(c < min)
    {
        min = c;
    }

    return min;
}

int main()
{
    // Data Abstraction
    int m[101][101];

    vector<int> sizes;

    int n = 1;

    // Input
    // read in input into size until a 0 is found
    do
    {
        cin >> n;

        if(n != 0 && n < 101)
        {
            sizes.push_back(n);
        }

    }
    while(n != 0 && n < 101);

    // Process
    for(int i = 0; i < static_cast<int>(sizes.size()); i++)
    {
        // iterate row first, then column
        for(int row = 1; row <= sizes.at(i);  row++)
        {
            for(int col = 1; col <= sizes.at(i); col++)
            {

                // find the minimum for this box and assign it to m
                m[row][col] = minimum(col, row, sizes.at(i));
            }
        }

        // Output
        // iterate through the matrix and output each box
        for(int row = 1; row <= sizes.at(i); row++)
        {
            for(int col = 1; col <= sizes.at(i); col++)
            {
                cout << fixed << setw(4) << left;
                cout << m[row][col];
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}
