typedef struct no* ArvBin;

ArvBin *criar();

int vazia(ArvBin *raiz);

int inserir(ArvBin* raiz, int valor);

int altura(ArvBin *raiz);

int inserir_balanceada(ArvBin *raiz, int num);

void liberar(ArvBin *raiz);