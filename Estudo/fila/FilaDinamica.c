// O tipo de dados "fila"
// Implementar as suas funções

#include "stdlib.h"
#include "stdio.h"
#include "aluno.h"
#include "FilaDinamica.h"

struct fila_dinamica{
    struct elemento *inicio;
    struct elemento *final;
};

struct elemento{
    struct aluno dados;
    struct elemento *prox;
};
typedef struct elemento Elem;

FilaDinamica* cria_fila_dinamica() {
    FilaDinamica *fi = (FilaDinamica*)malloc(sizeof(FilaDinamica));
    if(fi != NULL){
        fi->final = NULL;
        fi->inicio = NULL;
    }
    return fi;
}

int fila_dinamica_vazia(FilaDinamica* fi){
    if(fi == NULL)
        return 1;
    if(fi->inicio == NULL)
        return 1;
    return 0;
}

int insere_fila_dinamica(FilaDinamica* fi, struct aluno al) {
    if(fi == NULL)
        return 0;
    Elem *no = (Elem*)malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dados = al;
    no->prox = NULL;
    if(fi->final == NULL) // Insere na Fila Vazia
        fi->inicio = no;
    else
        fi->final->prox = no;
    fi->final = no;
    return 1;
}

int consulta_fila_dinamica(FilaDinamica* fi, struct aluno *al) {
    if(fi == NULL)
        return 0;
    if(fi->inicio == NULL)
        return 0;
    *al = fi->inicio->dados;
    return 1;
}

int remove_fila_dinamica(FilaDinamica* fi) {
    if(fi == NULL)
        return 0;
    if(fi->inicio == NULL)
        return 0;
    Elem *no = fi->inicio;
    fi->inicio = fi->inicio->prox;
    if(fi->inicio == NULL) // Verifica se fila ficou vazia
        fi->final = NULL;
    free(no);
    return 1;
}

void libera_fila_dinamica(FilaDinamica* fi) {
    if(fi != NULL){
        Elem *no;
        while(fi->inicio != NULL){
            no = fi->inicio;
            fi->inicio = fi->inicio->prox;
            free(no);
        }
        free(fi);
    }
}