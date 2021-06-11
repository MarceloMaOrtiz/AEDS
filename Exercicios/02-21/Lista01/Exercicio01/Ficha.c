#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Ficha.h"

struct ficha{
    int inscricao;
    char nome[30];
    int classe; 
    int horas_normal;
    int horas_extra;
};

Ficha* cria_ficha(int inscricao, char nome[], int classe, int hrs_normal, int hrs_extra){
    Ficha* f = (Ficha*)malloc(sizeof(Ficha));
    if (f != NULL){
        f->inscricao = inscricao;
        strcpy(f->nome, nome);
        f->classe = classe;
        f->horas_normal = hrs_normal;
        f->horas_extra = hrs_extra;
    }
    return f;
}

void libera_ficha(Ficha* f) {
    free(f);
}

void imprime_contracheque(Ficha* f, float salario_base) {
    if (f->classe == 1)
        salario_base = salario_base * 1.3;
    else if (f->classe == 2)
        salario_base = salario_base * 1.9;
    else {
        printf("\tClasse Inválida\n\n");
        return;
    }
    float salario_normal = salario_base * f->horas_normal;
    float salario_extra = salario_base * 1.3 * f->horas_extra;
    float salario_bruto = salario_normal + salario_extra;
    float inss = salario_bruto * 0.11;
    float salario_liquido = salario_bruto - inss;

    printf("\tNUMERO DE INSCRICAO: %d\n", f->inscricao);
    printf("\tNOME: %s\n", f->nome);
    printf("\tSALARIO HORAS NORMAIS: R$ %.2f\n", salario_normal);
    printf("\tSALARIO HORAS EXTRAS: R$ %.2f\n", salario_extra);
    printf("\tDEDUCAO INSS: R$ %.2f\n", inss);
    printf("\tSALARIO LIQUIDO: R$ %.2f\n\n", salario_liquido);
}