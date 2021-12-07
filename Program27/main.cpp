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
#include <string>
#include <fstream>
#include <iomanip>
#include <ostream>
#include <sstream>

const int W = 7;

using namespace std;

void writeToFile(int, double, char, string, ostream&);

int main()
{
    // Data Abstraction
    string fileName, line1, line2, dataLine, code;
    ifstream inputFile;
    ofstream a_out, b_out, c_out;
    stringstream ss;
    int accNum;
    double amount;
    char type;

    // Input
    do {
        //Ask the user for the name of a data file
        cout << "Enter Name of Data File: ";
        cin >> fileName;

        //Echo print the name of the file
        cout << fileName << endl;

        //Open the data file
        inputFile.open(fileName);

        //If the file does not open
        if(!inputFile){
            //Print an error message, return to step 1
            cout << "Error: File Not Open." << endl;
        }
    } while(!inputFile);

    // Process
    //Read the first two lines of the file and remember them for use in step 7.
    getline(inputFile, line1);
    getline(inputFile, line2);

    //Open three different output files named:
    //Company_A.txt
    a_out.open("Company_A.txt");
    //Company_B.txt
    b_out.open("Company_B.txt");
    //Company_C.txt
    c_out.open("Company_C.txt");

    //Write the first two lines from the data file (read in step 5) into each
    //of the three output files.
    a_out << line1 << endl << line2 << endl;
    b_out << line1 << endl << line2 << endl;
    c_out << line1 << endl << line2 << endl;

    //Next process the mixed data.
    while(getline(inputFile, dataLine)){
        ss.clear();
        ss.str(dataLine);

        //Each of the next N lines of the data file have the following format:
        //Account-Number Amount W/D Transaction_Code
        ss >> accNum;
        ss >> amount;
        ss >> type;
        ss >> code;

        // Output
        //Use the following information to determine which file each record
        // should be written to;
        //0 <= Account Numbers < 100 should be written to Company_A.txt
        if(accNum >= 0 && accNum < 100){
            writeToFile(accNum, amount, type, code, a_out);
        }
        //300 <= Account Numbers <400 should be written to Company_B.txt
        else if(accNum >= 300 && accNum < 400){
            writeToFile(accNum, amount, type, code, b_out);
        }
        //200 <= Account Numbers < 300 should be written to Company_C.txt
        else if(accNum >= 200 && accNum < 300){
            writeToFile(accNum, amount, type, code, c_out);
        }
    }
    return 0;
}

void writeToFile(int acc, double amount, char t, string code, ostream& out){
    out << fixed << setprecision(2);
    out << acc << " " << amount << " " << t << " " << code << endl;
}
