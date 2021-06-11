#include <stdlib.h>
#include <stdio.h>
#include "Livro.h"

struct livro {
    char titulo[150];
    char autor[150];
    float precos[6];
};

// Função auxiliar para limpar o buffer do teclado
void fflush_stdin(){
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

Livro* cria_livro() {
    Livro* l = (Livro*)malloc(sizeof(Livro));
    return l;
}

void atribui_livros(Livro** livros, int tam){
    for (int i = 0; i < tam; i++){
        livros[i] = cria_livro();
        printf("\n\t### Livro %d\n\n", (i + 1));
        printf("\tTitulo: ");
        fgets(livros[i]->titulo, 150, stdin);
        // scanf("%s", &(livros[i]->titulo));
        printf("\n\tAutor: ");
        fgets(livros[i]->autor, 150, stdin);
        // scanf("%s", &(livros[i]->autor));
        printf("\n\tPrecos: \n");
        for(int j = 0; j < 6; j++) {
            printf(" %d- ", (j+1));
            scanf("%f", &(livros[i]->precos[j]));
        }
        fflush_stdin();
    }
}

void preco_medio(Livro **livros, int tam){

    float caro = 0;
    float barato = 0;

    int index_caro = 0;
    int index_barato = 0;

    for (int i = 0; i < tam; i++){
        float somatorio = 0;
        float media = 0;
        for (int j = 0; j < 6; j++) {
            somatorio = somatorio + livros[i]->precos[j];
        }
        media = somatorio / 6;
        printf("\n\n\tLivro %d\n", (i+1));
        printf("\n\t Titulo: %s\n", livros[i]->titulo);
        printf("\n\t Autor: %s\n", livros[i]->autor);
        printf("\n\tMedia: R$ %.2f\n", media);
        if (i == 0) {
            caro = media;
            barato = media;
        }
        else {
            if (media > caro) {
                caro = media;
                index_caro = i;
            }
            else if (media < barato){
                barato = media;
                index_barato = i;
            }
            else {
                continue;
            }
        }
    }

    printf("\n\t## Livro mais caro ##\n\n");
    printf("\tTitulo: %s\n", livros[index_caro]->titulo);
    printf("\tAutor: %s\n", livros[index_caro]->autor);
    printf("\tPreco medio: R$ %.2f\n", caro);

    printf("\n\t## Livro mais barato ##\n\n");
    printf("\tTitulo: %s\n", livros[index_barato]->titulo);
    printf("\tAutor: %s\n", livros[index_barato]->autor);
    printf("\tPreco medio: R$ %.2f\n", barato);
}

void libera_livro(Livro* l) {
    free(l);
}