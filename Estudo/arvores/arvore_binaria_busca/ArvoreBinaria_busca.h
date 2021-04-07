// Nomeando o ponteiro para o NO como ArvBin
typedef struct NO* ArvBin;

// Cria o ponteiro Raiz
ArvBin* cria_ArvBin();

// Destroi a árvore
void libera_ArvBin(ArvBin* raiz);

// Insere na árvore binária sem recursão
int insere_ArvBin(ArvBin* raiz, int valor);

// Remove valor da árvore
int remove_ArvBin(ArvBin* raiz, int valor);

// Consulta a árvore
int consulta_ArvBin(ArvBin* raiz, int valor);