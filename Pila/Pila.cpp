#include <iostream>

#include "Pila.h"

// Ejemplo de una pila de objetos personalizados
class Persona {
public:
    std::string nombre;
    int edad;

    Persona() : nombre(""), edad(0) {} // Constructor por defecto

    Persona(std::string nombre, int edad) : nombre(nombre), edad(edad) {}

    friend std::ostream& operator<<(std::ostream& os, const Persona& persona) {
        os << persona.nombre << ", " << persona.edad << " anioos";
        return os;
    }
};


// Constructor por default
template<typename T>
Pila<T>::Pila() {
    capacidad = 10;
    tope = -1;
    elementos = new T[capacidad];
}

// Constructor de copias
template<typename T>
Pila<T>::Pila(const Pila<T>& other) {
    capacidad = other.capacidad;
    tope = other.tope;
    elementos = new T[capacidad];
    for (int i = 0; i <= tope; i++) {
        elementos[i] = other.elementos[i];
    }
}

// Operador de asignación sobrecargado
template<typename T>
Pila<T>& Pila<T>::operator=(const Pila<T>& other) {
    if (this != &other) {
        capacidad = other.capacidad;
        tope = other.tope;
        delete[] elementos;
        elementos = new T[capacidad];
        for (int i = 0; i <= tope; i++) {
            elementos[i] = other.elementos[i];
        }
    }
    return *this;
}

// Destructor
template<typename T>
Pila<T>::~Pila() {
    delete[] elementos;
}

// Agrega un nuevo elemento en la pila
template<typename T>
void Pila<T>::Apilar(const T& elemento) {
    if (EstaLlena()) {
        Redimensionar();
    }
    elementos[++tope] = elemento;
}

// Elimina un elemento de la pila
template<typename T>
void Pila<T>::Desapilar() {
    if (!EstaVacia()) {
        tope--;
    }
}

// Obtiene el elemento en el tope de la pila
template<typename T>
const T& Pila<T>::Tope() const {
    if (!EstaVacia()) {
        return elementos[tope];
    }
    throw "La pila esta vacia";
}

// Conoce si la pila está vacía
template<typename T>
bool Pila<T>::EstaVacia() const {
    return tope == -1;
}

// Vacia la pila
template<typename T>
void Pila<T>::Vaciar() {
    tope = -1;
}

// Conoce el número de elementos que tiene la pila
template<typename T>
int Pila<T>::Tamano() const {
    return tope + 1;
}

// Conoce la capacidad de la pila (para pruebas)
template<typename T>
int Pila<T>::Capacidad() const {
    return capacidad;
}

// Imprime los elementos de la pila (para pruebas)
template<typename T>
void Pila<T>::Imprimir() const {
    for (int i = 0; i <= tope; i++) {
        std::cout << elementos[i] << " ";
    }
    std::cout << std::endl;
}

// Redimensiona el arreglo que contiene los elementos de la pila
template<typename T>
void Pila<T>::Redimensionar() {
    capacidad *= 2;
    T* nuevo_arreglo = new T[capacidad];
    for (int i = 0; i <= tope; i++) {
        nuevo_arreglo[i] = elementos[i];
    }
    delete[] elementos;
    elementos = nuevo_arreglo;
}

// Conoce si la pila está llena
template<typename T>
bool Pila<T>::EstaLlena() const {
    return tope == capacidad - 1;
}

