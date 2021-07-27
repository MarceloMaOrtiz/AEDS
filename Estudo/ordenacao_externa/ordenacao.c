// Ordenação Externa
//  - Consiste em Ordenar conjuntos de dados maiores do que a memória
//      interna disponível
//  - Ordenação deve ser feita em arquivos
//  - Os algoritmos devem minimizar o número de acessos às unidades de
//      memória externa
//  - Diferença em relação a Ordenação Interna
//      - Custo de acesso a memória secundária é muito maior
//      - Transferência de dados entre a memória interna e externa
//      - Acesso sequencial aos dados (Acesso direto é muito caro)
//  - MergeSort Externo
//      - Método mais importante de ordenação externa
//      - Intercalação
//          - Combina dois ou mais blocos ordenados em um único bloco,
//              maior, ordenado
//      - Funcionamento
//          - RAM comporta "N" registros de Dados
//          - Carregar parte do arquivo na RAM
//          - Ordenar os dados na RAM com um algoritmo in-place (ex. QuickSort)
//          - Salvar os dados ordenados em um arquivo separado
//          - Repetir os passos anteriores até terminar o arquivo original
//              - Ao final, temos "K" arquivos ordenados
//          - "Multi-Way Merging"
//              - Criar "K+1" buffers de tamanho "N / (K + 1)"
//                  - 1 de Saída
//                  - K de Entrada
//              - Carregar parte dos arquivos ordenados nos Buffers de Entrada,
//                  intercalar no Buffer de Saída
//              - Buffer de Entrada "Vazio" -> Carregar mais Dados
//              - Buffer de Saída "Cheio" -> Salvar Dados

#include "stdio.h"
#include "stdlib.h"
#include "time.h"

#define N 100

struct arquivo{
    FILE *f;
    int pos, MAX, *buffer;
};

void cria_arquivo_teste(char *nome){
    int i;
    FILE *f = fopen(nome, "w");
    srand(time(NULL));
    for(i = 1; i < 1000; i++)
        fprintf(f, "%d\n", rand());
    fprintf(f, "%d", rand());
    fclose(f);
}

void salvar_arquivo(char *nome, int *v, int tam, int muda_linha_final){
    int i;
    FILE *f = fopen(nome, "a");
    for(i = 0; i < tam-1; i++)
        fprintf(f, "%d\n", v[i]);
    if(muda_linha_final == 0)
        fprintf(f, "%d", v[tam-1]);
    else
        fprintf(f, "%d\n", v[tam-1]);
    fclose(f);
}

int compara (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int cria_arquivos_ordenados(char *nome){
    int v[N], cont = 0, total = 0;
    char novo[20];
    FILE *f = fopen(nome, "r");
    while(!feof(f)){
        fscanf(f, "%d", &v[total]);
        total++;
        if(total == N){
            cont++;
            sprintf(novo, "Temp%d.txt", cont);
            qsort(v, total, sizeof(int), compara);
            salvar_arquivo(novo, v, total, 0);
            total = 0;
        }
    }
    if(total > 0){
        cont++;
        sprintf(novo, "Temp%d.txt", cont);
        qsort(v, total, sizeof(int), compara);
        salvar_arquivo(novo, v, total, 0);
    }
    fclose(f);
    return cont;
}

void preenche_buffer(struct arquivo* arq, int k){
    int i;
    if(arq->f == NULL)
        return;
    arq->pos = 0;
    arq->MAX = 0;
    for(i = 0; i < k; i++){
        if(!feof(arq->f)){
            fscanf(arq->f, "%d", &arq->buffer[arq->MAX]);
            arq->MAX++;
        }else{
            fclose(arq->f);
            arq->f = NULL;
            break;
        }
    }
}

int procura_menor(struct arquivo *arq, int num_arqs, int k, int *menor){
    int i, idx = -1;
    for(i = 0; i < num_arqs; i++){
        if(arq[i].pos < arq[i].MAX){
            if(idx == -1)
                idx = i;
            else{
                if(arq[i].buffer[arq[i].pos] < arq[idx].buffer[arq[idx].pos])
                    idx = i;
            }
        }
    }
    if(idx != -1){
        *menor = arq[idx].buffer[arq[idx].pos];
        arq[idx].pos++;
        if(arq[idx].pos == arq[idx].MAX)
            preenche_buffer(&arq[idx], k);
        return 1;
    }else
        return 0;
}

void merge(char *nome, int num_arqs, int k){
    char novo[20];
    int i;
    int *buffer = (int*)malloc(k*sizeof(int));
    struct arquivo *arq;
    arq = (struct arquivo*)malloc(num_arqs*sizeof(struct arquivo));
    for(i = 0; i < num_arqs; i++){
        sprintf(novo, "Temp%d.txt", i+1);
        arq[i].f = fopen(novo, "r");
        arq[i].MAX = 0;
        arq[i].pos = 0;
        arq[i].buffer = (int*)malloc(k*sizeof(int));
        preenche_buffer(&arq[i], k);
    }
    int menor, qtd_buffer = 0;
    // Enquanto houver arquivos para processar
    while(procura_menor(arq, num_arqs, k, &menor) == 1){
        buffer[qtd_buffer] = menor;
        qtd_buffer++;
        if(qtd_buffer == k){
            salvar_arquivo(nome, buffer, k, 1);
            qtd_buffer = 0;
        }
    }
    // Salva dados ainda no buffer
    if(qtd_buffer != 0)
        salvar_arquivo(nome, buffer, qtd_buffer, 1);
    for(i = 0; i < num_arqs; i++)
        free(arq[i].buffer);
    free(arq);
    free(buffer);
}

void merge_sort_externo(char *nome){
    char novo[20];
    int num_arqs = cria_arquivos_ordenados(nome);
    int i, k = N / (num_arqs + 1);
    remove(nome);
    merge(nome, num_arqs, k);
    for(i = 0; i < num_arqs; i++){
        sprintf(novo, "Temp%d.txt", i+1);
        remove(novo);
    }
}

int main(){
    cria_arquivo_teste("dados.txt");
    merge_sort_externo("dados.txt");

    return 0;
}