// - Os protótipos das fuções
// - O tipo de dado armazenado
// - O ponteiro pilha
// - Tamanho do vetor usado

#define MAX 100

typedef struct pilha_estatica PilhaEstatica;

PilhaEstatica* cria_pilha_estatica();

int pilha_estatica_vazia(PilhaEstatica* pi);

int pilha_estatica_cheia(PilhaEstatica* pi);

int insere_pilha_estatica(PilhaEstatica* pi, struct aluno al);

int consulta_topo_pilha_estatica(PilhaEstatica* pi, struct aluno *al);

int remove_pilha_estatica(PilhaEstatica* pi);

void libera_pilha_estatica(PilhaEstatica* pi);