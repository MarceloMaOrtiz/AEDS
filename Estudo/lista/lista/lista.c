// Operações básica de uma lista
//  - Criação
//  - Inserção
//  - Exclusão
//  - Acesso
//  - Destruição
//  - etc...

// Alocação da Memória
// Estática (Vetor)
//  - Exige a definição do número máximo
//  - Espaço de memória é alocada no momento da compilação
//  - Acesso sequencial
//      - Elementos consecutivos na memória
//      - É possível acessar um elemento através do índice
// Dinâmica
//  - Cresce ou diminui a medida que nova funções são executadas
//  - Espaço de memória alocado em tempo de execução
//  - Acesso encadeado
//      - Cada elemento pode estar em uma área distinta da memória
//      - Necessário percorrer todos elementos antecessores até chegar no elemento desejado

#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "ListaSequencial.h"
#include "ListaDinEncad.h"

int main(){
    // Lista Sequencial Estática - Vetor
    //  - O sucessor ocupa a posição física seguinte
    //  - Vantagens
    //      - Acesso rápido e direto aos elementos (ìndice)
    //      - Tempo constante para acessar um elemento
    //      - Facilidade de modificar informações
    //  - Desvantagens
    //      - Difinição prévia
    //      - Dificuldade de inserção e remoção de um elemento entre elementos
    //  - 3 Tipos de Inserção e Remoção variando com a posição na lista
    //      - Início
    //      - Meio
    //      - Fim
    //  - 2 Tipos de Consultas
    //      - Pela posição -> Direta
    //      - Pelo conteúdo -> Busca

    ListaSequencial *ls;
    ls = cria_lista_sequencial();
    struct aluno dados_aluno;
    struct aluno* dados_aluno_busca;
    dados_aluno.matricula = 123;
    strcpy(dados_aluno.nome, "Marcelo");
    dados_aluno.n1 = 10;
    dados_aluno.n2 = 10;
    dados_aluno.n2 = 10;
    int x;
    x = insere_lista_sequencial_final(ls, dados_aluno);
    x = insere_lista_sequencial_inicio(ls, dados_aluno);
    x = insere_lista_sequencial_ordenada(ls, dados_aluno);
    x = consulta_lista_sequencial_pos(ls, 1, dados_aluno_busca);
    x = consulta_lista_sequencial_mat(ls, 123, dados_aluno_busca);
    x = remove_lista_sequencial_final(ls);
    x = remove_lista_sequencial_inicio(ls);
    x = remove_lista_sequencial(ls, dados_aluno);
    libera_lista(ls);
    printf("\nFim Lista Sequencial\n");

    // Lista Dinâmica Encadeada
    //  - Cada elemento é tratado como um ponteiro que é alocado dinâmicamente
    //      - Para guardar o primeiro elemento será utilizado um ponteiro para ponteiro
    //      para auxiliar a mudança no início da lista, mudando somente o conteúdo do ponteiro
    //      inicial
    //  - Cada elemento aponta para o seu sucessor
    //  - É utilizado um ponteiro especial para o primeiro elemento
    //  - Ultimo elemento aponta para NULL
    //  - Vantagens
    //      - Melhor utilização dos recursos da memória
    //      - Nao precisa movimentar os elementos nas operações de inserção e remoção
    //  - Desvantagens
    //      - Acesso indireto aos elementos
    //          - Necessidade de percorres a lista para acessar algum nó

    printf("\nFim\n");
    return 0;
}