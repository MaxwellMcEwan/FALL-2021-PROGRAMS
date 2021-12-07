/*
 * Author: Maxwell McEwan
 * Assignment Title: Caesar Cipher
 * Assignment Description: Read from a file and shift the values
 *      to 'encrypt' the file.
 * Due Date: 9/24/2021
 * Date Created: 9/20/2021
 * Date Last Modified: 9/24/2021
 */

/*
 * Data Abstraction:
 *      Make variables to read the file name into and hold both the
 *      output and input file. I make a columnWidth so if we want to
 *      change how wide to set the columns we don't have to change
 *      every single spot. We also make a command string to hold
 *      the users command. we need a boolean to save if either the command
 *      for filename was bad data. A character is made to hold the
 *      file input. Shift is used to hold the amount of characters
 *      we want to move the letter, number or symbol by. The,
 *      finally, we have the vowel counts.
 *
 * Input:
 * 		Ask the user for a file name then read it into fileName
 *      Ask the user for a command then read it into command.
 *
 * Process:
 * 		Open the input file and check the validity of the command previously
 *      given to us. We also need to check to see that the file was opened
 *      properly. If either of these fails end the program. Else, read
 *      read character by character, apply the shift, and output the
 *      character to both the screen and into the outputFile.
 *
 * Output:
 * 		Output each of the vowels frequency
 *
 * Assumptions:
 * 		It is assumed that the user enters valid input.
 *
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
    // Data Abstraction
    string fileName;
    ifstream inputFile;
    ofstream outputFile;

    int columnWidth = 7;

    string command;
    bool badInput = false;
    char inputChar;

    string shiftedInput;

    int shift = 3;

    int aCount = 0;
    int eCount = 0;
    int iCount = 0;
    int oCount = 0;
    int uCount = 0;
    int yCount = 0;

    // Input
    // ask for file name and read it into fileName
    cout << "Enter File Name: ";
    cin  >> fileName;
    cout << fileName << endl;

    // ask for a command and read it into command
    cout << "Enter encrypt or decrypt: ";
    cin  >> command;
    cout << command << endl;

    // Process
    // - open input file
    inputFile.open(fileName);

    // check validity of command
    if (command != "encrypt" and command != "decrypt")
    {
        cout << "Error: Bad Command." << endl;
        badInput = true;
    }

    // check if file opened
    if (!inputFile)
    {
        cout << "Error: File did NOT open." << endl;
        badInput = true;
    }

    // if all checks passed, start encrypting or decrypting
    if (!badInput)
    {
        // if the command is decrypt adjust the shift
        if (command == "decrypt")
        {
            shift = -shift;
        }

        // open the output file
        outputFile.open("message");

        // attempt to get a character from the file
        while (inputFile.get(inputChar))
        {
            // check for vowel
            if (inputChar == 'a' or inputChar == 'A')
            {
                aCount++;
            }
            else if (inputChar == 'e' or inputChar == 'E')
            {
                eCount++;
            }
            else if (inputChar == 'i' or inputChar == 'I')
            {
                iCount++;
            }
            else if (inputChar == 'o' or inputChar == 'O')
            {
                oCount++;
            }
            else if (inputChar == 'u' or inputChar == 'U')
            {
                uCount++;
            }
            else if (inputChar == 'y' or inputChar == 'Y')
            {
                yCount++;
            }

            // add shift to character
            inputChar += shift;

            // write the character to the outputFile
            shiftedInput += inputChar;
        }

        // Output
        // report the message after it has been shifted to the screen
        cout << endl;
        cout << shiftedInput << endl << endl;

        // push the shifted input into the outputfile
        outputFile << shiftedInput << endl;

        // disconnect the hoses
        inputFile.close();
        outputFile.close();

        // report vowels
        cout << "Letter Frequency" << endl;
        cout << "   A" << setw(columnWidth) << aCount  << endl;
        cout << "   E" << setw(columnWidth) << eCount  << endl;
        cout << "   I" << setw(columnWidth) << iCount  << endl;
        cout << "   O" << setw(columnWidth) << oCount  << endl;
        cout << "   U" << setw(columnWidth) << uCount  << endl;
        cout << "   Y" << setw(columnWidth) << yCount  << endl;

    }

    return 0;
}
