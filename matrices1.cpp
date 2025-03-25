#include <iostream>
#include <stdexcept>
using namespace std;

// Clase Matrix (basada en tus ejemplos de clase)
template <typename T, int ROWS, int COLS>
class Matrix {
private:
    T m[ROWS][COLS];

public:
    Matrix() {
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                m[i][j] = T(); // Inicializa con valor por defecto (0 para int)
            }
        }
    }

    T at(int row, int col) const {
        if (row < 0 || row >= ROWS || col < 0 || col >= COLS) {
            throw out_of_range("Índice fuera de rango");
        }
        return m[row][col];
    }

    void set(int row, int col, T value) {
        if (row < 0 || row >= ROWS || col < 0 || col >= COLS) {
            throw out_of_range("Índice fuera de rango");
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

    // Nueva función para sumar los elementos impares
    T sumaImpares() const {
        T suma = 0; // Usamos T para que sea genérico (int en este caso)
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (m[i][j] % 2 != 0) { // Verifica si es impar
                    suma += m[i][j];
                }
            }
        }
        return suma;
    }
};

// Ejemplo de uso
int main() {
    // Crear una matriz de 3x4
    Matrix<int, 3, 4> mat;

    // Llenar la matriz con valores de ejemplo
    mat.set(0, 0, 1);  mat.set(0, 1, 2);  mat.set(0, 2, 3);  mat.set(0, 3, 4);
    mat.set(1, 0, 5);  mat.set(1, 1, 6);  mat.set(1, 2, 7);  mat.set(1, 3, 8);
    mat.set(2, 0, 9);  mat.set(2, 1, 10); mat.set(2, 2, 11); mat.set(2, 3, 12);

    // Imprimir la matriz
    cout << "Matriz:" << endl;
    mat.print();

    // Calcular y mostrar la suma de los impares
    int suma = mat.sumaImpares();
    cout << "Suma de los elementos impares: " << suma << endl;

    return 0;
}
