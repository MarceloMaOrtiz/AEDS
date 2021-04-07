// Nomeando o ponteiro para o NO como ArvBin
typedef struct NO* ArvBin;

// Cria o ponteiro Raiz
ArvBin* cria_ArvBin();

// Destroi a árvore
void libera_ArvBin(ArvBin* raiz);

// Verifica se árvore está vazia
int estaVazia_ArvBin(ArvBin* raiz);

// Retorna a altura da árvore
int altura_ArvBin(ArvBin* raiz);

// Retorna o total de nó da árvore
int totalNO_ArvBin(ArvBin* raiz);

// Percorre utilizando Pré-Ordem
void preOrdem_ArvBin(ArvBin* raiz);

// Percorre utilizando Em-Ordem
void emOrdem_ArvBin(ArvBin* raiz);

// Percorre utilizando Pós-Ordem
void posOrdem_ArvBin(ArvBin* raiz);