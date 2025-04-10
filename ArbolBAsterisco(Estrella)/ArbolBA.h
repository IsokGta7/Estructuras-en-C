#ifndef ARBOLBA_H
#define ARBOLBA_H

#include <iostream>
#include "Vector.h"

enum CriterioImpresion {
    ASCENDENTE,
    DESCENDENTE,
    PORNIVEL
};

template <typename T, unsigned G>
class ArbolBA {
public:
    ArbolBA();
    ~ArbolBA();
    void Agregar(const T& clave);
    bool Eliminar(const T& clave);
    bool Buscar(const T& clave) const;
    int NumeroDeClaves() const;
    bool Vaciar();
    void Imprimir(CriterioImpresion criterio) const;
    ArbolBA<T, G>& operator=(const ArbolBA<T, G>& other);

private:
    struct Nodo {
        Vector<int> claves;
        Vector<Nodo*> hijos;
        bool hoja;
        int numeroDeClaves;

        Nodo();
        ~Nodo();
    };

    Nodo* raiz;

    void AgregarEnNodo(Nodo* nodo, const T& clave);
    bool EliminarDeNodo(Nodo* nodo, const T& clave);
    bool BuscarEnNodo(Nodo* nodo, const T& clave) const;
    void ImprimirAscendente(Nodo* nodo) const;
    void ImprimirDescendente(Nodo* nodo) const;
    void ImprimirPorNivel() const;
    void VaciarNodo(Nodo* nodo);
    Nodo* CopiarNodo(const Nodo* nodo) const;
    std::ostream& operator<<(std::ostream& os);
};

#include "ArbolBA.cpp"

#endif // ARBOLBA_H
