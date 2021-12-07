/*
* Author: Maxwell McEwan
* Assignment Title: Point Struct
* Assignment Description: Implement the following Point structure.
* Due Date: 11/3/2021
* Date Created: 10/29/2021
* Date Last Modified: 11/1/2021
 */

#include "Point.h"

Point::Point(int x, int y){
    // Point constructor with default values (0, 0);
    this->x = x;
    this->y = y;
}

void Point::display(ostream& output) const{
    // Displays the Point Object in the following format:  (x,y)
    output << "(" << x << "," << y << ")" << endl;
}

double Point::distance(const Point& p2) const{
    // Returns the distance between two points
    return sqrt(pow((p2.x - x), 2) + pow((p2.y - y), 2));
}

Point Point::midPoint(const Point& p2) const{
    // returns the midpoint between two points.
    // If the midpoint has decimal coordinates the values should
    // be rounded to the nearest integer.
    double mx, my;
    mx = static_cast<double>(x + p2.x) / 2;
    my = static_cast<double>(y + p2.y) / 2;

    if(mx < 0){
        mx -= 0.5;
    } else {
        mx += 0.5;
    }

    if(my < 0){
        my -= 0.5;
    } else {
        my += 0.5;
    }

    Point mp(static_cast<int>(mx), static_cast<int>(my));
    return mp;
}
