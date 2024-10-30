/**
 * @file maxstack.h
 * @brief  Archivo de especificación del TDA MaxStack
 * @author Carlos Roman Alvarez
 * @author Amador Carmona Mendez
 */
#include <iostream>
#include <queue>

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
  @brief T.D.A. MaxStack o PilaMax

  * Una instancia del tipo de dato abstracto MaxStack es una pila de pareja de enteros
  * donde la pareja  se guarda un valor y el maximo de esta pila hasta el momento, ademas esta pila a nivel
  * de implementación esta implementada con una  cola (queue) de la stl.

  * El TDA MaxStack nos da las herramientas básicas para la utilizacion de este tidpo de datos como lo son:
  * Cosntructor
  * Colocar un elemento en la parte superior de la pila
  * Consultar el elemento en la parte superior de la pila (sin extraerlo)
  * Extraer el elemento en la parte superior de la pila
  * Consultar el tamaño de la pila (número de elementos que la componen)
  * Consultar si la pila está vacía

  * Para poder usar el TDA MaxStack se debe incluir el fichero maxstack.h de la siguiente manera:
  * #include <maxstack.h>

 * @author Carlos Roman Alvarez
 * @author Amador Carmona Mendez
 * @date Noviembre 2022


**/
class MaxStack{
private:
    queue<element> max_queue;

public:
    /**
     * @brief Constructor de la clase MaxStack sin parametros
     */
    MaxStack();

    /**
     * @brief Devuelve el último valor almacenado en la pila
     *
     * @return Elemento mas reciente de la pila
     */
    element top();

    /**
     * @brief Elimina el ultimo elemento de la pila
     */
    void pop();

    /**
     * @brief Devuelve la cantidad de elementos de la pila
     * @return Entero que expresa el tamaño de la pila
     */
    int size();

    /**
     * @brief Comprueba si la pila está vacia o no
     * @return  Booleano que especifica si esta vacia la pila
     */
    bool empty();

    /**
     * @brief Introduce en la pila un objeto de tipo element
     * @param num Valor a almacenar en la pila
     */
    void push(int num);

    /**
    * @brief comprueba si el valor dado es mayor que el maximo de la pila,
    *si es asi devuelve el valor, si no devuelve el maximo (En este ejercicio no es necesario actualizar los maximos)
    * @param num el numeor que queremos comprobar si es el maximo o no.
    * @return el maximo de la pila**/
    int maximo(int num);

};