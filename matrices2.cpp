#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class Vector {
private:
    T *items;
    int size;
    int capacity;

public:
    Vector(int _capacity = 10) : size(0), capacity(_capacity) {
        items = new T[capacity];
    }

    ~Vector() {
        delete[] items;
    }

    void pushBack(const T& value) {
        if (size == capacity) {
            resize(capacity * 2);
        }
        items[size++] = value;
    }

    T at(int index) const {
        if (index < 0 || index >= size) {
            throw out_of_range("Índice fuera de rango");
        }
        return items[index];
    }

    int getSize() const { return size; }

    void resize(int newCapacity) {
        if (newCapacity <= capacity) return;
        T *newItems = new T[newCapacity];
        for (int i = 0; i < size; i++) {
            newItems[i] = items[i];
        }
        delete[] items;
        items = newItems;
        capacity = newCapacity;
    }

    void print() const {
        for (int i = 0; i < size; i++) {
            cout << items[i] << " ";
        }
        cout << endl;
    }
};

template <typename T, int ROWS, int COLS>
class Matrix {
private:
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

    Vector<T> sumaPorFila() const {
        Vector<T> resultado(ROWS); 
        for (int i = 0; i < ROWS; i++) {
            T sumaFila = 0; 
            for (int j = 0; j < COLS; j++) {
                sumaFila += m[i][j]; 
            }
            resultado.pushBack(sumaFila); 
        }
        return resultado;
    }
};

int main() {
  
    Matrix<int, 3, 4> mat;

  
    mat.set(0, 0, 1); mat.set(0, 1, 2); mat.set(0, 2, 3); mat.set(0, 3, 4);  
    mat.set(1, 0, 5); mat.set(1, 1, 6); mat.set(1, 2, 7); mat.set(1, 3, 8);  
    mat.set(2, 0, 9); mat.set(2, 1, 10); mat.set(2, 2, 11); mat.set(2, 3, 12); 
    
    cout << "Matriz:" << endl;
    mat.print();

    Vector<int> sumas = mat.sumaPorFila();
    cout << "Suma de cada fila: ";
    sumas.print();

    return 0;
}
