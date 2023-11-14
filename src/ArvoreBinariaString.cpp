#include "ArvoreBinariaString.h"
#include <iostream>

//construtor: inicializa raiz como NULL
ArvoreBinaria::ArvoreBinaria(){
    raiz = NULL;
}

//destrutor: chama a função Limpa
ArvoreBinaria::~ArvoreBinaria(){
    Limpa();
}

//insere um nó chamando a função InsereRecursivo
void ArvoreBinaria::Insere(TipoNo* no){
    InsereRecursivo(raiz, no);
}

//faz chamadas recursivas comparando o valor de key até achar as folhas
void ArvoreBinaria::InsereRecursivo(TipoNo* &p, TipoNo* no){
    if(p==NULL){
        p = new TipoNo();
        p->item = no->item;
        p->key = no->key;
        p->value = no->value;
    }
    else{
        if(no->key < p->key){
            InsereRecursivo(p->esq, no);
        }
        else{
            InsereRecursivo(p->dir, no);
        }
    }
}

//limpa a árvore chamando a função ApagaRecursivo
void ArvoreBinaria::Limpa(){
    ApagaRecursivo(raiz);
    raiz = NULL;
}

//apaga os nós da árvore fazendo o caminhamento Pos-Ordem
void ArvoreBinaria::ApagaRecursivo(TipoNo *p){
    if(p!=NULL){
        ApagaRecursivo(p->esq);
        ApagaRecursivo(p->dir);
        delete p;
    }
}