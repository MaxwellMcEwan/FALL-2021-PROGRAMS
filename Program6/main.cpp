/*
* Author: Maxwell McEwan
* Assignment Title: Program 6 "Quadratic Formula"
* Assignment Description: Input 3 numbers and then calculate their
* Roots(sorted) as well as their X and Y vertex.
* Due Date: 9/10/2021
* Date Created: 9/6/2021
* Date Last Modified: 9/9/2021
 */

/*
 * Data Abstraction:
 *      - Create the variables of a,b,c to store the input values of the user.
 *      - Create rootOne, rootTwo, and discriminant doubles.
 *      - Initialize numRoots to 0 so we can avoid an if statement later.
 *      - Create two doubles for the x and y vertex.
 *
 * Input:
 * 		The program reads input from the user and assigns the doubles
 *      a,b,c to their respective variables
 *
 * Process:
 * 		- Calculate The Discriminate
 *      - Determine Number Of Roots
 *      - Calculate And Assign Roots And X Vertex
 *      - Remove Negative Sign From b To Avoid -0 Error if b == 0
 *      - Calculate and Assign Y Vertex
 *      - Set numRoots = 1 If Both Roots Are Equal
 *
 * Output:
 *      - Display all Numbers To The Hundreths Place
 *      - Print No Real Roots, The One Root, Or Both Roots
 *
 * Assumptions:
 * 		It is assumed that the user enters numbers.
 */

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    //Data Abstraction
    double  a,b,c;
    double  rootOne, rootTwo;
    double  discriminant;
    int     numRoots = 0;

    double  xVertex;
    double  yVertex;

    //Input
    cin >> a;
    cin >> b;
    cin >> c;

    //Process
    // - Calculate Discriminate
    discriminant = sqrt(pow(b,2.0) - 4.0*a*c);

    // - Determine Number Of Roots
    if (discriminant == 0){
        numRoots = 1;
    }
    else if (discriminant > 0){
        numRoots = 2;
    }

    // - Calculate And Assign Roots And X Vertex
    if (b != 0){
        rootOne = (-b - discriminant) / (2.0 * a);
        rootTwo = (-b + discriminant) / (2.0 * a);

        xVertex = -b / (2.0 * a);
    } else {
        // -- Remove Negative Sign From b To Avoid -0 Error if b == 0
        rootOne = (b - discriminant) / (2.0 * a);
        rootTwo = (b + discriminant) / (2.0 * a);

        xVertex = b / (2.0 * a);
    }

    // - Calculate and Assign Y Vertex
    yVertex = a * pow(xVertex, 2) + b * xVertex + c;

    // - Set numRoots = 1 If Both Roots Are Equal
    if (rootOne == rootTwo){
        numRoots = 1;
    }

    //Output
    // - Display all Numbers To The Hundreths Place
    cout << fixed << setprecision(2);

    // - Print No Real Roots, The One Root, Or Both Roots
    if (numRoots == 0){
        cout << "NO REAL ROOTS";
    }
    if (numRoots > 0){
        cout << rootOne;
    }
    if (numRoots > 1){
        cout << " " << rootTwo;
    }

    cout << " (" << xVertex << ", " << yVertex << ") ";
    return 0;
}
