/*
* Author: Maxwell McEwan
* Assignment Title: Matrix Arithmetic with objects
* Assignment Description: Construct a matrix_t class with
*        fields and methods
* Due Date: 11/12/2021
* Date Created: 11/9/2021
* Date Last Modified: 11/12/2021
 */

#include "matrix.h"

matrix_t::matrix_t(){
    row = 2;
    col = 2;
}

matrix_t::matrix_t(int r, int c){
    row = r;
    col = c;
}

void matrix_t::setRow(int r){
    row = r;
}

void matrix_t::setCol(int c){
    col = c;
}

void matrix_t::setValue(int r, int c, double val){
    data[r][c] = val;
}

int matrix_t::getRow() const{
    return row;
}

int matrix_t::getCol() const{
    return col;
}

double matrix_t::getValue(int r, int c) const{
    return data[r][c];
}

void matrix_t::display(ostream& output) const{
    output << setprecision(6) << right;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            output << setw(9) << data[i][j];
        }
        output << endl;
    }
}

double matrix_t::determinant() const{
    double det = 0;
    int subi, subj;
    matrix_t submatrix(row-1,col-1);

    if (row == 2)
        det = ((data[0][0] * data[1][1]) - (data[1][0] * data[0][1]));
    else {
        for (int n = 0; n < row; n++) {
            subi = 0;
            for (int i = 1; i < row; i++) {
                subj = 0;
                for (int j = 0; j < col; j++) {
                    if (j != n){
                        submatrix[subi][subj] = data[i][j];
                        subj++;
                    }
                }
                subi++;
            }
            det += (pow(-1, n) * data[0][n] * submatrix.determinant());
        }
    }

    return det;
}

matrix_t matrix_t::add(const matrix_t& m2) const{
    matrix_t result(row, col);

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            result.setValue(i, j, data[i][j] + m2.data[i][j]);
        }
    }

    return result;
}

matrix_t matrix_t::subtract(const matrix_t& m2) const{
    matrix_t result(row, col);

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            result.setValue(i, j, data[i][j] - m2.data[i][j]);
        }
    }

    return result;
}

matrix_t matrix_t::multiply(const matrix_t& m2) const{
    matrix_t result(row, m2.col);
    double product;

    for(int i = 0; i < row; i++){
        for(int j = 0; j < m2.col; j++){
            product = 0;
            for(int k = 0; k < col; k++){
                product += data[i][k] * m2.data[k][j];
            }
            result.setValue(i, j, product);
        }
    }

    return result;
}

matrix_t matrix_t::operator+(const matrix_t& m2) const{
    return add(m2);
}

matrix_t matrix_t::operator-(const matrix_t& m2) const{
    return subtract(m2);
}

matrix_t matrix_t::operator*(const matrix_t& m2) const{
    return multiply(m2);
}

double* matrix_t::operator[](int n){
    return data[n];
}
