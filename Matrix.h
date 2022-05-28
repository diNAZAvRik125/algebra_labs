#define CRT_SECURE_NO_WARNINGS
#ifndef MATRIX_CLASS_MATRIX_H
#define MATRIX_CLASS_MATRIX_H
#include <iostream>
using namespace std;

template<typename T> class Matrix{
public:
    int rows = 0;
    int columns = 0;
    T ** values = nullptr;
    Matrix(int row, int column): rows(row), columns(column){
        values = new T * [rows];
        for (int i = 0; i < rows; i++)
            values[i] = new T [columns];
    }


    Matrix(int row, int column, const T &value): rows(row), columns(column){
        values = new T * [rows];
        for (int index = 0; index < rows; ++index) values[index] = new T [columns];
        for (int index_1 = 0; index_1 < rows; ++index_1)
            for (int index_2 = 0; index_2 < columns; ++index_2) values[index_1][index_2] = value;
    }


    Matrix(const Matrix &matrix){
        rows = matrix.rows;
        columns = matrix.columns;
        values = new T * [rows];
        for (int index = 0; index < rows; ++index) values[index] = new T [columns];
        for (int index_1 = 0; index_1 < rows; ++index_1)
            for (int index_2 = 0; index_2 < columns; ++index_2) values[index_1][index_2] = matrix[index_1][index_2];
    }


    ~Matrix(){
        for (int index = 0; index < rows; ++index) delete[] values[index];
        delete[] values;
    }


    T & operator() (int row, int column){
        return values[row][column];
    }


    const T & operator() (int row, int column) const{
        return values[row][column];
    }


    Matrix & operator= (const Matrix &matrix){
        if (this == &matrix) return *this;
        rows = matrix.rows;
        columns = matrix.columns;
        values = new T * [rows];
        for (int index = 0; index < rows; ++index) values[index] = new T [columns];
        for (int index_1 = 0; index_1 < rows; ++index_1)
            for (int index_2 = 0; index_2 < columns; ++index_2) values[index_1][index_2] = matrix[index_1][index_2];
        return *this;
    }


    Matrix & operator= (const T &value){
        for (int index_1 = 0; index_1 < rows; ++index_1)
            for (int index_2 = 0; index_2 < columns; ++index_2) values[index_1][index_2] = value;
        return *this;
    }


    T * operator[] (int row){
        return values[row];
    }


    const T * operator[] (int row) const{
        return values[row];
    }


    friend Matrix operator+ (const Matrix &first, const Matrix &secend){
        if ((first.rows != secend.rows) || (first.columns != secend.columns)){
            cout << "ERROR";
            exit(-1);
        }
        Matrix res = Matrix(first.rows, first.columns);
        for(int index_1 = 0; index_1 < res.rows; ++index_1)
            for(int index_2 = 0; index_2 < res.columns; ++index_2) res[index_1][index_2] = first[index_1][index_2] + secend[index_1][index_2];
        return res;
    }


    friend Matrix operator+ (const Matrix &first, const T &value){
        Matrix res = Matrix(first.rows, first.columns);
        for(int index_1 = 0; index_1 < res.rows; ++index_1)
            for(int index_2 = 0; index_2 < res.columns; ++index_2) res[index_1][index_2] = first[index_1][index_2] + value;
        return res;
    }


    friend Matrix operator+ (const T &value, const Matrix &first){
        Matrix res = Matrix(first.rows, first.columns);
        for(int index_1 = 0; index_1 < res.rows; ++index_1)
            for(int index_2 = 0; index_2 < res.columns; ++index_2) res[index_1][index_2] = first[index_1][index_2] + value;
        return res;
    }


    friend Matrix operator- (const Matrix &first, const Matrix &secend){
        if ((first.rows != secend.rows) || (first.columns != secend.columns)){
            cout << "ERROR";
            exit(-1);
        }
        Matrix res = Matrix(first.rows, first.columns);
        for(int index_1 = 0; index_1 < res.rows; ++index_1)
            for(int index_2 = 0; index_2 < res.columns; ++index_2) res[index_1][index_2] = first[index_1][index_2] - secend[index_1][index_2];
        return res;
    }


    friend Matrix operator- (const Matrix &first, const T &value){
        Matrix res = Matrix(first.rows, first.columns);
        for(int index_1 = 0; index_1 < res.rows; ++index_1)
            for(int index_2 = 0; index_2 < res.columns; ++index_2) res[index_1][index_2] = first[index_1][index_2] - value;
        return res;
    }


    friend Matrix operator- (const T &value, const Matrix &first){
        Matrix res = Matrix(first.rows, first.columns);
        for(int index_1 = 0; index_1 < res.rows; ++index_1)
            for(int index_2 = 0; index_2 < res.columns; ++index_2) res[index_1][index_2] = value - first[index_1][index_2];
        return res;
    }


    friend Matrix operator* (const Matrix &first, const Matrix &secend){
        if (first.columns != secend.rows){
            cout << "ERROR:";
            exit(-1);
        }
        Matrix res = Matrix(first.rows, secend.columns);
        for(int index_1 = 0; index_1 < res.rows; ++index_1)
            for(int index_2 = 0; index_2 < res.columns; ++index_2){
                res[index_1][index_2] = 0;
                for(int index_3 = 0; index_3 < first.columns; ++index_3) res[index_1][index_2] += first[index_1][index_3] * secend[index_3][index_2];
            }
        return res;
    }


    friend Matrix operator* (const Matrix &first, const T &value){
        Matrix res = Matrix(first.rows, first.columns);
        for(int index_1 = 0; index_1 < res.rows; ++index_1)
            for(int index_2 = 0; index_2 < res.columns; ++index_2) res[index_1][index_2] = first[index_1][index_2] * value;
        return res;
    }


    friend Matrix operator* (const T &value, const Matrix &first){
        Matrix res = Matrix(first.rows, first.columns);
        for(int index_1 = 0; index_1 < res.rows; ++index_1)
            for(int index_2 = 0; index_2 < res.columns; ++index_2) res[index_1][index_2] = first[index_1][index_2] * value;
        return res;
    }


    bool operator== (const Matrix &other){
        if ((rows != other.rows) || (columns != other.columns)) return false;
        for(int index_1 = 0; index_1 < rows; ++index_1)
            for(int index_2 = 0; index_2 < columns; ++index_2)
                if (values[index_1][index_2] != other[index_1][index_2]) return false;
        return true;
    }


    bool operator== (const T &value){
        for(int index_1 = 0; index_1 < rows; ++index_1)
            for(int index_2 = 0; index_2 < columns; ++index_2)
                if (values[index_1][index_2] != value) return false;
        return true;
    }


    bool operator!= (const Matrix &other){
        if ((rows != other.rows) || (columns != other.columns)) return true;
        for(int index_1 = 0; index_1 < rows; ++index_1)
            for(int index_2 = 0; index_2 < columns; ++index_2)
                if (values[index_1][index_2] != other[index_1][index_2]) return true;
        return false;
    }


    bool operator!= (const T &value){
        for(int index_1 = 0; index_1 < rows; ++index_1)
            for(int index_2 = 0; index_2 < columns; index_2++)
                if (values[index_1][index_2] != value) return true;
        return false;
    }


    Matrix transpose(){
        Matrix transposed_matrix = Matrix(columns, rows);
        for (int index_1 = 0; index_1 < columns; index_1++)
            for (int index_2 = 0; index_2 < rows; ++index_2) transposed_matrix[index_1][index_2] = values[index_2][index_1];
        return transposed_matrix;
    }


    void swap_elements(double &first, double &secend){
        double additional_variable = first;
        first = secend;
        secend = additional_variable;
    }


    void swap_rows(double first_row[], double secend_row[], int &a, int &b){
        for(int index = a; index < b; ++index) swap_elements(first_row[index], secend_row[index]);
    }


    void add_multiplied_row(const double first_row[], double secend_row[], double coefficient, int a, int b){
        for(int index = a; index < b; ++index) secend_row[index] += first_row[index] * coefficient;
    }


    double calc_det(){
        if (rows != columns){
            cout << "ERROR";
            exit(-1);
        }
        double determinant = 1, coefficient, element;
        double matrix[rows][columns];
        for (int index_1 = 0; index_1 < columns; ++index_1)
            for (int index_2 = 0; index_2 < columns; ++index_2) matrix[index_1][index_2] = values[index_1][index_2];
        for (int index_2 = 0; index_2 < columns; ++index_2)
            for (int index_1 = index_2; index_1 < columns; ++index_1)
                if (matrix[index_1][index_2] != 0){
                    if (index_1 != index_2){
                        swap_rows(matrix[index_2], matrix[index_1], index_2, columns);
                        determinant *= -1;
                    }
                    element = matrix[index_2][index_2];
                    for (int g = index_2+1; g < columns; g++){
                        coefficient = -matrix[g][index_2]/element;
                        if (coefficient != 0) add_multiplied_row(matrix[index_2], matrix[g], coefficient, index_2, columns);
                    }
                    break;
                }
        for(int index = 0; index < columns; ++index) determinant *= matrix[index][index];
        return determinant;
    }


    static Matrix eye(int row, int column){
        Matrix e = Matrix(row, column, 0);
        for(int index = 0; index < e.rows && index < e.columns; ++index) e[index][index] = 1;
        return e;
    }


    static Matrix zeros(int row, int column){
        Matrix zero = Matrix(row, column, 0);
        return zero;
    }
};


#endif
