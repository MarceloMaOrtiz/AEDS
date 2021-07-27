// Definição
//  - Tipo de dado grafo
//  - Implementação das funções

#include "stdlib.h"
#include "stdio.h"
#include "ListaGrafo.h"

struct grafo{
    int eh_ponderado;
    int nro_vertices;
    int grau_max;
    int **arestas;
    float **pesos;
    int *grau;
};

Grafo *cria_grafo(int nro_vertices, int grau_max, int eh_ponderado){
    Grafo *gr = (Grafo*)malloc(sizeof(struct grafo));
    if(gr != NULL){
        int i;
        gr->nro_vertices = nro_vertices;
        gr->grau_max = grau_max;
        gr->eh_ponderado = eh_ponderado;
        gr->grau = (int*)malloc(nro_vertices*sizeof(int));
        gr->arestas = (int**)malloc(nro_vertices*sizeof(int*));
        for(i = 0; i < nro_vertices; i++){
            gr->arestas[i] = (int*)malloc(grau_max*sizeof(int));
            if(gr->eh_ponderado){
                gr->pesos = (float**)malloc(nro_vertices*sizeof(float*));
                for(i = 0; i < nro_vertices; i++){
                    gr->pesos[i] = (float*)malloc(grau_max*sizeof(float));
                }
            }
        }
    }
    return gr;
}

int insere_aresta(Grafo *gr, int orig, int dest, int eh_digrafo, float peso){
    if(gr == NULL)
        return 0;
    if(orig < 0 || orig >= gr->nro_vertices)
        return 0;
    if(dest < 0 || dest >= gr->nro_vertices)
        return 0;
    gr->arestas[orig][gr->grau[orig]] = dest;
    if(gr->eh_ponderado)
        gr->pesos[orig][gr->grau[orig]] = peso;
    gr->grau[orig]++;
    if(eh_digrafo == 0)
        insere_aresta(gr, dest, orig, 1, peso); // 1 Para evitar o loop infinito
    return 1;
}

int remove_aresta(Grafo *gr, int orig, int dest, int eh_digrafo){
    if(gr == NULL)
        return 0;
    if(orig < 0 || orig >= gr->nro_vertices)
        return 0;
    if(dest < 0 || dest >= gr->nro_vertices)
        return 0;
    int i = 0;
    while(i < gr->grau[orig] && gr->arestas[orig][i] != dest)
        i++;
    if(i == gr->grau[orig])
        return 0;
    gr->grau[orig]--;
    gr->arestas[orig][i] = gr->arestas[orig][gr->grau[orig]];
    if(gr->eh_ponderado)
        gr->pesos[orig][i] = gr->pesos[orig][gr->grau[orig]];
    if(eh_digrafo == 0)
        remove_aresta(gr, dest, orig, 1);
    return 1;
}

// Função Auxiliar: Realiza o Cálculo
void busca_profundidade_calc(Grafo *gr, int ini, int *visitado, int cont){
    int i;
    visitado[ini] = cont;
    for(i = 0; i < gr->grau[ini]; i++){
        if(!visitado[gr->arestas[ini][i]])
            busca_profundidade_calc(gr, gr->arestas[ini][i], visitado, cont+1);
    }
}

// Função Principal: Interface com o Usuário
void busca_profundidade(Grafo *gr, int ini, int *visitado){
    int i, cont = 1;
    for(i = 0; i < gr->nro_vertices; i++){
        visitado[i] = 0;
    }
    busca_profundidade_calc(gr, ini, visitado, cont);
}


void busca_largura(Grafo *gr, int ini, int *visitado){
    int i, vert, nro_vertices, cont = 1, *fila, ini_fila = 0, fim_fila = 0;
    for(i = 0; i < gr->nro_vertices; i++)
        visitado[i] = 0;
    nro_vertices = gr->nro_vertices;
    fila = (int*)malloc(nro_vertices*sizeof(int));
    fim_fila++;
    fila[fim_fila] = ini;
    visitado[ini] = cont;
    while(ini_fila != fim_fila){
        ini_fila = (ini_fila + 1) % nro_vertices;
        vert = fila[ini_fila];
        cont++;
        for(i = 0; i < gr->grau[vert]; i++){
            if(!visitado[gr->arestas[vert][i]]){
                fim_fila = (fim_fila + 1) % nro_vertices;
                fila[fim_fila] = gr->arestas[vert][i];
                visitado[gr->arestas[vert][i]] = cont;
            }
        }
    }
    free(fila);
}

// Função Auxiliar: Procura vértice com menor distância
int procura_menor_distancia(float *dist, int *visitado, int nro_vertices){
    int i, menor = -1, primeiro = 1;
    for(i = 0; i < nro_vertices; i++){
        if(dist[i] >= 0 && visitado[i] == 0){
            if(primeiro){
                menor = i;
                primeiro = 0;
            }else{
                if(dist[menor] > dist [i])
                    menor = i;
            }
        }
    }
    return menor;
}

// Função Principal: Interface com Usuário
void menor_caminho(Grafo *gr, int ini, int *ant, float *dist){
    int i, cont, nro_vertices, ind, *visitado, u;
    nro_vertices = gr->nro_vertices;
    cont = nro_vertices;
    visitado = (int*)malloc(nro_vertices*sizeof(int));
    for(i = 0; i < nro_vertices; i++){
        ant[i] = -1;
        dist[i] = -1;
        visitado[i] = 0;
    }
    dist[ini] = 0;
    while(cont > 0){
        u = procura_menor_distancia(dist, visitado, nro_vertices);
        if(u == -1)
            break;
        visitado[u] = 1;
        cont--;
        for(i = 0; i < gr->grau[u]; i++){
            ind = gr->arestas[u][i];
            if(dist[ind] < 0){
                dist[ind] = dist[u] + 1;
                // Ou peso da Aresta
                // dist[ind] = dist[u] + gr->pesos[u][i];
                ant[ind] = u;
            }else{
                if(dist[ind] > dist[u] + 1){
                    dist[ind] = dist[u] + 1;
                    // Ou peso da Aresta
                    // dist[ind] = dist[u] + gr->pesos[u][i];
                    ant[ind] = u;
                }
            }
        }
    }
    free(visitado);
}

void libera_grafo(Grafo *gr){
    if(gr != NULL){
        int i;
        for(i = 0; i < gr->nro_vertices; i++)
            free(gr->arestas[i]);
        free(gr->arestas);
        if(gr->eh_ponderado){
            for(i = 0; i < gr->nro_vertices; i++)
                free(gr->pesos[i]);
            free(gr->pesos);
        }
        free(gr->grau);
        free(gr);
    }
}