#ifndef ARVORE_BINARIA_STRING_H
#define ARVORE_BINARIA_STRING_H

#include "TipoNoString.h"
#include <string>

//cada nó é da classe TipoNoString e possui um item do tipo string
class ArvoreBinaria{
    public:
        ArvoreBinaria();
        ~ArvoreBinaria();

        void Insere(TipoNo* no);
        void Caminha(int tipo);
        void Limpa();

    private:
        void InsereRecursivo(TipoNo* &p, TipoNo* no);
        void ApagaRecursivo(TipoNo* p);
        TipoNo* raiz;   
};


#endif