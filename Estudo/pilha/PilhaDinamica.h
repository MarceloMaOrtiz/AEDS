// - Os protótipos das fuções
// - O tipo de dado armazenado
// - O ponteiro pilha

typedef struct elemento* PilhaDinamica;

PilhaDinamica* cria_pilha_dinamica();

int tamanho_pilha_dinamica(PilhaDinamica* pi);

int pilha_dinamica_vazia(PilhaDinamica* pi);

int insere_pilha_dinamica(PilhaDinamica* pi, struct aluno al);

int consulta_topo_pilha_dinamica(PilhaDinamica* pi, struct aluno *al);

int remove_pilha_dinamica(PilhaDinamica* pi);

void libera_pilha_dinamica(PilhaDinamica* pi);