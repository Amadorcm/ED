/**
 * @file maxqueue.cpp
 * @brief  Archivo de implementación del TDA MaxQueue
 * @author Carlos Roman Alvarez
 * @author Amador Carmona Mendez
 */

#include "maxqueue.h"
ostream & operator <<(ostream & os, const element & elemento){
    return os<< elemento.value << "," << elemento.maximum;
}

MaxQueue::MaxQueue(){}

MaxQueue::MaxQueue(MaxQueue & q) {
    //cout<<"copia";
    if(!q.empty()){
        stack<element> aux;
        while(q.pilaMax.size()!=0){
            aux.push(q.pilaMax.top());
            q.pilaMax.pop();
        }
        while(q.pilaMax.size()!=0){
            pilaMax.push(aux.top());
            //cout<<"COPIA: "<<aux.top()<<endl;
            aux.pop();
        }
        //cout<<"copia";
    }
}


void MaxQueue::push(int num){
    element aux;
    stack<element>pilaAux;
    //cout<<"1111";
    aux.value = num;
    //cout<<"NUMERO:"<<num<<endl;
    if(pilaMax.empty()){
        aux.maximum = num;
        pilaMax.push(aux);
    }else{

        aux.value = num;

        aux.maximum = maximo(num);

        pilaMax.push(aux);

        while(!pilaMax.empty()){
            pilaAux.push(pilaMax.top());
            //cout<<"_____Invertido:"<<pilaMax.top()<<endl;
            pilaMax.pop();
        }

        pilaMax.swap(pilaAux);

    }


}

void MaxQueue::pop(){
    int num;
    //cout<<"POP:"<<pilaMax.top()<<endl;
    stack<element>pilaAux;
    element auxpm=pilaMax.top();
    pilaMax.pop();
    if(auxpm.maximum==auxpm.value){
        popmaximo();
    }
    element aux;

    while(!pilaMax.empty()){
        aux=pilaMax.top();
        pilaAux.push(aux);
        //cout<<aux<<"   ";
        pilaMax.pop();
    }
    //pilaAux.pop();
    //cout<<"aAaAAAaA"<<endl;
    pilaMax.swap(pilaAux);

    while(!pilaMax.empty()){
        pilaAux.push(pilaMax.top());
        //cout<<"POP invert:      "<<pilaMax.top()<<endl;
        pilaMax.pop();
    }

    pilaMax.swap(pilaAux);
    //this->imprimir();





}

bool MaxQueue::empty(){
    return pilaMax.empty();
}

element MaxQueue::back(){
    return pilaMax.top();
}

element MaxQueue::front(){
    /*stack<element> aux(pilaMax);
    while(aux.size()!=1){
        aux.pop();
    }
    //cout<<aux.top();*/
    return pilaMax.top();

}

int MaxQueue::size(){
    return pilaMax.size();
}
 int MaxQueue::maximo(int num) {
    element aux,aux2;
    stack<element>pilaAux;
    aux = pilaMax.top();
     //this->imprimir();
     //cout<<"Tamañoooooo"<<pilaMax.size()<<endl;
    if(aux.maximum<=num){
        while(!pilaMax.empty()){
            aux2=pilaMax.top();
            //cout<<"ElementoM :"<<aux2<<endl;
            pilaMax.pop();
            aux2.maximum=num;
            pilaAux.push(aux2);
        }

        while(!pilaAux.empty()){
            pilaMax.push(pilaAux.top());
            //cout<<"Elemento_ :"<<pilaAux.top()<<endl;
            pilaAux.pop();
        }
        pilaAux.swap(pilaMax);
        while(!pilaAux.empty()){
            pilaMax.push(pilaAux.top());
            //cout<<"Elemento pila inverso:"<<pilaAux.top()<<endl;
            pilaAux.pop();
        }

        return num;

    }else{
        while(!pilaAux.empty()){
            pilaMax.push(pilaAux.top());
            //cout<<"Elemento_ :"<<pilaAux.top()<<endl;
            pilaAux.pop();
        }
        pilaAux.swap(pilaMax);
        while(!pilaAux.empty()){
            pilaMax.push(pilaAux.top());
            //cout<<"Elemento pila inverso:"<<pilaAux.top()<<endl;
            pilaAux.pop();
        }
        return aux.maximum;
    }
}
void MaxQueue::popmaximo(){
    element aux,aux2;
    stack<element>pilaAux;
    stack<element>pilaAux2;
    //aux = pilaMax.top();
        while(!pilaMax.empty()){
            aux2=pilaMax.top();
            //cout<<"Elemento :"<<aux2<<endl;
            pilaMax.pop();
            aux2.maximum=-9999;
            //cout<<"Elemento :"<<aux2<<endl;
            pilaAux.push(aux2);
            pilaAux2.push(aux2);
        }
        pilaMax.swap(pilaAux);
        //cout<<"HOLA";
        while(!pilaAux2.empty()){
            //cout<<"pilaMax:"<<pilaAux2.size();
            aux2=pilaAux2.top();
            //cout<<"Elemento 1:"<<aux2<<endl;
            aux2.maximum=maximo(aux2.value);

            pilaAux.push(aux2);

            pilaAux2.pop();
            //this->imprimir();


        }
        pilaMax.swap(pilaAux);
        //this->imprimir();
        pilaAux.swap(pilaAux2);
        while(!pilaAux.empty()){
            pilaMax.push(pilaAux.top());
            //cout<<"Elemento_ :"<<pilaAux.top()<<endl;
            pilaAux.pop();
        }
        /*pilaAux.swap(pilaMax);
        while(!pilaAux.empty()){
            pilaMax.push(pilaAux.top());
            //cout<<"Elemento pila inverso:"<<pilaAux.top()<<endl;
            pilaAux.pop();
        }*/

}
void MaxQueue::imprimir(){
    stack<element>pilaAux;
    pilaAux.swap(pilaMax);
    cout<<"COLA__________"<<endl;
    while(!pilaAux.empty()){
        cout<<pilaAux.top()<<endl;
        pilaMax.push(pilaAux.top());
        pilaAux.pop();
    }
    cout<<"FIN__________"<<endl;
    while(!pilaMax.empty()){
        pilaAux.push(pilaMax.top());
        pilaMax.pop();
    }
    pilaMax.swap(pilaAux);

}

