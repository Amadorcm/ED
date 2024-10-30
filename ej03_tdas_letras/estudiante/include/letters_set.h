/**
 * @file letters_set.h
 * @brief  Archivo de especificación del TDA LettersSet
 * @author Carlos Roman Alvarez
 * @author Amador Carmona Mendez
 */
#ifndef __LETTER_SET_H__
#define __LETTER_SET_H__
#include<map>
#include<iostream>
using namespace std;
/**
 * @brief Struct LetterInfo
 *
 * Contiene información sobre un determinado carácter del juego de las
 * letras. En concreto, almacena información sobre el número de repeticiones de
 * la letra en la partida y de la puntuación que otorga al utilizarse en una
 * palabra
 */
struct LetterInfo{
    int numRep;
    int puntuacion;
};
/**
 * @brief TDA LettersSet
 *
 * Este TDA representa un conjunto de letras, con la información necesaria para
 * jugar una partida al juego de las letras, es decir, el número de repeticiones
 * que tenemos de la letra y la puntuación que dicha letra otorga cuando se
 * utiliza en una palabra
 */
 class LettersSet{
 private:
     map<char,LetterInfo > letras;
 public:
     /**
     * @brief Constructor de la Clase
     *Crea un LettersSet vacio
     */
     LettersSet();
     /**
     * @brief Constructor de copia de la Clase
     * Crea un LettersSet con los datos de otro letterset pasados por referencia
     * @param l LettersSet a copiar
     */
     LettersSet(LettersSet &l);
     /**
     * @brief inserta en LettersSet un elemento
     * @param l par char,LetterInfo a insertar
     * @return booleano que nos indica si se ha realizado la inserccion correctamente o no
     */
     bool insert(const pair<char,LetterInfo> &l);
     /**
     * @brief Elimina un caracter del LettersSet
     * @param key Caracter a eliminar
     * @return booleano que indica si se ha borrado correctamente la letra en el LetterSet
     */
     bool erase(const char &key);
     /**
     * @brief Limpia/elimina el contenido del LettersSet
     */
     void clear();
     /**
     * @brief Consulta si el LettersSet esta vacio
     * @return verdadero si esta vacío, falso el caso contrario.
     */
     bool empty()const;
     /**
     * @brief Consulta el tamaño del LettersSet
     * @return Número de elementos del LettersSet
     */
     unsigned int size();
     /**
     * @brief Calcula la puntuación de una palabra
     * @pre La palabra dada debe ser valida
     * @param  word palabra a ser evaluada
     * @return valor de la puntuación de la palabra dada, calculada con la suma del valor de sus letras.
     */
     unsigned int getScore(string word);
     /**
     * @brief Destructor de la Clase
     */
     ~LettersSet();
     /**
     * @brief sobrecarga del operador de asignación
     * @param cl LettersSet a copiar
     * @return referencia al objeto this para poder encadenar con el operador =
     */
     LettersSet &operator =(const LettersSet &cl);
     /**
     * @brief sobrecarga del operador de consulta
     * @param key letra a consultar
     * @return estructura de tipo LetterInfo con la informacion del caracter consultado
     */
     LetterInfo &operator [](const char &key);
     /**
     * @brief sobrecarga del operador de salida
     * @param os Flujo de salida donde escribir el LetterSet
     * @param cl LettersSet que se escribe
     */
     friend ostream &operator <<(ostream &os, const LettersSet &cl);
     /**
     * @brief sobrecarga del operador de entrada
     * @param is flujo de entrada del que leer LettersSet
     * @param cl LettersSet en el que almacenar la nformación leida
     */
     friend istream & operator>>(istream &is, const LettersSet &cl);
     /**
     * @brief TDA  Iterator
     * @details Clase que sirve para iterar sobre el TDA LettersSet
     *Las principales funciones que tiene son, el Constructor,Destructor, operacores de asignacion,incremento, decremento y comparación e inicio y fin.
     */
     class Iterator{
     private:
         map<char,LetterInfo >::iterator it;
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
         * @return letra  del set
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
      * @brief TDA  ConstIterator
      * @details Clase que sirve para iterar sobre el TDA LettersSet
      *Las principales funciones que tiene son, el Constructor,Destructor, operacores de asignacion,incremento, decremento y comparación e inicio y fin.
      */
     class ConstIterator{
     private:
         map<char,LetterInfo >::const_iterator it;
     public:
         /**
         * @brief Constructor por defecto
         */
         ConstIterator(){};
         /**
         *@brief constructor de copia
         * @param it iterador a copiar
         */
         ConstIterator(ConstIterator &it){};
         /**
         * @brief Destructor de la clase
         */
         ~ConstIterator();
         /**
         * @brief Operador de asignacion
         * @param it iterador qeu deseamos asignar
         * @return iterador a concatenar con el operador =
         */
         ConstIterator operator=(ConstIterator &it){};
         /**
         * @brief Operador puntero
         * @return letra palabra del set
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
