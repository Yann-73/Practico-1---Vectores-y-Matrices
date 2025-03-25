#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T, int ROWS, int COLS>
class Matrix {
protected:
    T m[ROWS][COLS];

public:
    Matrix() {
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                m[i][j] = T(); 
            }
        }
    }

    T at(int row, int col) const {
        if (row < 0 || row >= ROWS || col < 0 || col >= COLS) {
            throw out_of_range("Indice fuera de rango");
        }
        return m[row][col];
    }

    void set(int row, int col, T value) {
        if (row < 0 || row >= ROWS || col < 0 || col >= COLS) {
            throw out_of_range("Indice fuera de rango");
        }
        m[row][col] = value;
    }

    int numRows() const { return ROWS; }
    int numCols() const { return COLS; }

    void print() const {
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                cout << m[i][j] << " ";
            }
            cout << endl;
        }
    }
};

template <int ROWS, int COLS>
class MathMatrix : public Matrix<int, ROWS, COLS> {
public:
    MathMatrix() : Matrix<int, ROWS, COLS>() {}

    bool esSimetrica() const {
        if (ROWS != COLS) {
            return false; 
        }

        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (this->at(i, j) != this->at(j, i)) { 
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    
    MathMatrix<3, 3> matSimetrica;
    matSimetrica.set(0, 0, 1); matSimetrica.set(0, 1, 2); matSimetrica.set(0, 2, 3);
    matSimetrica.set(1, 0, 2); matSimetrica.set(1, 1, 5); matSimetrica.set(1, 2, 6);
    matSimetrica.set(2, 0, 3); matSimetrica.set(2, 1, 6); matSimetrica.set(2, 2, 9);

    //Matriz simétrica
    matSimetrica.print();
    if (matSimetrica.esSimetrica()) {
        cout << "Es simetrica" << endl;
    } else {
        cout << "No es simetrica" << endl;
    }

  
    MathMatrix<3, 3> matNoSimetrica;
    matNoSimetrica.set(0, 0, 1); matNoSimetrica.set(0, 1, 4); matNoSimetrica.set(0, 2, 7);
    matNoSimetrica.set(1, 0, 2); matNoSimetrica.set(1, 1, 5); matNoSimetrica.set(1, 2, 8);
    matNoSimetrica.set(2, 0, 3); matNoSimetrica.set(2, 1, 6); matNoSimetrica.set(2, 2, 9);

    //Matriz no simétrica
    matNoSimetrica.print();
    if (matNoSimetrica.esSimetrica()) {
        cout << "Es simetrica" << endl;
    } else {
        cout << "No es simetrica" << endl;
    }

    // Matriz no cuadrada (no puede ser simétrica)
    MathMatrix<2, 3> matNoCuadrada;
    matNoCuadrada.set(0, 0, 1); matNoCuadrada.set(0, 1, 2); matNoCuadrada.set(0, 2, 3);
    matNoCuadrada.set(1, 0, 4); matNoCuadrada.set(1, 1, 5); matNoCuadrada.set(1, 2, 6);

    cout << "\nMatriz no cuadrada:" << endl;
    matNoCuadrada.print();
    if (matNoCuadrada.esSimetrica()) {
        cout << "Es simetrica" << endl;
    } else {
        cout << "No es simetrica" << endl;
    }

    return 0;
}
