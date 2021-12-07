/*
* Author: Maxwell McEwan
* Assignment Title:  Array of Spheres
* Assignment Description: Create a sphere driver to make spheres
*       and read data out of them.
* Due Date: 11/15/2021
* Date Created: 11/13/2021
* Date Last Modified: 11/14/2021
 */

/*
 * Data Abstraction:
 *          create a string to hold the file name, line, and the
 *          color of the sphere. An Ifstream for our input file
 *          and a stringstream to read data in and out of. Next,
 *          some counts for statistics we need to keep track of.
 *
 * Input:
 * 		Input validation loop for input file name
 *
 * Process:
 * 		calculate the shift of row and column.
 *          read the radius and color for an unknown number of
 *          Spheres. Also calculate some statistics.
 *
 * Output:
 * 		Output all spheres in the array numbered, their radius,
 *          color, area, and volume. Then number of spheres,
 *          percentage of spheres that are red, how many have a
 *          volume over 215, and the average area.
 *
 * Assumptions:
 * 		It is assumed the user eventually enters a valid file name.
 *         Everything in the file is sorted as said.
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include "Sphere.h"

using namespace std;

const int W = 12;

int main()
{
    // Data Abstraction
    string fileName, line, color;
    ifstream inputFile;
    stringstream ss;
    int count = 0, redCount = 0, volCount;
    double radius, areaSum;

    //declare an array of 100 Spheres
    Sphere s[100];

    // Input
    do
    {
        //Ask the user for the name of the data file
        cout << "Enter file name: ";
        cin >> fileName;
        cout << fileName << endl;

        //Open the data file
        inputFile.open(fileName);

        //check to make sure the file opened successfully
        //if the file FAILED to open return to step 2
        if(!inputFile){
            cout << "Error: File Not Open." << endl;
        }
    }
    while(!inputFile);
    cout << endl;

    // Process
    //Skip the first two lines of the data file.
    getline(inputFile, line);
    getline(inputFile, line);

    //read the radius and color for an unknown number of
    //Spheres, assume that there is one record per line.
    while(getline(inputFile, line))
    {
        // clear and empty the string stream to fix it
        ss.clear();
        ss.str("");

        // put the read line into the stream
        ss.str(line);

        // read out radius and color
        ss >> radius;
        ss >> color;

        // create a new sphere using the constructor
        Sphere newSphere(radius, color);

        // add the sphere to the array and increment count
        s[count] = newSphere;
        count++;

        // increment red count if needed
        if(color == "red"){
            redCount++;
        }

        // check for volume over 215
        if(newSphere.volume() > 215){
            volCount++;
        }

        // add to our area total
        areaSum += newSphere.area();
    }

    //don’t forget to close the data file
    inputFile.close();

    // Output
    //Report the following:
    cout << fixed << setprecision(2);
    cout << setw(W) << "Number" << setw(W) << "Radius" << setw(W) <<
    setw(W) << "Color" << setw(W) << "Area" << setw(W) << "Volume" << endl;

    //Print a list of all Spheres reporting the color, radius, area, and volume
    for(int i = 0; i < count; i++){
        // for every sphere
        cout << setw(W) << i << setw(W) << s[i].getRadius() << setw(W)
        << s[i].getColor() << setw(W) << s[i].area() << setw(W)
        << s[i].volume() << endl;
    }
    // go down an extra line
    cout << endl;

    //Total number of Spheres
    cout << "Total Number of Spheres = " << count << "." << endl;

    //Percentage of Spheres that are red
    cout << (static_cast<double>(redCount)/count) * 100
    << " % of Spheres are red." << endl;

    //Total number of Spheres with volume greater than 215.
    cout << volCount << " Spheres have a Volume over 215." << endl;

    //Average area of all Spheres
    cout << "Average Area = " << areaSum/count << endl;

    return 0;
}
