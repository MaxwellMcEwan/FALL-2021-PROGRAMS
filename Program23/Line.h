/*
* Author: Maxwell McEwan
* Assignment Title: Line Class
* Assignment Description: implement a Line Class
*       that uses points to represent a line
* Due Date: 11/10/2021
* Date Created: 11/5/2021
* Date Last Modified: 11/9/2021
 */

#ifndef LINE_H_
#define LINE_H_

#include <ostream>
#include <iostream>
#include "Point.h"

using namespace std;


class Line{
	private:
		Point p1, p2;

	public:

       /*
        * description: constructor class for Line object
        * return: Line
        * precondition: Line obj has been made
        * postcondition: returns values for p1 and p2
        *
        */
		Line(Point=Point(1,1), Point=Point(0,0));

       /*
        * description: set first p1 object
        * return: none
        * precondition: a p1 object exists
        * postcondition: p1 is set to a point
        *
        */
 		void setFirstPoint(const Point&);

       /*
        * description: set first p2 object
        * return: none
        * precondition: a p2 object exists
        * postcondition: p2 is set to a point
        *
        */
		void setSecondPoint(const Point&);

       /*
        * description: accessor function for p1
        * return: Point
        * precondition: p1 exists
        * postcondition: p1 is returned
        *
        */
		Point getFirstPoint() const;

       /*
        * description: accessor function for p2
        * return: Point
        * precondition: p2 exists
        * postcondition: p2 is returned
        *
        */
		Point getSecondPoint() const;

       /*
        * description: find if the line has slope
        * return: bool
        * precondition: a line exists with points
        * postcondition: returns if the line has a slope
        *
        */
		bool   hasSlope() const;

       /*
        * description: calculate slope of the line
        * return: double
        * precondition: a line exists with points
        * postcondition: returns the slope of a line
        *
        */
        double slope() const;

       /*
        * description: y intercept of a line is calculated
        * return: double
        * precondition: a line exists with points
        * postcondition: returns the y intercept
        *
        */
		double yIntercept() const;

       /*
        * description: calculates if two lines are parallel
        * return: bool
        * precondition: two lines exist with points
        * postcondition: returns if the two line is parallel
        *
        */
		bool isParallel(const Line&) const;

       /*
        * description: calculates if two lines are collinear
        * return: bool
        * precondition: two lines exist with points
        * postcondition: returns if the two line is collinear
        *
        */
		bool isCollinear(const Line&) const;

       /*
        * description: calculates if two lines are perpendicular
        * return: bool
        * precondition: two lines exist with points
        * postcondition: returns if the two line is perpendicular
        *
        */
		bool isPerpendicular(const Line&) const;

       /*
        * description: calculates where two lines intersect
        * return: Point
        * precondition: two lines exist with points
        * postcondition: returns the point where two lines intersect
        *
        */
		Point intersect(const Line&) const;

       /*
        * description: display the line in slope intercept form
        * return: void
        * precondition: a line exists with points
        * postcondition: the line in slope intercept it inserted
        *       into the output
        *
        */
		void display(ostream&) const;
};

#endif /* LINE_H_ */
