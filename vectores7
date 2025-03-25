#include <iostream>
#include <vector>
#include <numeric> // Para std::accumulate
#include <iomanip> // Para std::setprecision

using namespace std;

class Estudiante {
public:
    int registro;
    string nombre;
    vector<double> calificaciones;

    Estudiante(int registro, string nombre, const vector<double>& calificaciones)
        : registro(registro), nombre(nombre), calificaciones(calificaciones) {}

    double calcularPromedio() const {
        if (calificaciones.empty()) {
            return 0.0;
        }
        double suma = accumulate(calificaciones.begin(), calificaciones.end(), 0.0);
        return suma / calificaciones.size();
    }
};

class GestionAcademica {
private:
    vector<Estudiante> estudiantes;

public:
    void agregarEstudiante(const Estudiante& estudiante) {
        estudiantes.push_back(estudiante);
    }

    double calcularPromedioGeneral() const {
        if (estudiantes.empty()) {
            return 0.0;
        }
        double sumaPromedios = 0.0;
        for (const auto& estudiante : estudiantes) {
            sumaPromedios += estudiante.calcularPromedio();
        }
        return sumaPromedios / estudiantes.size();
    }

    void mostrarPromediosEstudiantes() const {
        for (const auto& estudiante : estudiantes) {
            cout << "Estudiante: " << estudiante.nombre
                 << ", Registro: " << estudiante.registro
                 << ", Promedio: " << fixed << setprecision(2) << estudiante.calcularPromedio() << endl;
        }
    }
};

int main() {
    GestionAcademica gestion;

    gestion.agregarEstudiante(Estudiante(101, "Ana", {85.5, 90.0, 92.5}));
    gestion.agregarEstudiante(Estudiante(102, "Carlos", {78.0, 85.0, 80.0}));
    gestion.agregarEstudiante(Estudiante(103, "Sofia", {95.0, 92.0, 98.0}));

    gestion.mostrarPromediosEstudiantes();

    cout << "\nPromedio General del Grupo: " << fixed << setprecision(2) << gestion.calcularPromedioGeneral() << endl;

    return 0;
}
