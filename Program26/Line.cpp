/*
* Author: Maxwell McEwan
* Assignment Title: Line Class
* Assignment Description: implement a Line Class
*       that uses points to represent a line
* Due Date: 11/10/2021
* Date Created: 11/5/2021
* Date Last Modified: 11/9/2021
 */

#include "Line.h"

Line::Line(Point p1, Point p2){
    this->p1 = p1;
    this->p2 = p2;
}

void Line::setFirstPoint(const Point& a){
    p1 = a;
}

void Line::setSecondPoint(const Point& a){
    p2 = a;
}

Point Line::getFirstPoint() const{
    return p1;
}

Point Line::getSecondPoint() const{
    return p2;
}

bool Line::hasSlope() const{
    return p1.x != p2.x;
}

double Line::slope() const{
    return static_cast<double>(p2.y - p1.y) / (p2.x - p1.x);
}

double Line::yIntercept() const{
    return -p1.x * slope() + p1.y;
}

bool Line::isParallel(const Line& L2) const{
    return slope() == L2.slope() && yIntercept() != L2.yIntercept();
}

bool Line::isCollinear(const Line& L2) const{
    return (slope() == L2.slope() && yIntercept() == L2.yIntercept())||
    ((!hasSlope() && !L2.hasSlope()) && yIntercept() == L2.yIntercept());
}

bool Line::isPerpendicular(const Line& L2) const{
    return slope() == -1/L2.slope();
}

Point Line::intersect(const Line& L2) const{
    double x, y;

    x = static_cast<double>(L2.yIntercept() - yIntercept())
            / (slope() - L2.slope());

    if(!hasSlope()){
        x = p1.x;
    } else if (!L2.hasSlope()){
        x = L2.getFirstPoint().x;
    }

    y = slope() * x + yIntercept();

    if(!hasSlope()){
        y = L2.slope() * x + L2.yIntercept();
    } else if (!L2.hasSlope()){
        y = slope() * x + yIntercept();
    }

    if(x < 0){
        x -= 0.5;
    } else {
        x += 0.5;
    }

    if(y < 0){
        y -= 0.5;
    } else {
        y += 0.5;
    }

    Point intersectP(x, y);
    return intersectP;
}

void Line::display(ostream& output) const{

    if(hasSlope()){
        output << "y = ";

        if(slope() != 0 && abs(slope()) != 1){
            output << slope();
        } else if (slope() == -1){
            output << "-";
        }

        output << "x ";

        if(yIntercept() != 0){
            if(yIntercept() > 0){
                output << " + ";
            }
            output << yIntercept();
        }
    } else {
        output << "x = " << p1.x;
    }
}
