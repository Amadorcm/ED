/**
 * @file palabras_longitud.cpp
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
#include <vector>

using namespace std;

/*El primero de ellos, palabras_longitud.cpp, recibe dos argumentos
1. Un fichero con las palabras de un diccionario
2. Un entero con la longitud de las palabras que buscamos
Construye un Dictionary con el fichero de las palabras, extrae de dicho diccionario
las palabras de la longitud que buscamos y las imprime por pantalla.*/
int main(int argc, char *argv[])
{
    if(argc!=3){
        cout<<"Error en el numero de parametros";
        return EXIT_FAILURE;
    }else{
        ifstream fichero(argv[2]);
        int longitud=atoi(argv[2]);
        Dictionary d;
        string palabra;
        //asignar d al fichero
        if(fichero.is_open()){
            while(getline(fichero,palabra)){
                d.insert(palabra);
            }
        }else {
            cout << "No se puede abrir el archivo" << endl;
            return EXIT_FAILURE;
        }
        fichero.close();
        vector<string> words;
        words=d.wordsOfLength(longitud);
        for(int i=0; i<words.size();i++){
            cout<<words[i]<<endl;
        }
        return EXIT_SUCCESS;
    }
}