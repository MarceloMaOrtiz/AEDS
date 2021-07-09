// Escreva um algoritmo completo na linguagem C seguindo as instruções abaixo. Leia atentamente todos os itens
// antes de iniciar seu desenvolvimento:
// a) Crie uma estrutura chamada livro. Cada livro terá os seguintes dados: título (150 caracteres), autor (150
// caracteres), preços (vetor de números reais com 6 posições). O vetor "preços" representa o preço do livro
// nos últimos 6 meses.
// b) Crie um procedimento que peça ao usuário para digitar todos os dados de um conjunto de livros. Os
// parâmetros do procedimento são: um vetor de livros e seu tamanho.
// c) Crie um procedimento para imprimir o preço médio de cada livro do vetor de livros. O preço médio será
// calculado pela média aritmética de todos os preços de cada livro. Os parâmetros deste procedimento são:
// um vetor de livros e seu tamanho.
// d) Faça uma função principal (main) para criar dinamicamente um vetor de 5 livros usando a estrutura do
// item (a) e, posteriormente, “chame” os procedimentos dos itens (b) e (c). Imprima também as informações
// do livro mais caro e do livro mais barato.

#include <stdlib.h>
#include <stdio.h>
#include "Livro.h"

int main() {
    Livro ** livros = (Livro**)malloc(5*sizeof(Livro*));

    atribui_livros(livros, 5);

    preco_medio(livros, 5);

    for (int i = 0; i < 5; i++){
        libera_livro(livros[i]);
    }

    free(livros);
    return 0;
}