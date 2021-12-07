/*
* Author: Maxwell McEwan
* Assignment Title:  Array of Spheres
* Assignment Description: You have been hired by a data
*       processing company to help clean up a big mess. The last person
*       in charge of all the company’s data mixed the information from
*       three different accounts into a single file. Your job is to open
*       the data file and separate the data into the original data files.
*
* Due Date: 11/17/2021
* Date Created: 11/19/2021
* Date Last Modified: 11/17/2021
 */

/*
 * Data Abstraction:
 *          create a string to hold the file name as well as two lines to
 *          hold the headers of the input file. Then, a string to put
 *          lines of data into as we suck them out. Finally, a code string
 *          to hold the last part of the line. if stream for our file, and
 *          three ofstreams for the output files. A string stream for
 *          parsing the data an int for account number and double for
 *          the amount regarding the transaction. Finally, the transaction
 *          'type' which represents a withdrawal or deposit.
 *
 * Input:
 * 		basic input validation loop until we get a file that opens
 *
 * Process:
 * 		read the first two lines of the input, open all the output files,
 *          get each line of the input file, read the acccount number as
 *          well as the amount, type and code. Put the data into its
 *          respective output file dependent on its account number.
 *
 * Output:
 *          write data to respective output file dependent on the account
 *          number.
 *
 * Assumptions:
 * 		A valid input file name is eventually entered.
 *         The data is stored as:
 *               Account-Number Amount W/D Transaction_Code
 */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

const int SIZE = 100;

struct Time
{
    int hour;
    int min;
    double second;
};

void secondSort(Time*, int);
void minuteSort(Time*, int);
void hourSort(Time*, int);

int main()
{
    //Data Abstraction
    ifstream inputFile;
    stringstream ss;
    string line;
    Time stamps[SIZE];
    int hour, minute, count = 0;
    double second;

    inputFile.open("timeData.txt");

    //Input
    //Check to see if the file opened
    if(inputFile)
    {
        //Skip the first line of input
        getline(inputFile, line);

        //Process
        //Read up to 100 times from a file named timeData.txt
        while(getline(inputFile, line))
        {
            //Pick apart the data into parts
            ss.clear();
            ss.str(line);

            ss >> hour;
            ss >> minute;
            ss >> second;

            //Create a time object with these attributes
            Time newStamp;
            newStamp.hour = hour;
            newStamp.min = minute;
            newStamp.second = second;

            //Add the new stamp to the array and increment count
            stamps[count] = newStamp;
            count++;
        }

        //Close the file
        inputFile.close();

        //Print them in sorted order
        //Sort by seconds
        secondSort(stamps, count);
        //Sort by minutes
        minuteSort(stamps, count);
        //Sort by hours
        hourSort(stamps, count);

        for(int i = 0; i < count; i++)
        {
            cout << fixed << setw(2) << setfill('0') << setprecision(0);
            cout << stamps[i].hour << ":" << stamps[i].min << ":" <<
                 stamps[i].second<< endl;
        }

    }
    else
    {
        //Print an error and exit
        cout << "Data File Failed To Open." << endl;
    }

    return 0;
}

void secondSort(Time a[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n-i-1; j++)
        {
            if(a[j + 1].second > a[i].second)
            {
                swap(a[i], a[j + 1]);
            }
        }
    }
}

void minuteSort(Time a[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n-i-1; j++)
        {
            if(a[j + 1].min > a[i].min)
            {
                swap(a[i], a[j + 1]);
            }
        }
    }
}

void hourSort(Time a[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n-i-1; j++)
        {
            if(a[j + 1].hour > a[i].hour)
            {
                swap(a[i], a[j + 1]);
            }
        }
    }
}
