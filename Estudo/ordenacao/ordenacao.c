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
#include "math.h"

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

// ShellSort
//  - É uma extensão do InsertionSort
//  - Contorna um problema do InsertionSort
//      - No insertion, quando o menor item está na ultima posição, o algoritmo faz n-1 comparações
//      - No ShellSort, permite a troca de registros mais distantes
//  - Os itens separados de h posições são rearranjados
//      - Todo h-esimo item leva a uma sequenção ordenada (Sequência estará h-ordenada)
//      - Quando h = 1, Shellsort corresponde ao InsertionSort
//  - Performance
//      - A eficiência do algoritmo ainda não é conhecida
//          - Ocorre por conta dos incrementos no h
//      - Ótima opção para arquivos de tamanho moderado
//      - Tempo de execução do algoritmo é sensível à ordem incial do arquivo
//      - Não estável: Altera a ordem de dados iguais
void shell_sort(int *v, int tam){
    int i, j, h = 1;
    int x;
    do{
        h = h * 3 + 1;
    }while(h < tam);
    do{
        h = h / 3;
        for(i = h; i < tam; i++){
            x = v[i];
            j = i - h;
            while(j >= 0 && v[j] > x){
                v[j+h] = v[j];
                j = j - h;
            }
            v[j+h] = x;
        }
    }while(h > 1);
}

// MergeSort
//  - Ideia Básica
//      - Dividir e Conquistar
//          - Divide, recursivamente, o conjunto de dados até que cada subconjunto
//              possua 1 elemento
//          - Combina 2 subconjuntos de forma a obter 1 subconjunto maior e ordenado
//          - Processo se repete até existir 1 conjunto
//  - Performance
//      - Melhor Caso: O(n*log(n))
//      - Pior Caso: O(n*log(n))
//      - Estável: Não altera a ordem de dados iguais
//      - Desvatagens
//          - Recursivo
//          - Usa um vetor auxiliar durante a ordenação
void merge(int *v, int inicio, int meio, int fim){
    int *temp, p1, p2, tamanho, i, j, k;
    int fim1 = 0, fim2 = 0.;
    tamanho = fim - inicio + 1;
    p1 = inicio;
    p2 = meio + 1;
    temp = (int*)malloc(tamanho*sizeof(int));
    if(temp != NULL){
        for(i = 0; i < tamanho; i++){
            if(!fim1 && !fim2){
                if(v[p1] < v[p2])
                    temp[i] = v[p1++];
                else
                    temp[i] = v[p2++];
                if(p1 > meio)
                    fim1 = 1;
                if(p2 > fim)
                    fim2 = 1;
            }else{
                if(!fim1)
                    temp[i] = v[p1++];
                else
                    temp[i] = v[p2++];
            }
        }
        for(j = 0, k = inicio; j < tamanho; j++, k++)
            v[k] = temp[j];
    }
    free(temp);
}

void merge_sort(int *v, int inicio, int fim){
    int meio;
    if(inicio < fim){
        meio = floor((inicio+fim)/2);
        merge_sort(v, inicio, meio);
        merge_sort(v, meio+1, fim);
        merge(v, inicio, meio, fim);
    }
}

// QuickSort
//  - Ideia Básica
//      - Dividir e Conquistar
//      - Um elemento é escolhido como pivô
//      - O dados são rearranjados
//          - Valores menores que o pivô são colocados antes dele e os maiores, depois
//      - recursivamente ordena as duas partições
//  - Performance
//      - Melhor Caso: O(n*log(n))
//      - Pior Caso: O(n²)
//      - Estável: Não altera a ordem de dados iguais
//      - Desvantagens
//          - Como escolher o pivô?
int particiona(int *v, int inicio, int final){
    int esq, dir, pivo, aux;
    esq = inicio;
    dir = final;
    pivo = v[inicio];
    while(esq < dir){
        while(v[esq] <= pivo)
            esq++;
        while(v[dir] > pivo)
            dir --;
        if(esq < dir){
            aux = v[esq];
            v[esq] = v[dir];
            v[dir] = aux;
        }
    }
    v[inicio] = v[dir];
    v[dir] = pivo;
    return dir;
}

void quick_sort(int *v, int inicio, int fim){
    int pivo;
    if(fim > inicio){
        pivo = particiona(v, inicio, fim);
        quick_sort(v, inicio, pivo-1);
        quick_sort(v, pivo+1, fim);
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

    int vetor_shell[10] = {4, 5, 3, 2, 1, 9, 7, 0, 8, 6};
    printf("\n - ShellSort\n");
    imprimir(vetor_shell, 10);
    shell_sort(vetor_shell, 10);
    imprimir(vetor_shell, 10);

    int vetor_merge[10] = {4, 5, 3, 2, 1, 9, 7, 0, 8, 6};
    printf("\n - MergeSort\n");
    imprimir(vetor_merge, 10);
    merge_sort(vetor_merge, 0, 9);
    imprimir(vetor_merge, 10);

    int vetor_quick[10] = {4, 5, 3, 2, 1, 9, 7, 0, 8, 6};
    printf("\n - QuickSort\n");
    imprimir(vetor_quick, 10);
    quick_sort(vetor_quick, 0, 9);
    imprimir(vetor_quick, 10);

    return 0;
}