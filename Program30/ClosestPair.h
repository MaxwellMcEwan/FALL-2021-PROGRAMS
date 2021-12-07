/*
 * Author: Maxwell McEwan
 * Assignment Title:  Closest Pair
 * Assignment Description: Return a Pair of Indices where indexPointOne
 *      and indexPointTwo are the closest pair of points in the array
 * Due Date: 12/3/2021
 * Date Created: 12/1/2021
 * Date Last Modified: 12/3/2021
 */

#ifndef CLOSESTPAIR_H_INCLUDED
#define CLOSESTPAIR_H_INCLUDED

#include <cmath>

using namespace std;

struct Point {
    double x;
    double y;

    Point(double a = 0, double b = 0){
        x = a;
        y = b;
    }

    /*
     * description: calculate the distance from our point to another
     * return: double
     * precondition: the point passed is valid
     * postcondition: returns the distance to that point from ours
     *
    */
    double distanceTo(Point p2);
};

struct Pair {
    int indexPointOne;
    int indexPointTwo;
};



/*
 * description: calculate closest pair
 * return: Pair
 * precondition: the array and the size are valid
 * postcondition: returns closest two points
 *
*/
Pair Closest_Pair( Point  P[ ], int n);

#endif // CLOSESTPAIR_H_INCLUDED
