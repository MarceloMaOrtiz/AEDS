// Definir
//  - Protótipos das funções
//  - Tipo de dado armazenado na árvore
//  - Ponteiro árvore

typedef struct no* ArvLLRB;

ArvLLRB* cria_ArvLLRB();

int insere_ArvLLRB(ArvLLRB *raiz, int valor);

int remove_ArvLLRB(ArvLLRB *raiz, int valor);

void libera_ArvLLRB(ArvLLRB* raiz);