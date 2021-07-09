// O Sucessor de um elemento ocupa a posição física seguinte
// O tipo de dados "fila"
// Implementar as suas funções

#include "stdlib.h"
#include "stdio.h"
#include "aluno.h"
#include "FilaEstatica.h"

struct fila{
    int inicio, final, qtd;
    struct aluno dados[MAX];
};

FilaEstatica* cria_fila_estatica() {
    FilaEstatica *fi = (FilaEstatica*)malloc(sizeof(struct fila));
    if(fi != NULL) {
        fi->inicio = 0;
        fi->final = 0;
        fi->qtd = 0;
    }
    return fi;
}

int fila_estatica_vazia(FilaEstatica* fi) {
    if(fi == NULL)
        return 1;
    if(fi->qtd == 0)
        return 1;
    else
        return 0;
}

int fila_estatica_cheia(FilaEstatica* fi) {
    if(fi == NULL)
        return 0;
    if(fi->qtd == MAX)
        return 1;
    else
        return 0;
}

int insere_fila_estatica(FilaEstatica* fi, struct aluno al) {
    if(fi == NULL)
        return 0;
    if(fila_estatica_cheia(fi))
        return 0;
    fi->dados[fi->final] = al;
    // % MAX gerou uma circuncidade na fila, portanto quando tivermos final = 100, a divisão
    // será feita por 100 e o resto que é 0, fará com que o final seja a posição 0.
    fi->final = (fi->final + 1) % MAX;
    fi->qtd++;
    return 1;
}

int consulta_fila_estatica(FilaEstatica* fi, struct aluno *al) {
    if(fi == NULL || fila_estatica_vazia(fi))
        return 0;
    *al = fi->dados[fi->inicio];
    return 1;
}

int remove_fila_estatica(FilaEstatica* fi) {
    if(fi == NULL || fila_estatica_vazia(fi))
        return 0;
    // fi->inicio = (fi->inicio+1) % MAX;
    // É possível ao invés de utilizar o MAX acima utilizar if
    fi->inicio++;
    if(fi->inicio == MAX)
        fi->inicio = 0;
    fi->qtd--;
    return 1;
}

void libera_fila_estatica(FilaEstatica* fi) {
    free(fi);
}