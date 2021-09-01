#include "stdlib.h"
#include "stdio.h"
#include "ListaGrafo.h"

int main(){
    // Grafo *gr;
    // gr = cria_grafo(10, 7, 0);
    // insere_aresta(gr, 0, 1, 0, 0);
    // insere_aresta(gr, 1, 2, 0, 0);
    // insere_aresta(gr, 2, 5, 0, 0);
    // insere_aresta(gr, 5, 3, 0, 0);
    // insere_aresta(gr, 3, 4, 0, 0);
    // remove_aresta(gr, 3, 4, 0);
    // remove_aresta(gr, 5, 3, 0);
    // libera_grafo(gr);

    Grafo *gr;
    int eh_digrafo = 1;
    gr = cria_grafo(5, 5, 0);
    insere_aresta(gr, 0, 1, eh_digrafo, 0);
    insere_aresta(gr, 1, 3, eh_digrafo, 0);
    insere_aresta(gr, 1, 2, eh_digrafo, 0);
    insere_aresta(gr, 2, 4, eh_digrafo, 0);
    insere_aresta(gr, 3, 0, eh_digrafo, 0);
    insere_aresta(gr, 3, 4, eh_digrafo, 0);
    insere_aresta(gr, 4, 1, eh_digrafo, 0);
    int visita_profundidade[5];
    busca_profundidade(gr, 0, visita_profundidade);
    int visita_largura[5];
    busca_largura(gr, 0, visita_largura);
    int anterior_menor_caminho[5];
    float distancia_menor_caminho[5];
    menor_caminho(gr, 0, anterior_menor_caminho, distancia_menor_caminho);
    libera_grafo(gr);
    return 0;
}
