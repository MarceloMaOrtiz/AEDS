#include "stdlib.h"
#include "stdio.h"
#include "Fila.h"

struct fila{
    int inicio, final, qtd;
    int ids[4];
};

typedef struct fila Fila;

Fila* cria_fila(){
    Fila *fi = (Fila*)malloc(sizeof(Fila));
    if(fi != NULL){
        fi->inicio = 0;
        fi->final = 0;
        fi->qtd = 0;
    }
    return fi;
}

int vazia(Fila *fi){
    if(fi == NULL || fi->qtd == 0)
        return 1;
    else
        return 0;
}

int deslocar(Fila *fi){
    if(fi == NULL)
        return 0;
    for(int i = 0; i < fi->qtd; i++){
        int pos = fi->inicio + i;
        fi->ids[i] = fi->ids[pos];
    }
    fi->inicio = 0;
    fi->final = fi->qtd - 1;
    return 1;
}

int enfileira(Fila *fi, int ID){
    if(fi == NULL || fi->qtd == 100)
        return 0;
    fi->ids[fi->final] = ID;
    fi->final++;
    if(fi->final == 100){
        deslocar(fi);
    }
    fi->qtd++;
    return 1;
}

int desenfileira(Fila *fi){
    if(fi == NULL || vazia(fi))
        return 0;
    fi->inicio++;
    if(fi->inicio == 100){
        deslocar(fi);
    }
    fi->qtd--;
    return 1;
}

void libera_fila(Fila *fi){
    free(fi);
}