/*
 * Author: Maxwell McEwan
 * Assignment Title:  Sorting Students
 * Assignment Description: Write a C++ program that will open a file
 *    and sort the date inside of it, then print the sorted data.
 * Due Date: 12/1/2021
 * Date Created: 11/27/2021
 * Date Last Modified: 11/29/2021
*/

#ifndef CLASSFUNCTIONS_H_
#define CLASSFUNCTIONS_H_

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const int W = 15;

struct student{
  string first, last, hometown, classification;
  int zip, age, grade;
  double gpa;
  bool duplicate = false;

  /*
  * description: Print the students stats
  * return: void
  * precondition: the function is called
  * postcondition: the stats are printed to cout
  *
  */
  void display();
};

/*
 * description: Sort the students of an array by GPA
 * return: void
 * precondition: a valid array and size are passed
 * postcondition: the array is sorted by GPA
 *
*/
void SortByGPA(student*, int);

/*
 * description: Sort the students of an array by class
 * return: void
 * precondition: a valid array and size are passed
 * postcondition: the array is sorted by class
 *
*/
void SortByClass(student*, int);

/*
 * description: Sort the students of an array by last
 * return: void
 * precondition: a valid array and size are passed
 * postcondition: the array is sorted by last
 *
*/
void SortByLast(student*, int);

/*
 * description: Sort the students of an array by first
 * return: void
 * precondition: a valid array and size are passed
 * postcondition: the array is sorted by first
 *
*/
void SortByFirst(student*, int);


#endif /* CLASSFUNCTIONS_H_ */
