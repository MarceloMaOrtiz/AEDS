// Implemente um tipo abstrato de dados TConjunto para representar conjuntos de números inteiros. Seu tipo
// abstrato deverá armazenar os elementos do conjunto e o seu tamanho n. Considere que o tamanho máximo de
// um conjunto é 20 elementos e use vetor para a sua implementação. Seu TAD deve possuir procedimentos (ou
// funções quando for o caso) para:
// a) criar um conjunto vazio
// b) ler os dados de um conjunto
// c) fazer a união de dois conjuntos
// d) fazer a interseção de dois conjuntos
// e) verificar se dois conjuntos são iguais (possuem os mesmos elementos)
// f) imprimir um conjunto
// Faça um pequeno programa para testar o seu TAD.

#include <stdlib.h>
#include <stdio.h>
#include "TConjunto.h"

int main() {
    TConjunto *tc1, *tc2, *tc3;

    tc1 = cria_conjunto(5);
    tc2 = cria_conjunto(5);

    ler_dados(tc1);
    ler_dados(tc2);

    imprimir_conjunto(tc1);
    imprimir_conjunto(tc2);

    uniao_conjuntos(tc1, tc2);

    intersecao_conjuntos(tc1, tc2);

    iguais_conjuntos(tc1, tc2);

    libera_conjunto(tc1);
    libera_conjunto(tc2);

    return 0;
}