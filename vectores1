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

    // Nueva función para verificar simetría
    bool esSimetrico() {
        if (size == 0 || size == 1) {
            return true; // Vectores vacíos o de un elemento son simétricos
        }

        for (int i = 0; i < size / 2; i++) {
            if (items[i] != items[size - 1 - i]) {
                return false; // Si un par no coincide, no es simétrico
            }
        }
        return true; // Si todos los pares coinciden, es simétrico
    }
};

int main() {
    // Ejemplo 1: Vector simétrico
    Vector<int> v1;
    v1.pushBack(1);
    v1.pushBack(2);
    v1.pushBack(3);
    v1.pushBack(2);
    v1.pushBack(1);

    cout << "Vector 1: ";
    v1.print();
    if (v1.esSimetrico()) {
        cout << "El vector 1 es simetrico" << endl;
    } else {
        cout << "El vector 1 no es simetrico" << endl;
    }

    // Ejemplo 2: Vector no simétrico
    Vector<int> v2;
    v2.pushBack(1);
    v2.pushBack(2);
    v2.pushBack(3);
    v2.pushBack(4);

    cout << "Vector 2: ";
    v2.print();
    if (v2.esSimetrico()) {
        cout << "El vector 2 es simetrico" << endl;
    } else {
        cout << "El vector 2 no es simetrico" << endl;
    }

    return 0;
}
