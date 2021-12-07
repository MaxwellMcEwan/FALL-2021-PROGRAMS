#include <iostream>
#include "Cstring.h"

using namespace std;

int main()
{
    const char sMyName[10] = {"deez nutz"};
    char sMyAge[5] = {"bruh"};

    cout << Strlen(sMyName);
    Strcpy(sMyAge, sMyName);

    cout << sMyName;


    return 0;
}
