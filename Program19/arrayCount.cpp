/*
* Author: Maxwell McEwan
* Assignment Title: Array Processing
* Assignment Description: implement a collection of functions
*       to refresh your C++ skills and strengthen your array
*       processing skills.
* Due Date: 10/27/2021
* Date Created: 10/24/2021
* Date Last Modified: 10/26/2021
 */

#include "arrayCount.h"

int arrayCount(int a[ ], int s, int v){
    int n = 0;
    int i =0;

    while(i < s){
        if (a[i] == v){
            n++;
        }
        i++;
    }

    return n;
}

int arrayCount(double a[ ], int s, double v){
    int n = 0;
    int i =0;

    while(i < s){
        if (a[i] == v){
            n++;
        }
        i++;
    }

    return n;
}

int arrayCount(string a[ ], int s , string v){
    int n = 0;
    int i =0;

    while(i < s){
        if (a[i] == v){
            n++;
        }
        i++;
    }

    return n;
}

int arrayCount(char a[ ], char v){
    int n = 0;
    int i =0;

    while(a[i] != '\0'){
        if (a[i] == v){
            n++;
        }
        i++;
    }

    return n;
}

int arrayCount(vector<int> a, int v){
    int n = 0;
    int i =0;

    while(i < static_cast<int>(a.size())){
        if (a[i] == v){
            n++;
        }
        i++;
    }

    return n;
}

int arrayCount(vector<string> a, string v){
    int n = 0;
    int i =0;

    while(i < static_cast<int>(a.size())){
        if (a[i] == v){
            n++;
        }
        i++;
    }

    return n;
}

int arrayCount(vector<double> a, double v){
    int n = 0;
    int i =0;

    while(i < static_cast<int>(a.size())){
        if (a[i] == v){
            n++;
        }
        i++;
    }

    return n;
}

int arrayCount(vector<char> a, char v){
    int n = 0;
    int i =0;

    while(a[i] != '\0'){
        if (a[i] == v){
            n++;
        }
        i++;
    }

    return n;
}
