#include <stdlib.h>
#include <stdio.h>
#include "Ficha.h"

int main() {
    Ficha **fichas;
    fichas = (Ficha**)malloc(4*sizeof(Ficha*));

    // Ficha *f1, *f2, *f3, *f4;
    fichas[0] = cria_ficha(1, "Julia", 1, 100, 10);
    fichas[1] = cria_ficha(2, "Eduardo", 2, 43, 0);
    fichas[2] = cria_ficha(3, "Guilherme", 2, 50, 9);
    fichas[3] = cria_ficha(4, "Matheus", 1, 60, 12);

    float salario;

    printf("\nDigite o salário de referência: ");
    scanf("%f", &salario);

    for (int i = 0; i < 4; i++){
        imprime_contracheque(fichas[i], salario);
    }
    

    libera_ficha(fichas[0]);
    libera_ficha(fichas[1]);
    libera_ficha(fichas[2]);
    libera_ficha(fichas[3]);

    return 0;
}