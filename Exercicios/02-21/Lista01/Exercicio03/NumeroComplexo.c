#include <stdlib.h>
#include <stdio.h>
#include "NumeroComplexo.h"

struct numero_complexo{
    float real;
    float imaginario;
};

NumeroComplexo* cria_numero(){
    NumeroComplexo* n = (NumeroComplexo*)malloc(sizeof(NumeroComplexo));
    return n;
}

void atribui_numero(NumeroComplexo* n, float r, float i) {
    if (n != NULL) {
        n->real = r;
        n->imaginario = i;
    }
}

void imprime_numero(NumeroComplexo* n) {
    printf("\n\n\t%.2f + %.2f i\n", n->real, n->imaginario);
}

void copia_numero(NumeroComplexo* n1, NumeroComplexo* n2) {
    n2->real = n1->real;
    n2->imaginario = n1->imaginario;
}

NumeroComplexo* soma(NumeroComplexo* n1, NumeroComplexo* n2) {

    NumeroComplexo* soma = cria_numero();

    float soma_real, soma_imaginario;

    soma_real = n1->real + n2->real;
    soma_imaginario = n1->imaginario + n2->imaginario;

    atribui_numero(soma, soma_real, soma_imaginario);

    return soma;
}

void libera_numero(NumeroComplexo* n) {
    free(n);
}
