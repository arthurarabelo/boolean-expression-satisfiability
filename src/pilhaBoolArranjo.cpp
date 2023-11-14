#include "pilhaBoolArranjo.h"
#include <iostream>

using namespace std;

//construtor: inicializa topo com -1 e tamanho com 0
PilhaBoolArranjo::PilhaBoolArranjo(){
    topo = -1;
    tamanho = 0;
}

//insere elemento no topo da pilha e atualiza variáveis topo e tamanho
void PilhaBoolArranjo::Empilha(bool item){
    //verifica se a pilha já atingiu o tamanho máximo
    if(tamanho == MAXTAM){
        ExcecaoPilhaCheia e;
        cerr << "Pilha cheia." << endl;
        throw e;
    }

    topo++;
    itens[topo] = item;
    tamanho++;
}

//retira o último elemento da pilha e retorna seu valor
bool PilhaBoolArranjo::Desempilha(){
    bool aux;

    //verifica se a pilha está sem elementos
    if(this->Vazia()){
        ExcecaoPilhaVazia e;
        cerr << "Pilha vazia." << endl;
        throw e;
    }

    aux = itens[topo];
    topo--;
    tamanho--;
    return aux;
}

//seta topo e tamanho com seus valores iniciais
void PilhaBoolArranjo::Limpa(){
    topo = -1;
    tamanho = 0;
}

//retorna o valor do topo da pilha
bool PilhaBoolArranjo::GetTopo(){
    if(this->Vazia()){
        //testa se pilha está vazia
        ExcecaoPilhaVazia e;
        cerr << "Pilha vazia." << endl;
        throw e;
    }

    return itens[topo];
}