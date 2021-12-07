/*
 * Author: Maxwell McEwan
 * Assignment Title: Array Backwards
 * Assignment Description: Write a program in C++ to read n integers into
 *      an array and display it in reverse order.
 * Due Date: 10/8/2021
 * Date Created: 10/3/2021
 * Date Last Modified: 10/8/2021
 */

/*
 * Data Abstraction:
 *      Make an array of ints to hold inputted values
 *      Next, ints for a read input, number of inputs
 *      something to hold the sum, and min as well as max.
 *      Lastly, we need a bool to hold onto if an item is already
 *      on our list and a vector for duplicates
 *
 * Input:
 * 		Ask the user for a number of values we're gonna store in an
 *      array. Then continue to prompt for input that many times.
 *      Store that value in our array.
 *
 * Process:
 * 		Running through our array and checking for min, max, adding
 *      to our sum, and scanning the array for duplicates.
 *
 * Output:
 * 		Report the array forwards and backwards. Then, the sum,
 *      number of duplicates, as well as the min and max.
 *
 * Assumptions:
 * 		It is assumed that the user enters the number of integers
 *      that they said they were going to.
 *
 */

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // Data Abstraction
    int a[25];
    int num, numVals, i = 0, sum = 0, min, max;
    bool onList;
    vector<int> dupList;

    // Input
    // prompt the user for some input
    cout << "Input the number of elements to store in the array: ";
    cin  >> numVals;

    // echoprint back the input that the user gave
    cout << numVals << endl;

    // print an output message for numVals
    cout << "Input " << numVals << " integers:" << endl;

    // get the rest of the input and fill in our array
    while(i < numVals)
    {
        cout << "integer - " << i << " : ";
        cin >> num;
        cout << num << endl;
        a[i] = num;
        i++;
    }
    cout << endl << endl;

    // Process
    for(i = 0; i < numVals; i++)
    {
        // if it is the first iteration, set the min and max
        if (i == 0)
        {
            min = max = a[i];
        }
        else
        {
            // check for a new min and max
            if (a[i] < min)
            {
                min = a[i];
            }

            if (a[i] > max)
            {
                max = a[i];
            }
        }

        // add the number to our sum
        sum += a[i];

        // check for a duplicate
        for(int j = i + 1; j < numVals; j++)
        {
            // run through every character looking for duplicates
            if(a[i] == a[j])
            {
                // by default make onList set to false
                onList = false;

                // sort through duplist to see if we already have the item
                for(int k = 0; k < static_cast<int>(dupList.size()); k++)
                {
                    if(dupList.at(k) == a[i])
                    {
                        onList = true;
                    }
                }
                if (!onList)
                {
                    dupList.push_back(a[i]);
                }
            }
        }
    }

    // Output
    i = 0;

    // print the array forwards
    cout << "The values stored into the array are :" << endl;
    while(i < numVals)
    {
        cout << a[i] << " ";
        i++;
    }
    cout << endl << endl;

    // set i to the index we should start at
    i = numVals - 1;

    // print the array backwards
    cout << "The values stored into the array in reverse are :" << endl;
    while(i > -1)
    {
        cout << a[i] << " ";
        i--;
    }
    cout << endl << endl;

    // report the rest of the statistics
    cout << "The sum of all elements of the array is " << sum << endl;
    cout << "The total number of duplicate elements in the array is "
         << dupList.size() << endl;
    cout << "The maximum and minimum element in the array are " << max
         << " , " << min << endl;

    return 0;
}
