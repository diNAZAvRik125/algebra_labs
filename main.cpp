#define CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Hamming.h"
using namespace std;

int main(){
    Hamming code = Hamming(1, 2);
    for(int index_1 = 0; index_1 < code.verification_matrix.rows; ++index_1){
        for(int index_2 = 0; index_2 < code.verification_matrix.columns; ++index_2) cout << code.verification_matrix[index_1][index_2] << " ";
        cout << endl;
    }
    cout << endl;
    for(int index_1 = 0; index_1 < code.generating_matrix.rows; ++index_1){
        for(int index_2 = 0; index_2 < code.generating_matrix.columns; ++index_2) cout << code.generating_matrix[index_1][index_2] << " ";
        cout << endl;
    }
    cout << endl;
    return 0;
}
