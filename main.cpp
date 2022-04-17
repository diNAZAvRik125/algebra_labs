#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class MATRIX{
private:
    T** M;
    T** M_1;
    T** M_2;
    int row_count;
    int columns_count;

public:
    MATRIX(){
        columns_count = row_count = 0;
        M = nullptr;
    }

    MATRIX(int new_row, int new_columns){
        row_count = new_row;
        columns_count = new_columns;
        M = (T**) new T*[row_count];
        for (int index = 0; index < row_count; ++index)
            M[index] = (T*)new T[columns_count];
        for (int index_row = 0; index_row < row_count; ++index_row)
            for (int index_column = 0; index_column < columns_count; ++index_column){
                M[index_row][index_column] = 0;
            }
    }

    void MATRIX_1(int new_row, int new_columns){
        row_count = new_row;
        columns_count = new_columns;
        M = (T**) new T*[row_count];
        for (int i = 0; i < row_count; i++)
            M[i] = (T*)new T[columns_count];
        for (int i = 0; i < row_count; i++){
            for (int j=0; j<columns_count; ++j){
                if (i==j){
                    M[i][j] = 1;
                }else{
                    M[i][j] = 0;
                }
            }
        }
    }

    void SetMij(int row, int column, T value){
        if ((row < 0) || (row >= row_count))
            return;
        if ((column < 0) || (column >= columns_count))
            return;
        M[row][column] = value;
    }

    void get_element(int row, int column){
        if ((row<row_count)&&(row>=0)){
            if ((column<columns_count)&&(column>=0)){
                cout<<"Your elemnt: "<<M[row][column]<<endl;
                cout<<"---------------------";
            }
        }
    }

    void Print(const char* ObjName){
        cout << "Object: " << ObjName << endl;
        for (int index_row = 0; index_row < row_count; ++index_row){
            for (int index_column = 0; index_column < columns_count; ++index_column){
                cout << M[index_row][index_column] << "\t";
            }
            cout << endl;
        }
        cout << "---------------------" << endl << endl;
    }

    void det_matrix(const char* ObjName){
        int M_new[row_count][columns_count];
        if (row_count == columns_count){
        for (int index_row = 0; index_row < row_count ; ++index_row){
            for (int index_column = 0; index_column < columns_count ; ++index_column){
                M_new[index_row][index_column] = M[index_row][index_column];
            }
        }
        int nenol_stroka=0,tekushaia_stroka=0, razmer = columns_count;
        for(int tekushaia_stolbec=0;tekushaia_stolbec<razmer;++tekushaia_stolbec) {
            int stolbec_iz_nuley=1;
            for (int stroka=tekushaia_stroka;stroka<razmer;++stroka) {
                if (M_new[stroka][tekushaia_stolbec]!=0) {
                    stolbec_iz_nuley=0;
                    nenol_stroka=stroka;
                    break;
                }
            }
            if (stolbec_iz_nuley==1) {
                continue;
            }
            double nenol_element = M_new[nenol_stroka][tekushaia_stolbec];
            if (nenol_stroka != tekushaia_stroka) {
                for (int stolbec = 0 ; stolbec < razmer ; ++stolbec) {
                    M_new[tekushaia_stolbec][stolbec] += M_new[nenol_stroka][stolbec];
                }
            }
            for (int stroka = tekushaia_stroka + 1 ; stroka < razmer ; ++stroka) {
                double perv_elemnt_v_stroke = M_new[stroka][tekushaia_stolbec];
                for (int stolbec = 0 ; stolbec < razmer ; ++stolbec) {
                    M_new[stroka][stolbec] += (-(perv_elemnt_v_stroke/nenol_element))*M_new[tekushaia_stroka][stolbec];
                }
            }
            ++tekushaia_stroka;
        }
        double determinant=1;
        for(int diagonal_index=0; diagonal_index<razmer;++diagonal_index){
            determinant *= M_new[diagonal_index][diagonal_index];
        }
        cout << determinant <<endl <<"---------------------";
    }else{
            cout<<"NO!";
        }
    }

    void matrix_plus_matrix(const char* ObjName, const char* ObjName_1, int row_1, int column_1, int row_2,int column_2){
        if (row_1 == row_2){
            if (column_1 == column_2){
              for (int index_row = 0; index_row < row_1 ; ++index_row){
                  for (int index_column = 0; index_column < column_1 ; ++index_column){
                      cout << M[index_row][index_column]+M_1[index_row][index_column] <<" ";
                  }
                  cout<<endl;
              }
               cout << "---------------------";
            }
        }else{
            cout<<"NO!";
        }
    }

    void scalar(int scalar){
        for (int index_row = 0; index_row < row_count ; ++index_row){
            for (int index_column = 0; index_column < columns_count ; ++index_column){
                M[index_row][index_column] *= scalar;
            }
        }
    }

    void rav_matrix(const char* ObjName, const char* ObjName_1, int row_1, int column_1, int row_2,int column_2){
        if (row_1 == row_2){
            if (column_1 == column_2){
                for (int index_row = 0; index_row < row_1 ; ++index_row){
                    for (int index_column = 0; index_column < column_1 ; ++index_column){
                        if (M[index_row][index_column] != M_1[index_row][index_column]){
                            cout<<"NO!";
                            break;
                        }
                    }
                    cout<<"YES!"<<endl;
                }
                cout << "---------------------";
            }
            else{
                cout<<"NO!";
            }
        }else{
            cout<<"NO!";
        }
    }

    void transpon(const char* ObjName){
        int t;
        for(int i = 0; i < row_count; ++i)
        {
            for(int j = i; j < columns_count; ++j)
            {
                t = M[i][j];
                M[i][j] = M[j][i];
                M[j][i] = t;
            }
        }
    }

    ~MATRIX(){
        if (columns_count > 0){
            for (int index = 0; index < row_count; ++index){
                delete[] M[index];
            }
        }

        if (row_count > 0)
            delete[] M;
    }
};

int main() {
    MATRIX<int> M(3, 3);
    M.Print("M");
    M.MATRIX_1(3,3);
    M.Print("M_1");
    // Заполнить матрицу значеннями по формуле
    int i, j;
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            M.SetMij(i, j, i + j);
    M.Print("M");
    M.get_element(1,1);
    M.transpon("M");
    M.Print("M");
    M.scalar(2);
    M.Print("M");
    return 0;
}
