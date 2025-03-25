#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class Producto {
private:
    int id;
    string nombre;
    double precio;
    int cantidadEnStock;

public:
    Producto() : id(0), nombre(""), precio(0.0), cantidadEnStock(0) {}
    Producto(int _id, string _nombre, double _precio, int _cantidad)
        : id(_id), nombre(_nombre), precio(_precio), cantidadEnStock(_cantidad) {}

    int getId() const { return id; }
    string getNombre() const { return nombre; }
    double getPrecio() const { return precio; }
    int getCantidadEnStock() const { return cantidadEnStock; }

    friend ostream& operator<<(ostream& os, const Producto& p) {
        os << "ID: " << p.id << ", Nombre: " << p.nombre
           << ", Precio: " << p.precio << ", Stock: " << p.cantidadEnStock;
        return os;
    }
};

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
          throw out_of_range("Indice fuera de rango");
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

    void eliminar(int index) {
        if (index < 0 || index >= size) {
          throw out_of_range("Indice fuera de rango");
        }
        for (int i = index; i < size - 1; i++) {
            items[i] = items[i + 1];
        }
        size--;
    }

    void print() const {
        for (int i = 0; i < size; i++) {
            cout << items[i] << endl;
        }
    }
};

class Inventario {
private:
    Vector<Producto> productos;

public:
    void agregarProducto(const Producto& p) {
        productos.pushBack(p);
    }

    void eliminarProducto(int id) {
        for (int i = 0; i < productos.getSize(); i++) {
            if (productos.at(i).getId() == id) {
                productos.eliminar(i);
                return;
            }
        }
        cout << "Producto con ID " << id << " no encontrado." << endl;
    }

    Vector<Producto> buscarPorNombre(const string& nombre) {
        Vector<Producto> resultado;
        string nombreLower = toLower(nombre);
        for (int i = 0; i < productos.getSize(); i++) {
            string prodNombreLower = toLower(productos.at(i).getNombre());
            if (prodNombreLower.find(nombreLower) != string::npos) {
                resultado.pushBack(productos.at(i));
            }
        }
        return resultado;
    }

    void ordenarPorPrecio() {
        std::vector<Producto> temp;
        for (int i = 0; i < productos.getSize(); i++) {
            temp.push_back(productos.at(i));
        }
        std::sort(temp.begin(), temp.end(), [](const Producto& a, const Producto& b) {
            return a.getPrecio() < b.getPrecio();
        });
        productos = Vector<Producto>(static_cast<int>(temp.size()));
        for (const auto& p : temp) {
            productos.pushBack(p);
        }
    }

    void imprimirInventario() const {
        productos.print();
    }

private:
    string toLower(const string& str) {
        string lowerStr = str;
        transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
        return lowerStr;
    }
};

int main() {
    Inventario inv;

    inv.agregarProducto(Producto(1, "Laptop", 999.99, 10));
    inv.agregarProducto(Producto(2, "Mouse", 19.99, 50));
    inv.agregarProducto(Producto(3, "Teclado", 49.99, 20));
    inv.agregarProducto(Producto(4, "Monitor", 199.99, 15));

    cout << "Inventario inicial:" << endl;
    inv.imprimirInventario();

    cout << "\nBuscar 'lap':" << endl;
    Vector<Producto> busqueda = inv.buscarPorNombre("lap");
    busqueda.print();

    cout << "\nInventario ordenado por precio:" << endl;
    inv.ordenarPorPrecio();
    inv.imprimirInventario();

    cout << "\nEliminar producto con ID 2:" << endl;
    inv.eliminarProducto(2);
    inv.imprimirInventario();

    return 0;
}
