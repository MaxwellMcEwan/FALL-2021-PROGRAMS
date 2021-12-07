/*
* Author: Maxwell McEwan
* Assignment Title:  Letter Grade
* Assignment Description: Gets 5 test scores from the user
* 	And calculates the average, min, max, median, and grade
* Due Date: 9/16/2021
* Date Created: 9/10/2021
* Date Last Modified: 9/10/2021
 */

/*
 * Data Abstraction:
 * 		5 variables, a, b, c, d, and e initialized for test scores
 *      we need temp for sorting and sum for the average
 *      Theres a char for grade and doubles for the rest
 * Input:
 * 		The user Inputs the 5 test scores, we then echo print them
 * Process:
 *      We have to first check to make sure that all of the values
 *      are within a range we can take (0-100).
 * 		Then we sort all of the test scores from greatest to least.
 *      After that it is pretty straight forward, just calculate the
 *      sum and then average and assign the rest of the values
  * Output:
 *      We output all of our calculations to the screen. This includes
 *      Average, Grade, Min, Max, and Median.
 * Assumptions:
 * 		It is assumed that the user only inputs doubles or ints
 * 		It is assumed that the user inputs values 0-100
 */

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    //Data Abstraction
    double a,b,c,d,e;
    double sum;
    double temp;

    char   grade;

    double average;
    double minNum;
    double maxNum;
    double median;


    //Input
    cout << "Please Enter Five Test Scores." << endl;
    cin  >> a;
    cin  >> b;
    cin  >> c;
    cin  >> d;
    cin  >> e;

    cout << fixed << setprecision(2);
    cout << a << " " << b << " " <<c <<" " << d << " " << e << endl;
    cout << endl;

    //Process

    // - Check that all values are within the range of 0-100
    if (100/a < 1 or 100/b < 1 or 100/c < 1 or 100/d < 1 or 100/e < 1){
        cout << "ERROR: BAD DATA" << endl;
    }

    // - Sort the test scores from greatest to least
    // -- A
    if (a > b){
        temp = a;
        a = b;
        b = temp;
    }
    if (a > c) {
        temp = a;
        a = c;
        c = temp;
    }
    if (a > d) {
        temp = a;
        a = d;
        d = temp;
    }
    if (a > e) {
        temp = a;
        a = e;
        e = temp;
    }

    // -- B
    if (b > c) {
        temp = b;
        b = c;
        c = temp;
    }
    if (b > d) {
        temp = b;
        b = d;
        d = temp;
    }
    if (b > e) {
        temp = b;
        b = e;
        e = temp;
    }

    // -- C
    if (c > d) {
        temp = c;
        c = d;
        d = temp;
    }
    if (c > e) {
        temp = c;
        c = e;
        e = temp;
    }

    // -- D
    if (d > e) {
        temp = d;
        d = e;
        e = temp;
    }

    // - Calculate the sum
    sum = a + b + c + d + e;

    // - Finish average calculations and then assign the min, max and median
    average = sum / 5;
    minNum = a;
    maxNum = e;
    median = c;

    // - Calculate the grade using the average of the five test scores
    if (average >= 89.5){
        grade = 'A';

    } else if (average >= 79.5) {
        grade = 'B';

    } else if (average >= 69.5){
        grade = 'C';

    } else if (average >= 59.5){
        grade = 'D';

    } else {
        grade = 'F';

    }

    //Output
    cout << "Average = " << average << endl;
    cout << "Grade   = " << grade   << endl;
    cout << "Min     = " << minNum  << endl;
    cout << "Max     = " << maxNum  << endl;
    cout << "Median  = " << median  << endl;

    return 0;
}
