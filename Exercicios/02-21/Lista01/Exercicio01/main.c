// Uma indústria faz a folha mensal de pagamentos de seus empregados baseada em uma tabela que contém os
// dados dos funcionários:

// Fazer um algoritmo que processe a tabela e emita, para cada funcionário, seu contracheque cujo formato é
// dado a seguir:
//     NUMERO DE INSCRICAO:
//     NOME:
//     SALARIO HORAS NORMAIS:
//     SALARIO HORAS EXTRAS:
//     DEDUCAO INSS :
//     SALARIO LIQUIDO:
// O salário de referência deverá ser lido previamente. O salário referente às horas extras é calculado
// acrescentando 30% ao salário-hora normal. O desconto do INSS é de 11% do salário bruto (salário
// correspondente às horas normais trabalhadas + salário correspondente às horas extras). Para o cálculo do
// salário, considerar que existem duas classes de funcionários, a classe 1, cujo salário é 1,3 vezes o salário de
// referência, e a classe 2, cujo salário é 1,9 vezes o salário de referência.

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