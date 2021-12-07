/*
* Author: Maxwell McEwan
* Assignment Title:  Program 4
* Assignment Description: Write a program that reads an int from 0-9999999
* Due Date: 9/3/2021
* Date Created: 8/30/2021
* Date Last Modified: 9/1/2021
 */

/*
 * Data Abstraction:
 *      2 variables n and sum.
 * Input:
 *      The user inputs a number between 0 and 9999999 through cin.
 *      I included the first cout here because while it may not be actively
 *      trying to get a number from the user, it felt like it had more to do
 *      with input than data abstraction.
 * Process:
 *      the loop executes 7 times each time adding the remainder of n modulus
 *      10 to sum. It then divides n by 10 in order to get the next column/
 *      I put it into a loop because I thought it looked prettier.
 * Output:
 *      After processing, we print the final sum to the output.
 *      Along with the sum, we print some text so the user can make more sense
 *      of the output.
 * Assumptions:
 * 		It is assumed that the user enters an int from 0 to 9999999.
 */

#include <iostream>

using namespace std;

int main() {

  // Data Abstraction
  int n;
  int sum = 0;

  // Input
  cout << "Enter an integer between 0 and 9999999: ";

  cin >> n ;
  cout << n << endl;

  // Process
  for (int i = 0; i <= 6; i++){
    sum += n % 10;
    n /= 10;
  }

  // Output
  cout << "The sum of the digits is  " << sum << "." << endl;

  return 0;
}
