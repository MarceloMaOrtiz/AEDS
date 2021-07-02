// Definir
    // - Protótipos das funções
    // - Tipo de dado Armazenado
    // - Ponteiro "lista"

// É instaciado um tipo ListaDinEncad para trabalharmos com a lista, isso foi feito
// para auxiliar em alterações feita na raiz da lista. O que temos aqui é uma variável
// responsável por armazenar um ponteiro para um Elemento, e com isso temos com
// ListaDinEncad um ponteiro para um Elemento.

typedef struct elemento* ListaDinEncad;

ListaDinEncad* cria_lista_din();

int lista_vazia_din(ListaDinEncad *li);

int insere_lista_din_inicio(ListaDinEncad* li, struct aluno al);

int insere_lista_din_fim(ListaDinEncad* li, struct aluno al);

int insere_lista_din_ordenada(ListaDinEncad* li, struct aluno al);

int consulta_lista_din_pos(ListaDinEncad* li, int pos, struct aluno *al);

int consulta_lista_din_mat(ListaDinEncad* li, int mat, struct aluno *al);

int remove_lista_din_inicio(ListaDinEncad* li);

int remove_lista_din_fim(ListaDinEncad* li);

int remove_lista_din(ListaDinEncad* li, struct aluno al);

void libera_lista_din(ListaDinEncad* li);