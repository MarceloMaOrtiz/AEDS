// Suponha que produtos com códigos 770, 875, 007, 059, 068, 682, 588, 067, 234, 411, 191 e 512 sejam
// inseridos, nesta ordem, em uma estrutura vazia do tipo Árvore Binária de Busca.
// a) Desenhe a árvore resultante (grafo) após a inserção de todos os itens, representando o código do produto
// dentro de cada nó.
// b) Determine em que sequência esses elementos seriam processados por um algoritmo que execute um
// percurso em pré-ordem.
// c) Determine em que sequência esses elementos seriam processados por um algoritmo que execute um
// percurso em pós-ordem.
// d) Determine em que sequência esses elementos seriam processados por um algoritmo que execute um
// percurso em ordem central (InOrder).

#include "stdio.h"
#include "stdlib.h"
#include "Arvore.h"

int main(){
    ArvBin *raiz;
    raiz = criar();
    int opt;

    inserir(raiz, 770, 1);
    inserir(raiz, 875, 2);
    inserir(raiz, 7, 3);
    inserir(raiz, 59, 4);
    inserir(raiz, 68, 5);
    inserir(raiz, 682, 6);
    inserir(raiz, 588, 7);
    inserir(raiz, 67, 8);
    inserir(raiz, 234, 9);
    inserir(raiz, 411, 10);
    inserir(raiz, 191, 11);
    inserir(raiz, 512, 12);

    printf("### Arvore Binaria de Busca ###\n\n");
    do{
        printf("\t# MENU #\n\n");
        printf(" 1- Desenhar\n");
        printf(" 2- Pre-Ordem\n");
        printf(" 3- Pos-Ordem\n");
        printf(" 4- Central\n");
        printf(" 0- Sair\n");
        printf("Opcao: ");
        scanf("%d", &opt);
        switch(opt){
            case 1:
                desenhar(raiz);
                break;
            case 2:
                pre_ordem(raiz);
                break;
            case 3:
                pos_ordem(raiz);
                break;
            case 4:
                central(raiz);
                break;
            case 0:
                break;
            default:
                printf("\nOpcao Invalida. Insira Novamente\n\n");
                break;
        }
        printf("\n\n");
    }while(opt != 0);

    liberar(raiz);
    return 0;
}