#include <iostream>
#include <string>

#include "Pila.h"

void MostrarTitulo(const std::string& titulo) {
    std::cout << "\n== " << titulo << " ==\n";
}

int main() {
    try {
        MostrarTitulo("Pila de enteros");
        Pila<int> pila_enteros;
        pila_enteros.Apilar(1);
        pila_enteros.Apilar(2);
        pila_enteros.Apilar(3);
        pila_enteros.Imprimir();
        pila_enteros.Desapilar();
        std::cout << "Tope: " << pila_enteros.Tope() << "\n";
        std::cout << "Capacidad actual: " << pila_enteros.Capacidad() << "\n";

        MostrarTitulo("Pila de cadenas");
        Pila<std::string> pila_cadenas({"hola", "mundo"});
        pila_cadenas.Imprimir();
        std::cout << "Tope: " << pila_cadenas.Tope() << "\n";

        MostrarTitulo("Pila de personas");
        Pila<Persona> pila_personas;
        pila_personas.Apilar(Persona{"Juan", 30});
        pila_personas.Apilar(Persona{"Ana", 25});
        pila_personas.Imprimir();
        std::cout << "Tope: " << pila_personas.Tope().nombre << "\n";
    } catch (const std::exception& e) {
        std::cerr << "Error inesperado: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
