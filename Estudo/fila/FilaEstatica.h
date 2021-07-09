// - Os protótipos das fuções
// - O tipo de dado armazenado
// - O ponteiro fila
// - Tamanaho do vetor usado

#define MAX 100

typedef struct fila FilaEstatica;

FilaEstatica* cria_fila_estatica();

int fila_estatica_vazia(FilaEstatica* fi);

int fila_estatica_cheia(FilaEstatica* fi);

int insere_fila_estatica(FilaEstatica* fi, struct aluno al);

int consulta_fila_estatica(FilaEstatica* fi, struct aluno *al);

int remove_fila_estatica(FilaEstatica* fi);

void libera_fila_estatica(FilaEstatica* fi);