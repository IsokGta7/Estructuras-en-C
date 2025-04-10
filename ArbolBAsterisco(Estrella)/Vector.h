/* Nombre:Vector.cpp
   Autor: Ezequiel Isaac Rodriguez Tenorio
   Fecha: 20/03/21
   Descripci�n: Archivo de cabecera de la clase vector
*/

#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

#include<stdexcept>
#include<iostream>
#include<cmath>


/** \brief Clase que simula un vector
 */
class Vector
{
public:

    //*************************************************************************************
    /** \brief imprime una matriz en un flujo de salida
    *
    * \param salida el flujo de salida
    * \param mtz la matriz que se quiere mostrar en el flujo de salida
    * \return El mismo flujo de salida
    *
    */friend std::ostream & operator<<(std::ostream & salida, const Vector &v);

    //*************************************************************************************
    /** \brief Lee una matriz mediante un flujo de entrada
     *
     * \param entrada el flujo de entrada
     * \param mtz la matriz que se quiere leer
     * \return El mismo flujo de entrada
     *
     */friend std::istream & operator>>(std::istream & entrada, Vector &v);

    //*************************************************************************************
    /** \brief constructor por defaut
    *
    */Vector();

    //*************************************************************************************
    /** \brief Constructor de copias
    * \param v el vector a copiar
    *
    */Vector(const Vector &v);

    //*************************************************************************************
    /** \brief Constructor de un parametro
    * \param dim la dimenci�n del vector
    *
    */explicit Vector(int dim);

    //*************************************************************************************
    /** \brief constructor de dos parametros
    *
    * \param dim la dimenci�n del vector
    * \param ValorIn valor iniciar de todos los valores
    *
    */Vector(int dim, double valorIn);

    //*************************************************************************************
    /** \brief destructor
     *
     */
    ~Vector();


    //*************************************************************************************
    /** \brief Cambia un elemento del vector
    *
    * \param i el indice a cambiar
    * \param comp el nuevo valor del indice
    *
    */void EstablecerComponente(int i,double comp);

    //*************************************************************************************
    /** \brief Sobrecarga del operador =
    *
    * \param v el vector a copiar
    * \return el vector
    *
    */Vector & operator=(const Vector & v);

    //*************************************************************************************
    /** \brief Sobrecarga del operador ==
    *
    * \param v vector con el que se comparar�
    * \return true si ambas magnitudes son iguales
    *
    */bool operator==(const Vector & v) const;

    //*************************************************************************************
    /** \brief Sobrecarga del operador !=
    *
    * \param v vector con el que se comparar�
    * \return true si ambas magnitudes son diferentes
    *
    */bool operator!=(const Vector & v) const;

    //*************************************************************************************
    /** \brief Sobrecarga del operador >=
    *
    * \param v vector con el que se comparar�
    * \return true si la magnitud de V es menor o igual
    *
    */bool operator>=(const Vector & v) const;

    //*************************************************************************************
    /** \brief Sobrecarga del operador <=
    *
    * \param v vector con el que se comparar�
    * \return true si la magnitud de V es mayor o igual
    *
    */bool operator<=(const Vector & v) const;

    //*************************************************************************************
    /** \brief Sobrecarga del operador <
    *
    * \param v vector con el que se comparar�
    * \return true si la magnitud de V es mayor
    *
    */bool operator<(const Vector & v) const;

    //*************************************************************************************
    /** \brief Sobrecarga del operador >
    *
    * \param v vector con el que se comparar�
    * \return true si la magnitud de V es menor
    *
    */bool operator>(const Vector & v) const;

    //*************************************************************************************
    //*************************************************************************************
    /** \brief Sobrecarga del operador ==
    *
    * \param i una magnitud
    * \return true si la magnitud es igual a i
    *
    */bool operator==(const int i) const;

    //*************************************************************************************
    /** \brief Sobrecarga del operador !=
    *
    * \param i una magnitud
    * \return true si la magnitud es diferente a i
    *
    */bool operator!=(const int i) const;

    //*************************************************************************************
    /** \brief Sobrecarga del operador >=
    *
    * \param i una magnitud
    * \return true si la magnitud es mayor o igual a i
    *
    */bool operator>=(const int i) const;

    //*************************************************************************************
    /** \brief Sobrecarga del operador <=
    *
    * \param i una magnitud
    * \return true si la magnitud es igual menor o igual a i
    *
    */bool operator<=(const int i) const;

    //*************************************************************************************
    /** \brief Sobrecarga del operador <
    *
    * \param i una magnitud
    * \return true si la magnitud es igual menor a i
    *
    */bool operator<(const int i) const;

    //*************************************************************************************
    /** \brief Sobrecarga del operador >
    *
    * \param i una magnitud
    * \return true si la magnitud es mayor a i
    *
    */bool operator>(const int i) const;

    //*************************************************************************************
    /** \brief Establece la dimenci�n
    *
    * \param dim la nueva dimenci�n
    * \exception std::logic_error Si se intenta declarar un vector de magnitud negativa
    * \exception std::bad_alloc No hay memoria
    *
    */void EstablecerDimension(int dim);


    //*************************************************************************************
    /** \brief Regresa el tama�o del vector
    * \return el tama�o del vector
    *
    */int ObtenerDimencion() const;

    //*************************************************************************************
    /** \brief Regresa el componente i
    *
    * \param i el indice del componente
    * \return el componente
    *
    */double ObtenerComponente(int i) const;


    //*************************************************************************************
    /** \brief Imprime el vector
    *
    */void Imprimir() const;

    //*************************************************************************************
    /** \brief Lee los elementos del vector
    *
    */void Captura();

    //*************************************************************************************
    /** \brief Suma dos vectores
    *
    * \param v el vector a sumar
    * \return el vector resultante
    *
    */Vector Sumar(const Vector &v) const;

    //*************************************************************************************
    /** \brief Resta dos vectores
    *
    * \param v el vector a restar
    * \return el vector resultante
    *
    */Vector Resta(const Vector &v) const;

    //*************************************************************************************
    /** \brief Multiplica un vector por un escalar
    *
    * \param escalar el escalar
    * \return el vector resultante
    *
    */Vector Multiplicar(double escalar) const;

    //*************************************************************************************
    /** \brief Calcula la magnitud de un vector
    * \return la magnitud del vector
    *
    */double ObtenerMagnitud() const;




protected:


private:
    int dim;
    double *componente=NULL; //<-------------------------

};

#endif // VECTOR_H_INCLUDED
