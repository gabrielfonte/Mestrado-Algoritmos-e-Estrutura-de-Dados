//
// Created by gabrielfonte on 09/04/24.
//
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cstdbool>

#define BUFFER_SIZE 512
#define print_line() printf("\n-------------------------------------------------\n")

enum opcoes {
    INSERIR = 1,
    REMOVER = 2,
};

enum codigos_erro {
    SUCESSO,
    FALHA
};

typedef enum {
    zero,
    menos,
    mais,
} balanceamento_e;

struct Arvore {
    int valor;
    struct Arvore* esq;
    struct Arvore* dir;
    balanceamento_e balanceamento;
};

typedef struct Arvore* Arv;

void drawTree(sf::RenderWindow& window, Arv* root, float x, float y, float offsetX, float offsetY);
bool Insere_Bin(Arv *arvore, int num, bool *alt);
bool Remove_Bin(Arv *arvore, int num, bool *alt);
int visualize_tree(Arv *arvore);

bool Insere_Bin(Arv *arvore, int num, bool *alt){
    if((*arvore) == NULL){
        printf("Inserindo %d\n", num);
        *arvore = (Arv) malloc(sizeof(struct Arvore));
        (*arvore)->esq = NULL;
        (*arvore)->dir = NULL;
        (*arvore)->valor = num;
        (*arvore)->balanceamento = zero;
        *alt = true;
        return true;
    }
    else{
        int valor = (*arvore)->valor;
        if(num == valor){
            return false;
        }
        else if(num < valor){
            bool res = Insere_Bin(&((*arvore)->esq), num, alt);
            if(!res){
                return false;
            }
            if(*alt) {
                Arv p1, p2;
                switch ((*arvore)->balanceamento) {
                    case mais:
                        (*arvore)->balanceamento = zero;
                        *alt = false;
                        break;
                    case zero:
                        (*arvore)->balanceamento = menos;
                        break;
                    case menos:
                        p1 = (*arvore)->esq;
                        if (p1->balanceamento == menos) {
                            (*arvore)->esq = p1->dir;
                            p1->dir = *arvore;
                            (*arvore)->balanceamento = zero;
                            *arvore = p1;
                        } else {
                            p2 = p1->dir;
                            p1->dir = p2->esq;
                            p2->esq = p1;
                            (*arvore)->esq = p2->dir;
                            p2->dir = *arvore;
                            if (p2->balanceamento == menos) {
                                (*arvore)->balanceamento = mais;
                            } else {
                                (*arvore)->balanceamento = zero;
                            }
                            if (p2->balanceamento == mais) {
                                p1->balanceamento = menos;
                            } else {
                                p1->balanceamento = zero;
                            }
                            *arvore = p2;
                        }
                        (*arvore)->balanceamento = zero;
                        *alt = false;
                        break;
                }
                return true;
            }
        } else {
            bool res = Insere_Bin(&((*arvore)->dir), num, alt);
            if(!res){
                return false;
            }
            if(*alt) {
                Arv p1, p2;
                switch ((*arvore)->balanceamento) {
                    case mais:
                        p1 = (*arvore)->dir;
                        if (p1->balanceamento == mais) {
                            (*arvore)->dir = p1->esq;
                            p1->esq = *arvore;
                            (*arvore)->balanceamento = zero;
                            *arvore = p1;
                        } else {
                            p2 = p1->esq;
                            p1->esq = p2->dir;
                            p2->dir = p1;
                            (*arvore)->dir = p2->esq;
                            p2->esq = *arvore;
                            if (p2->balanceamento == mais) {
                                (*arvore)->balanceamento = menos;
                            } else {
                                (*arvore)->balanceamento = zero;
                            }
                            if (p2->balanceamento == menos) {
                                p1->balanceamento = mais;
                            } else {
                                p1->balanceamento = zero;
                            }
                            *arvore = p2;
                        }
                        (*arvore)->balanceamento = zero;
                        *alt = false;
                        break;
                    case zero:
                        (*arvore)->balanceamento = mais;
                        break;
                    case menos:
                        (*arvore)->balanceamento = zero;
                        *alt = false;
                        break;
                }
                return true;
            }
        }
    }

    return false;
}

bool Remove_Bin(Arv *arvore, int num, bool *alt){
    if((*arvore) == NULL){
        return false;
    }
    else if(num < (*arvore)->valor){
        bool res = Remove_Bin(&((*arvore)->esq), num, alt);
        if(!res){
            return false;
        }
        if(*alt){
            Arv p1, p2;
            switch ((*arvore)->balanceamento) {
                case menos:
                    (*arvore)->balanceamento = zero;
                    break;
                case zero:
                    (*arvore)->balanceamento = mais;
                    *alt = false;
                    break;
                case mais:
                    p1 = (*arvore)->dir;
                    if(p1->balanceamento == zero){
                        (*arvore)->dir = p1->esq;
                        p1->esq = *arvore;
                        (*arvore)->balanceamento = mais;
                        *arvore = p1;
                        (*arvore)->balanceamento = menos;
                        *alt = false;
                    }
                    else if(p1->balanceamento == mais){
                        (*arvore)->dir = p1->esq;
                        p1->esq = *arvore;
                        (*arvore)->balanceamento = zero;
                        *arvore = p1;
                        *alt = false;
                    }
                    else{
                        p2 = p1->esq;
                        p1->esq = p2->dir;
                        p2->dir = p1;
                        (*arvore)->dir = p2->esq;
                        p2->esq = *arvore;
                        if(p2->balanceamento == mais){
                            (*arvore)->balanceamento = menos;
                        }
                        else{
                            (*arvore)->balanceamento = zero;
                        }
                        if(p2->balanceamento == menos){
                            p1->balanceamento = mais;
                        }
                        else{
                            p1->balanceamento = zero;
                        }
                        *arvore = p2;
                        (*arvore)->balanceamento = zero;
                        *alt = false;
                    }
                    break;
            }
            return true;
        }
    }
    else if(num > (*arvore)->valor){
        bool res = Remove_Bin(&((*arvore)->dir), num, alt);
        if(!res){
            return false;
        }
        if(*alt){
            Arv p1, p2;
            switch ((*arvore)->balanceamento) {
                case mais:
                    (*arvore)->balanceamento = zero;
                    break;
                case zero:
                    (*arvore)->balanceamento = menos;
                    *alt = false;
                    break;
                case menos:
                    p1 = (*arvore)->esq;
                    if(p1->balanceamento == zero){
                        (*arvore)->esq = p1->dir;
                        p1->dir = *arvore;
                        (*arvore)->balanceamento = menos;
                        *arvore = p1;
                        (*arvore)->balanceamento = mais;
                        *alt = false;
                    }
                    else if(p1->balanceamento == menos){
                        (*arvore)->esq = p1->dir;
                        p1->dir = *arvore;
                        (*arvore)->balanceamento = zero;
                        *arvore = p1;
                        (*arvore)->balanceamento = mais;
                        *alt = false;
                    }
                    else{
                        p2 = p1->dir;
                        p1->dir = p2->esq;
                        p2->esq = p1;
                        (*arvore)->esq = p2->dir;
                        p2->dir = *arvore;
                        if(p2->balanceamento == menos){
                            (*arvore)->balanceamento = mais;
                        }
                        else{
                            (*arvore)->balanceamento = zero;
                        }
                        if(p2->balanceamento == mais){
                            p1->balanceamento = menos;
                        }
                        else{
                            p1->balanceamento = zero;
                        }
                        *arvore = p2;
                        (*arvore)->balanceamento = zero;
                        *alt = false;
                    }
            }
            return true;
        }
    }
    else{
        Arv p1, p2;
        if((*arvore)->esq == NULL){
            *arvore = (*arvore)->dir;
            *alt = true;
        }
        else if((*arvore)->dir == NULL){
            *arvore = (*arvore)->esq;
            *alt = true;
        }
        else{
            p1 = (*arvore)->dir;
            p2 = (*arvore)->dir;
            while(p1->esq != NULL){
                p1 = p1->esq;
            }
            p1->esq = (*arvore)->esq;
            *arvore = p2;
            *alt = true;
        }
    }

    return false;
}

void Pre_Ordem(Arv *arvore){
    if((*arvore) != NULL){
        printf("%d ", (*arvore)->valor);
        Pre_Ordem(&(*arvore)->esq);
        Pre_Ordem(&(*arvore)->dir);
    }
}

void In_Ordem(Arv *arvore){
    if((*arvore) != NULL){
        In_Ordem(&(*arvore)->esq);
        printf("%d ", (*arvore)->valor);
        In_Ordem(&(*arvore)->dir);
    }
}

void Pos_Ordem(Arv *arvore){
    if((*arvore) != NULL){
        Pos_Ordem(&(*arvore)->esq);
        Pos_Ordem(&(*arvore)->dir);
        printf("%d ", (*arvore)->valor);
    }
}

int main(){

    int opcao = 0;
    char numeros[BUFFER_SIZE];

    /* Criação da Árvore */
    Arv arvore = NULL;

    while(1){
        printf("Digite 1 para inserir um valor na árvore ou 2 para remover um valor da árvore: ");
        scanf("%d", &opcao);
        while (getchar() != '\n'); // Limpa o buffer do teclado

        if(opcao == INSERIR){
            printf("Digite um valor para inserir na árvore: ");
            scanf("%[0-9-+, ]", numeros);
            char *num = strtok(numeros,", \n");
            while(num != NULL){
                int converted = atoi(num);
                bool alt = false;
                Insere_Bin(&arvore, converted, &alt);
                num = strtok(NULL,", \n");
            }
        }
        else if(opcao == REMOVER){
            printf("Digite um valor para remover da árvore: ");
            scanf("%[0-9-+, ]", numeros);
            char *num = strtok(numeros,", \n");
            while(num != NULL){
                int converted = atoi(num);
                bool alt = false;
                Remove_Bin(&arvore, converted, &alt);
                num = strtok(NULL,", \n");
            }
        }
        else{
            printf("Opção inválida\n");
            return 1;
        }

        print_line();
        printf("Pre Ordem:\n");
        Pre_Ordem(&arvore);
        print_line();
        printf("Root: %d\n", arvore->valor);

        printf("In Ordem:\n");
        In_Ordem(&arvore);
        print_line();

        printf("Pos Ordem:\n");
        Pos_Ordem(&arvore);
        print_line();

        visualize_tree(&arvore);
    }

    return 0;
}


// Função para desenhar a árvore binária recursivamente
void drawTree(sf::RenderWindow& window, Arv* root, float x, float y, float offsetX, float offsetY) {
    if (root == nullptr)
        return;

    // Desenha o nó
    sf::CircleShape nodeShape(25);
    nodeShape.setPosition(x, y);
    nodeShape.setFillColor(sf::Color::White);
    nodeShape.setOutlineColor(sf::Color::Black);
    nodeShape.setOutlineThickness(2);
    window.draw(nodeShape);

    // Desenha o valor do nó
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        std::cerr << "Erro ao carregar a fonte." << std::endl;
        return;
    }
    sf::Text text(std::to_string((*root)->valor), font, 20);
    text.setPosition(x + 15, y + 10);
    text.setFillColor(sf::Color::Black);
    window.draw(text);

    // Desenha as conexões para os filhos esquerdos e direitos, se existirem
    if ((*root)->esq != nullptr) {
        sf::Vertex line[] = {
                sf::Vertex(sf::Vector2f(x + 25, y + 25)),
                sf::Vertex(sf::Vector2f(x - offsetX + 25, y + offsetY + 25))
        };
        window.draw(line, 2, sf::Lines);
        drawTree(window, &(*root)->esq, x - offsetX, y + offsetY, offsetX / 2, offsetY);
    }
    if ((*root)->dir != nullptr) {
        sf::Vertex line[] = {
                sf::Vertex(sf::Vector2f(x + 25, y + 25)),
                sf::Vertex(sf::Vector2f(x + offsetX + 25, y + offsetY + 25))
        };
        window.draw(line, 2, sf::Lines);
        drawTree(window, &(*root)->dir, x + offsetX, y + offsetY, offsetX / 2, offsetY);
    }
}

int visualize_tree(Arv *arvore){
    // Criação da janela
    sf::RenderWindow window(sf::VideoMode(800, 600), "Binary Tree Visualization");
    window.setFramerateLimit(60);

    // Loop principal
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);

        // Desenha a árvore binária
        drawTree(window, arvore, 400, 50, 200, 100);

        window.display();
    }

    return 0;
}