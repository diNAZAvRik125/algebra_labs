#define CRT_SECURE_NO_WARNINGS
#ifndef MATRIX_CLASS_HAMMING_H
#define MATRIX_CLASS_HAMMING_H
#include "Matrix.h"

class Hamming{

public:
    Matrix<int> verification_matrix;
    Matrix<int> generating_matrix;
    int p;


    Hamming(int input_p, int r): verification_matrix(r, (pow(input_p, r) - 1) / (input_p - 1), 0),
                                 generating_matrix(((pow(input_p, r) - 1) / (input_p - 1)) - r, (pow(input_p, r) - 1) / (input_p - 1), 0){
        p = input_p;
        for (int index = 0; index < r; ++index) verification_matrix[index][verification_matrix.columns - r + index] = 1;
        int * temp_column = new int[r], current_index = verification_matrix.columns - r;
        for (int index = 0; index < r; ++index) temp_column[index] = 0;
        while(next(temp_column, p, r))
            if (column_checkout(temp_column, current_index, p)){
                bool null = true;
                for (int index_1 = 0; index_1 < r; ++index_1)
                    if (temp_column[index_1] != 0) null = false;
                if (!null){
                    for (int index_2 = 0; index_2 < r; index_2++) verification_matrix[index_2][current_index - 1] = temp_column[index_2];
                    current_index--;
                }
            }
        for (int index = 0; index < generating_matrix.rows; ++index) generating_matrix[index][index] = 1;
        for (int index_1 = 0; index_1 < generating_matrix.rows; ++index_1)
            for (int index_2 = generating_matrix.rows; index_2 < generating_matrix.columns; index_2++) generating_matrix[index_1][index_2] = (p - verification_matrix[index_2 - generating_matrix.rows][index_1]) % p;
    }


    ~Hamming(){
        delete &verification_matrix;
        delete &generating_matrix;
    }


    static bool next(int *a, int p, int size){
        int index = 0;
        ++a[0];
        while(a[index] == p){
            if (index == size - 1) return false;
            a[index] = 0;
            ++a[index+1];
            ++index;
        }
        return true;
    }

    bool column_checkout(const int * temp, int index, int p) const{
        int *prev = new int[verification_matrix.columns], right_border = verification_matrix.columns, col_len = verification_matrix.rows;
        for (int index_1 = index; index_1 < right_border; ++index_1){
            for (int index_2 = 0; index_2 < col_len; ++index_2) prev[index_2] = verification_matrix[index_2][index_1];
            for (int number = 1; number < p; ++number){
                bool same = true;
                for (int n = 0; n < col_len; ++n)
                    if ((temp[n] * number) % p != prev[n]){
                        same = false;
                        break;
                    }
                if (same) return false;
            }
        }
        return true;
    }


    static int pow(int x, int y){
        int temp = 1;
        for (int index = 0; index < y; ++index) temp *= x;
        return temp;
    }


    Matrix<int> decode(Matrix<int> x){
        int r = verification_matrix.rows, n = verification_matrix.columns;
        int *vector = new int[r];
        for (int index_1 = 0; index_1 < r; ++index_1){
            vector[index_1] = 0;
            for (int index_2 = 0; index_2 < n; ++index_2) vector[index_1] += x[0][index_2] * verification_matrix[index_1][index_2];
        }
        bool no_mistakes = true;
        for (int index = 0; index < r; ++index)
            if (vector[index] != 0){
                no_mistakes = false;
                break;
            }
        if (!no_mistakes){
            int mistake_index = -1, correct_alpha;
            for (int index_1 = 0; index_1 < n; ++index_1){
                for (int alpha = 1; alpha < p; alpha++){
                    bool equal = true;
                    for (int j = 0; j < r; j++)
                        if (vector[j] != alpha * verification_matrix[j][index_1]){
                            equal = false;
                            break;
                        }
                    if (equal){
                        mistake_index = index_1;
                        correct_alpha = alpha;
                        break;
                    }
                }
                if (mistake_index != -1) break;
            }
            x[0][mistake_index] = x[0][mistake_index] - correct_alpha;
        }
        Matrix<int> u = Matrix<int>(1, generating_matrix.rows);
        for (int j = 0; j < generating_matrix.rows; j++) u[0][j] = x[0][j];
        return u;
    }


};


#endif