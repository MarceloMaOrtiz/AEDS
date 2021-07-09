// - Os protótipos das fuções
// - O tipo de dado armazenado
// - O ponteiro fila

typedef struct fila_dinamica FilaDinamica;

FilaDinamica* cria_fila_dinamica();

int fila_dinamica_vazia(FilaDinamica* fi);

int insere_fila_dinamica(FilaDinamica* fi, struct aluno al);

int consulta_fila_dinamica(FilaDinamica* fi, struct aluno *al);

int remove_fila_dinamica(FilaDinamica* fi);

void libera_fila_dinamica(FilaDinamica* fi);