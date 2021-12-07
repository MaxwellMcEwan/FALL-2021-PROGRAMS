/*
* Author: Maxwell McEwan
* Assignment Title: Sphere Class
* Assignment Description: implement a Sphere class with the
*       following data fields and methods.
* Due Date: 11/5/2021
* Date Created: 11/2/2021
* Date Last Modified: 11/2/2021
 */

#include "Sphere.h"

Sphere::Sphere(double r, string c){
    radius = r;
    color = c;
}

void Sphere::setRadius(double r){
    radius = r;
}

double Sphere::getRadius() const{
    return  radius;
}

void Sphere::setColor(string c){
    color = c;
}

string Sphere::getColor() const{
    return color;
}

double Sphere::area() const{
    return 4 * PI * pow(radius, 2);
}

double Sphere::volume() const{
    return (static_cast<double>(4)/3) * PI * pow(radius, 3);
}

bool Sphere::isEqual(const Sphere s) const{
    return radius == s.radius and color == s.color;
}
