/**
 * @file cola_max.cpp
 * @brief  Archivo de implementacion y uso del TDA MaxQueue y que genera el ejecutable
 * Trabaja con el numero de parametros que le pasamos, cada numero lo inserta en la cola, cada punto saca un elemento de la cola
 * @author Carlos Roman Alvarez
 * @author Amador Carmona Mendez
 */
#include "maxqueue.h"

using namespace std;

int main(int argc, char *argv[]){
     // Run the current exercise
     MaxQueue queue;
     //queue.push(1);
     //cout<<queue.front();
     //cout<<"________1"<<endl;
     for(int i = 1; i < argc; i++){
        if (argv[i][0] == '.'){
            //cout<<"________"<<endl;
             cout <<queue.front() << endl;
             queue.pop();
             //queue.imprimir();
        }else{
            //cout<<"INSERTO"<<atoi(argv[i])<<endl;
            queue.push(atoi(argv[i]));
            //queue.imprimir();

        }
     }
     return 0;
}
