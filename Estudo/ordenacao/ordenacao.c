// Ordenação
//  - Permite acesso mais eficiente aos dados
//  - Classificação dos métodos de ordenação
//      - Ordenação Interna -> Nessas aulas, só serão visto esses métodos
//          - O arquivo a ser ordenado cabe todo na memória principal
//          - Qualquer registro pode ser imediatamente acessado
//      - Ordenação Externa
//          - O arquivo a ser ordenado não cabe na memória principal
//          - Os registros são acessados sequencialmente ou em grandes blocos
//  - Métodos de ornenação que serão estudados
//      - Básicos -> em geral O(N²)
//          - Fácil implementação
//          - Auxiliam o entendimento dos algoritmos complexos
//      - Sofisticados -> em geral O(n*log(n))
//          - Melhor desempenho

#include "stdio.h"
#include "stdlib.h"
// #include "string.h"
// #include "aluno.h"

// BubbleSort
//  - Compara pares de elementos adjacentes e os troca de lugar se estiverem na ordem errada
//  - Esse processo se repete até que mais nenhuma troca seja necessária (elementos já ordenados)
//  - Performance
//      - Melhor Caso: O(n)
//      - Pior Caso: O(n²)
//      - Não recomentado para grande conjuntos de dados
void bubble_sort(int *v, int tam){
    int i, continua, aux, fim = tam;
    do{
        continua = 0;
        for(i = 0; i < fim - 1; i++){
            if(v[i] > v[i+1]){
                aux = v[i];
                v[i] = v[i+1];
                v[i+1] = aux;
                continua = 1;
            }
        }
    }while(continua != 0);
}

// InsertionSort
//  - Similar Ordenação de cartas de baralho com as mãos
//      - Pega-se uma carta de cada vez e a coloca em seu devido lugar, sempre deixando as cartas
//          da mão em ordem
//  - Performance
//      - Melhor Caso: O(n)
//      - Pior Caso: O(n²)
//      - Eficiente para conjuntos pequenos de dados
//      - Estável: Não altera a ordem de dados iguais
//      - Capaz de ordenar os dados a medida em que os recebe (tempo real)
void insertion_sort(int *v, int tam){
    int i, j, aux;
    for(i = 1; i < tam; i++){
        aux = v[i];
        for(j = i; (j > 0) && (aux < v[j-1]); j--)
            v[j] = v[j-1];
        v[j] = aux;
    }
}

// SelectionSort
//  - A cada passo, procura o menor valor do array e o coloca na primeira posição do array
//  - Descarta-se a primeira posição do array e repete-se o processo para a segunda posição
//  - Isso é feito para todas as posições do array
//  - Performance
//      - Melhor Caso: O(n²)
//      - Pior Caso: O(n²)
//      - Ineficiente para grandes conjuntos de dados
//      - Estável: Não altera a ordem de dados iguais
void selection_sort(int *v, int tam){
    int i, j, menor, troca;
    for(i = 0; i < tam-1; i++){
        menor = i;
        for(j = i+1; j < tam; j++){
            if(v[j] < v[menor])
                menor = j;
        }
        if(i != menor){
            troca = v[i];
            v[i] = v[menor];
            v[menor] = troca;
        }
    }
}

void imprimir(int *v, int tam){
    printf("\n[");
    for(int i = 0; i < tam; i++)
        printf("%d, ", v[i]);
    printf("]\n");
}

int main(){
    printf("\n### ORDENAÇÃO ###\n");

    int vetor_bubble[10] = {4, 5, 3, 2, 1, 9, 7, 0, 8, 6};
    printf("\n - BubbleSort\n");
    imprimir(vetor_bubble, 10);
    bubble_sort(vetor_bubble, 10);
    imprimir(vetor_bubble, 10);

    int vetor_insertion[10] = {4, 5, 3, 2, 1, 9, 7, 0, 8, 6};
    printf("\n - InsertionSort\n");
    imprimir(vetor_insertion, 10);
    insertion_sort(vetor_insertion, 10);
    imprimir(vetor_insertion, 10);

    int vetor_selection[10] = {4, 5, 3, 2, 1, 9, 7, 0, 8, 6};
    printf("\n - SelectionSort\n");
    imprimir(vetor_selection, 10);
    selection_sort(vetor_selection, 10);
    imprimir(vetor_selection, 10);

    return 0;
}