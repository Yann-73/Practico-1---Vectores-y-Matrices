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

    int encontrarMaximo() const {
        if (ROWS == 0 || COLS == 0) {
            throw logic_error("Matriz vacia, no hay maximo");
        }
        int maximo = this->at(0, 0); 
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (this->at(i, j) > maximo) {
                    maximo = this->at(i, j);
                }
            }
        }
        return maximo;
    }

    int encontrarMinimo() const {
        if (ROWS == 0 || COLS == 0) {
            throw logic_error("Matriz vacia, no hay minimo");
        }
        int minimo = this->at(0, 0); 
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (this->at(i, j) < minimo) {
                    minimo = this->at(i, j);
                }
            }
        }
        return minimo;
    }

    double calcularPromedio() const {
        if (ROWS == 0 || COLS == 0) {
            return 0.0; 
        }
        double suma = 0.0;
        int totalElementos = ROWS * COLS;
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                suma += this->at(i, j);
            }
        }
        return suma / totalElementos;
    }
};

int main() {
  
    MathMatrix<2, 3> mat;
    mat.set(0, 0, 5); mat.set(0, 1, 2); mat.set(0, 2, 8);
    mat.set(1, 0, 1); mat.set(1, 1, 9); mat.set(1, 2, 3);

    cout << "Matriz:" << endl;
    mat.print();

    cout << "Valor maximo: " << mat.encontrarMaximo() << endl;

    cout << "Valor minimo: " << mat.encontrarMinimo() << endl;

    cout << "Promedio: " << mat.calcularPromedio() << endl;

    return 0;
}
