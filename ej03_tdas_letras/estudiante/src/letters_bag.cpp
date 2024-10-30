/**
 * @file letters_bag.cpp
 * @brief  Archivo de implementación del TDA LettersBag
 * @author Carlos Roman Alvarez
 * @author Amador Carmona Mendez
 */
#include "letters_bag.h"

LettersBag::LettersBag(){};

LettersBag::LettersBag(LettersSet &l){
    //bolsaletras;
};

void LettersBag::insertLetter(const char letra){
    bolsaletras.add(letra);
};

char LettersBag::extractLetter(){
    return bolsaletras.get();
};

vector<char> LettersBag::extractLetters(int num){
    vector<char> let;
    for(int i=0; i<num; i++){
        let[i]=bolsaletras.get();
    }
    return let;
};

void LettersBag::clear(){
    bolsaletras.clear();
};

unsigned int LettersBag::size(){
    return bolsaletras.size();
};

LettersBag &LettersBag::operator=(const LettersBag &otro){
    if (this != &otro) {
        bolsaletras = otro.bolsaletras;
    }
    return *this;
};