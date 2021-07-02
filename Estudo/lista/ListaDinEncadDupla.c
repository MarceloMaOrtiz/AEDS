// Tipo de dados
// Implementar as funções

#include "stdlib.h"
#include "stdio.h"
#include "aluno.h"
#include "ListaDinEncadDupla.h"

struct elemento{
    struct elemento *ant;
    struct aluno dados;
    struct elemento *prox;
};
typedef struct elemento Elem;

ListaDinEncadDupla* cria_lista_din_dupla() {
    ListaDinEncadDupla* li = (ListaDinEncadDupla*)malloc(sizeof(ListaDinEncadDupla));
    if (li != NULL)
        *li = NULL;
    return li;
}

int lista_vazia_din_dupla(ListaDinEncadDupla *li){
    if(li == NULL)
        return 1;
    if(*li == NULL)
        return 1;
    return 0;
}

int insere_lista_din_dupla_inicio(ListaDinEncadDupla* li, struct aluno al){
    if(li == NULL)
        return 0;
    Elem* no = (Elem*)malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dados = al;
    no->prox = (*li);
    no->ant = NULL;
    if(*li != NULL)
        (*li)->ant = no;
    *li = no;
    return 1;
}

int insere_lista_din_dupla_fim(ListaDinEncadDupla* li, struct aluno al){
    if(li == NULL)
        return 0;
    Elem* no = (Elem*)malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dados = al;
    no->prox = NULL;
    if((*li) == NULL){ // Para inserir na lista vazia
        no->ant = NULL;
        *li = no;
    }
    else{
        Elem *aux = *li;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = no;
        no->ant = aux;
    }
    return 1;
}

int insere_lista_din_dupla_ordenada(ListaDinEncadDupla* li, struct aluno al){
    if(li == NULL)
        return 0;
    Elem* no = (Elem*)malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dados = al;
    if(lista_vazia_din_dupla(li)){ // Insere no inicio
        no->prox = NULL;
        no->ant = NULL;
        *li = no;
    }
    else{
        Elem *ant, *atual = *li;
        while(atual != NULL && atual->dados.matricula < al.matricula){
            ant = atual;
            atual = atual->prox;
        }
        if(atual == *li){ // Insere no início
            no->ant = NULL;
            (*li)->ant = no;
            no->prox = (*li);
            *li = no;
        }else{
            no->prox = ant->prox;
            no->ant = ant;
            ant->prox = no;
            if(atual != NULL)
                atual->ant = no;
        }
    }
    return 1;
}

int consulta_lista_din_dupla_pos(ListaDinEncadDupla* li, int pos, struct aluno *al){
    if(li == NULL || pos <= 0)
        return 0;
    Elem *no = *li;
    int i = 1;
    while(no != NULL && i < pos){
        no = no->prox;
        i++;
    }
    if(no == NULL)
        return 0;
    else{
        *al = no->dados;
        return 1;
    }
}

int consulta_lista_din_dupla_mat(ListaDinEncadDupla* li, int mat, struct aluno *al){
    if(li == NULL || mat <= 0)
        return 0;
    Elem *no = *li;
    while(no != NULL && no->dados.matricula != mat){
        no = no->prox;
    }
    if(no == NULL)
        return 0;
    else{
        *al = no->dados;
        return 1;
    }
}


int remove_lista_din_dupla_inicio(ListaDinEncadDupla* li){
    if(li == NULL)
        return 0;
    if((*li) == NULL);
        return 0;
    Elem *no = *li;
    *li = no->prox;
    if(no->prox != NULL)
        no->prox->ant = NULL;
    free(no);
    return 1;
}

int remove_lista_din_dupla_fim(ListaDinEncadDupla* li){
    if(li == NULL)
        return 0;
    if((*li) == NULL);
        return 0;
    Elem *no = *li;
    while(no->prox != NULL){
        no = no->prox;
    }
    if(no->ant == NULL)
        *li = no->prox;
    else
        no->ant->prox = NULL;
    free(no);
    return 1;
}

int remove_lista_din_dupla(ListaDinEncadDupla* li, struct aluno al){
    if(li == NULL)
        return 0;
    Elem *no = *li;
    while(no != NULL && no->dados.matricula != al.matricula){
        no = no->prox;
    }
    if(no == NULL){
        return 0;
    }
    if(no->ant == NULL){
        *li = no->prox;
    }
    else{
        no->ant->prox = no->prox;
    }
    if(no->prox != NULL)
        no->prox->ant = no->ant;
    free(no);
    return 1;
}

void libera_lista_din_dupla(ListaDinEncadDupla* li) {
    if(li != NULL) {
        Elem* no;
        while((*li) != NULL){
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }
}