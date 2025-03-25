#include <iostream>
#include <stdexcept>
using namespace std;

// Clase base Matrix<T, ROWS, COLS>
template <typename T, int ROWS, int COLS>
class Matrix {
protected:
    T m[ROWS][COLS];

public:
    Matrix() {
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                m[i][j] = T(); // Inicializa con 0.0 para double
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
};

// Clase GestionCalificaciones
template <int ESTUDIANTES, int MATERIAS>
class GestionCalificaciones {
private:
    Matrix<double, ESTUDIANTES, MATERIAS> calificaciones;

public:
    GestionCalificaciones() {}

    void setCalificacion(int estudiante, int materia, double calificacion) {
        calificaciones.set(estudiante, materia, calificacion);
    }

    double promedioEstudiante(int estudiante) const {
        if (estudiante < 0 || estudiante >= ESTUDIANTES) {
            throw out_of_range("Estudiante inválido");
        }
        double suma = 0.0;
        for (int j = 0; j < MATERIAS; j++) {
            suma += calificaciones.at(estudiante, j);
        }
        return suma / MATERIAS;
    }

    double promedioGeneral() const {
        if (ESTUDIANTES == 0 || MATERIAS == 0) {
            return 0.0; // Evita división por cero
        }
        double sumaTotal = 0.0;
        for (int i = 0; i < ESTUDIANTES; i++) {
            for (int j = 0; j < MATERIAS; j++) {
                sumaTotal += calificaciones.at(i, j);
            }
        }
        return sumaTotal / (ESTUDIANTES * MATERIAS);
    }

    // Método para imprimir la matriz de calificaciones
    void print() const {
        for (int i = 0; i < ESTUDIANTES; i++) {
            cout << "Estudiante " << i << ": ";
            for (int j = 0; j < MATERIAS; j++) {
                cout << calificaciones.at(i, j) << " ";
            }
            cout << endl;
        }
    }
};

// Ejemplo de uso
int main() {
    GestionCalificaciones<3, 4> gestion;

    // Asignar calificaciones
    gestion.setCalificacion(0, 0, 85.0);
    gestion.setCalificacion(0, 1, 90.0);
    gestion.setCalificacion(0, 2, 78.0);
    gestion.setCalificacion(0, 3, 88.0);

    gestion.setCalificacion(1, 0, 92.0);
    gestion.setCalificacion(1, 1, 88.0);
    gestion.setCalificacion(1, 2, 95.0);
    gestion.setCalificacion(1, 3, 90.0);

    gestion.setCalificacion(2, 0, 70.0);
    gestion.setCalificacion(2, 1, 75.0);
    gestion.setCalificacion(2, 2, 80.0);
    gestion.setCalificacion(2, 3, 85.0);

    // Mostrar la matriz de calificaciones
    cout << "Matriz de calificaciones:" << endl;
    gestion.print();

    // Calcular y mostrar promedios
    cout << "\nPromedio Estudiante 0: " << gestion.promedioEstudiante(0) << endl;
    cout << "Promedio Estudiante 1: " << gestion.promedioEstudiante(1) << endl;
    cout << "Promedio Estudiante 2: " << gestion.promedioEstudiante(2) << endl;
    cout << "Promedio general: " << gestion.promedioGeneral() << endl;

    return 0;
}
