// Fila
//  - Sequência de elementos do mesmo tipo
//      - Tipo especial de lista
//          - Inserções e exclusões de elementos ocorrem nas extremidades da lista
//              - Insere de um lado (inicio), e remove do outro (final)
//  - Aplicações
//      - Controle de Fluxo
//      - Recursos compartilhados (Impressora, transações de BDs, ...)
//  - Operações básicas (Dependendo do tipo de alocação de memória utilizada - Estática ou Dinâmica)
//      - Criação da Fila
//      - Inserção de um elemento no final
//      - Remoção de um elemento no inicio
//      - Acessso ao elemento do início
//      - Destruição da fila
//  - Alocação Estática
//      - Espaço de memória é alocado no momento da compilação
//      - Exige a definição do número máximo de elementos
//      - Acesso sequencial, elementos consecutivos na memória
//  - Alocação Dinâmica
//      - Espaço de memória alocado em tempo de execução
//      - Acesso encadeado
//          - Cada elemento pode estar em uma área distinta da memória

#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "aluno.h"
#include "FilaEstatica.h"
#include "FilaDinamica.h"

int main(){
    struct aluno dados_aluno;
    dados_aluno.matricula = 123;
    strcpy(dados_aluno.nome, "Marcelo");
    dados_aluno.n1 = 8;
    dados_aluno.n2 = 9;
    dados_aluno.n3 = 10;
    int x;

    FilaEstatica *fe;

    fe = cria_fila_estatica();
    x = insere_fila_estatica(fe, dados_aluno);
    x = consulta_fila_estatica(fe, &dados_aluno);
    x = remove_fila_estatica(fe);
    libera_fila_estatica(fe);

    printf("\nFim da Fila Estatica\n");

    // Fila Dinâmica
    //  - É possível utilizar um Nó Descritor
    //      - Representando o início, final e uma indicação de final de fila

    FilaDinamica *fd;
    fd = cria_fila_dinamica();
    x = insere_fila_dinamica(fd, dados_aluno);
    x = consulta_fila_dinamica(fd, &dados_aluno);
    x = remove_fila_dinamica(fd);
    libera_fila_dinamica(fd);

    printf("\nFim da Fila Dinâmica\n");

    printf("\nFim\n");

    return 0;
}