#include "ArbolBA.h"

template <typename T, unsigned G>
ArbolBA<T, G>::ArbolBA() {
    raiz = new Nodo();
    raiz->hoja = true;
    raiz->numeroDeClaves = 0;
}

template <typename T, unsigned G>
ArbolBA<T, G>::~ArbolBA() {
    Vaciar();
    delete raiz;
}

template <typename T, unsigned G>
void ArbolBA<T, G>::Agregar(const T& clave) {
    if (Buscar(clave)) {
        std::cout << "La clave ya existe en el árbol." << std::endl;
        return;
    }

    if (raiz->numeroDeClaves == (2 * G - 1)) {
        Nodo* nuevo = new Nodo();
        nuevo->hijos[0] = raiz;
        raiz = nuevo;
        raiz->hoja = false;
        raiz->numeroDeClaves = 0;
        raiz->claves.Agregar(clave);
        raiz->numeroDeClaves++;
        AgregarEnNodo(raiz, clave);
    } else {
        AgregarEnNodo(raiz, clave);
    }
}

template <typename T, unsigned G>
void ArbolBA<T, G>::AgregarEnNodo(Nodo* nodo, const T& clave) {
    int i = nodo->numeroDeClaves - 1;

    if (nodo->hoja) {
        nodo->claves.Agregar(clave);
        nodo->numeroDeClaves++;
    } else {
        while (i >= 0 && clave < nodo->claves[i]) {
            i--;
        }
        i++;

        if (nodo->hijos[i]->numeroDeClaves == (2 * G - 1)) {
            Nodo* hijo = nodo->hijos[i];
            Nodo* nuevo = new Nodo();
            nodo->hijos[i] = nuevo;
            nuevo->hoja = false;
            nuevo->numeroDeClaves = 0;

            for (int j = 0; j < G - 1; j++) {
                nuevo->claves.Agregar(hijo->claves[j + G]);
                hijo->claves[j + G] = T();
            }

            for (int j = 0; j < G; j++) {
                nuevo->hijos[j] = hijo->hijos[j + G];
                hijo->hijos[j + G] = nullptr;
            }

            hijo->numeroDeClaves = G - 1;
            nodo->claves.Agregar(hijo->claves[G - 1]);
            nodo->numeroDeClaves++;
            hijo->claves[G - 1] = T();

            if (clave > nodo->claves[i]) {
                i++;
            }
        }

        AgregarEnNodo(nodo->hijos[i], clave);
    }
}

template <typename T, unsigned G>
bool ArbolBA<T, G>::Eliminar(const T& clave) {
    if (!Buscar(clave)) {
        std::cout << "La clave no existe en el árbol." << std::endl;
        return false;
    }

    bool eliminado = EliminarDeNodo(raiz, clave);

    if (raiz->numeroDeClaves == 0 && !raiz->hoja) {
        Nodo* antiguaRaiz = raiz;
        raiz = raiz->hijos[0];
        delete antiguaRaiz;
    }

    return eliminado;
}

template <typename T, unsigned G>
bool ArbolBA<T, G>::EliminarDeNodo(Nodo* nodo, const T& clave) {
    int i = 0;
    while (i < nodo->numeroDeClaves && clave > nodo->claves[i]) {
        i++;
    }

    if (i < nodo->numeroDeClaves && clave == nodo->claves[i]) {
        if (nodo->hoja) {
            nodo->claves.Eliminar(i);
            nodo->numeroDeClaves--;
        } else {
            Nodo* hijoIzq = nodo->hijos[i];
            Nodo* hijoDer = nodo->hijos[i + 1];

            if (hijoIzq->numeroDeClaves >= G) {
                T predecesor = hijoIzq->claves[hijoIzq->numeroDeClaves - 1];
                EliminarDeNodo(hijoIzq, predecesor);
                nodo->claves[i] = predecesor;
            } else if (hijoDer->numeroDeClaves >= G) {
                T sucesor = hijoDer->claves[0];
                EliminarDeNodo(hijoDer, sucesor);
                nodo->claves[i] = sucesor;
            } else {
                hijoIzq->claves.Agregar(clave);
                hijoIzq->numeroDeClaves++;

                for (int j = 0; j < G - 1; j++) {
                    hijoIzq->claves.Agregar(hijoDer->claves[j]);
                }

                for (int j = 0; j < G; j++) {
                    hijoIzq->hijos.Agregar(hijoDer->hijos[j]);
                }

                hijoIzq->numeroDeClaves += hijoDer->numeroDeClaves;

                nodo->claves.Eliminar(i);
                nodo->hijos.Eliminar(i + 1);
                nodo->numeroDeClaves--;

                delete hijoDer;

                if (nodo->numeroDeClaves == 0 && !nodo->hoja) {
                    Nodo* antiguoNodo = nodo;
                    nodo = hijoIzq;
                    delete antiguoNodo;
                }
            }
        }

        return true;
    } else {
        if (nodo->hoja) {
            return false;
        }

        Nodo* hijo = nodo->hijos[i];

        if (hijo->numeroDeClaves >= G) {
            return EliminarDeNodo(hijo, clave);
        } else {
            if (i > 0) {
                Nodo* hermanoIzq = nodo->hijos[i - 1];

                if (hermanoIzq->numeroDeClaves >= G) {
                    for (int j = hijo->numeroDeClaves; j > 0; j--) {
                        hijo->claves[j] = hijo->claves[j - 1];
                    }

                    hijo->claves[0] = nodo->claves[i - 1];

                    for (int j = hijo->numeroDeClaves + 1; j > 0; j--) {
                        hijo->hijos[j] = hijo->hijos[j - 1];
                    }

                    hijo->hijos[0] = hermanoIzq->hijos[hermanoIzq->numeroDeClaves];
                    hijo->numeroDeClaves++;

                    nodo->claves[i - 1] = hermanoIzq->claves[hermanoIzq->numeroDeClaves - 1];

                    hermanoIzq->claves.Eliminar(hermanoIzq->numeroDeClaves - 1);
                    hermanoIzq->hijos.Eliminar(hermanoIzq->numeroDeClaves);
                    hermanoIzq->numeroDeClaves--;

                    return EliminarDeNodo(hijo, clave);
                }
            }

            if (i < nodo->numeroDeClaves) {
                Nodo* hermanoDer = nodo->hijos[i + 1];

                if (hermanoDer->numeroDeClaves >= G) {
                    hijo->claves[hijo->numeroDeClaves] = nodo->claves[i];

                    hijo->hijos[hijo->numeroDeClaves + 1] = hermanoDer->hijos[0];
                    hijo->numeroDeClaves++;

                    nodo->claves[i] = hermanoDer->claves[0];

                    hermanoDer->claves.Eliminar(0);
                    hermanoDer->hijos.Eliminar(0);
                    hermanoDer->numeroDeClaves--;

                    return EliminarDeNodo(hijo, clave);
                }
            }

            if (i > 0) {
                Nodo* hermanoIzq = nodo->hijos[i - 1];

                hermanoIzq->claves.Agregar(nodo->claves[i - 1]);
                hermanoIzq->numeroDeClaves++;

                for (int j = 0; j < hijo->numeroDeClaves; j++) {
                    hermanoIzq->claves.Agregar(hijo->claves[j]);
                }

                for (int j = 0; j <= hijo->numeroDeClaves; j++) {
                    hermanoIzq->hijos.Agregar(hijo->hijos[j]);
                }

                hermanoIzq->numeroDeClaves += hijo->numeroDeClaves;

                nodo->claves.Eliminar(i - 1);
                nodo->hijos.Eliminar(i);
                nodo->numeroDeClaves--;

                delete hijo;

                if (nodo->numeroDeClaves == 0 && !nodo->hoja) {
                    Nodo* antiguoNodo = nodo;
                    nodo = hermanoIzq;
                    delete antiguoNodo;
                }

                return EliminarDeNodo(hermanoIzq, clave);
            }

            if (i < nodo->numeroDeClaves) {
                Nodo* hermanoDer = nodo->hijos[i + 1];

                hijo->claves.Agregar(nodo->claves[i]);
                hijo->numeroDeClaves++;

                for (int j = 0; j < hermanoDer->numeroDeClaves; j++) {
                    hijo->claves.Agregar(hermanoDer->claves[j]);
                }

                for (int j = 0; j <= hermanoDer->numeroDeClaves; j++) {
                    hijo->hijos.Agregar(hermanoDer->hijos[j]);
                }

                hijo->numeroDeClaves += hermanoDer->numeroDeClaves;

                nodo->claves.Eliminar(i);
                nodo->hijos.Eliminar(i + 1);
                nodo->numeroDeClaves--;

                delete hermanoDer;

                if (nodo->numeroDeClaves == 0 && !nodo->hoja) {
                    Nodo* antiguoNodo = nodo;
                    nodo = hijo;
                    delete antiguoNodo;
                }

                return EliminarDeNodo(hijo, clave);
            }
        }
    }

    return false;
}

template <typename T, unsigned G>
bool ArbolBA<T, G>::Buscar(const T& clave) const {
    return BuscarEnNodo(raiz, clave);
}

template <typename T, unsigned G>
bool ArbolBA<T, G>::BuscarEnNodo(Nodo* nodo, const T& clave) const {
    int i = 0;
    while (i < nodo->numeroDeClaves && clave > nodo->claves[i]) {
        i++;
    }

    if (i < nodo->numeroDeClaves && clave == nodo->claves[i]) {
        return true;
    } else {
        if (nodo->hoja) {
            return false;
        } else {
            return BuscarEnNodo(nodo->hijos[i], clave);
        }
    }
}

template <typename T, unsigned G>
int ArbolBA<T, G>::NumeroDeClaves() const {
    return raiz->numeroDeClaves;
}

template <typename T, unsigned G>
bool ArbolBA<T, G>::Vaciar() {
    VaciarNodo(raiz);
    raiz->numeroDeClaves = 0;
    raiz->hoja = true;
    return true;
}

template <typename T, unsigned G>
void ArbolBA<T, G>::VaciarNodo(Nodo* nodo) {
    if (nodo->hoja) {
        nodo->claves.Limpiar();
        nodo->numeroDeClaves = 0;
    } else {
        for (int i = 0; i <= nodo->numeroDeClaves; i++) {
            VaciarNodo(nodo->hijos[i]);
        }

        nodo->claves.Limpiar();
        nodo->numeroDeClaves = 0;

        nodo->hijos.Limpiar();
        nodo->hijos.Redimensionar(G);
    }
}

template <typename T, unsigned G>
void ArbolBA<T, G>::RecorridoEnAnchura() const {
    std::queue<Nodo*> cola;
    cola.push(raiz);

    while (!cola.empty()) {
        Nodo* nodo = cola.front();
        cola.pop();

        for (int i = 0; i < nodo->numeroDeClaves; i++) {
            std::cout << nodo->claves[i] << " ";
        }

        if (!nodo->hoja) {
            for (int i = 0; i <= nodo->numeroDeClaves; i++) {
                cola.push(nodo->hijos[i]);
            }
        }
    }

    std::cout << std::endl;
}
