#ifndef PILA_H
#define PILA_H

#include <initializer_list>
#include <iostream>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

/**
 * @brief Representa una persona simple para las demostraciones de la pila.
 */
struct Persona {
    std::string nombre;
    int edad{};

    Persona() = default;
    Persona(std::string nombre, int edad) : nombre(std::move(nombre)), edad(edad) {}

    friend std::ostream& operator<<(std::ostream& os, const Persona& persona) {
        os << persona.nombre << " (" << persona.edad << " años)";
        return os;
    }
};

/**
 * @brief Implementación dinámica de una pila genérica.
 *
 * La clase sigue la semántica de valor de C++ (constructor de copia, asignación
 * y destructor) y puede almacenar cualquier tipo movible o copiable.
 */
template <typename T>
class Pila {
public:
    /**
     * @brief Construye una pila con capacidad inicial configurable.
     */
    explicit Pila(std::size_t capacidad_inicial = 10)
        : capacidad_(capacidad_inicial), tope_(-1), elementos_(capacidad_inicial) {}

    /**
     * @brief Construye una pila a partir de una lista de inicialización.
     */
    Pila(std::initializer_list<T> elementos) : Pila(elementos.size()) {
        for (const auto& elemento : elementos) {
            Apilar(elemento);
        }
    }

    /**
     * @brief Inserta un elemento en la parte superior de la pila.
     */
    void Apilar(const T& elemento) {
        if (EstaLlena()) {
            Redimensionar();
        }
        elementos_[++tope_] = elemento;
    }

    /**
     * @brief Extrae el elemento del tope. Lanza si la pila está vacía.
     */
    void Desapilar() {
        if (EstaVacia()) {
            throw std::underflow_error("La pila está vacía");
        }
        --tope_;
    }

    /**
     * @brief Devuelve el elemento en el tope. Lanza si la pila está vacía.
     */
    const T& Tope() const {
        if (EstaVacia()) {
            throw std::underflow_error("La pila está vacía");
        }
        return elementos_[tope_];
    }

    /**
     * @brief Indica si la pila no contiene elementos.
     */
    bool EstaVacia() const { return tope_ == -1; }

    /**
     * @brief Elimina todos los elementos en O(1).
     */
    void Vaciar() { tope_ = -1; }

    /**
     * @brief Número de elementos almacenados actualmente.
     */
    std::size_t Tamano() const { return static_cast<std::size_t>(tope_ + 1); }

    /**
     * @brief Capacidad interna de la pila. Visible para pruebas.
     */
    std::size_t Capacidad() const { return capacidad_; }

    /**
     * @brief Imprime los elementos en orden de inserción.
     */
    void Imprimir(std::ostream& os = std::cout) const {
        for (int i = 0; i <= tope_; i++) {
            os << elementos_[i] << (i == tope_ ? "" : " ");
        }
        os << std::endl;
    }

private:
    void Redimensionar() {
        capacidad_ *= 2;
        elementos_.resize(capacidad_);
    }

    bool EstaLlena() const { return static_cast<std::size_t>(tope_ + 1) == capacidad_; }

    std::size_t capacidad_;
    int tope_;
    std::vector<T> elementos_;
};

#endif // PILA_H
