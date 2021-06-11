
#include <stdio.h>
#include <stdlib.h>
#include "Ponto.h"

// Estruturas de Dados: Trata-se de um relacionamento lógico entre tipos de dados incluindo
// Manipulações dos Dados:
//  - Criação da Estrutura
//  - Inclusão de um elemento
//  - Remoção de um elemento
//  - Acesso a um elemento
//  - etc
// Vantagens:
//  - Encapsulamento
//  - Segurança
//  - Flexibilidade
//  - Reutilização

// Exemplo de TAD: arquivo em C
// FILE* f;
// Os dados de "f" só podem ser acessados pelas funções de manipulação do tipo:
//  - fopen()
//  - fclose()
//  - fputc()
//  - fgetc()
//  - feof()
//  - ...

// É utilizado 2 arquivos para implementar TAD
//  - ".h": Protótipos das funções, tipos de ponteiros, e dados globais
//  - ".c": Declaração do tipo de dados e implementação de suas funções

// Exemplo de TAD
//
// struct ponto{
//     float x;
//     float y;
// };
//
// 1º Passo: definir o arquivo ".h"
//   - Protótipos das funções
//   - Tipos de ponteiros
//   - Dados globalmente acessíveis

int main(){

    float d;
    Ponto *p, *q;

    p = pto_cria(10, 21);
    q = pto_cria(7, 25);

    d = pto_distancia(p, q);
    printf("Distancia entre pontos: %f\n", d);

    pto_libera(p);
    pto_libera(q);

    return 0;
}