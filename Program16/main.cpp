/*
* Author: Maxwell McEwan
* Assignment Title:  Multiplication Table
* Assignment Description: Get a stop and a start from the user and
*       create a multiplication table based off of that.
* Due Date: 10/15/2021
* Date Created: 10/12/2021
* Date Last Modified: 10/14/2021
 */

/*
 * Data Abstraction:
 *      Make a 25 x 25 two dimensional array, and two vectors to
 *      hold our row and column values. We need ints to hold our
 *      stop, start, and shift for both row and column
 * Input:
 * 		read in the start and stop for both row and column
 * Process:
 * 		calculate the shift of row and column.
 *          fill both vectors with their values for row and column
 *          fill the multiplication table using row * column
 * Output:
 * 		printing the table neatly was the difficult part.
 *          We have to determine what kind of element we are printing
 *          and output a different number of spaces depending on
 *          what value we are outputting.
 * Assumptions:
 * 		It is assumed that the user enters a number greater that
 *          does not generate an item in the table greater than 3
 *          digits.
 */

#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>

using namespace std;

// make a function to print a position to add readability and
// remove somewhat duplicate code
void printInt(int n){
    cout << setw(4) << left << n;
    cout << "  ";
}

// make a function to fill a vector to avoid redundancy in code
void fillVector(int start, int stop, int shift, vector<int>& toFill){
    for(int n = start; n != stop + shift; n += shift){
        toFill.push_back(n);
    }
}

int main()
{
    // Data Abstraction
    vector<int> row, col;
    int table[25][25];

    int rOne, rTwo, cOne, cTwo, rShift = 1, cShift = 1;

    // Input
    cout << "Please Enter Four Integers R1 R2 C1 C2: ";
    cin >> rOne;
    cin >> rTwo;
    cin >> cOne;
    cin >> cTwo;
    cout << rOne << " " << rTwo << " "
           << cOne << " " <<  cTwo << " "<< endl;

    // Process
    // fill the row and column vectors;
    if (rOne > rTwo){
        rShift = -1;
    }

    if (cOne > cTwo){
        cShift = -1;
    }

    // fill row vector
    fillVector(rOne, rTwo, rShift, row);

    // fill column vector
    fillVector(cOne, cTwo, cShift, col);

    // fill the multiplication table
    // for every row
    for(int i = 0; i < static_cast<int>(row.size()); i++){
        // for every column
        for(int j = 0; j < static_cast<int>(col.size()); j++){
            // calculate and fill in the spot at in the matrix
            table[i][j] = row.at(i) * col.at(j);
        }
    }

    // Output
    // print our table
    for(int r = 0; r < static_cast<int>(row.size()) + 1; r++){
        // for every column
        for(int c = 0; c < static_cast<int>(col.size()) + 1; c++){
            // if we're in the not first column or row print the matrix spot
            if(r != 0 && c > 0){
                // print the spot in the matrix
                printInt(table[r - 1][c - 1]);
            }
            else
            {
                // if we're in the first row print col number or space
                if(c > 0){
                    printInt(col.at(c - 1));
                }
                else if (r != 0){
                    // if we should print rows, print them
                    cout << setw(4) << row.at(r - 1) << "    ";
                } else {
                    // if it is our first iteration, add some space
                    cout << "        ";
                }
            }
        }
        cout << endl;

        // print a whole row of lines
        for(int k = 0; k <= static_cast<int>(col.size()); k++){
            cout << "-----|";
        }
        cout << endl;
    }
    return 0;
}
