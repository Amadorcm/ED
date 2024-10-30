// Fichero: subimagen.cpp
// Calcula la subimagen de una imagen PGM
//

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <image.h>
using namespace std;
int main(int argc, char *argv[]){
    char *origen, *destino; // nombres de los ficheros
    Image image;
    int a1,a2,a3,a4;
    // Comprobar validez de la llamada
    if (argc != 7){
        cerr << "Error: Numero incorrecto de parametros.\n";
        cerr << "Uso: contraste <FichImagenOriginal> <FichImagenDestino>\n";
        exit (1);
    }

    // Obtener argumentos
    origen  = argv[1];
    destino = argv[2];
    a1= atoi(argv[3]);
    a2= atoi(argv[4]);
    a3= atoi(argv[5]);
    a4= atoi(argv[6]);
    // Mostramos argumentos
    cout << endl;
    cout << "Fichero origen: " << origen << endl;
    cout << "Fichero resultado: " << destino << endl;

    // Leer la imagen del fichero de entrada
    if (!image.Load(origen)){
        cerr << "Error: No pudo leerse la imagen." << endl;
        cerr << "Terminando la ejecucion del programa." << endl;
        return 1;
    }

    //Obtengo la imagen con el ajuste de contraste
    cout<<"____________________________________________________"<<endl;
    Image image_n;
    image.AdjustContrast(a1,a2,a3,a4);
    cout<<"____________________________________________________"<<endl;

    // Mostrar los parametros de la Imagen
    cout << endl;
    cout << "Dimensiones de " << origen << ":" << endl;
    cout << "   Imagen   = " << image.get_rows()  << " filas x " << image.get_cols() << " columnas " << endl;


    // Guardar la imagen resultado en el fichero
    if (image.Save(destino))
        cout  << "La imagen se guardo en " << destino << endl;
    else{
        cerr << "Error: No pudo guardarse la imagen." << endl;
        cerr << "Terminando la ejecucion del programa." << endl;
        return 1;
    }
}