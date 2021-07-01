// Definir
    // - Tipo de dados Lista
    // - Implementação das funções

#include "stdio.h"
#include "stdlib.h"
#include "ListaSequencial.h"

struct lista_sequencial {
    int qtd;
    struct aluno dados[MAX];
};

ListaSequencial* cria_lista_sequencial(){
    ListaSequencial *li;
    li = (ListaSequencial*)malloc(sizeof(struct lista_sequencial));
    if (li != NULL)
        li->qtd = 0;
    return li;
}

int lista_cheia(ListaSequencial* li){
    if (li == NULL)
        return -1;
    return (li->qtd == MAX);
}

int insere_lista_sequencial_final(ListaSequencial* li, struct aluno al){
    if(li == NULL)
        return 0;
    if(lista_cheia(li))
        return 0;
    li->dados[li->qtd] = al;
    li->qtd++;
    return 1;
}

int insere_lista_sequencial_inicio(ListaSequencial* li, struct aluno al){
    if( li == NULL)
        return 0;
    if(lista_cheia(li))
        return 0;
    int i;
    for(i = li->qtd; i >= 0; i--)
        li->dados[i+1] = li->dados[i];
    li->dados[0] = al;
    li->qtd++;
    return 1;
}

int insere_lista_sequencial_ordenada(ListaSequencial* li, struct aluno al){
    if(li == NULL)
        return 0;
    if(lista_cheia(li))
        return 0;
    int k, i = 0;
    while(i < li->qtd && li->dados[i].matricula < al.matricula)
        i++;
    for (k = li->qtd-1; k >= i; k--)
        li->dados[k+1] = li->dados[k];
    li->dados[i] = al;
    li->qtd++;
    return 1;
}


int remove_lista_sequencial_final(ListaSequencial* li){
    if(li == NULL)
        return 0;
    if(li->qtd == 0)
        return 0;
    li->qtd--;
    return 1;
}

int remove_lista_sequencial_inicio(ListaSequencial* li){
    if(li == NULL)
        return 0;
    if(li->qtd == 0)
        return 0;
    int k = 0;
    for(k = 0; k < li->qtd-1; k++)
        li->dados[k] = li->dados[k+1];
    li->qtd--;
    return 1;
}

int remove_lista_sequencial(ListaSequencial* li, struct aluno al){
    if(li == NULL)
        return 0;
    if(li->qtd == 0)
        return 0;
    int k, i = 0;
    while(i < li->qtd && li->dados[i].matricula != al.matricula)
        i++;
    if(i == li->qtd)
        return 0;
    for(k = i; k < li->qtd-1; k++)
        li->dados[k] = li->dados[k+1];
    li->qtd--;
    return 1;
}

int consulta_lista_sequencial_pos(ListaSequencial* li, int pos, struct aluno *al) {
    if (li == NULL || pos <= 0 || pos > li->qtd)
        return 0;
    *al = li->dados[pos-1];
    return 1;
}

int consulta_lista_sequencial_mat(ListaSequencial* li, int mat, struct aluno *al) {
    if (li == NULL)
        return 0;
    int k, i = 0;
    while(i < li->qtd && li->dados[i].matricula != mat)
        i++;
    if(i == li->qtd)
        return 0;
    *al = li->dados[i];
    return 1;
}

void libera_lista(ListaSequencial* li){
    free(li);
}