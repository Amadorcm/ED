/**
 * @file bag.cpp
 * @brief  Archivo de uso e implementación del TDA Bag
 * @author Carlos Roman Alvarez
 * @author Amador Carmona Mendez
 */
#include "bag.h"
template <class T>
Bag<T>::Bag(){};
template <class T>
Bag<T>::Bag(Bag<T> &b){
    bolsa=b.bolsa;
};
template <class T>
void Bag<T>::add(const T &element){
    bolsa.push_back(element);
};
template <class T>
T Bag<T>::get(){
    srand(time(NULL));
    int num = rand()%bolsa.size();
    T n=bolsa[num];
    bolsa.erase(num);
    return n;
};
template <class T>
void Bag<T>::clear(){
    bolsa.clear();
};
template <class T>
unsigned int Bag<T>::size(){
    return bolsa.size();
};
template <class T>
bool Bag<T>::empty(){
    return bolsa.empty();
};
template <class T>
const Bag<T> & Bag<T>::operator=(const Bag<T> &otro){
    if(bolsa!=otro.bolsa){
        bolsa=otro.bolsa;
    }
    return this;
};