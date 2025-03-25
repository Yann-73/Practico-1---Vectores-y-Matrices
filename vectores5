#include <iostream>
#include <stdexcept>

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

    T at(int index) const { 
        if (index < 0 || index >= size) {
          throw out_of_range("Indice fuera de rango");
        }
        return items[index];
    }

    int getSize() const { 
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

    void print() const { 
        for (int i = 0; i < size; i++) {
            cout << items[i] << " | ";
        }
        cout << endl;
    }
};

class VectorCalculator {
public:
    Vector<int> sumar(const Vector<int>& v1, const Vector<int>& v2) {
        if (v1.getSize() != v2.getSize()) {
          throw invalid_argument("Los vectores deben tener el mismo tamano");
        }
        Vector<int> resultado(v1.getSize());
        for (int i = 0; i < v1.getSize(); i++) {
            resultado.pushBack(v1.at(i) + v2.at(i));
        }
        return resultado;
    }

    Vector<int> restar(const Vector<int>& v1, const Vector<int>& v2) {
        if (v1.getSize() != v2.getSize()) {
          throw invalid_argument("Los vectores deben tener el mismo tamano");
        }
        Vector<int> resultado(v1.getSize());
        for (int i = 0; i < v1.getSize(); i++) {
            resultado.pushBack(v1.at(i) - v2.at(i));
        }
        return resultado;
    }

    Vector<int> multiplicar(const Vector<int>& v1, const Vector<int>& v2) {
        if (v1.getSize() != v2.getSize()) {
          throw invalid_argument("Los vectores deben tener el mismo tamano");
        }
        Vector<int> resultado(v1.getSize());
        for (int i = 0; i < v1.getSize(); i++) {
            resultado.pushBack(v1.at(i) * v2.at(i));
        }
        return resultado;
    }
};

int main() {
    Vector<int> v1;
    v1.pushBack(1);
    v1.pushBack(2);
    v1.pushBack(3);

    Vector<int> v2;
    v2.pushBack(4);
    v2.pushBack(5);
    v2.pushBack(6);

    VectorCalculator calc;

    cout << "Vector 1: ";
    v1.print();
    cout << "Vector 2: ";
    v2.print();

    cout << "Suma: ";
    Vector<int> suma = calc.sumar(v1, v2);
    suma.print();

    cout << "Resta: ";
    Vector<int> resta = calc.restar(v1, v2);
    resta.print();

    cout << "Multiplicacion: ";
    Vector<int> multiplicacion = calc.multiplicar(v1, v2);
    multiplicacion.print();

    Vector<int> v3;
    v3.pushBack(1);
    v3.pushBack(2);

    cout << "\nPrueba con vectores de diferente tamano:" << endl;
    try {
        Vector<int> suma_invalida = calc.sumar(v1, v3);
        suma_invalida.print();
    } catch (const std::invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
