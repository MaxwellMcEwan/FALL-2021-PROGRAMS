/*
 * Author: Maxwell McEwan
 * Assignment Title: Class average
 * Assignment Description: Read names from a file that then give
 *      you other file names to open and read data from.
 * Due Date: 10/1/2021
 * Date Created: 9/28/2021
 * Date Last Modified: 9/30/2021
 */

/*
 * Data Abstraction:
 *      Create two file input streams for the one main student name file
 *      and for the individual student grade files. We need to create
 *      strings to hold the file names, student names as well. Next,
 *      we initialize some integers to hold counters and sums for us.
 *      For our doubles, we have min, max, grade, class average and
 *      student average.
 *
 * Input:
 * 		Ask the user for a file name then read it into fileName
 *      if the file fails to open, end the program.
 *
 * Process:
 * 		We open the main student names file and read the first name out
 *      of it. For ever student the process goes as such:
 *      - construct string for their expected file name
 *      - attempt to open the file
 *      - if successfully opened, input grades and update our statistics
 *      - once no more grades can be read, perform last calculations
 *      - close the students specific grade file
 *
 *      We attempt to complete these steps for every students file.
 *
 * Output:
 * 		Unfortunately, I could not successfully implement a design that
 *      kept Input, process, and output entirely separate.
 *      However, it was not in the specifications of this program.
 *      Dr. Booth said he was going to show us how to completely divide
 *      the different sections using arrays for next weeks programming
 *      assignments.
 *
 * Assumptions:
 * 		It is assumed that the user enters a valid file name.
 *
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

const int COLUMN_WIDTH = 24;

int main()
{
    // Data Abstraction
    ifstream nameData, studentGradeData;
    string inputFileName, studentFileName, studentName, first, last, middle;
    int classSum = 0, numGrades = 0, studentSum, numStudentGrades;
    int numStudents = 0;

    double min, max, grade, classAverage, studentAverage;

    // Input
    // prompt user for file name
    cout << "Enter Name of Data File: ";
    cin  >> inputFileName;
    cout << inputFileName << endl << endl;

    // attempt to open the file
    nameData.open(inputFileName);

    // Process
    // check for file validity
    if(nameData)
    {
        // report headers
        cout << left << setw(COLUMN_WIDTH) << "Student"
             << setw(COLUMN_WIDTH) << "Average" << endl;

        cout << fixed << setprecision(2);

        // read names from the student names file
        while (nameData >> last >> first >> middle)
        {
            studentName = first + " " + middle + " " + last;

            cout << left << setw(COLUMN_WIDTH) << studentName
                 << setw(COLUMN_WIDTH);

            // increment the number of students by one
            numStudents++;

            // construct a file name for the current student
            studentFileName = first + last + ".dat";

            // open a file with the previously constructed name
            studentGradeData.open(studentFileName);

            // reset num student grades, student sum from last iteration
            numStudentGrades = 0;
            studentSum = 0;

            // check if the file successfully opens
            if (studentGradeData)
            {
                // read the grade data out of the file
                while (studentGradeData >> grade)
                {
                    // add to the students grade sum
                    studentSum += grade;

                    // check for first ever iteration of loops
                    if (numStudentGrades == 0 and numGrades == 0)
                    {
                        min = max = grade;
                    }

                    // check for new minimum and maximum
                    if (grade < min)
                    {
                        min = grade;
                    }

                    if (grade > max)
                    {
                        max = grade;
                    }

                    // increment the number of grades recorded
                    numStudentGrades++;
                }

                // check if any grades were recorded for this student
                if (numStudentGrades > 0)
                {
                    // add the grade count and sum to the classes variables
                    numGrades += numStudentGrades;
                    classSum += studentSum;

                    // computer the students average
                    studentAverage = static_cast<double>(studentSum)
                                    /numStudentGrades;

                    // add the name to the vector
                    cout << studentAverage << endl;
                }
                else
                {
                    // if there are not any grades in the file
                    cout << "No Grades" << endl;
                }
            }
            else
            {
                // if we can't locate a file for that student
                cout << "No Data File" << endl;
            }

            // DISCONNECT THE STUDENT HOSE
            studentGradeData.close();
        }
        // calculate the class average
        classAverage = static_cast<double>(classSum)/numGrades;

        // DISCONNECT THE CLASS HOSE
        nameData.close();

        // finish reporting: min, max, and class average
        cout << endl << "Class Average: " << classAverage << endl;
        cout << "Max Score: " << max << endl;
        cout << "Min Score: " << min << endl;

    } else {
        // if the file containing student names does not open
        cout << "ERROR: File Not Open.";
    }

    return 0;
}
