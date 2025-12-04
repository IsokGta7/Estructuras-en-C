#include <cassert>
#include <stdexcept>
#include <string>

#include "../Pila/Pila.h"

void ProbarEnteros() {
    Pila<int> pila;
    assert(pila.EstaVacia());

    pila.Apilar(10);
    pila.Apilar(20);
    assert(pila.Tamano() == 2);
    assert(pila.Tope() == 20);

    pila.Desapilar();
    assert(pila.Tope() == 10);
    pila.Desapilar();
    assert(pila.EstaVacia());

    bool lanzo = false;
    try {
        pila.Desapilar();
    } catch (const std::underflow_error&) {
        lanzo = true;
    }
    assert(lanzo);
}

void ProbarPersonas() {
    Pila<Persona> pila_personas;
    pila_personas.Apilar({"Alex", 35});
    pila_personas.Apilar({"Sara", 28});

    assert(pila_personas.Tamano() == 2);
    assert(pila_personas.Tope().nombre == "Sara");
}

int main() {
    ProbarEnteros();
    ProbarPersonas();
    return 0;
}
