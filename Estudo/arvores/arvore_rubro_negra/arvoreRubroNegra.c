// Árvore Rubro-Negra
//  - É um tipo de árvore binária balanceada
//  - Originalmente criada por Rudolf Bayer em 1972 e chamada de Árvores
//      Binárias Simétricas
//  - Utiliza um esquema de coloração dos nós para manter o balanceamento
//      - Nó da árvore possui um atributo de cor
//  - Propriedades da árvore
//      - Todo nó da árvore é Vermelho ou Preto
//      - A raiz é sempre Preta
//      - Todo nó folha, ou NULL, é Preto
//      - Se um nó é Vermelho, então os seus filhos são pretos
//          - Não existe nós Vermelhos consecutivos
//      - Para cada nó, todos os caminhos desse nó para os nós
//          folhas descendentes contem o mesmo número de nós pretos
//  - Permite rebalancemento local
//      - Apenas a parte afetada pela Inserção ou Remoção é rebalanceada
//      - Uso de Rotações e Ajuste de Cores na etapa de rebalanceamento
//          - Essas operações corrigem as propriedades que foram violadas
//  - A ideia consta em manter-se como uma Árvore Binária Quase Completa
//      - Custo de qualquer algoritmo é máximo O(log(n))
//  - AVL x Rubro-Negra
//      - Na teoria, possuem a mesma complexidade computacional - O(log(n))
//          - Inserção, remoção e busca
//      - Na prática a árvore AVL é mais rápida na operação de busca, e mais
//          lenta nas operações de inserção e remoção
//      - Árvore AVL é mais balanceada que a Árvore Rubro-Negra, acelerando
//          a operação de busca
//      - Maior custo na operação de Inserção e Remoção
//          - No pior caso, pode exigir O(log(n)) rotações na Árvore AVL
//          - No pior caso, apenas três rotações na árvore Rubro-Negra
//      - Árvores Rubro-Negra são de uso mais geral do que as árvores AVL
//          - Isso faz com que elas sejam mais utilizadas em diversas
//              aplicações e bibliotecas de linguagens de programação
//  - Árvore Rubro Negra caída para a Esquerda (Left-Leaning Red-Black Tree)
//      - Variante da árvore rubro-Negro que garante a mesma complexidade de
//          operações, mas possui uma implmentação mais simples na inserção e
//          remoção
//      - Satisfaz todas as propriedades da Árvore Rubro-Negra convencional
//      - Possui uma propriedade extra
//          - Se um nó é Vermelho, então ele é o filho esquerdo do seu pai
//              - Essa propriedade confere o ser aspecto caída para a esquerda
//              - Os nós vermelhos sempre são filhos à esquerda
//      - Implementação
//          - Corresponde a implementação de uma Árvore 2-3 (Não é um árvore Binária)
//              - Na Árvore 2-3 cada nó interno pode armazenar 1 ou 2 valores e,
//                  dependendo da quantidade de valores armazenados, ter 2 (um valor)
//                  ou 3 (dois valores) filhos
//              - Funcionamento igual ao da Árvore Binária de Busca.
//                  - No caso de 3 sub-árvores, na sub-árvore do meio se encontram os
//                      elementos que são maiores do que o primeiro, mas menores do que o
//                      segundo valor do nó pai  
//          - Implementação corresponde a implementação de uma árvore 2-3 se
//              considerarmos que o nó vermelho será sempre o valor menor de um
//              nó contendo dois valores e três sub-árvores
//              - Com isso balancear a árvore rubro-negra equivale manipular uma Árvore
//                  2-3, uma tarefa muito mais simples do que manipular uma árvore AVL ou
//                  uma Rubro-Negra convencional
//          - Rotação Árvore Rubro-Negra Caída para Esquerda - LLRB
//              - Operações básicas para balanceamento
//              - Dado um conjunto de três nós, a rotação visa deslocar um nó vermelho
//                  que esteja à esquerda para à direita e vice-versa
//              - A rotação apenas atualiza ponteiro, de modo que a complexidade é O(1)
//              - Dois tipos de rotações
//                  - Rotação à Esquerda
//                      - Recebe um nó A com B como filho direito
//                      - Move B para o lugar de A, A se torna o filho esquerdo de B
//                      - B recebe a cor de A, A fica Vermelho
//                  - Rotação à Direita
//                      - Recebe um nó A com B como filho esquerdo
//                      - Move B para o lugar de A, A se torna o filho direito de B
//                      - B recebe a cor de A, A fica Vermelho
//          - Movendo os nós vermelhos na LLRB
//              - Rotações e trocas de cores podem causar uma violação das propriedades
//                  da árvore
//              - Necessidade de 3 funções para reestabelecer o balanceamento da árvore
//                  e garantir que as suas propriedades são respeitadas
//                  - Mover um nó Vermelho para a esquerda
//                      - Recebe um nó H e troca as cores dele e de seus filhos
//                      - Se o filho a esquerda do filho direito é Vermelho, aplicar uma
//                          rotação esquerda no pai
//                      - Troca as cores do nó pai e seus filhos
//                  - Mover um nó Vermelho para a direita
//                      - Recebe um nó H e troca as cores dele e de seus filhos
//                      - Se o filho a esquerda do filho esquerdo é Vermelho, aplicar uma
//                          rotação a direita no pai
//                      - Troca as cores do nó pai e seus filhos
//                  - Arrumar o Balanceamento
//                      - Se o filho direito é Vermelho
//                          - Rotação à esquerda
//                      - Se o filho direito e o neto da esquerda são Vermelhos
//                          - Rotação à direita
//                      - Se ambos os filhos são vermelhor
//                          - Trocar a cor dos pais e dos filhos
//          - Inserção na LLRB
//              - Raiz é NULL -> Insira nó
//              - V > raiz -> Direita
//              - V < raiz -> Esqueda
//              - Aplicar método recursivamente
//              - Ao voltar na recursão
//                  - Verificar as propriedades em cada sub-árvore
//                  - Aplica a rotação ou mudança de cor quando necessário
//          - Remoção na LLRB
//              - Nó folha
//              - Nó com 1 filho
//              - Nó com 2 filhos

#include "stdio.h"
#include "stdlib.h"
#include "Arvore.h"

int main(){
    ArvLLRB *raiz;

    raiz = cria_ArvLLRB();

    insere_ArvLLRB(raiz, 6);
    insere_ArvLLRB(raiz, 1);
    insere_ArvLLRB(raiz, 4);
    insere_ArvLLRB(raiz, 3);
    insere_ArvLLRB(raiz, 7);
    insere_ArvLLRB(raiz, 8);
    insere_ArvLLRB(raiz, 9);
    insere_ArvLLRB(raiz, 2);
    insere_ArvLLRB(raiz, 4);

    remove_ArvLLRB(raiz, 4);
    remove_ArvLLRB(raiz, 7);
    remove_ArvLLRB(raiz, 1);
    remove_ArvLLRB(raiz, 6);
    remove_ArvLLRB(raiz, 7);
    remove_ArvLLRB(raiz, 8);
    remove_ArvLLRB(raiz, 9);
    remove_ArvLLRB(raiz, 2);
    remove_ArvLLRB(raiz, 4);

    libera_ArvLLRB(raiz);

    return 0;
}
