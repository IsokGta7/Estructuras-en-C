#ifndef PILA_H
#define PILA_H

template<typename T>
class Pila {
    friend int main();
public:
    // Constructor por default
    Pila();
    // Constructor de copias
    Pila(const Pila<T>& other);
    // Operador de asignación sobrecargado
    Pila<T>& operator=(const Pila<T>& other);
    // Destructor
    ~Pila();

    // Agrega un nuevo elemento en la pila
    void Apilar(const T& elemento);
    // Elimina un elemento de la pila
    void Desapilar();
    // Obtiene el elemento en el tope de la pila
    const T& Tope() const;
    // Conoce si la pila está vacía
    bool EstaVacia() const;
    // Vacia la pila
    void Vaciar();
    // Conoce el número de elementos que tiene la pila
    int Tamano() const;
    // Conoce la capacidad de la pila (para pruebas)
    int Capacidad() const;
    // Imprime los elementos de la pila (para pruebas)
    void Imprimir() const;

private:
    // Redimensiona el arreglo que contiene los elementos de la pila
    void Redimensionar();
    // Conoce si la pila está llena
    bool EstaLlena() const;

    int capacidad;
    int tope;
    T* elementos;
};

#endif // PILA_H
