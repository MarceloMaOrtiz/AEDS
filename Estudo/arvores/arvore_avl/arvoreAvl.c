//  AVL
//      - Árvores Balanceadas
//          - Fator de Balanceamento -> É uma árvore Binária onde as alturas das
//              sub-árvores "esquerda" e "direita" de cada nó diferem de no máximo uma unidade
//          - Custo
//              - Balanceada: O(log(n))
//              - Não Balanceada: O(n)
//          - Solução para o problema de balanceamento
//              - Modificar as operações de Inserção e Remoção
//      - Criada por Adelson-Velskii e Landis
//      - Permite rebalanceamento local
//          - Apenas a parte afetada pela inserção ou remoção é rebalanceada
//          - Uso de rotações simples ou duplas a etapa de rebalanceamento
//      - A ideia é manter como uma Árvore Binária Quase Completa
//          - Custo de qualquer algoritmo é no máximo O(log(n))
//      - Rotação
//          - Operação Básica para balanceamento da AVL
//          - Dois tipos de rotações
//              - Simples
//                  - Nó desbalanceado e seu filho estão no mesmo sentido
//              - Duplas
//                  - Nó desbalanceado e seu filho estão inclinado no sentido
//                      inverso ao pai
//                  - Equivale a duas rotações simples
//          - Existem 2 tipos de rotações simples e 2 tipos de rotações Duplas
//              - Rotação RR -> Rotação simples à Esquerda
//                  - Nó C é inserido na sub-árvore direita da sub-árvore
//                      direita de A
//                  - Nó intermediário B deve ser escolhido para ser a raiz da
//                      árvore resultante
//              - Rotação LL -> Rotação simples à Direita
//                  - Nó C é inserido na sub-árvore esquerda da sub-árvore
//                      esquerda de A
//                  - Nó intermediário B deve ser escolhido para ser a raiz da
//                      árvore resultante
//              - Rotação RL -> Rotação Dupla à Esquerda
//                  - Nó C é inserido na sub-árvore esquerda da sub-árvore
//                      direita de A
//                  - No C deve ser escolhido para ser a Raiz da árvore
//                      resultante
//              - Rotação LR -> Rotação Dupla à Direita
//                  - Nó C é inserido na sub-árvore direita da sub-árvore
//                      direita de A
//                  - No C deve ser escolhido para ser a Raiz da árvore
//                      resultante
//          - Quanto usar cada Rotação
//              - Considerando que o nó C foi inserido como filho do nó B,
//                  e que B é filho do nó A
//                  - A = +2 e B = +1 -> Rotação LL
//                  - A = -2 e B = -1 -> Rotação RR
//                  - A = +2 e B = -1 -> Rotação LR
//                  - A = -2 e B = +1 -> Rotação RL
//          - Implementando as Rotações
//              - As rotações são aplicadas no ancestral mais próximo do nó
//                  inserido cujo fator de balanceamento passa a ser +2 ou -2
//              - Esse é o parâmetro das funções implementadas
//              - As rotações simples atualizão as novas alturas das sub-árvores
//              - As rotações duplas podem ser implementadas com 2 rotaçoes
//                  simples
//      - Inserção
//          - Raiz é NULL -> Insere o nó
//          - V < Raiz -> Esquerda
//          - V > Raiz -> Direita
//          - Aplicar Recursivamente
//          - Ao voltar na rescursão, recalcular as alturas de cada sub-árvore
//          - Aplique a rotação necessário se o fator de balanceamento passar
//              a ser +2 ou -2
//      - Remoção
//          - Existe 3 tipos
//              - Nó folhas
//              - Nó com 1 filho
//              - Nó com 2 filhos
//          - O tipos de remoção trabalham juntos
//          - Balanceamento
//              - Vale as mesmas regras da inserção


#include "stdio.h"
#include "stdlib.h"
#include "Arvore.h"

#include <execinfo.h>
#include <signal.h>
#include <unistd.h>


void handler(int sig) {
  void *array[10];
  size_t size;

  // get void*'s for all entries on the stack
  size = backtrace(array, 10);

  // print out all the frames to stderr
  fprintf(stderr, "Error: signal %d:\n", sig);
  backtrace_symbols_fd(array, size, STDERR_FILENO);
  exit(1);
}

int main(int argc, char **argv) {
    signal(SIGSEGV, handler);   // install our handler
    ArvAVL *arv;
    arv = cria_ArvAVL();

    insere_ArvAVL(arv, 20);
    insere_ArvAVL(arv, 30);
    insere_ArvAVL(arv, 25);
    insere_ArvAVL(arv, 84);
    insere_ArvAVL(arv, 56);
    insere_ArvAVL(arv, 12);
    insere_ArvAVL(arv, 1);
    insere_ArvAVL(arv, 69);
    insere_ArvAVL(arv, 78);

    consulta_ArvAVL(arv, 69);
    consulta_ArvAVL(arv, 81);

    

    remove_ArvAVL(arv, 25);

    remove_ArvAVL(arv, 20);
    remove_ArvAVL(arv, 1);
    remove_ArvAVL(arv, 30);
    remove_ArvAVL(arv, 78);
    remove_ArvAVL(arv, 56);
    remove_ArvAVL(arv, 12);
    remove_ArvAVL(arv, 84);
    remove_ArvAVL(arv, 69);


    libera_ArvAVL(arv);

    return 0;
}