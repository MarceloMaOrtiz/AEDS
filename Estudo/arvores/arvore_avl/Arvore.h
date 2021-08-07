// Definir
//  - Protótipos das funções
//  - Tipo de dado armazenado na árvore
//  - Ponteiro árvore

typedef struct no* ArvAVL;

ArvAVL* cria_ArvAVL();

int insere_ArvAVL(ArvAVL* raiz, int valor);

int remove_ArvAVL(ArvAVL* raiz, int valor);

int consulta_ArvAVL(ArvAVL* raiz, int valor);

void libera_ArvAVL(ArvAVL* raiz);