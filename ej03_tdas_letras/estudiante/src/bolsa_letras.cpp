/**
 * @file bolsa_letras.cpp
 * @brief  Archivo de uso del TDA LettersBag
 * @author Carlos Roman Alvarez
 * @author Amador Carmona Mendez
 */
#include "letters_bag.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>

using namespace std;
/*Para comprobar el funcionamiento de este TDA, implementaremos un programa de prueba que realice las siguientes operaciones:
- Cree un conjunto de letras (LettersSet), y lo rellene a partir de la información leída de un archivo.
- Cree una bolsa de letras (LettersBag), y la rellene con la información del LettersSet anterior
- Extraiga todas las letras de la LettersBag (aleatoriamente) y las imprima por pantalla.*/

int main(int argc, char *argv[]) {
    srand(time(NULL));

    if (argc != 2) {
        cout << "Numero incorrecto de argumentos" << endl;
        return EXIT_FAILURE;
    }else{

        LettersSet letras;
        ifstream fichero;
        //pasamos el fichero a letras
        fichero.open(argv[1]);
        if (fichero.is_open()) {
            fichero >> letras;
        }else {
            cout << "No se puede abrir el archivo" << endl;
            return EXIT_FAILURE;
        }
        fichero.close();
        //creamos la bolsa
        LettersBag bolsa(letras);
        //sacamos las letras
        for (int i = 0; i < bolsa.size(); i++) {
            cout << bolsa.extractLetter() << endl;
        }

        return EXIT_SUCCESS;
    }
}