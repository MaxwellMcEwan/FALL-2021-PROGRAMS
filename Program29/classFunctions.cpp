/*
 * Author: Maxwell McEwan
 * Assignment Title:  Sorting Students
 * Assignment Description: Write a C++ program that will open a file
 *    and sort the date inside of it, then print the sorted data.
 * Due Date: 12/1/2021
 * Date Created: 11/27/2021
 * Date Last Modified: 11/29/2021
*/

#include "classFunctions.h"

void student::display(){
  if(!duplicate){

    switch(grade){
      case 0:
        classification = "FR";
      break;

      case 1:
        classification = "SO";
      break;

      case 2:
        classification = "JR";
      break;

      case 3:
        classification = "SR";
      break;
    }

    cout << setw(W) << left << first
    << setw(W) << last
    << setw(W) << classification
    << setw(W) << zip
    << setw(W) << age
    << setw(W) << hometown << fixed
    << setw(W) << setprecision(2) << gpa << endl;
  } else {
    cout << "I THINK THIS IS A DUPLICATE RECORD" << endl;
  }
}

void SortByGPA(student a[], int size){
  for(int i = 0; i < size-1; i++){
    for(int j = 0; j < size-1-i; j++){
      if(a[j].gpa > a[j + 1].gpa){
        swap(a[j], a[j + 1]);
      }
    }
  }
}

void SortByClass(student a[], int size){
  for(int i = 0; i < size-1; i++){
    for(int j = 0; j < size-1-i; j++){
      if(a[j].grade > a[j + 1].grade){
        swap(a[j], a[j + 1]);
      }
    }
  }
}

void SortByLast(student a[], int size){
  for(int i = 0; i < size-1; i++){
    for(int j = 0; j < size-1-i; j++){
      if(a[j].last > a[j + 1].last){
        swap(a[j], a[j + 1]);
      }
    }
  }
}

void SortByFirst(student a[], int size){
  for(int i = 0; i < size-1; i++){
    for(int j = 0; j < size-1-i; j++){
      if(a[j].first > a[j + 1].first){
        swap(a[j], a[j + 1]);
      }
    }
  }
}
