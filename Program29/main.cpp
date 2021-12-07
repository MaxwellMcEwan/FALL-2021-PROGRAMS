/*
 * Author: Maxwell McEwan
 * Assignment Title:  Sorting Students
 * Assignment Description: Write a C++ program that will open a file
 *    and sort the date inside of it, then print the sorted data.
 * Due Date: 12/1/2021
 * Date Created: 11/27/2021
 * Date Last Modified: 11/29/2021
*/

/*
 * Data Abstraction:
 *    Make strings for the first and last name, the grade,
 *    the hometown and a throw away line. Integers for the zip
 *    the age, and the array size. Finally, a double for the
 *    GPA and an array for 100 students as well as an input stream.
 *
 * Input:
 * 		Open the input file, skip the first line, and begin reading
 *    the data out of the input file. Specifically for the grade we
 *    have to assign a number for the string given to us.
 *
 * Process:
 * 		To begin, sort everything by GPA. Afterwhich, go item by item
 *    checking the previous student for duplicates in which case,
 *    sort the students on a statistic that differs between them.
 *    If all of their information is the same, flag one as a
 *    duplicate to be displayed as one later.
 *
 * Output:
 *    Use the students display function to print their stats.
 *
 * Assumptions:
 * 		The input file given exists.
 *    All the data is given in the manner specified.
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "classFunctions.h"

using namespace std;

const int SIZE = 100;
const string FILE_NAME = "stDATA.txt";

int main()
{
    //Data Abstraction
    string first, last, grade, hometown, line;
    int zip, age, count = 0;
    double gpa;
    student a[SIZE];

    ifstream inputFile;

    //Input
    //open a file named stDATA.txt.
    inputFile.open(FILE_NAME);

    //skip the first line
    getline(inputFile, line);

    //This file contains an unknown number of student records, one per line.
    while(inputFile >> first)
    {
        //take the line of data out of the file piece by piece
        inputFile >> last;
        inputFile >> grade;
        inputFile >> zip;
        inputFile >> age;
        inputFile >> hometown;
        inputFile >> gpa;

        //assign the variables to one of the students
        a[count].first = first;
        a[count].last = last;

        if(grade == "FR"){
            a[count].grade = 0;
        }
        else if (grade == "SO"){
            a[count].grade = 1;
        }
        else if (grade == "JR"){
            a[count].grade = 2;
        }
        else{
            a[count].grade = 3;
        }

        a[count].zip = zip;
        a[count].age = age;
        a[count].hometown = hometown;
        a[count].gpa = gpa;

        //increment count
        count++;
    }

    //close the file
    inputFile.close();

    //Process
    //sub-sort by first name
    SortByFirst(a, count);
    //sub-sort by last name
    SortByLast(a, count);
    //sub-sort by class
    SortByClass(a, count);
    //Your program should print a list of students sorted by GPA.
    SortByGPA(a, count);

    //iterate through everything in the array and check for duplicates
    for(int i = 0; i < count; i++)
    {
        if(i > 0 && a[i].gpa == a[i - 1].gpa && a[i].grade == a[i - 1].grade
                && a[i].last == a[i - 1].last && a[i].first == a[i - 1].first){
            // Duplicate Record
            a[i].duplicate = true;
        }
    }

    //Output
    //print the intitial line of text
    cout << setw(W) << left << "First Name"
         << setw(W) << "Last Name"
         << setw(W) << "Class"
         << setw(W) << "Zip"
         << setw(W) << "Age"
         << setw(W) << "Hometown"
         << setw(W) << "GPA" << endl;

    //iterate through everything in the array
    for(int i = 0; i < count; i++){
        a[i].display();
    }
}
