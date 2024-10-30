/**
 * @file dictionary.cpp
 * @brief  Archivo de implementación del TDA Dictionary
 * @author Carlos Roman Alvarez
 * @author Amador Carmona Mendez
 */
#include "dictionary.h"

Dictionary::Dictionary(){};

Dictionary::Dictionary(Dictionary &d){
    palabras=d.palabras;
};

bool Dictionary::exist(const string &val){

};

bool Dictionary::insert(const string &val){
    //el insert en el set devuelve un par con el booleano y el iterador
    return palabras.insert(val).second;
};

bool Dictionary::erase(const string &val){
    return palabras.erase(val);
};

void Dictionary::clear(){
    palabras.clear();
};

bool Dictionary::empty()const{
    return palabras.empty();
};

unsigned int Dictionary::size()const{
    return palabras.size();
};

int Dictionary::getOcurrences(const char c){

};

int Dictionary::getTotalLetters(){

};

vector<string> Dictionary::wordsOfLength(int length){

};
