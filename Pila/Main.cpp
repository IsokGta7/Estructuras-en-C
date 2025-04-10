//Ezequiel Isaac Rodriguez Tenorio
#include <iostream>
#include "Pila.h"
#include "Pila.cpp"

int main() {
    // Ejemplo de una pila de enteros
    Pila<int> pila_enteros;
    pila_enteros.Apilar(1);
    pila_enteros.Apilar(2);
    pila_enteros.Apilar(3);
    std::cout << "Pila de enteros: ";
    pila_enteros.Imprimir();
    pila_enteros.Desapilar();
    std::cout << "Después de desapilar: ";
    pila_enteros.Imprimir();
    std::cout << "El tope es: " << pila_enteros.Tope() << std::endl;

    // Ejemplo de redimensionamiento de la pila de enteros
    std::cout << "Capacidad de la pila antes de redimensionar: " << pila_enteros.Capacidad() << std::endl;
    pila_enteros.Apilar(4);
    pila_enteros.Apilar(5);
    std::cout << "Capacidad de la pila después de agregar elementos: " << pila_enteros.Capacidad() << std::endl;
    pila_enteros.Redimensionar();
    std::cout << "Capacidad de la pila después de redimensionar: " << pila_enteros.Capacidad() << std::endl;

    // Ejemplo de una pila de cadenas
    Pila<std::string> pila_cadenas;
    pila_cadenas.Apilar("hola");
    pila_cadenas.Apilar("mundo");
    std::cout << "Pila de cadenas: ";
    pila_cadenas.Imprimir();
    std::cout << "El tope es: " << pila_cadenas.Tope() << std::endl;

    Pila<Persona> pila_personas;
    pila_personas.Apilar(Persona("Juan", 30));
    pila_personas.Apilar(Persona("Ana", 25));
    std::cout << "Pila de personas: ";
    pila_personas.Imprimir();
    std::cout << "El tope es: " << pila_personas.Tope() << std::endl;

    system("pause");

    return 0;
}
