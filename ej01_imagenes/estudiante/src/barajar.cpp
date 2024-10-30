//
// Created by carlos on 25/10/22.
//

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <image.h>
#include <ctime>
#include <iomanip>

using namespace std;

void test_rows()
{
    const int ncols = 500;
    clock_t tini, tfin;
    int nrows;

    for(nrows=1; nrows<500; ++nrows)
    {
        Image img(nrows, ncols);
        tini = clock();
        img.ShuffleRows();
        tfin = clock();

        cout << setprecision(10) << "Numero de filas: " << nrows << "\t" << ((double)tfin - (double)tini) / (double)CLOCKS_PER_SEC << " seg.@\n";

    }
}

void test_cols()
{
    const int nrows = 500;
    clock_t tini, tfin;
    int ncols;

    for(ncols=1; ncols<500; ++ncols)
    {
        Image img(nrows, ncols);
        tini = clock();
        img.ShuffleRows();
        tfin = clock();

        cout << setprecision(10) << "Numero de columnas: " << ncols << "\t" << ((double)tfin - (double)tini) / (double)CLOCKS_PER_SEC << " seg.@\n";
    }
}

void test_calls(Image image)
{
    int i=0;
    clock_t tini, tfin;

    for(int j=0; j<1000;j+=100)
    {
        tini = clock();
        while(i<j)
        {
            image.ShuffleRows();
            i++;
        }
        tfin = clock();

        cout << "Numero de llamadas: " << j << "\t" << (double)(tfin-tini) << " ms.\n";
    }
}

int main(int argc, char *argv[])
{
    char *origen, *destino; // nombres de los ficheros
    Image image;

    //Comprobar llamada
    if (argc != 3){
        cerr << "Error: Numero incorrecto de parametros.\n";
        cerr << "Uso: barajar <FichImagenOriginal> <FichImagenDestino>\n";
        exit (1);
    }

    //Obtener y mostrar argumentos
    origen = argv[1];
    destino = argv[2];

    cout << "Fichero origen: " << origen << endl;
    cout << "Fichero resultado: " << destino << endl;

    //Leer la imagen del fichero de entrada
    if (!image.Load(origen)){
        cerr << "Error: No pudo leerse la imagen." << endl;
        cerr << "Terminando la ejecucion del programa." << endl;
        return 1;
    }

    //Parametros de imagen
    cout << endl;
    cout << "Dimensiones de " << origen << ":" << endl;
    cout << " Imagen = " << image.get_rows() << " filas x " << image.get_cols() << " columnas " << "\n";

    int n_test;

    cout << "Escoje test (0 para pasar): "; cin >> n_test;
    switch(n_test) {
        case 0:
            cout << "Saliendo del programa" << "\n";
            break;
        case 1:
            test_rows();
            break;
        case 2:
            test_cols();
            break;
        case 3:
            test_calls(image);
            break;
        default:
            cout << "Opcion incorrecta" << "\n";
            cout << "Saliendo del programa" << "\n";
            break;

    }

    // Barajar la imagen
    image.ShuffleRows();

    // Guardar la imagen resultado en el fichero
    if (image.Save(destino))
        cout << "La imagen se guardo en " << destino << endl;

    else
    {
        cerr << "Error: No pudo guardarse la imagen." << endl;
        cerr << "Terminando la ejecucion del programa." << endl;
        return 1;
    }
    return 0;
}

