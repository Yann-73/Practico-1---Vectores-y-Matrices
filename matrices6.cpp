#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Producto {
public:
    int id;
    string nombre;
    double precio;
    int cantidadEnStock;

    Producto(int id, string nombre, double precio, int cantidadEnStock)
        : id(id), nombre(nombre), precio(precio), cantidadEnStock(cantidadEnStock) {}
};

class Almacen {
private:
    vector<vector<Producto*>> matrizProductos;
    int numCategorias;
    int numUbicaciones;

public:
    Almacen(int categorias, int ubicaciones) : numCategorias(categorias), numUbicaciones(ubicaciones) {
        matrizProductos.resize(categorias, vector<Producto*>(ubicaciones, nullptr));
    }

    void agregarProducto(int categoria, int ubicacion, Producto* producto) {
        if (categoria >= 0 && categoria < numCategorias && ubicacion >= 0 && ubicacion < numUbicaciones) {
            matrizProductos[categoria][ubicacion] = producto;
        } else {
            cout << "Posición inválida en el almacén." << endl;
        }
    }

    int calcularTotalProductosCategoria(int categoria) const {
        if (categoria >= 0 && categoria < numCategorias) {
            int total = 0;
            for (int j = 0; j < numUbicaciones; j++) {
                if (matrizProductos[categoria][j] != nullptr) {
                    total += matrizProductos[categoria][j]->cantidadEnStock;
                }
            }
            return total;
        } else {
            cout << "Categoría inválida." << endl;
            return 0;
        }
    }

    void mostrarAlmacen() const {
        for (int i = 0; i < numCategorias; i++) {
            cout << "Categoría " << i << ": ";
            for (int j = 0; j < numUbicaciones; j++) {
                if (matrizProductos[i][j] != nullptr) {
                    cout << matrizProductos[i][j]->nombre << " (" << matrizProductos[i][j]->cantidadEnStock << ") | ";
                } else {
                    cout << "Vacío | ";
                }
            }
            cout << endl;
        }
    }

    ~Almacen() {
        for (int i = 0; i < numCategorias; i++) {
            for (int j = 0; j < numUbicaciones; j++) {
                delete matrizProductos[i][j];
            }
        }
    }
};

int main() {
    Almacen almacen(3, 4);

    almacen.agregarProducto(0, 0, new Producto(1, "Laptop", 1200.0, 10));
    almacen.agregarProducto(0, 1, new Producto(2, "Mouse", 25.0, 50));
    almacen.agregarProducto(1, 2, new Producto(3, "Impresora", 300.0, 5));
    almacen.agregarProducto(2, 3, new Producto(4, "Smartphone", 800.0, 20));

    almacen.mostrarAlmacen();

    cout << "\nTotal productos en categoria 0: " << almacen.calcularTotalProductosCategoria(0) << endl;
    cout << "Total productos en categoria 1: " << almacen.calcularTotalProductosCategoria(1) << endl;
    cout << "Total productos en categoria 2: " << almacen.calcularTotalProductosCategoria(2) << endl;

    return 0;
}
