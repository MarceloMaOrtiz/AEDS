

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
