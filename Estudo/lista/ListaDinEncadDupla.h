// Protótipos das funções
// Tipo de dado armazenado na lista
// Ponteiro "lista"

typedef struct elemento* ListaDinEncadDupla;

ListaDinEncadDupla* cria_lista_din_dupla();

int lista_vazia_din_dupla(ListaDinEncadDupla *li);

int insere_lista_din_dupla_inicio(ListaDinEncadDupla* li, struct aluno al);

int insere_lista_din_dupla_fim(ListaDinEncadDupla* li, struct aluno al);

int insere_lista_din_dupla_ordenada(ListaDinEncadDupla* li, struct aluno al);

int consulta_lista_din_dupla_pos(ListaDinEncadDupla* li, int pos, struct aluno *al);

int consulta_lista_din_dupla_mat(ListaDinEncadDupla* li, int mat, struct aluno *al);

int remove_lista_din_dupla_inicio(ListaDinEncadDupla* li);

int remove_lista_din_dupla_fim(ListaDinEncadDupla* li);

int remove_lista_din_dupla(ListaDinEncadDupla* li, struct aluno al);

void libera_lista_din_dupla(ListaDinEncadDupla* li);