#include "TipoNoString.h"
#include <iostream>
#include <string>

//construtor: incializa os elementos da esquerda e direita como NULL
TipoNo::TipoNo(){
    esq = NULL;
    dir = NULL;
}

//atribui um item de tipo string ao nó
void TipoNo::SetItem(std::string i){
    this->item = i;
}

//retorna o item do nó
std::string TipoNo::GetItem(){
    return this->item;
}

//atribui um valor de tipo booleano ao nó
void TipoNo::SetValue(bool value){
    this->value = value;
}

//retorna o valor do nó
bool TipoNo::GetValue(){
    return this->value;
}

//atribui uma chave de tipo int ao nó
void TipoNo::SetKey(int key){
    this->key = key;
}

//retorna a chave do nó
int TipoNo::GetKey(){
    return this->key;
}


