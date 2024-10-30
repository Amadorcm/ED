/**
 * @file cantidad_letras.cpp
 * @brief  Archivo de uso del TDA Dictionary
 * @author Carlos Roman Alvarez
 * @author Amador Carmona Mendez
 */
#include "dictionary.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>
#include "letters_set.h"

using namespace std;
/*El segundo de ellos, cantidad_letras.cpp, recibe dos argumentos
1. Un fichero con las palabras de un diccionario
2. Un fichero de letras
Construye un Dictionary con el fichero de palabras, un LettersSet con el fichero de letras,
e imprime por pantalla, para cada letra en el LettersSet, el número de ocurrencias de la letra
en el diccionario y su frecuencia relativa (es decir, el número total de ocurrencias de la letra
entre el número total de letras en el diccionario).
*/
int main(int argc, char *argv[])
{
    if(argc!=3){
        cout<<"Error en el numero de parametros";
        return EXIT_FAILURE;
    }else{
        ifstream fichero1(argv[1]);
        Dictionary d;
        string palabra;
        //asignar d al fichero
        if(fichero1.is_open()){
            while(getline(fichero1,palabra)){
                d.insert(palabra);
            }
        }else {
            cout << "No se puede abrir el archivo" << endl;
            return EXIT_FAILURE;
        }
        fichero1.close();
        LettersSet conjunto;
        ifstream fichero2(argv[2]);
        fichero2>>conjunto;
        for(LettersSet::ConstIterator i = conjunto.cbegin(); i != conjunto.cend(); ++i){
            //cout<<*i->first<<"\t"<<d.getOcurrences(*i->first);
        }
        return EXIT_SUCCESS;
    }
}