#include "Aluno.h"

typedef struct hash Hash;

// Cria tabela utilizando determinado tamanho
Hash* cria_hash(int TABLE_SIZE);

// Converte String para um valor
int valor_string(char *str);

int insere_hash_sem_colisao(Hash* ha, Aluno al);

int busca_hash_sem_colisao(Hash* ha, int mat, Aluno* al);

int insere_hash_endereco_aberto(Hash* ha, Aluno al);

int busca_hash_endereco_aberto(Hash* ha, int mat, Aluno* al);

void libera_hash(Hash* ha);