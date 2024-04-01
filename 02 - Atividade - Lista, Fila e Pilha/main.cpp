#include <cstdio>
#include <cstdlib>
#include <lista.hpp>
#include <pilha.hpp>

int main(){
    /*
    auto estrutura_lista = new lista();
    estrutura_lista->Insere(10);
    estrutura_lista->Insere(20);
    estrutura_lista->Insere(30);
    estrutura_lista->Imprime();
    delete estrutura_lista;*/

    auto estrutura_pilha = new pilha();
    estrutura_pilha->Insere(20);
    estrutura_pilha->Imprime();
    estrutura_pilha->Insere(50);
    estrutura_pilha->Insere(70);
    estrutura_pilha->Imprime();
    estrutura_pilha->Remove();
    estrutura_pilha->Remove();
    estrutura_pilha->Imprime();
    delete estrutura_pilha;

    return 0;
}