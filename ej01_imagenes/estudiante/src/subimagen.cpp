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
    int ncol,nrow,height,width;
    // Comprobar validez de la llamada
    if (argc != 7){
        cerr << "Error: Numero incorrecto de parametros.\n";
        cerr << "Uso: subimagen <FichImagenOriginal> <FichImagenDestino>\n";
        exit (1);
    }

    // Obtener argumentos
    origen  = argv[1];
    destino = argv[2];
    nrow= atoi(argv[3]);
    ncol= atoi(argv[4]);
    height= atoi(argv[5]);
    width= atoi(argv[6]);
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

    //Obtengo la subimagen
    cout<<"____________________________________________________"<<endl;
    Image image_n;
    image_n=image.Crop(nrow,ncol,height,width);
    cout<<"____________________________________________________"<<endl;

    // Mostrar los parametros de la Imagen
    cout << endl;
    cout << "Dimensiones de " << origen << ":" << endl;
    cout << "   Imagen   = " << image.get_rows()  << " filas x " << image.get_cols() << " columnas " << endl;


    // Guardar la imagen resultado en el fichero
    if (image_n.Save(destino))
        cout  << "La imagen se guardo en " << destino << endl;
    else{
        cerr << "Error: No pudo guardarse la imagen." << endl;
        cerr << "Terminando la ejecucion del programa." << endl;
        return 1;
    }
}