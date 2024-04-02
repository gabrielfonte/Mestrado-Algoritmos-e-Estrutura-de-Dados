#include <cstdio>
#include <cstdlib>
#include <lista.hpp>
#include <pilha.hpp>
#include <fila.hpp>

using namespace std;

#define BUFFER_SIZE 512

int main(){

    char estrutura;
    int opcao = 0;
    char numeros[BUFFER_SIZE];

    lista* estrutura_generica;
    string nome_estrutura;

    cout << "Digite 'L' para a estrutura Lista, 'P' para a estrutura Pilha e 'F' para a estrutura Fila: ";
    estrutura = getchar();
    switch (estrutura) {
        case 'L':
            estrutura_generica = new lista();
            nome_estrutura = "Lista";
            break;
        case 'P':
            estrutura_generica = new pilha();
            nome_estrutura = "Pilha";
            break;
        case 'F':
            estrutura_generica = new fila();
            nome_estrutura = "Fila";
            break;
        default:
            std::cout << "Opção inválida" << std::endl;
            return 1;
    }

    while(1){

        cout << "Digite 1 para inserir um valor na " << nome_estrutura << " ou 2 para remover um valor da " << nome_estrutura << ": ";
        scanf("%d", &opcao);
        while (getchar() != '\n'); // Limpa o buffer do teclado

        if(opcao == INSERIR){
            cout << "Digite um valor para inserir na " << nome_estrutura << ": ";
            scanf("%[0-9-+, ]", numeros);
            char *num = strtok(numeros,", \n");
            while(num != NULL){
                int converted = atoi(num);
                estrutura_generica->Insere(converted);
                num = strtok(NULL,", \n");
            }
        }
        else if(opcao == REMOVER){
            if(estrutura == 'L'){
                cout << "Digite um valor para remover da " << nome_estrutura << ": ";
                scanf("%[0-9-+, ]", numeros);
                char *num = strtok(numeros,", \n");
                while(num != NULL){
                    int converted = atoi(num);
                    estrutura_generica->Remove(converted);
                    num = strtok(NULL,", \n");
                }
            }
            else{
                estrutura_generica->Remove();
            }
        }
        else{
            printf("Opção inválida\n");
            delete estrutura_generica;
            return 1;
        }

        estrutura_generica->Imprime();
    }

    return 0;
}