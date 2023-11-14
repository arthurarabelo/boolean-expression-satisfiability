#ifndef PILHA_CHAR_ARRANJO_H
#define PILHA_CHAR_ARRANJO_H

class PilhaCharArranjo{
    public:
        PilhaCharArranjo();
        int GetTamanho() {return tamanho;} //retorna o tamanho da pilha
        bool Vazia() {return tamanho == 0;} //retorna 1 se a pilha estiver vazia
        void Empilha(char c);
        char Desempilha();
        void Limpa();
        char GetTopo();

        //declaração dos structs das exceções
        struct ExcecaoPilhaCheia{}; 
        struct ExcecaoPilhaVazia{};

    protected:
        int tamanho;
        int topo;
        static const int MAXTAM = 1000000; //define o tamanho máximo da pilha
        char itens[MAXTAM]; //declara vetor de itens da pilha com tipo bool
};

#endif