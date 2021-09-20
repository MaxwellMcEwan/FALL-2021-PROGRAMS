//Author: Maxwell McEwan
//Assignment Title: Approximate PI
//Assignment Description: Approximating Pi (believe it or not)
//Due Date: 9/1/2021
//Date Created: 8/29/2021
//Date Last Modified: 8/29/2021

#include <iostream>

using namespace std;

int main()
{
    double PiOne = 4 * (1 - 1.0/3 + 1.0/5 - 1.0/7 + 1.0/9 - 1.0/11);
    double PiTwo = 4 * (1 - 1.0/3 + 1.0/5 - 1.0/7 + 1.0/9 - 1.0/11 + 1.0/13);

    cout << "PI = " << PiOne << endl;
    cout << "PI = " << PiTwo << endl;

    return 0;
}
