/**
 * @file letters_set.cpp
 * @brief  Archivo de uso e implementación del TDA LettersSet
 * @author Carlos Roman Alvarez
 * @author Amador Carmona Mendez
 */
#include "letters_set.h"

    LettersSet::LettersSet(){};

    LettersSet::LettersSet(LettersSet &l){
        letras=l.letras;
    };

     bool LettersSet::insert(const pair<char,LetterInfo> &l){
         letras.insert(l);
     };

     bool LettersSet::erase(const char &key){
         letras.erase(key);
     };

     void LettersSet::clear(){
         letras.clear();
     };

     bool LettersSet::empty()const{
         return letras.empty();
     };

     unsigned int LettersSet::size(){
         return letras.size();
     };

     unsigned int LettersSet::getScore(string word){};

    LettersSet::~LettersSet(){};

     LettersSet &LettersSet::operator =(const LettersSet &cl){
         //if(this!=cl){ //hay que sobrecargar el operador != para LettersSet
             letras=cl.letras;
         //}
         return *this;
     };

     LetterInfo &LettersSet::operator [](const char &key){
         return letras[key];
     };

     ostream &LettersSet::operator <<(ostream &os, const LettersSet &cl){

     };

     istream &LettersSet::operator>>(istream &is, const LettersSet &cl){};

