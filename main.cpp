/*
 * Author: Maxwell McEwan
 * Assignment Title: Guessing Game
 * Assignment Description: Asks for a range of ints then makes the user
 *     guess a random integer chosen in between the given range.
 * Due Date: 9/17/2021
 * Date Created: 9/12/2021
 * Date Last Modified: 9/16/2021
 */

/*
 * Data Abstraction:
 * 		Make a and b to hold the range of integers that we can pick from.
 * 		We need temp for when we sort a and b to make sure a is less than b.
 *      Next, we prematurely make the guess variable to hold the users inputs
 *      We make range to hold the range from a to b and answer to hold the
 *      randomly generated number from range.
 *
 * Input:
 * 		The program gets input from the user and reads them into a and b.
 *
 * Process:
 * 		Sort a and b to make a the smaller of the two
 * 		Seed random with time
 *      Calculate random and store it in the answer variable
 *      Run a do while loop while the users guess != the generated answer
 *
 * Output:
 * 		Print to the screen number of guesses it took the user to
 *      display the correct answer.
 *
 * Assumptions:
 * 		It is assumed that the user enters integers
 * 		It is assumed that the user enters different integers
 *
 */

#include <iostream>
#include <ctime>

using namespace std;

int main()
{
    //Data Abstraction
    int a, b;
    int temp;

    int guess;
    int range;
    int answer;
    int numGuess = 0;

    //Input
    // - Ask for input from the user and read it into a and b
    cout << "Please enter 2 intergers: ";
    cin  >> a;
    cin  >> b;

    // - Echo print data back to user
    cout << a << " " << b << endl << endl;

    //Process
    // - Sort a and b to make a the smaller of the two
    if (a > b){
        temp = a;
        a = b;
        b = temp;
    }

    //
    cout << "I'm thinking of a number between "
         << a << " and " << b << "." << endl << endl;

    // - Calculate range
    range = (b - a) + 1;
    // - Seed random with time
    srand(time(0));
    // - Calculate random and store it in the answer variable
    answer = rand() % (range + a);

    // - Run a do while loop while the users guess != the generated answer
    do{
        // LOOP INPUT
        // -- Get input from the user and put it into the guess variable
        cout << "Enter guess: ";
        cin  >> guess;
        cout << guess;

        // LOOP PROCESS
        // -- Increment the number of guesses by one
        numGuess++;

        // LOOP OUTPUT
        // -- Print if the guess was too high or too low
        if (guess > answer){
            cout << " - Too High" << endl << endl;
        } else if (guess < answer){
            cout << " - Too Low"  << endl << endl;
        }

    } while (guess != answer);

    //Output
    // - Go down two lines for readability after the num is guessed
    cout << endl << endl;
    // - Print to the screen the number of guesses it took the user
    cout << "Correct, it took you " << numGuess << " tries to guess my number."
         << endl;

    return 0;
}
