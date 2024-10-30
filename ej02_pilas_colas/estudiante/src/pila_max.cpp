/**
 * @file pila_max.cpp
 * @brief  Archivo de implementacion y uso del TDA MaxStack y que genera el ejecutable
 * Trabaja con el numero de parametros que le pasamos, cada numero lo inserta en la pila, cada punto saca un elemento de la pila
 * @author Carlos Roman Alvarez
 * @author Amador Carmona Mendez
 */
#include <iostream>
#include "maxstack.h"

using namespace std;

int main(int argc, char *argv[]){

     // Run the current exercise
     MaxStack stack;
    for(int i = 1; i < argc; i++){
         if (argv[i][0] == '.'){
             cout << stack.top() << endl;
             stack.pop();
         } else {
             stack.push(atoi(argv[i]));
         }
     }
     return 0;
}
