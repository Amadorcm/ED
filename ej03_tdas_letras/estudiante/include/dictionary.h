/**
 * @file dictionary.h
 * @brief  Archivo de especificación del TDA Dictionary
 * @author Carlos Roman Alvarez
 * @author Amador Carmona Mendez
 */
#ifndef __DICTIONARY_H__
#define __DICTIONARY_H__
#include<set>
#include<string>
#include<iostream>
#include<vector>
using namespace std;
/**
 * @brief TDA Dictionary
 * Almacena las palabras de un fichero de texto y permite iterar sobre ellas
 */
class Dictionary{
private:
    set<string> palabras;
public:
    /**
     * @brief Constructor de la case por defecto crea un objeto vacío
     */
    Dictionary();
    /**
     * @brief Constructor de copia de la clase, crea un objeto a partir de una dado
     * @param d objeto a copiar
     */
    Dictionary(Dictionary &d);
    /**
     * @brief indicar si una palabra esta en el diccionario o no
     * @param val palabra a consultar
     * @return booleano, true si está, false si no está la palabra
     */
    bool exist(const string &val);
    /**
     * @brief inserta una palabra en el diccionario
     * @param val pablabra a insertar en el diccionario
     * @return booleano que indica si se ha insertado correctamente la palabra
     */
    bool insert(const string &val);
    /**
     * @brief elimina una palabra del diccionario
     * @param val palabra a eliminar
     * @return booleano que indica si se ha borrado correctamente la palabra
     */
    bool erase(const string &val);
    /**
     * @brief elimina todas las palabras del diccionario
     */
    void clear();
    /**
     * @brief Comprueba si el diccionario está vacio
      * @return booleano que indica si esta lleno o no el diccionario
     */
    bool empty()const;
    /**
     * @brief Consulta el tamaño del diccionario
     * @return entero con el tamaño del diccionario
     */
    unsigned int size()const;
    /**
     * @brief indica el numero de apariciones de una letra
     * @param c letra a consultar
     * @return entero con el numero de repeticiones de la letra
     */
    int getOcurrences(const char c);
    /**
     * @brief Consulta el total de letras de un diccionario
     * @return entero con el total de letras
     */
    int getTotalLetters();
    /**
     * @brief devuelve las palabras con una longitud dada del diccionario
     * @param length longitud de las palabras
     * @return vector de palabras con las palabras de dicha longitud
     */
    vector<string> wordsOfLength(int length);
    /**
     * @brief TDA  Iterator
     * @details Clase que sirve para iterar sobre el TDA Dictionary
     *Las principales funciones que tiene son, el Constructor,Destructor, operacores de asignacion,incremento, decremento y comparación e inicio y fin.
     */
    class Iterator{
    private:
        set<string>::iterator it;
    public:
        /**
         * @brief Constructor por defecto
         */
        Iterator(){};
        /**
         *@brief constructor de copia
         * @param it iterador a copiar
         */
        Iterator(Iterator &it){};
        /**
         * @brief Destructor de la clase
         */
        ~Iterator(){};
        /**
         * @brief Operador de asignacion
         * @param it iterador qeu deseamos asignar
         * @return iterador a concatenar con el operador =
         */
        Iterator operator=(Iterator &it){};
        /**
         * @brief Operador puntero
         * @return string palabra del diccionario
         */
        char operator*(){};
        /**
         * @brief Operador aumento
         * @return iterador siguiente
         */
        Iterator operator ++(){};
        /**
         * @brief Operador de decremento
         * @return iterador anterior
         */
        Iterator operator --(){};
        /**
         * @brief Operador distinto
         * @param it iterador a comparar
         * @return booleano si es distinto o no
         */
        bool operator !=(Iterator &it){};
        /**
         * @brief Operador igual
         * @param it iterador a comparar
         * @return booleano si es igual o no
         */
        bool operator==(Iterator &it){};

    };
    /**
     * @brief Función begin
     * @return devuelve el primer elemento de la clase
     */
    Iterator begin(){};
    /**
     * @brief Funcion end
     * @return devuelve el ultimo elemento de la clase
     */
    Iterator end(){};
    /**
     * @brief TDA ConstIterator
     * @details Clase que sirve para iterar sobre el TDA Dictionary
     *Las principales funciones que tiene son, el Constructor,Destructor, operacores de asignacion,incremento, decremento y comparación e inicio y fin.
     */
    class ConstIterator{
    private:
        set<string>::const_iterator it;
    public:
        /**
         * @brief Constructor por defecto
         */
        ConstIterator(){
        };
        /**
         *@brief constructor de copia
         * @param it iterador a copiar
         */
        ConstIterator(ConstIterator &it){};
        /**
         * @brief Destructor de la clase
         */
        ~ConstIterator(){};
        /**
         * @brief Operador de asignacion
         * @param it iterador qeu deseamos asignar
         * @return iterador a concatenar con el operador =
         */
        ConstIterator operator=(ConstIterator &it){};
        /**
         * @brief Operador puntero
         * @return string palabra del diccionario
         */
        char operator*(){};
        /**
         * @brief Operador aumento
         * @return iterador siguiente
         */
        ConstIterator operator ++(){};
        /**
         * @brief Operador de decremento
         * @return iterador anterior
         */
        ConstIterator operator --(){};
        /**
         * @brief Operador distinto
         * @param it iterador a comparar
         * @return booleano si es distinto o no
         */
        bool operator !=(ConstIterator &it){};
        /**
         * @brief Operador igual
         * @param it iterador a comparar
         * @return booleano si es igual o no
         */
        bool operator==(ConstIterator &it){};

    };
    /**
     * @brief Función cbegin
     * @return devuelve el primer elemento de la clase
     */
    ConstIterator cbegin(){};
    /**
     * @brief Funcion cend
     * @return devuelve el ultimo elemento de la clase
     */
    ConstIterator cend(){};
};
#endif
