/**
 * @file image.cpp
 * @brief Fichero con definiciones para los métodos primitivos de la clase Image
 *
 */

#include <cstring>
#include <cassert>
#include <iostream>
#include <math.h>
#include <image.h>
#include <imageIO.h>

using namespace std;

/********************************
      FUNCIONES PRIVADAS
********************************/
void Image::Allocate(int nrows, int ncols, byte * buffer){
    rows = nrows;
    cols = ncols;

    img = new byte * [rows];

    if (buffer != 0)
        img[0] = buffer;
    else
        img[0] = new byte [rows * cols];

    for (int i=1; i < rows; i++)
        img[i] = img[i-1] + cols;
}

// Función auxiliar para inicializar imágenes con valores por defecto o a partir de un buffer de datos
void Image::Initialize (int nrows, int ncols, byte * buffer){
    if ((nrows == 0) || (ncols == 0)){
        rows = cols = 0;
        img = 0;
    }
    else Allocate(nrows, ncols, buffer);
}

// Función auxiliar para copiar objetos Imagen

void Image::Copy(const Image & orig){
    Initialize(orig.rows,orig.cols);
    for (int k=0; k<rows*cols;k++)
        set_pixel(k,orig.get_pixel(k));
}

// Función auxiliar para destruir objetos Imagen
bool Image::Empty() const{
    return (rows == 0) || (cols == 0);
}

void Image::Destroy(){
    if (!Empty()){
        delete [] img[0];
        delete [] img;
    }
}

LoadResult Image::LoadFromPGM(const char * file_path){
    if (ReadImageKind(file_path) != IMG_PGM)
        return LoadResult::NOT_PGM;

    byte * buffer = ReadPGMImage(file_path, rows, cols);
    if (!buffer)
        return LoadResult::READING_ERROR;

    Initialize(rows, cols, buffer);
    return LoadResult::SUCCESS;
}

/********************************
       FUNCIONES PÚBLICAS
********************************/

// Constructor por defecto

Image::Image(){
    Initialize();
}

// Constructores con parámetros
Image::Image (int nrows, int ncols, byte value){
    Initialize(nrows, ncols);
    for (int k=0; k<rows*cols; k++) set_pixel(k,value);
}

bool Image::Load (const char * file_path) {
    Destroy();
    return LoadFromPGM(file_path) == LoadResult::SUCCESS;
}

// Constructor de copias

Image::Image (const Image & orig){
    assert (this != &orig);
    Copy(orig);
}

// Destructor

Image::~Image(){
    Destroy();
}

// Operador de Asignación

Image & Image::operator= (const Image & orig){
    if (this != &orig){
        Destroy();
        Copy(orig);
    }
    return *this;
}

// Métodos de acceso a los campos de la clase

int Image::get_rows() const {
    return rows;
}

int Image::get_cols() const {
    return cols;
}

int Image::size() const{
    return get_rows()*get_cols();
}

// Métodos básicos de edición de imágenes
void Image::set_pixel (int i, int j, byte value) {
    img[i][j] = value;
}
byte Image::get_pixel (int i, int j) const {
    return img[i][j];
}

// This doesn't work if representation changes
void Image::set_pixel (int k, byte value) {
    // TODO this makes assumptions about the internal representation
    // TODO Can you reuse set_pixel(i,j,value)?
    img[0][k] = value;
}

// This doesn't work if representation changes
byte Image::get_pixel (int k) const {
    // TODO this makes assumptions about the internal representation
    // TODO Can you reuse get_pixel(i,j)?
    return img[0][k];
}

// Métodos para almacenar y cargar imagenes en disco
bool Image::Save (const char * file_path) const {
    // TODO this makes assumptions about the internal representation
    byte * p = img[0];
    return WritePGMImage(file_path, p, rows, cols);
}

//Metodo ejercicio1
Image Image::Crop(int nrow, int ncol, int height, int width) const{
    Image nueva(height,width);

    for(int i=0;i<height;i++){

        for(int j=0;j< width;j++) {
            byte val;
            val = get_pixel(nrow+i, ncol+j);
            //cout<<val<<endl;
            nueva.set_pixel(i, j, val);
        }
    }
    //cout<<"-------------hecho"<<endl;
    return nueva;
}

//funcion Ejercicio2
Image Image::Zoom2X(int fila,int columna, int n) const{
    Image nueva(n*2-1,n*2-1);
    int ii=0,jj=0;
    float media;
    byte val;
    //rellenamos los pares de la matriz con los valores del tramo original
    for(int i=0; i<n*2-1;i+=2){
        jj=0;
        for(int j=0; j<n*2-1;j+=2){
            val=get_pixel(fila+ii,columna+jj);
            nueva.set_pixel(i,j, val);
            jj++;
        }
        ii++;
    }
    //interpolamos horizontalmente
    ii=0;
    for(int i=0; i<n*2-1;i+=2){
        jj=0;
        for(int j=1; j<n*2-1;j+=2){
            media=(float)round((get_pixel(fila+ii,columna+jj)+get_pixel(fila+ii,columna+1+jj))/2);
            val=(byte) media;
            nueva.set_pixel(i,j, val);
            jj++;
        }
        ii++;
    }
    //
    for(int i=1; i<n*2-1;i+=2){
        for(int j=1; j<n*2-1;j++){
            if((j+1)%2!=0){//los impares los relleno
                media=(float)round((nueva.get_pixel(i+1,j)+nueva.get_pixel(i-1,j))/2);
                val=(byte) media;
                nueva.set_pixel(i,j, val);
            }else{//relleno los que son entre 4
                media=round(nueva.get_pixel(i-1,j-1)+nueva.get_pixel(i+1,j-1)+nueva.get_pixel(i-1,j+1)+nueva.get_pixel(i+1,j+1))/4;
                val=(byte)media;
                nueva.set_pixel(i,j,val);
            }
        }
    }

    return nueva;
}

//funcion ejercicio 3
Image Image::Subsample(int factor) const{
    int col,fil;
    float media=0;
    col=get_cols()/factor;
    fil=get_rows()/factor;
    Image nueva(col,fil);
    //recorro la imagen nueva para ir asignandoles sus medias correspondientes
    for(int i=0; i<fil; i++){
        for(int j=0;j<col;j++){
        media=0;
            //calculo las medias correspondientes para cada valor
            for(int z=0;z < factor;z++){
                for(int k=0;k < factor; k++){
                    media += (float)get_pixel(z + factor * i, k + factor * j);
                }
            }
            media=round(media/(float)(factor*factor));
            nueva.set_pixel(i,j,(byte)media);
        }
    }
    return nueva;
}

//funcion del ejercicio4
void Image::AdjustContrast(byte in1, byte in2, byte out1, byte out2){
    int col,fil;
    col=get_cols();
    fil=get_rows();
    //Image nueva(col,fil);
    if (0 <= (in1, in2, out1, out2) <= 255 && in1 < in2 && out1 < out2){
        float min, max, a, b; //valores de la formula
        for (int i=0; i<fil*col; i++){ //ajusto valores de la formula y la calculo para cada pixel
            byte p=get_pixel(i);
            if (0<=p && p<in1){//si el pixel esta entre 0 e in1
                a=0;
                b=(float)in1;
                min=0;
                max=(float)out1;
            }
            else if (in1<=p && p<=in2){//si esta el pixel entre in1 e in2
                a=(float)in1;
                b=(float)in2;
                min=(float)out1;
                max=(float)out2;
            }
            else if (in2<p && p<=255){//si el pixel esta entre in2 y 255 q es lo maximo
                a=(float)in2;
                b=255;
                min=(float)out2;
                max=255;
            }
            byte pn;
            pn=(byte)round((min + (((max - min) / (b - a)) * ((float)p - a))));
            set_pixel(i, pn);
        }
    }
}

void Image::ShuffleRows(){
    const int p = 9973;
    int nuevafila;
    // lo vamos a realizar con una matroz, o un puntero a punteros de bytes que es lo mismo
    byte ** nueva = new byte * [rows];
    // Barajamos y asignamos
    for (int r=0; r<rows; ++r) {
        nuevafila=(r*p)%rows;
        nueva[r]=img[nuevafila];
    }// le aplicamos el cambio a nuestra imagen despues de barajar
    img=nueva;
    nueva=NULL;
}
