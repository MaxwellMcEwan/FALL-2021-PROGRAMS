/*
* Author: Maxwell McEwan
* Assignment Title: Sphere Class
* Assignment Description: implement a Sphere class with the
*       following data fields and methods.
* Due Date: 11/5/2021
* Date Created: 11/2/2021
* Date Last Modified: 11/2/2021
 */

#ifndef SPHERE_H_INCLUDED
#define SPHERE_H_INCLUDED

#include<cmath>
#include<string>

using namespace std;

const double PI = 3.14159;

class Sphere{
    private:
        double radius;
        string color;

    public:
        /* description: Sphere Class constructor.
         * return: None
         * precondition: either nothing is passed or a double or
         *      a string
         * postcondition: radius and color are assigned values
         */
        Sphere(double = 1, string = "green");

        /* description: Mutator function for radius.
         * return: None
         * precondition: a new radius is passed
         * postcondition: our radius is set to the passed radius
         */
        void setRadius(double);

        /* description: Accessor  function for radius.
         * return: double
         * precondition: radius exists
         * postcondition: returns the radius
         */
        double getRadius() const;

        /* description: Mutator function for color.
         * return: None
         * precondition: a new color is passed
         * postcondition: our color is set to the passed color
         */
        void setColor(string);

        /* description: Accessor  function for color.
         * return: string
         * precondition: color exists
         * postcondition: returns the color
         */
        string getColor() const;

        /* description: calculate the area of the circle.
         * return: double
         * precondition: radius exists
         * postcondition: returns the area of the circle
         */
        double area() const;

        /* description: calculate the volume of the sphere.
         * return: double
         * precondition: radius exists
         * postcondition: returns the area of the sphere
         */
        double volume() const;

        /* description: checks if two spheres are equal.
         * return: bool
         * precondition: a valid sphere is passeed
         * postcondition: returns if the color and radius of
         *      the two spheres are equal.
         */
        bool isEqual(const Sphere) const;
};


#endif // SPHERE_H_INCLUDED
