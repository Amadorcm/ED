/**
 * @file maxqueue.h
 * @brief  Archivo de especificación del TDA MaxQueue
 * @author Carlos Roman Alvarez
 * @author Amador Carmona Mendez
 */
#include<stack>
#include<iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;
/**
  @brief Struct element

  * Estructura de datos que almacena un elemento y el maximo,
  * sobrecargamos el operador << para la salida de este mismo.
  * Viene dada en el Guion de la practica.

 * @author Carlos Roman Alvarez
 * @author Amador Carmona Mendez
 * @date Noviembre 2022
**/
struct element{
    int value; //Valor actual para almacenar
    int maximum; //Valor maximo actual en la estructura

    /**
     * @brief Sobrecarga del operador << para visualizar por salida un
     * objeto element de la cola_max
     * @param os instancia de tipo element que saca por pantalla
     * @param elemento salida de informacion
     * @return flujo de salida el
     */
    friend ostream & operator <<(ostream & os, const element & elemento);
};
/**
  @brief T.D.A. MaxQueue o ColaMAx

  * Una instancia del tipo de dato abstracto MaxQueue es una cola de pareja de enteros
  * donde la pareja  se guarda un valor y el maximo de esta cola hasta el momento, ademas esta cola a nivel
  * de implementación esta implementada con una  pila (stack) de la stl.

  * El TDA MaxQueue nos da las herramientas básicas para la utilizacion de este tidpo de datos como lo son:
  * constructor
  * Colocar un elemento al final de la cola
  * Consultar el elemento al principio de la cola (sin extraerlo)
  * Extraer el elemento al principio de la cola
  * Consultar el tamaño de la cola (número de elementos que la componen)
  * Consultar si la cola está vacía

  * Para poder usar el TDA MaxQueue se debe incluir el fichero maxqueue.h de la siguiente manera:
  * #include <maxqueue.h>

 * @author Carlos Roman Alvarez
 * @author Amador Carmona Mendez
 * @date Noviembre 2022


**/
class MaxQueue{
private:
    stack<element> pilaMax;
public:
    /**
     * @brief Constructor de la Clase
     */
    MaxQueue();
    /**
     * @brief Constructor de copia de la Clase
     * @param q cola para crear la nueva cola a partir de esa
     */
    MaxQueue(MaxQueue &q);
    /**
     * @brief Inserta un elemento en la cola y actualiza el maximo si es necesario
     * @param num entero que se va a insertar
     */
    void push(int num);
    /**
     * @brief Elimina el valor que le corresponde al inicio de la cola (front)
     */
    void pop();
    /**
     * @brief Devuelve si la cola esta vacia o no
     * @return Booleano que especifica si esta vacia la cola
     */
    bool empty();
    /**
     * @brief Devuelve el ultimo elemento insertado en la cola y el maximo que hay en la cola
     * @return pareja de valores correspondiente al valor y al maximo de la cola cuya posicion es el final de la cola
     */
    element back();
    /**
     * @brief Devuelve el primer elemento en la cola  y el máximo que hay en la cola
     * @return pareja de valores correspondiente al valor y al maximo de la cola cuya posicion es el principio de la cola
     */
    element front();
    /**
     * @brief Devuelve la cantidad de elementos de la cola
     * @return Entero que expresa el tamaño de la cola
     */
    int size();
    /**
    * @brief comprueba si el valor dado es mayor que el maximo de la cola,
    *si es asi actualiza los valores de la pila y devuelve el valor, si no devuelve el maximo
    * @param num el numeor que queremos comprobar si es el maximo o no.
    * @return el maximo de la cola**/
    int maximo(int num);
    /**
    * @brief despues de hacer un pop resetea todos los maximos al nuevo maximo solo pasa cuando el valor y el maximo coinciden y estos son los que se van a borrar
    **/
    void popmaximo();
    /**
     * @brief imprime el contenido de MAxQueue
     */
    void imprimir();
};
