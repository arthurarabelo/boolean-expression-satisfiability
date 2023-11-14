#include <iostream>
#include <getopt.h>
#include <string>
#include <stdbool.h>
#include "pilhaCharArranjo.h"
#include "pilhaBoolArranjo.h"
#include "ArvoreBinariaString.h"

using namespace std;

//declara struct para excecão de caractere inváldio
struct caractereInvalido{
    char op;
};

ArvoreBinaria arvoreSatisfabilidade;
string expressao;

//retorna a precedencia do operador
int precedencia(char operador){
    if(operador == '~') return 3;
    if(operador == '&') return 2;
    if(operador == '|') return 1;
    return 0;
}

//retorna 1 se o parâmetro o for um operador
bool operador(char o){
    if(o == '~' || o == '&' || o == '|'){
        return true;
    }
    return false;
}

//retorna o valor da expressão lógica
bool avaliaExpressao(string p, string s){
    PilhaCharArranjo operadores;
    PilhaBoolArranjo operandos;

    //loop que testa se há algum caractere inválido  ou quantificadores na string de valores
    for(long unsigned int i = 0; i < s.size(); i++){
        if(!isdigit(s[i]) && (s[i] != 'e') && (s[i] != 'a')){
            caractereInvalido e;
            e.op = s[i];
            throw e;
        }
        if(s[i] == 'e' || s[i] == 'a'){
            return 0;
        }
    }
    
    //loop que percorre a expressão p e trata do problema da precedência e das prioridades da expressão
    for(long unsigned int i = 0; i < p.size(); i++){
        if(p[i] == ' ') continue;

        if(p[i] == '('){
            operadores.Empilha(p[i]);
        }
        else if(p[i] == ')'){
            while(!operadores.Vazia() && operadores.GetTopo() != '('){
                char op = operadores.Desempilha();

                bool valor2 = operandos.Desempilha();
                
                if(op == '~'){
                    operandos.Empilha(!valor2);
                }
                else if(op == '&' || op == '|'){
                    bool valor1 = operandos.Desempilha();
                    if(op == '&') {
                        operandos.Empilha(valor1 && valor2);
                    }
                    if(op == '|') {
                        operandos.Empilha(valor1 || valor2);
                    }
                }
                
            }
            if(!operadores.Vazia() && operadores.GetTopo() == '('){
                operadores.Desempilha();
            }
        }
        else if(operador(p[i])){
            if(operador(p[i-2])){
                operadores.Empilha(p[i]);
                continue;
            }
            while(!operadores.Vazia() && precedencia(p[i]) <= precedencia(operadores.GetTopo())){
                char op = operadores.Desempilha();

                bool valor2 = operandos.Desempilha();
                
                if(op == '~'){
                    operandos.Empilha(!valor2);
                }
                else if(op == '&' || op == '|'){
                    bool valor1 = operandos.Desempilha();
                    if(op == '&') {
                        operandos.Empilha(valor1 && valor2);
                    }
                    if(op == '|') {
                        operandos.Empilha(valor1 || valor2);
                    }
                }
            }
            operadores.Empilha(p[i]);
        }
        else if(isdigit(p[i])){
            //"resgata" da expressão s o valor booleano do dígito da expressão p
            string digito;
            while(isdigit(p[i])){
                digito.push_back(p[i]);
                i++;
            }

            int digit = stoi(digito);

            bool boolean_value = (bool)(s[digit]-48);

            operandos.Empilha(boolean_value);
        }
        else if(p[i] == 0){
            break;
        }
        else{
            //lança o valor do respectivo caractere se houver a exceção caractereInvalido na expressão p 
            caractereInvalido e;
            e.op = p[i];
            throw e;
            return 0;
        }
    }

    //loop que resolve a expressão depois que todos os problemas de prioridade e precedência foram tratados
    while(!operadores.Vazia()){
        char op = operadores.Desempilha();
        
        bool valor2 = operandos.Desempilha();

        if(op == '~'){
            operandos.Empilha(!valor2);
        }
        else if(op == '&' || op == '|'){
            bool valor1 = operandos.Desempilha();
            if(op == '&') {
                operandos.Empilha(valor1 && valor2);
            }
            if(op == '|') {
                operandos.Empilha(valor1 || valor2);
            }
        }
    }

    //retorna o valor final da expressão
    return operandos.GetTopo();
}

//retorna a quantidade de quantificadores na expressão s
int numQuantificadores(string s){
    int num = 0;
    for(long unsigned int i = 0; i < s.size(); i++){
        if(s[i] == 'a' || s[i] == 'e'){
            num++;
        }
    }
    return num;
}

//diz se a expressão é satisfazível ou não
bool satisfazExpressao(string p, string s, TipoNo* no){

    //declara os dois nós a serem inseridos na árvore
    TipoNo str0_no;
    TipoNo str1_no;

    //testa se o número de quantificadores é maior que 0
    //essa parte do código faz com que as folhas sejam as últimas expressões possíveis, ou seja, aquelas com apenas 0s e 1s
    if(numQuantificadores(s) > 0){
        if(no->GetItem() == expressao){
            str0_no.SetKey(-32);
            str1_no.SetKey(32);
        }
        else{
            str0_no.SetKey(no->GetKey() - 1);
            str1_no.SetKey(no->GetKey() + 1);
        }

        //se a condição for verdadeira, os nós são inseridos na árvore
        arvoreSatisfabilidade.Insere(&str0_no);
        arvoreSatisfabilidade.Insere(&str1_no);
    }

    //chama avaliaExpressao e retorna 1, finalizando as chamadas recursivas, se o resultado for verdadeiro        
    if(avaliaExpressao(p, s)){
        return 1;
    }

    //loop que percorre a string de valores s
    for(long unsigned int i = 0; i < s.size(); i++){
        if(s[i] == 'e'){
            //declara e modifica as strings que serão os itens dos nós inseridos
            string str0 = s;
            string str1 = s;
            str0[i] = '0';
            str1[i] = '1';

            //seta os itens para os nós inseridos
            str0_no.SetItem(str0);
            str1_no.SetItem(str1);

            //chamadas recursivas para atribuir valor booleano a cada nó inserido
            str0_no.SetValue(satisfazExpressao(p, str0, &str0_no));
            str1_no.SetValue(satisfazExpressao(p, str1, &str1_no));

            //condições para que a string de valores seja alterada de acordo com o requisito de saída
            if(str0_no.GetValue()){
                expressao[i] = str0[i];
            }
            if(str1_no.GetValue()){
                expressao[i] = str1[i];
            }
            if(str0_no.GetValue() && str1_no.GetValue()){
                expressao[i] = 'a';
            }

            //retorna o valor booleano de acordo com a regra do quantificador 'e'
            return (str0_no.GetValue() || str1_no.GetValue());
        }
        else if(s[i] == 'a'){
            //declara e modifica as strings que serão os itens dos nós inseridos
            string str0 = s;
            string str1 = s;
            str0[i] = '0';
            str1[i] = '1';

            //seta os itens para os nós inseridos
            str0_no.SetItem(str0);
            str1_no.SetItem(str1);

            //chamadas recursivas para atribuir valor booleano a cada nó inserido
            str0_no.SetValue(satisfazExpressao(p, str0, &str0_no));
            str1_no.SetValue(satisfazExpressao(p, str1, &str1_no));

            //condição para que a string de valores seja alterada de acordo com o requisito de saída
            if(str0_no.GetValue() && str1_no.GetValue()){
                expressao[i] = 'a';
            }

            //retorna o valor booleano de acordo com a regra do quantificador 'a'
            return (str0_no.GetValue() && str1_no.GetValue());
        }
        else if(isdigit(s[i])){
            expressao[i] = s[i];
            continue;
        }
        else{
            //lança exceção para caractere inválido na string s
            caractereInvalido e;
            e.op = s[i];
            throw e;
        }
    }
    return 0;
}

int main(int argc, char *argv[]){

    int opt;
    
    while((opt = getopt(argc, argv, "as:")) != -1){
        if(argc != 4){
            cerr << "Número de argumentos inválido." << endl;
            break;
        }
        switch(opt){
            case 'a':
                try{
                    cout << avaliaExpressao(argv[2], argv[3]) << endl;
                } catch(caractereInvalido e){
                    cerr << "Caractere Inválido: " << e.op << endl;
                }
                break;
            case 's':
                try{
                    expressao = argv[3];

                    //criação e inserção da raiz na árvore da satisfabilidade
                    TipoNo raiz;
                    raiz.SetItem(argv[3]);
                    raiz.SetKey(0); 
                    arvoreSatisfabilidade.Insere(&raiz);

                    //chamada da função para verificar se a expressão é satisfazível ou não
                    raiz.SetValue(satisfazExpressao(argv[2], argv[3], &raiz));
                    if(raiz.GetValue()){
                        cout << "1 " << expressao << endl;
                    }
                    else {
                        cout << "0" << endl;
                    }
                } catch(caractereInvalido e){
                    cerr << "Caractere Inválido: " << e.op << endl;
                }
                break;
        }
    }
}
