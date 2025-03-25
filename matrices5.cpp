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

class MatrixCalculator {
public:
    template <int ROWS, int COLS>
    Matrix<int, ROWS, COLS> sumar(const Matrix<int, ROWS, COLS>& m1, const Matrix<int, ROWS, COLS>& m2) {
        Matrix<int, ROWS, COLS> resultado;
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                resultado.set(i, j, m1.at(i, j) + m2.at(i, j));
            }
        }
        return resultado;
    }

    template <int ROWS, int COLS>
    Matrix<int, ROWS, COLS> restar(const Matrix<int, ROWS, COLS>& m1, const Matrix<int, ROWS, COLS>& m2) {
        Matrix<int, ROWS, COLS> resultado;
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                resultado.set(i, j, m1.at(i, j) - m2.at(i, j));
            }
        }
        return resultado;
    }

    template <int ROWS1, int COLS1, int COLS2>
    Matrix<int, ROWS1, COLS2> multiplicar(const Matrix<int, ROWS1, COLS1>& m1, const Matrix<int, COLS1, COLS2>& m2) {
        Matrix<int, ROWS1, COLS2> resultado;
        for (int i = 0; i < ROWS1; i++) {
            for (int j = 0; j < COLS2; j++) {
                int suma = 0;
                for (int k = 0; k < COLS1; k++) { // COLS1 == ROWS2
                    suma += m1.at(i, k) * m2.at(k, j);
                }
                resultado.set(i, j, suma);
            }
        }
        return resultado;
    }
};

int main() {
    MatrixCalculator calc;

    Matrix<int, 2, 3> m1;
    m1.set(0, 0, 1); m1.set(0, 1, 2); m1.set(0, 2, 3);
    m1.set(1, 0, 4); m1.set(1, 1, 5); m1.set(1, 2, 6);

    Matrix<int, 2, 3> m2;
    m2.set(0, 0, 7); m2.set(0, 1, 8); m2.set(0, 2, 9);
    m2.set(1, 0, 1); m2.set(1, 1, 2); m2.set(1, 2, 3);

    cout << "Matriz 1:" << endl;
    m1.print();
    cout << "Matriz 2:" << endl;
    m2.print();

    Matrix<int, 2, 3> suma = calc.sumar(m1, m2);
    cout << "\nSuma:" << endl;
    suma.print();

    Matrix<int, 2, 3> resta = calc.restar(m1, m2);
    cout << "\nResta:" << endl;
    resta.print();

    Matrix<int, 2, 3> m3;
    m3.set(0, 0, 1); m3.set(0, 1, 2); m3.set(0, 2, 3);
    m3.set(1, 0, 4); m3.set(1, 1, 5); m3.set(1, 2, 6);

    Matrix<int, 3, 2> m4;
    m4.set(0, 0, 7); m4.set(0, 1, 1);
    m4.set(1, 0, 8); m4.set(1, 1, 2);
    m4.set(2, 0, 9); m4.set(2, 1, 3);

    cout << "\nMatriz 3 (2x3):" << endl;
    m3.print();
    cout << "Matriz 4 (3x2):" << endl;
    m4.print();

    Matrix<int, 2, 2> multiplicacion = calc.multiplicar(m3, m4);
    cout << "\nMultiplicacion (2x2):" << endl;
    multiplicacion.print();

    return 0;
}
