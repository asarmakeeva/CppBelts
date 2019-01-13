#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>

using namespace std;

// Реализуйте здесь
// * класс Matrix
// * оператор ввода для класса Matrix из потока istream
// * оператор вывода класса Matrix в поток ostream
// * оператор проверки на равенство двух объектов класса Matrix
// * оператор сложения двух объектов класса Matrix

class Matrix{
public:
    Matrix (){
        col = 0;
        row = 0;
    }
    Matrix(const int& num_rows,const int& num_cols){
        if ((num_rows < 0) || (num_cols < 0)) {
            throw out_of_range("num_rows and num_cols must be >= 0"); }
        else {
            row = num_rows;
            col = num_cols; 
            }
            elements.assign(row, vector<int>(col));
    }
    Matrix Reset(const int& num_rows,const int& num_cols){
        return Matrix(num_rows, num_cols);
    }
    int At(const int& n, const int& m)const {
        //return elements.at(n).at(m);
        return elements[n][m];
    }
    int& At(const int& n, const int& m) {
        //return elements.at(n).at(m);
        return elements[n][m];
    }

    int GetNumRows() const {
        return row;
    }
    int GetNumColumns() const {
        return col;
    }
private:
    int row;
    int col;
    vector<vector<int> > elements;
};

istream& operator >> (istream& inp, Matrix& m){
    int row, col;
    inp >> row >> col;

    m.Reset(row, col);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
        inp >> m.At(i, j);
        }
    }
  return inp;
}
ostream& operator << (ostream& out, const Matrix& m){
    out << m.GetNumRows() << m.GetNumColumns() << endl;
    for (int i = 0; i < m.GetNumRows(); i++){
        for(int j = 0; j < m.GetNumColumns(); j++){
            if (j > 0) cout << " ";
                out << m.At(i, j);
        }
        cout << endl;
    }
    return out;
}
Matrix operator +(const Matrix& m1, const Matrix& m2){
    Matrix res(m1.GetNumRows(), m1.GetNumColumns());
    if ((m1.GetNumRows() != m2.GetNumRows()) || (m1.GetNumColumns() != m2.GetNumColumns()))
        throw invalid_argument("!!");
    else {
        
        for (int i = 0; i < m1.GetNumRows(); i++) {
            for (int j = 0; j < m1.GetNumColumns(); j++) {
            res.At(i, j) = m1.At(i, j) + m2.At(i, j);
            }
        }
    }
    return res;
}
bool operator == (const Matrix& m1, const Matrix& m2){
    for (int i = 0; i < m1.GetNumRows(); i++) {
        for (int j = 0; j < m1.GetNumColumns(); j++) {
         if (m1.At(i, j) != m2.At(i, j)) return false;
        }
    }
    return true;
}

int main() {
  Matrix one;
  Matrix two;

  cin >> one >> two;
  cout << one + two << endl;
  return 0;
}