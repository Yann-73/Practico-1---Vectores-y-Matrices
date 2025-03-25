#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <map>

using namespace std;

template <typename T>
class Vector {
protected:
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

    void pushBack(const T &value) {
        if (size == capacity) {
            resize(capacity * 2);
        }
        items[size++] = value;
    }

    T at(int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Índice fuera de rango");
        }
        return items[index];
    }

    int getSize() {
        return size;
    }

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

    void print() {
        for (int i = 0; i < size; i++) {
            cout << items[i] << " | ";
        }
        cout << endl;
    }
};

class MathVector : public Vector<int> {
public:
    MathVector(int _capacity = 10) : Vector<int>(_capacity) {}

    double calcularPromedio() {
        if (size == 0) {
            return 0.0; // Vector vacío, devuelve 0.0
        }
        int suma = 0;
        for (int i = 0; i < size; i++) {
            suma += items[i];
        }
        return static_cast<double>(suma) / size;
    }

    double calcularMediana() {
        if (size == 0) {
            return 0.0; // Vector vacío, devuelve 0.0
        }
        int* temp = new int[size];
        for (int i = 0; i < size; i++) {
            temp[i] = items[i];
        }
        sort(temp, temp + size);
        double mediana;
        if (size % 2 == 0) {
            mediana = (temp[size / 2 - 1] + temp[size / 2]) / 2.0;
        } else {
            mediana = temp[size / 2];
        }
        delete[] temp; // Liberar memoria
        return mediana;
    }

    int calcularModa() {
        if (size == 0) {
            throw std::logic_error("No hay moda en un vector vacío");
        }
        smap<int, int> frecuencias;
        for (int i = 0; i < size; i++) {
            frecuencias[items[i]]++;
        }
        int maxFrecuencia = 0;
        int moda = 0;
        for (const auto& par : frecuencias) {
            if (par.second > maxFrecuencia) {
                maxFrecuencia = par.second;
                moda = par.first;
            }
        }
        return moda;
    }
};

// Ejemplo de uso
int main() {
    MathVector mv;
    mv.pushBack(4);
    mv.pushBack(2);
    mv.pushBack(2);
    mv.pushBack(3);
    mv.pushBack(2);
    mv.pushBack(5);
    mv.pushBack(3);

    cout << "Vector: ";
    mv.print();
    cout << "Promedio: " << mv.calcularPromedio() << endl;
    cout << "Mediana: " << mv.calcularMediana() << endl;
    cout << "Moda: " << mv.calcularModa() << endl;

    return 0;
}
