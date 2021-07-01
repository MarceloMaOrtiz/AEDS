// Definir
    // - Protótipos das funções
    // - Tipo de dado Armazenado
    // - Ponteiro "lista"
    // - Tamanho do vetor usado na lista

#define MAX 100

struct aluno {
    int matricula;
    char nome[30];
    float n1, n2, n3;
};
typedef struct lista_sequencial ListaSequencial;

ListaSequencial* cria_lista_sequencial();

int insere_lista_sequencial_final(ListaSequencial* li, struct aluno al);

int insere_lista_sequencial_inicio(ListaSequencial* li, struct aluno al);

int insere_lista_sequencial_ordenada(ListaSequencial* li, struct aluno al);

int remove_lista_sequencial_final(ListaSequencial* li);

int remove_lista_sequencial_inicio(ListaSequencial* li);

int remove_lista_sequencial(ListaSequencial* li, struct aluno al);

int consulta_lista_sequencial_pos(ListaSequencial* li, int pos, struct aluno *al);

int consulta_lista_sequencial_mat(ListaSequencial* li, int mat, struct aluno *al);

void libera_lista(ListaSequencial* li);