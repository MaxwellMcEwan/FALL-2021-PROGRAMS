/*
* Author: Maxwell McEwan
* Assignment Title: Program 5
* Assignment Description: Input 5 intergers and then calculate their
* arithmetic mean, geometric mean, harmonic mean, and standard deviation.
* The program should then print and label the original 5 numbers
* (sorted from greatest to least) and the four statistics. from the user
* and uses them to calculate the formula's roots.
* Due Date: 9/8/2021
* Date Created: 9/6/2021
* Date Last Modified: 9/6/2021
 */

/*
 * Data Abstraction:
 *      We make all of our variables. I specifically create duplicates
 *      of a,b,c,d,e to sort. I also made temp for the sorting process.
 *      I went ahead and made doubles that we can store all of our mean
 *      and standard deviation data in later.
 *
 * Input:
 * 		The program reads input from the user and assigns the integers
 *      a,b,c,d,e to their respective variables
 *
 * Process:
 * 		- Sorting, we sort all of the numbers by sequentially making
 *      numbers smaller than each other.
 *      - Arithmetic Mean, we plug in a,b,c,d,e into an equation to solve
 *      for the arithmetic mean.
 *      - Geometric Mean, we have to specifically static cast double before
 *      we plug in the variables here, otherwise, we'd get massive numbers
 *      and likely overflow.
 *      - Harmonic Mean, here, we just plug in the numbers into the harmonic
 *      mean but all number ones must be written as 1.0 this way, the variably
 *      implicitly converts to a double.
 *
 * Output:
 *      As a header, we print "Result:". Then "Data:" and the data sorted.
 *      After that, we list the arithmetic, geometric and harmonic means.
 *      We finish output by printing our standard deviation to the screen.
 *
 * Assumptions:
 * 		It is assumed that the user enters intergers only.
 */

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    //Data Abstraction
    int a,b,c,d,e;
    int sortA,sortB,sortC,sortD,sortE;
    int temp;

    double arithmeticMean;
    double geometricMean;
    double harmonicMean;
    double standardDeviation;

    //Input
    cout << "Enter Five Numbers:" << endl;

    cin >> a >> b >> c >> d >> e;

    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
    cout << d << endl;
    cout << e << endl;
    cout << endl;
    cout << endl;
    cout << endl;


    sortA = a;
    sortB = b;
    sortC = c;
    sortD = d;
    sortE = e;

    //Process

    // - Sort the original numbers from greatest to least
    // -- A
    if (sortA > sortB){
        temp = sortA;
        sortA = sortB;
        sortB = temp;
    }
    if (sortA > sortC) {
        temp = sortA;
        sortA = sortC;
        sortC = temp;
    }
    if (sortA > sortD) {
        temp = sortA;
        sortA = sortD;
        sortD = temp;
    }
    if (sortA > sortE) {
        temp = sortA;
        sortA = sortE;
        sortE = temp;
    }

    // -- B
    if (sortB > sortC) {
        temp = sortB;
        sortB = sortC;
        sortC = temp;
    }
    if (sortB > sortD) {
        temp = sortB;
        sortB = sortD;
        sortD = temp;
    }
    if (sortB > sortE) {
        temp = sortB;
        sortB = sortE;
        sortE = temp;
    }

    // -- C
    if (sortC > sortD) {
        temp = sortC;
        sortC = sortD;
        sortD = temp;
    }
    if (sortC > sortE) {
        temp = sortC;
        sortC = sortE;
        sortE = temp;
    }

    // -- D
    if (sortD > sortE) {
        temp = sortD;
        sortD = sortE;
        sortE = temp;
    }

    // - Arithmetic Mean
    arithmeticMean = (a + b + c + d + e) / 5.0;

    // - Geometric Mean
    geometricMean = static_cast<double>(a) * b * c * d * e;
    geometricMean = pow(geometricMean, 1.0/5);

    // - Harmonic Mean
    harmonicMean = 5 / (1.0/a + 1.0/b + 1.0/c + 1.0/d + 1.0/e);

    // - Standard Deviation
    standardDeviation = sqrt((pow(a - arithmeticMean, 2)+
                              pow(b - arithmeticMean, 2)+
                              pow(c - arithmeticMean, 2)+
                              pow(d - arithmeticMean, 2)+
                              pow(e - arithmeticMean, 2))/ 5.0);

    //Output
    cout << "Result: " << endl;
    cout << endl;

    cout << "Data: "   << endl;

    cout << sortE << endl;
    cout << sortD << endl;
    cout << sortC << endl;
    cout << sortB << endl;
    cout << sortA << endl;
    cout << endl;

    cout << fixed << setprecision(2);

    cout << "Arithmetic Mean    = " << arithmeticMean    << endl;
    cout << "Geometric  Mean    = " << geometricMean     << endl;
    cout << "Harmonic   Mean    = " << harmonicMean      << endl;
    cout << "Standard Deviation = " << standardDeviation << endl;

    return 0;
}
