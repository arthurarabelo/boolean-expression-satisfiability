#ifndef PILHA_BOOL_ARRANJO_H
#define PILHA_BOOL_ARRANJO_H

class PilhaBoolArranjo{
    public:
        PilhaBoolArranjo();
        int GetTamanho() {return tamanho;} //retorna o tamanho da pilha
        bool Vazia() {return tamanho == 0;} //retorna 1 se a pilha estiver vazia
        void Empilha(bool c);
        bool Desempilha();
        void Limpa();
        bool GetTopo();

        //declaração dos structs das exceções
        struct ExcecaoPilhaCheia{};
        struct ExcecaoPilhaVazia{};

    protected:
        int tamanho;
        int topo;
        static const int MAXTAM = 100; //define o tamanho máximo da pilha
        bool itens[MAXTAM]; //declara vetor de itens da pilha com tipo bool
};

#endif