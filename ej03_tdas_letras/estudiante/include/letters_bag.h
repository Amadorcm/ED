/**
 * @file letters_bag.h
 * @brief  Archivo de especificación del TDA LettersBag
 * @author Carlos Roman Alvarez
 * @author Amador Carmona Mendez
 */
#ifndef __LETTERS_BAG_H__
#define __LETTERS_BAG_H__
#include "bag.h"
#include "letters_set.h"
#include<iostream>
using namespace std;
/**
 * @brief TDA LettersBag
 *
 * Este TDA almacena un conjunto de chars utilizado en el juego de letras.
 * La estructura de datos subyacente es una lista de chars.
 */
 class LettersBag{
 private:
     Bag<char> bolsaletras;
 public:
     /**
     * @brief Constructor de la clase por defecto
     */
     LettersBag();
     /**
     * @brief Constructor dado un LettersSet, con el contenido del LettersSet dado se tiene que rellenar la bolsa de letras introduciendo cada letra el numero de veces dado por las repeticiones en el letterset
     * @param l letterset con el contenido de las letras a rellenar la bolsa
     */
     LettersBag(LettersSet &l);
     /**
     * @brief Introduce una letra en la bolsa
     * @param letra letra a introducir en la bolsa
     */
     void insertLetter(const char letra);
     /**
     * @brief Extrae una letra aleatoria de la bolsa, eliminandola de esta.
     * @return Char que representa la letra extraida de la bolsa
     */
     char extractLetter();
     /**
     * @brief Extrae un conjunto de letras aleatorias de la bolsa, eliminandolas de esta.
     * @param num numero de letras a extraer
      * @return Vector con todas las letras extraidas
     */
     vector<char> extractLetters(int num);
     /**
     * @brief Vacía la bolsa de letras
     */
     void clear();
     /**
     * @brief Consulta el tamaño de la bolsa de letras
     * @return Entero con el tamaño de la volsa de letras
     */
     unsigned int size();
     /**
     * @brief sobrecarga del operador =
     * @param otro lettersBag con el que encadenar el operador =
     * @return referencia a this para encadenarlo con el operador =
     */
     LettersBag &operator=(const LettersBag &otro);


 };

#endif
