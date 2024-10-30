/**
 * @file bag.h
 * @brief  Archivo de especificación del TDA Bag
 * @author Carlos Roman Alvarez
 * @author Amador Carmona Mendez
 */
#ifndef __BAG_H__
#define __BAG_H__
#include<vector>
#include<iostream>
using namespace std;

/**
 *  @brief TDA Bag
 *
 *  Este TDA abstracto nos permite trabajar con una colección de elementos que
 *  permite la extracción de elementos de forma aleatoria sin reemplazamiento
 */
template <class T>
class Bag {
private:
    vector<T> bolsa;
public:
    /**
     * @brief Constructor de la Clase
     *Crea una Bolsa vacio
     */
    Bag();
    /**
     * @brief Constructor de copia de la Clase
     *Crea una bolsa a partir del parametro dado
     * @param  b objeto tipo Bag<T> del que se va a realizar la copia
     */
    Bag(Bag<T> &b);
    /*Métodos para añadir y extraer elementos de la bolsa, y posibilidad de vaciar la bolsa.
     * Los tres con complejidad computacional O(1). Para poder obtener esta eficiencia en
     * dichos métodos cabe destacar que es posible modificar el contenido del vector y alterar
     * su orden, puesto que no es de interés en este TDA
    */
    /**
     * @brief Añade un elemento nuevo a la bolsa
     * @tparam element  elemento del tipo T que se añadira a la bolsa
     */
    void add(const T &element);
    /**
     * @brief Extrae un elemento aleatorio de la bolsa y lo elimina de la bolsa
     * @return elemento del tipo T extraido de la bolsa
     * @pre la bolsa no está vacía
     * @post el elemento devuelto se ha eliminado de la bolsa
     */
    T get();
    /**
     * @brief elimina todos los elementos almacenados en la bolsa
     */
    void clear();
    /**
     * @brief consulta el tamaño de la bolsa
     * @return un entero con el numero de elementos que contiene la bolsa
     */
    unsigned int size();
    /**
     * @brief comprueba si la bolsa está vacía
     * @return un booleano que tiene el valor verdadero si esta vacía la bolsa y falso en el caso contrario
     */
    bool empty();
    /**
     * @brief sobrecarga el operador de asignación
     * @param otro objeto del tipo Bag<T> a copiar
     * @return referencia al objeto this para encadenarlo con el operador =
     */
    const Bag<T> & operator=(const Bag<T> &otro);
};
#endif
