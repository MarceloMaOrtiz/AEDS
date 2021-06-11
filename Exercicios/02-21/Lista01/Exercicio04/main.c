#include <stdlib.h>
#include <stdio.h>
#include "Livro.h"

int main() {
    Livro ** livros = (Livro**)malloc(5*sizeof(Livro*));

    atribui_livros(livros, 5);

    preco_medio(livros, 5);

    for (int i = 0; i < 5; i++){
        libera_livro(livros[i]);
    }

    free(livros);
    return 0;
}