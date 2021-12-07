/*
* Author: Maxwell McEwan
* Assignment Title:  Array of Spheres
* Assignment Description: reads two linear equations from
*       standard input (cin) and calculate the intersection
* Due Date: 11/17/2021
* Date Created: 11/13/2021
* Date Last Modified: 11/17/2021
 */

/*
 * Data Abstraction:
 *          create a string to hold the input, and a token for the
 *          data. two ints for sign and side as well as a string
 *          -stream. x and y coefficients as well as the constant
 *          two point objects as well as line objects that hold them
 *          lastly, an intersect point to hold the answer in.
 *
 * Input:
 * 		getline input to read the equation in
 *
 * Process:
 * 		find each coefficient of x, y and constant (c).
 *          after that, calculate two points based off of what coefs
 *          were found in the equation.
 *
 * Output:
 * 		If the line intercepts somewhere, print the point.
 *          However, if the point is collinear or parrallel it won't
 *          have an intersection fo print no solution.
 *
 * Assumptions:
 * 		both inputs are valid representations of lines.
 *          Either in y = mx + b or standard form.
 */

#include <iostream>
#include<sstream>
#include<string>
#include<cmath>
#include "Line.h"
#include "Point.h"

using namespace std;

double getCoef(string);

int main()
{
    // Data Abstraction
    string line, token;
    int sign = 1, side = 1;
    stringstream ss;
    double xCoef, yCoef, c;
    Point p1, p2, intersect;
    Line L1, L2;

    // there is going to be two linear equations so run twice
    for(int i = 0; i < 2; i++)
    {
        // reset the values for both points
        side = 1;
        xCoef = 0;
        yCoef = 0;
        c = 0;
        p1.x = 1;
        p1.y = 1;
        p2.x = -1;
        p2.y = -1;

        // Input
        //reads two linear equations from standard input (cin) and
        getline(cin, line);

        // fix our string stream
        ss.clear();
        ss.str("");

        // fill the string stream
        ss.str(line);

        // Process
        // tokenize the data
        while(ss >> token)
        {
            // if there is an x in the token, pick apart the data for
            // the coefficent
            if(token.find('x') != string::npos)
            {
                xCoef = getCoef(token) * side * sign;
                sign = 1;
            }
            // if there is a y in the token, look for the y's coefficent
            else if (token.find('y') != string::npos){
                yCoef = getCoef(token) * side * sign;
                sign = 1;
            }
            // if we've crossed to the other side change side
            else if(token == "=")
            {
                side = -1;
            }
            // if we passed a negative sign, change the sign
            else if(token == "-")
            {
                sign = -1;
            }
            // if it isn't an addition sign, it is our c
            else if (token != "+"){
                c = getCoef(token) * sign * side * -1;
                sign = 1;
            }
        }

        // construct the line object
        if(yCoef != 0){ // y = mx + b
            p1.y = round(-xCoef + c);
            p2.y = round(xCoef + c);
        } else { //x = c
            p1.x = p2.x = c;
        }

        if(xCoef == 0){//y = c
            p1.y = p2.y = c;
        }

        // assign each line points
        if(i == 0){
            L1.setFirstPoint(p1);
            L1.setSecondPoint(p2);
        } else {
            L2.setFirstPoint(p1);
            L2.setSecondPoint(p2);
        }
    }

    // Output
    //if the two lines are parallel or collinear
    if(L1.isCollinear(L2) || L1.isParallel(L2)){
        //print "NO SOLUTION"
        cout << "NO SOLUTION" << endl;
    } else {
        //if the two lines intersect
        //print "SOLUTION: (x,y) "
        //note: x and y should be rounded two three decimal places
        intersect = L1.intersect(L2);
        cout << "SOLUTION: ";
        intersect.display(cout);
    }

    return 0;
}

double getCoef(string token)
{
    stringstream ss2;
    double a;

    ss2.clear();
    ss2.str(token);

    if(token.size() == 1 && (token == "x" || token == "y"))
    {
        a = 1;
    }
    else if (token.size() == 2 && token[0] == '-')
    {
        a = -1;
    } else {
        ss2 >> a;
    }

    return a;
}
