/**
 * @file maxstack.cpp
 * @brief  Archivo de implementación del TDA MaxStack
 * @author Carlos Roman Alvarez
 * @author Amador Carmona Mendez
 */

#include <queue>
#include <iostream>
#include <maxstack.h>

using namespace std;

ostream & operator <<(ostream & os, const element & elemento){
    return os<< elemento.value << "," << elemento.maximum;
}
MaxStack::MaxStack(){}
element MaxStack::top()
{
    return max_queue.front();
}

void MaxStack::pop()
{
    max_queue.pop();
}

int MaxStack::size()
{
    return max_queue.size();
}

bool MaxStack::empty()
{
    return max_queue.empty();
}

void MaxStack::push(int num)
{
    element aux;
    aux.value = num;
    if(max_queue.empty())   aux.maximum = num;
    else    aux.maximum = maximo(num);
    queue<element> queueAux;
    queueAux.push(aux);
    while( !max_queue.empty() ){
        queueAux.push(max_queue.front());
        max_queue.pop();
    }
    max_queue.swap(queueAux);
}

int MaxStack::maximo(int num)
{
    if(num > top().maximum) return num;
    else return top().maximum;

}


