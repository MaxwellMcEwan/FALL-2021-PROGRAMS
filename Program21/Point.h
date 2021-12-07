/*
* Author: Maxwell McEwan
* Assignment Title: Point Struct
* Assignment Description: Implement the following Point structure.
* Due Date: 11/3/2021
* Date Created: 10/29/2021
* Date Last Modified: 11/1/2021
 */

#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

#include<fstream>
#include<cmath>

using namespace std;

struct Point{
    int x, y;
    Point(int = 0, int = 0);

    /*
     * description: Function displays our point to the screen.
     * return: None
     * precondition: We have an x and y to display
     * postcondition: X and y are displayed to the screen
     *
     */
    void display(ostream&) const;

    /*
     * description: Function returns distance to another point.
     * return: double
     * precondition: Both points are valid
     * postcondition: Returns the distance of the points.
     *
     */
    double distance(const Point&) const;

    /*
     * description: Function returns the midpoint of two points.
     * return: integer
     * precondition: Both points are valid
     * postcondition: Returns the midPoint as a point object.
     *
     */
    Point midPoint(const Point&) const;
};

#endif // POINT_H_INCLUDED
