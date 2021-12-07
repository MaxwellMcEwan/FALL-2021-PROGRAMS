#include <iostream>
#include "Point.h"

using namespace std;

int main()
{
    Point p1(0,0), p2(-5,62);

    p1.midPoint(p2).display(cout);


    return 0;
}
