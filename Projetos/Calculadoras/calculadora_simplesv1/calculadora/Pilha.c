#include "stdio.h"
#include "stdlib.h"
#include "Pilha.h"

struct no{
    int elem;
    struct no *prox;
};
typedef struct no No;

// Complexidade: O(1)
Pilha *criar_pilha(){
    Pilha *pi = (Pilha*)malloc(sizeof(Pilha));
    if(pi != NULL)
        *pi = NULL;
    return pi;
}

// Complexidade: O(1)
// Consulta o topo da Pilha, armazenando o valor em uma variável inteira
    void consulta_pilha(Pilha *pi, int *elem){
        if(pi == NULL)
            return;
        if((*pi) == NULL)
            return;
        *elem = (*pi)->elem;
        return;
    }

// Complexidade: O(1)
// Remove e libera o topo da pilha
void desempilhar_pilha(Pilha *pi){
    if(pi == NULL)
        return;
    if((*pi) == NULL)
        return;
    No *no = *pi;
    *pi = no->prox;
    free(no);
}

// Complexidade: O(1) para maioria dos casos
//      Para elem = C temos O(n) onde n é o tamanho da pilha
// Função empilhar recebe um caractere, verificar qual o valor presente
// no topo da pilha e baseado nesse valor, atualiza o topo da pilha
void empilhar_pilha(Pilha *pi, char elem){
    if(pi == NULL) // Verifica se pilha existe
        return;
    No* no = (No*)malloc(sizeof(No)); // Cria um nó para inserir na pilha
    if(no == NULL) // Verifica se alocou memoria corretamente
        return;
    switch(elem){
        int topo, topo_y, topo_x, resultado, num;
        case 'E': // Insere 0 na pilha caso receba um Enter
            no->elem = 0;
            no->prox = (*pi);
            *pi = no;
            break;
        case 'C': // Esvazia a pilha completamente
            while(*pi != NULL){
                desempilhar_pilha(pi);
            };
            break;
        case '+':
        case '-':
        case '*':
        case '/':
            consulta_pilha(pi, &topo_y);
            desempilhar_pilha(pi);
            consulta_pilha(pi, &topo_x);
            desempilhar_pilha(pi);
            if(elem == '+')
                resultado = topo_x + topo_y;
            else if(elem == '-')
                resultado = topo_x - topo_y;
            else if(elem == '*')
                resultado = topo_x * topo_y;
            else{
                if(topo_y != 0){
                    resultado = topo_x / topo_y;
                }else{
                    printf("\n\nError. Impossível efetuar divisão por 0.\n\n");
                    while(*pi != NULL){
                        desempilhar_pilha(pi);
                    };
                    return;
                }
            }
            no->elem = resultado;
            no->prox = (*pi);
            *pi = no;
            break;
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            consulta_pilha(pi, &topo);
            desempilhar_pilha(pi);
            num = (int)elem - 48; // Convert para integer, pois o 0 comeca em 48 em ASCII
            resultado = topo * 10 + num;
            no->elem = resultado;
            no->prox = (*pi);
            *pi = no;
            break;
        default:
            printf("Error. Caractere Invalido");
            return;
    }
}

// Complexidade: O(n) onde n é o número de nós na pilha
// Função para imprimir pilha
void imprimir_pilha(Pilha *pi){
    No* no = (*pi);
    printf("[");
    while(no != NULL){
        printf("  %d  ", no->elem);
        no = no->prox;
    }
    printf("]\n");
}

// Complexidade: O(n) onde n é o número de nós na pilha
// Função responsável por liberar a pilha antes de finalizar o programa
void liberar_pilha(Pilha *pi){
    if(pi != NULL){
        No *no;
        // Enquanto a pilha não esvaziar, liberará nó por nó
        while((*pi) != NULL){
            no = *pi;
            *pi = (*pi)->prox;
            free(no);
        }
        free(pi);
    }
}