// Busca
//  - Tipo de busca depende dos dados
//      - Dados estão estruturados. (Vetor, lista, árvore...)
//      - Dados não estruturados
//      - Dados ordenados
//      - Dados não ordenados
//      - Valores duplicados
//  - Nesse estudo será abordados
//      - Dados armazenados em um vetor
//      - Ordenados
//  - Métodos
//      - Busca Linear
//      - Buscar Ordenada -> Dados ordenados
//      - Busca Binária -> Dados ordenados

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "aluno.h"

int busca_linear(int *v, int tam, int elem){
    int i;
    for(i = 0; i < tam; i++){
        if(elem == v[i])
            return i;
    }
    return -1;
}

int busca_ordenada(int *v, int tam, int elem){
    int i;
    for(i = 0; i < tam; i++){
        if(elem == v[i])
            return i;
        else
            if(elem < v[i])
                return -1;
    }
    return -1;
}

int busca_binaria(int *v, int tam, int elem){
    int i, inicio, meio, final;
    inicio = 0;
    final = tam-1;
    while(inicio <= final) {
        meio = (inicio + final) / 2;
        if(elem < v[meio])
            final = meio - 1;
        else
            if(elem > v[meio])
                inicio = meio + 1;
            else
                return meio;
    }
    return -1;
}

int busca_linear_matricula(struct aluno *v, int tam, int elem){
    int i;
    for(i = 0; i < tam; i++){
        if(elem == v[i].matricula)
            return i;
    }
    return -1;
}

int busca_linear_nome(struct aluno *v, int tam, char *elem){
    int i;
    for(i = 0; i < tam; i++){
        if(strcmp(elem, v[i].nome) == 0)
            return i;
    }
    return -1;
}

int main(){
    int *vetor = (int*)malloc(10*sizeof(int));
    int i, indice;

    struct aluno vet[6];

    for(i = 0; i < 10; i++)
        vetor[i] = i * 2;

    printf("\n### BUSCA EM VETOR ###\n");
    indice = busca_linear(vetor, 10, 8);
    printf("\nBusca Linear -> Indice = %d\n", indice);

    indice = busca_ordenada(vetor, 10, 9);
    printf("\nBusca Ordenada -> Indice = %d\n", indice);

    indice = busca_binaria(vetor, 10, 8);
    printf("\nBusca Binária -> Indice = %d\n\n", indice);

    vet[0].matricula = 1;
    strcpy(vet[0].nome, "Marcelo");
    vet[0].n1 = 8;
    vet[0].n1 = 10;
    vet[0].n1 = 9;

    vet[1].matricula = 2;
    strcpy(vet[1].nome, "Wallace");
    vet[1].n1 = 6;
    vet[1].n1 = 7;
    vet[1].n1 = 9;

    vet[2].matricula = 3;
    strcpy(vet[2].nome, "Bob");
    vet[2].n1 = 4;
    vet[2].n1 = 5;
    vet[2].n1 = 10;

    vet[3].matricula = 4;
    strcpy(vet[3].nome, "Rico");
    vet[3].n1 = 2;
    vet[3].n1 = 1;
    vet[3].n1 = 7;

    vet[4].matricula = 5;
    strcpy(vet[4].nome, "Sama");
    vet[4].n1 = 10;
    vet[4].n1 = 7;
    vet[4].n1 = 9;

    vet[5].matricula = 6;
    strcpy(vet[5].nome, "Ravena");
    vet[5].n1 = 10;
    vet[5].n1 = 8;
    vet[5].n1 = 10;

    printf("\n### BUSCA EM VETOR DE STRUCT ###\n");

    indice = busca_linear_matricula(vet, 6, 5);
    printf("\nBusca Linear Matricula -> Indice = %d\n", indice);

    indice = busca_linear_nome(vet, 6, "Ravena");
    printf("\nBusca Linear Nome -> Indice = %d\n", indice);

    return 0;
}