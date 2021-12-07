/*
* Author: Maxwell McEwan
* Assignment Title: C string functions
* Assignment Description: Implement each of the following
*       C-style string functions.
* Due Date: 10/22/2021
* Date Created: 10/17/2021
* Date Last Modified: 10/22/2021
 */

#include "Cstring.h"

using namespace std;

int Strlen(const char s1[ ]){
    int count = 0;

    while(s1[count] != '\0'){
        count++;
    }

    return count;
}

void Strcpy(char s1[ ], const char s2[ ]){
    int count = 0;

    while(s2[count] != '\0'){
        s1[count] = s2[count];
        count++;
    }

    s1[count] = '\0';
}

int Strcmp(const char s1[ ], const char s2[ ]){
    int count = 0;

    while(s1[count] != '\0' && s1[count] == s2[count]){
        count++;
    }

    return s1[count] - s2[count];
}

void Strcat(char s1[ ], const char s2[ ]){
    int i = 0;
    int j = 0;

    while (s1[i] != '\0'){
        i++;
    }

    while (s2[j] != '\0'){

        s1[i] = s2[j];

        i++;
        j++;
    }

    s1[i] = '\0';
}

