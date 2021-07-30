// Projete uma estrutura do tipo Árvore Binária de Busca para armazenar produtos de uma loja de conveniência
// com os seguintes campos: código do produto (inteiro) e preço (real). A árvore será ordenada pelo código dos
// produtos.
// a) Escreva um procedimento adicionar, que pede ao usuário para digitar as informações via teclado e
// posteriormente cria e insere um nó na árvore binária, indexando o produto pelo código.
// b) Escreva um procedimento preco, que busca na árvore binária pelo código do produto desejado e imprime
// na tela seu preço correspondente, no seguinte formato: O PRODUTO 132 CUSTA R$ 3.79. Se o produto
// não existir, imprima na tela: PRODUTO 642 NÃO ENCONTRADO.
// c) Escreva uma função remover, que pede ao usuário para informar um código de produto e remove esse
// produto da árvore, caso ele exista e imprima na tela: O PRODUTO 132 FOI REMOVIDO COM SUCESSO. Se o
// produto não existir, imprima na tela: PRODUTO 642 NÃO ENCONTRADO.

#include "stdio.h"
#include "stdlib.h"
#include "Arvore.h"

int main(){
    ArvBin *raiz;
    raiz = criar();
    int opt;
    int cod;
    float preco;
    printf("### Arvore Binaria de Busca ###\n\n");
    do{
        printf("\t# MENU #\n\n");
        printf(" 1- Adicionar Produto\n");
        printf(" 2- Buscar Produto\n");
        printf(" 3- Remover Produto\n");
        printf(" 0- Sair\n");
        printf("Opcao: ");
        scanf("%d", &opt);
        switch(opt){
            case 1:
                printf("\n\n## Adicionar Produto ##\n");
                printf("\n Codigo: ");
                scanf("%d", &cod);
                printf(" Preco: ");
                scanf("%f", &preco);
                inserir(raiz, cod, preco);
                break;
            case 2:
                printf("\n\n## Encontrar Produto ##\n");
                printf("\n Codigo: ");
                scanf("%d", &cod);
                buscar(raiz, cod);
                break;
            case 3:
                printf("\n\n## Remover Produto ##\n");
                printf("\n Codigo: ");
                scanf("%d", &cod);
                remover(raiz, cod);
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