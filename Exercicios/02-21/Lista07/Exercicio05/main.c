// Faça um programa na Linguagem C que que peça ao usuário para digitar n nomes, inserindo-os em uma lista de
// forma ordenada utilizando a ideia do algoritmo InsertionSort. No final, o programa deve imprimir na tela a lista
// com todos os nomes ordenados alfabeticamente

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "Lista.h"

int main(){
    int n = 0;
    char nome[30];
    ListaNomes* lista = cria_lista();
    printf("\n### Insira os nomes ###\n");
    do{
        printf("Nome %d ('s' para finalizar): ", n+1);
        scanf("%s", nome);
        if(strcmp(nome, "s") != 0){
            insere_lista_ordenado(lista, nome);
            n++;
        }
    }while(strcmp(nome, "s") != 0);
    imprime_lista(lista);
    free(lista);
}