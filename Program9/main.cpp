/* Author: Maxwell McEwan
 * Assignment Title: Min Max Sum Count Average
 * Assignment Description: Find the min, max, sum, count
 *      and average of the integers in a file.
 * Due Date: 9/22/2021
 * Date Created: 9/16/2021
 * Date Last Modified: 9/20/2021
 */

/* Data Abstraction:
 *      We initialize the input file from which we will be
 *       pulling data from. We also make a fileName string to
 *       hold the inputed file name. The read Int variable is
 *       to hold the integer that we read from the file one piece
 *       at a time. The rest of the variables are just the
 *       values that we need to make reports on. Such as,
 *       min, max, sum, count, and the average.
 *
 * Input:
 *      For input we have a loop for confirming that a file
 *       exists before we actually begin processing it.
 *
 * Process:
 *      While we're not at the end of the file we read the int
 *       check for new min and max values. Add the x to sum
 *       increment the count by one. After that, disconnect the
 *       hose and calculate the average.
 *
 * Output:
 *      We give the report of the min, max, sum, count and average.
 *
 * Assumptions:
 *      The user enters a file name that is valid and does not
 *       stay in the infinite loop of input.
 *
 */


#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
    // Data Abstraction
    ifstream inputFile;
    string   fileName;

    int readInt;
    int minNum, maxNum;
    int sum = 0;
    int intCount = 0;

    double Average;

    bool endOfData;

    // Input
    do
    {
        // - Prompt the user for input
        cout << "Enter Data File Name: ";
        // - Get input for the files name
        cin  >> fileName;
        cout << fileName << endl;

        // - Connect the hose
        inputFile.open(fileName);

        // - Check if it is a real file
        if (!inputFile)
        {
            cout << "Error: File Not Open." << endl;
        }

    }
    while (!inputFile);

    // Process
    do
    {
        // - Read the integer
        inputFile >> readInt;

        if (!inputFile.eof()){
            // - If it is the first iteration, set the min and max
            if (intCount == 0)
            {
                minNum = maxNum = readInt;
            }

            // - Is it less than min? If so, become min
            if (readInt < minNum)
            {
                minNum = readInt;
            }

            // - Is it greater than max? If so, become max
            if (readInt > maxNum)
            {
                maxNum = readInt;
            }

            // - Add the value to the sum
            sum += readInt;

            // - Increment count by one
            intCount++;
        } else {
            endOfData = true;
        }

    } while (!endOfData);

    // - Disconnect the hose when we're done reading
    inputFile.close();

    // - Calculate the average if all integers have been read
    Average = static_cast<double>(sum)/intCount;

    // Output
    cout << endl << fixed << setprecision(2);

    // Print the min, max, sum, count, and average
    cout << "Min = "     << minNum   << endl;
    cout << "Max = "     << maxNum   << endl;
    cout << "Sum = "     << sum      << endl;
    cout << "Count = "   << intCount << endl;
    cout << "Average = " << Average  << endl;

    return 0;
}
