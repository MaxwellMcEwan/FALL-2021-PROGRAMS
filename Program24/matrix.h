/*
* Author: Maxwell McEwan
* Assignment Title: Matrix Arithmetic with objects
* Assignment Description: Construct a matrix_t class with
*        fields and methods
* Due Date: 11/12/2021
* Date Created: 11/9/2021
* Date Last Modified: 11/12/2021
 */

#ifndef MATRIX_H_
#define MATRIX_H_

#include<ostream>
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

const int MAX_SIZE = 100;
const int WIDTH = 4;

class matrix_t{
private:
	int row, col;
	double data[MAX_SIZE][MAX_SIZE] = {{0}};

public:

    /*
    * description: default constructor class for matrix object
    * return: matrix
    * precondition: matrix obj has been made
    * postcondition: sets values for row and col
    *
    */
	matrix_t();

    /*
    * description: Custom constructor
    * return: matrix
    * precondition: two ints have been passed
    * postcondition: sets values for row and col
    *
    */
	matrix_t(int, int);

    /*
    * description: Mutator method to set the value of row.
    * return: matrix
    * precondition: an int has been passed
    * postcondition: sets value for row
    *
    */
	void setRow(int);

    /*
    * description: Mutator method to set the value of col.
    * return: none
    * precondition: an int has been passed
    * postcondition: sets value for col
    *
    */
	void setCol(int);

    /*
    * description: Mutator method to set a cell in the Matrix
    * return: none
    * precondition: two ints and a double have been passed
    * postcondition: sets value of a cell in the matrix
    *
    */
	void setValue(int, int, double);

    /*
    * description: Accessor method to return the value of row
    * return: int
    * precondition: matrix obj has been made
    * postcondition: returns the value of row
    *
    */
	int getRow() const;

    /*
    * description: Accessor method to return the value of col
    * return: int
    * precondition: matrix obj has been made
    * postcondition: returns the value of col
    *
    */
	int getCol() const;

    /*
    * description: Accessor method to return the value of a cell in the matrix
    * return: double
    * precondition: two ints and a double have been passed
    * postcondition: returns the value of a cell in the matrix
    *
    */
	double getValue(int, int) const;

    /*
    * description: Member function to write matrix to an ostream
    * return: none
    * precondition: matrix obj has been made
    * postcondition: outputs a matrix to an ostream
    *
    */
	void display(ostream&) const;

    /*
    * description: Member function to calculate the determinant
    * return: double
    * precondition: matrix obj has been made
    * postcondition: returns the determinate
    *
    */
	double determinant() const;

    /*
    * description: Member function to add two matrices
    * return: matrix
    * precondition: a matrix object has been passed
    * postcondition: adds two matricies
    *
    */
	matrix_t add(const matrix_t&) const;

    /*
    * description: Member function to subtract two matrices
    * return: matrix
    * precondition: a matrix object has been passed
    * postcondition: subtracts two matricies
    *
    */
	matrix_t subtract(const matrix_t&) const;

    /*
    * description: Member function to multiply two matrices
    * return: matrix
    * precondition: a matrix object has been passed
    * postcondition: multiplies two matricies
    *
    */
	matrix_t multiply(const matrix_t&) const;

    /*
    * description: Overloaded addition operator
    * return: matrix
    * precondition: the matricies can be multiplied
    * postcondition: returns result of add
    *
    */
	matrix_t operator+(const matrix_t&) const;

    /*
    * description: Overloaded subtraction operator
    * return: matrix
    * precondition: a matrix object has been passed
    * postcondition: returns result of subtract
    *
    */
	matrix_t operator-(const matrix_t&) const;

    /*
    * description: Overloaded multiplication operator
    * return: matrix
    * precondition: a matrix object has been passed
    * postcondition: returns result of multiplication
    *
    */
	matrix_t operator*(const matrix_t&) const;

    /*
    * description: Overloaded square brackets
    * return: double
    * precondition: double brackets have been used
    * postcondition: returns the double at position n
    *
    */
	double* operator[](int n);

};


#endif /* MATRIX_H_ */
