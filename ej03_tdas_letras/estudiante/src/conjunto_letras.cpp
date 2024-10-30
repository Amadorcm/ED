/**
 * @file conjunto_letras.cpp
 * @brief  Archivo de uso del TDA LettersSet
 * @author Carlos Roman Alvarez
 * @author Amador Carmona Mendez
 */
/*Para probar el funcionamiento de nuestro TDA, vamos a implementar un pequeño programa que recibirá dos argumentos:
1. Ruta al archivo con información sobre el conjunto de letras
2. Palabra de la que calcular la puntuación
E imprimirá por pantalla la puntuación de dicha palabra.*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>
#include "letters_set.h"
using namespace std;

int main(int argc, char *argv[])
{
    if(argc!=3){
        cout<<"Error en el numero de parametros";
        return EXIT_FAILURE;
    }else{
        //cogemos la palabra y abrimos el fichero
        string palabra;
        ifstream fichero;
        palabra=argv[2];
        fichero.open(argv[1]);
        // Inicializamos el generador de números aleatorios
        srand(time(NULL));
        //Creamos el conjunto de letras
        LettersSet con_letras;
        if(fichero.is_open()){
            fichero>>con_letras;
        }else {
            cout << "No se puede abrir el archivo" << endl;
            return EXIT_FAILURE;
        }

        fichero.close();
        unsigned int score=0;
        score=con_letras.getScore(palabra);
        //cout<<"La puntuación de la palabra :"<<palabra<<" es: "<<score<<endl;
        cout<<palabra<<"\t"<<score<<endl;
        return EXIT_SUCCESS;
    }

}