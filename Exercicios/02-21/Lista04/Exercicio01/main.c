#include "stdlib.h"
#include "stdio.h"
#include "Lista.h"

int main(){
    Lista *lista;
    lista = cria_lista();
    struct no n1, n2, n3;
    n1.num = 1;
    n2.num = 2;
    n3.num = 3;
    insere_lista(lista, n1);
    insere_lista(lista, n2);
    insere_lista(lista, n3);
    imprime_lista(lista);
    troca_elementos(lista, n1, n2);
    imprime_lista(lista);
    libera_lista(lista);
    return 0;
}