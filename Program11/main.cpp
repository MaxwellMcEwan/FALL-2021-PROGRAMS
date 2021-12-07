/*
 * Author: Maxwell McEwan
 * Assignment Title: Guessing Game
 * Assignment Description: Asks for a range of ints then makes the user
 *     guess a random integer chosen in between the given range.
 * Due Date: 9/29/2021
 * Date Created: 9/25/2021
 * Date Last Modified: 9/28/2021
 */

/*
 * Data Abstraction:
 *      input file is made to store the data file in. We make file name
 *      as well to hold the inputted file name. We make doubles for all
 *      of our states of points including start, current, previous, and
 *      stop. We need another string to store our command as well as the
 *      other variables we will be reporting at the end. Theres a metadata
 *      string added for readability.
 *
 * Input:
 * 		The program gets a file name and then attempts to open that file
 *      in an input validation loop.
 *
 * Process:
 * 		We first have to skip the meta data in the file which in this case
 *      is the first two lines. Then we hop into a loop to look for the
 *      first start command. After we get the signal to start we begin our
 *      other loop and begin performing those calculations. When we get the
 *      command to stop we perform some final calculations, close the file
 *      and move onto output.
 *
 * Output:
 * 		Print to the screen our calculations of final location, total distance
 *      traveled, distance to starting point and the average distance to
 *       starting point.
 *
 * Assumptions:
 * 		It is assumed that the user eventually enters a valid file name.
 *
 */

#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>

using namespace std;

int main()
{
    // Data Abstraction
    ifstream inputFile;
    string fileName;

    double startX, startY;
    double prevX, prevY;
    double currX, currY;
    double stopX, stopY;

    string command;
    double finalDistStart;
    double sumDistStart = 0;
    double sumDistTraveled = 0;
    double averageDistStart;

    string metaData;

    int count;

    // Input
    do
    {
        // prompt user to enter filename
        cout << "Please Enter The Name Of The Data File: ";

        // read filename
        cin  >> fileName;
        cout << fileName << endl;

        // open inputFile
        inputFile.open(fileName);

        if (!inputFile)
        {
            cout << "Error: File failed to open." << endl;
        }

    } //check to see if the file was able to open
    while (!inputFile);

    // Process
    // skip meta data by using getline
    getline(inputFile, metaData);
    getline(inputFile, metaData);

    do
    {
        // read command, currX, currY
        inputFile >> command;
        inputFile >> currX;
        inputFile >> currY;

        // if the command is not start, go read until it is
    }
    while (command != "START");

    // set startX and startY
    startX = currX;
    startY = currY;

    do
    {
        // set previous coordinate to current coordinate
        prevX = currX;
        prevY = currY;

        // read command, currX, currY
        inputFile >> command;
        inputFile >> currX;
        inputFile >> currY;

        // add to the total distance traveled
        sumDistTraveled += sqrt(pow(prevX - currX, 2) + pow(prevY - currY, 2));

        // increment count
        count++;

        // add to the distStart by distance to start
        sumDistStart += sqrt(pow(startX - currX, 2) + pow(startY - currY, 2));

        // if the command is not stop, read the next coordinate
    }
    while (command != "STOP");

    // set the stopX and stopY to currX and currY
    stopX = currX;
    stopY = currY;

    // calculate the distance to the start
    finalDistStart = sqrt(pow(startX - stopX, 2) + pow(startY - stopY, 2));

    // calculate the average distance to start
    averageDistStart = sumDistStart / count;

    inputFile.close();

    // Output
    // report calculations
    cout << fixed << setprecision(1) << endl;
    cout << "Final Location: (" << stopX << ", " << stopY << ")" << endl;
    cout << "Total distance traveled " << sumDistTraveled << endl;
    cout << "Distance to starting point " << finalDistStart << endl;
    cout << "Average distance to start point = " << averageDistStart;

    return 0;
}
