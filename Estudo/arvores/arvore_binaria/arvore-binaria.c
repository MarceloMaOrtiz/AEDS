#include <stdio.h>
#include <stdlib.h>
#include "arvoreBinaria.h"

//  Árvore Binária
//   - Tipo especial de árvore
//   - Cada vértice pode possuir duas sub-árvores
//    - sub-árvore esquerda e direita
//   - O grau de cada vértice pode ser 0, 1 ou 2
//  Árvore Estritamente Binária
//   - Cada nó possui 0 ou 2 sub-árvores
//  Árvore Binária Completa
//   - É Estritamente Binária
//   - Todos os nós folhas estão no mesmo nível
//   - O número de nós da árvore é ( 2^h-2, h = altura da árvore)
//  Árvore Binária Quase Completa
//   - A diferença de altura entre as sub-árvores de qualquer nós é no máximo 1

//   Implementando uma Árvore Binária
//    Operações
//     - criação
//      - Criação da raiz da árvore
//      - Nó especial que aponta pro primeiro elemento da árvore
//     - inserção de elemento
//     - remoção de elemento
//     - acesso a um elemento
//     - destruição
//      - Percorre todo a árvore liberando nó a nó
//       Dependem do tipo de alocação de memória utilizada (Estática ou Dinâmica)
//        - Estática
//         - Quando se sabe o tamanho da árvore
//         - Quando a árvore é Completa
//          - Todo o vetor será utilizado
//         - Vetor
//          - filho_esq(pai) = 2 * pai + 1
//          - filho_dir(pai) = 2 * pai + 2
//        - Dinâmica
//         - Lista Encadeada
//          - Cada nó da árvore é tratado como um ponteiro alocado dinâmicamente
//          Detalhes
//           - Para guardar a raiz é utilizado **
//            - Facilita a mudança da raiz da árvore
//           - arvoreBinaria.h
//            - Protótipos da função
//            - Tipo de dado armazenado na árvore
//            - Ponteiro arvore
//           - arvoreBinaria.c
//            - Tipo de dado arvore
//            - Implementação das funções
//
//   Percorrendo uma Árvore Binária
//    - Pré-Ordem -> Raiz, Esquerda, Direita
//    - Em-Ordem -> Esquerda, Raiz, Direita
//    - Pós-Ordem -> Esquerda, Direita, Raiz
    

int main(){

    ArvBin* raiz = cria_ArvBin();

    int x = estaVazia_ArvBin(raiz);

    if(x)
        printf("A Árvore está vazia\n");
    else
        printf("A Árvore não está vazia\n");

    x = altura_ArvBin(raiz);
    printf("A Altura da Árvore é: %d\n", x);

    x = totalNO_ArvBin(raiz);
    printf("A quantidade de nós é: %d\n", x);

    preOrdem_ArvBin(raiz);

    emOrdem_ArvBin(raiz);

    posOrdem_ArvBin(raiz);

    libera_ArvBin(raiz);

    return 0;
}