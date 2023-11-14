#ifndef TIPO_NO_STRING_H
#define TIPO_NO_STRING_H

#include <string>

//define classe TipoNo com item de tipo string
//os elementos da classe ArvoreBinariaString são de TipoNoString
class TipoNo{
public:
    TipoNo();
    void SetItem(std::string i);
    void SetKey(int key);
    void SetValue(bool value);
    std::string GetItem();
    bool GetValue();
    int GetKey();

private:
    std::string item; //valor principal do nó
    TipoNo *esq;
    TipoNo *dir;
    bool value; //valor booleano do nó, que será usado no problema da satisfabilidade
    int key; //chave a ser comparada no método de inserção da árvore
    friend class ArvoreBinaria;
};

#endif