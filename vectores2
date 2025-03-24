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

    void set(int index, T value) {
        if (index < 0 || index >= size) {
            throw out_of_range("Índice fuera de rango");
        }
        items[index] = value;
    }

    int getSize() {
        return size;
    }

    int getCapacity() {
        return capacity;
    }

    void resize(int newCapacity) {
        if (newCapacity <= capacity)
            return;

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

    // Nueva función para sumar números pares
    int sumaPares() {
        int suma = 0;
        for (int i = 0; i < size; i++) {
            if (items[i] % 2 == 0) { // Verifica si el número es par
                suma += items[i];
            }
        }
        return suma;
    }
};

int main() {
    // Ejemplo 1: Vector con números pares e impares
    Vector<int> v1;
    v1.pushBack(1);
    v1.pushBack(2);
    v1.pushBack(3);
    v1.pushBack(4);
    v1.pushBack(6);

    cout << "Vector 1: ";
    v1.print();
    cout << "Suma de numeros pares en Vector 1: " << v1.sumaPares() << endl;

    // Ejemplo 2: Vector sin números pares
    Vector<int> v2;
    v2.pushBack(1);
    v2.pushBack(3);
    v2.pushBack(5);
    v2.pushBack(7);

    cout << "Vector 2: ";
    v2.print();
    cout << "Suma de numeros pares en Vector 2: " << v2.sumaPares() << endl;

    // Ejemplo 3: Vector vacío
    Vector<int> v3;
    cout << "Vector 3: ";
    v3.print();
    cout << "Suma de numeros pares en Vector 3: " << v3.sumaPares() << endl;

    return 0;
}
