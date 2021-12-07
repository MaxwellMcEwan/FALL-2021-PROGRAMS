/*
 * Author: Maxwell McEwan
 * Assignment Title:  Closest Pair
 * Assignment Description: Return a Pair of Indices where indexPointOne
 *      and indexPointTwo are the closest pair of points in the array
 * Due Date: 12/3/2021
 * Date Created: 12/1/2021
 * Date Last Modified: 12/3/2021
 */

#include "ClosestPair.h"

double Point::distanceTo(Point p2){
    return sqrt(pow((p2.x - x), 2) + pow((p2.y - y), 2));
}

Pair Closest_Pair( Point  P[ ], int n){
    //make a pair to return and variables to store distances/indexes
    Pair minPair;
    int min1, min2;
    float minDist, pointDist;

    //set min distance
    minDist = P[0].distanceTo(P[1]);

    //run through the array and try every combination for closest
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            pointDist = P[i].distanceTo(P[j]);
            if((pointDist < minDist) || (((i + j) / 2 < (min1 + min2) / 2)
                && (pointDist == minDist))){
                //set the new indexes
                min1 = i;
                min2 = j;
                minDist = pointDist;
            }
        }
    }

    //set the min Pair values
    minPair.indexPointOne = min1;
    minPair.indexPointTwo = min2;

    return minPair;
}
