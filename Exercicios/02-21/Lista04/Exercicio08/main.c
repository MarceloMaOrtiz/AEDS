// Considere a implementação de listas encadeadas utilizando ponteiros. Escreva um procedimento
// Troca(TipoLista * pLista, TipoCelula * p) que, dado um ponteiro para uma célula qualquer (p), troca
// de posição essa célula com a sua célula seguinte da lista, como mostrado na figura abaixo. (Obs.: Não vale
// trocar apenas o campo item! Você deverá fazer a manipulação dos ponteiros para trocar as duas células de
// posição). Não esqueça de tratar os casos especiais. Faça um pequeno programa para testar seu procedimento.

#include "stdio.h"
#include "stdlib.h"
#include "Lista.h"

int main(){
    Lista *lista;
    lista = cria_lista();
    struct dado d1, d2, d3, d4, d5, d6;
    d1.num = 1;
    d2.num = 2;
    d3.num = 3;
    d4.num = 4;
    d5.num = 5;
    d6.num = 6;
    insere_lista(lista, d1);
    insere_lista(lista, d2);
    insere_lista(lista, d3);
    insere_lista(lista, d4);
    insere_lista(lista, d5);
    insere_lista(lista, d6);
    imprime_lista(lista);
    troca(lista, d4);
    imprime_lista(lista);
    libera_lista(lista);
    return 0;
}