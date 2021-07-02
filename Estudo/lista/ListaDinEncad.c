// Definir
    // - Tipo de dados Lista
    // - Implementação das funções

#include "stdio.h"
#include "stdlib.h"
#include "aluno.h"
#include "ListaDinEncad.h"

struct elemento{
    struct aluno dados;
    struct elemento *prox;
};
typedef struct elemento Elem;

ListaDinEncad* cria_lista_din() {
    ListaDinEncad* li = (ListaDinEncad*)malloc(sizeof(ListaDinEncad));
    if (li != NULL)
        *li = NULL;
    return li;
}

int lista_vazia_din(ListaDinEncad *li){
    if(li == NULL)
        return 1;
    if(*li == NULL)
        return 1;
    return 0;
}

int insere_lista_din_inicio(ListaDinEncad* li, struct aluno al){
    if(li == NULL)
        return 0;
    Elem* no = (Elem*)malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dados = al;
    no->prox = (*li);
    *li = no;
    return 1;
}

int insere_lista_din_fim(ListaDinEncad* li, struct aluno al){
    if(li == NULL)
        return 0;
    Elem* no = (Elem*)malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dados = al;
    no->prox = NULL;
    if((*li) == NULL){ // Para inserir na lista vazia
        *li = no;
    }
    else{
        Elem *aux = *li;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = no;
    }
    return 1;
}

int insere_lista_din_ordenada(ListaDinEncad* li, struct aluno al){
    if(li == NULL)
        return 0;
    Elem* no = (Elem*)malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dados = al;
    if(lista_vazia_din(li)){ // Insere no inicio
        no->prox = (*li);
        *li = no;
    }
    else{
        Elem *ant, *atual = *li;
        while(atual != NULL && atual->dados.matricula < al.matricula){
            ant = atual;
            atual = atual->prox;
        }
        if(atual == *li){ // Insere no início
            no->prox = (*li);
            *li = no;
        }else{
            no->prox = ant->prox;
            ant->prox = no;
        }
    }
    return 1;
}

int consulta_lista_din_pos(ListaDinEncad* li, int pos, struct aluno *al){
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

int consulta_lista_din_mat(ListaDinEncad* li, int mat, struct aluno *al){
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

int remove_lista_din_inicio(ListaDinEncad* li){
    if(li == NULL)
        return 0;
    if((*li) == NULL);
        return 0;
    Elem *no = *li;
    *li = no->prox;
    free(no);
    return 1;
}

int remove_lista_din_fim(ListaDinEncad* li){
    if(li == NULL)
        return 0;
    if((*li) == NULL);
        return 0;
    Elem *ant, *no = *li;
    while(no->prox != NULL){
        ant = no;
        no = no->prox;
    }
    if(no == (*li))
        *li = no->prox;
    else
        ant->prox = no->prox;
    free(no);
    return 1;
}

int remove_lista_din(ListaDinEncad* li, struct aluno al){
    if(li == NULL)
        return 0;
    Elem *ant, *no = *li;
    while(no != NULL && no->dados.matricula != al.matricula){
        ant = no;
        no = no->prox;
    }
    if(no == NULL)
        return 0;
    if(no == *li)
        *li = no->prox;
    else
        ant->prox = no->prox;
    free(no);
    return 1;
}

void libera_lista_din(ListaDinEncad* li) {
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