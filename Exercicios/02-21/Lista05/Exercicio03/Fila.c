#include "stdlib.h"
#include "stdio.h"
#include "Fila.h"

struct fila{
    int qtd;
    int elens[100];
};

Fila* cria_fila(){
    Fila *fi = (Fila*)malloc(sizeof(Fila));
    if(fi != NULL){
        fi->qtd = 0;
        fi->elens[0] = 0;
        fi->elens[1] = 0;
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
        int pos = fi->elens[0] + i;
        fi->elens[i+2] = fi->elens[pos];
    }
    fi->elens[0] = 2;
    fi->elens[1] = fi->qtd + 1;
    return 1;
}

int enfileira(Fila *fi, int num){
    if(fi == NULL)
        return 0;
    if(fi->qtd == 98)
        return 0;
    if(fi->elens[0] == 0 && fi->elens[1] == 0){
        fi->elens[2] = num;
        fi->elens[0] = 2;
        fi->elens[1] = 2;
    }
    else{
        fi->elens[1]++;
        if(fi->elens[1] == 100){
            deslocar(fi);
        }
        fi->elens[fi->elens[1]] = num;
    }
}

int desenfileira(Fila *fi){
    if(fi == NULL || vazia(fi))
        return 0;
    fi->elens[0]++;
    if(fi->elens[0] == 100){
        deslocar(fi);
    }
    fi->qtd--;
    return 1;
}

void libera_fila(Fila *fi){
    free(fi);
}