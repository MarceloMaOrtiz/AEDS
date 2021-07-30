typedef struct no* ArvBin;

ArvBin *criar();

int vazia(ArvBin *raiz);

int inserir(ArvBin* raiz, int valor);

int balanceada(ArvBin *raiz, int *height);

int perfeitamente_balanceada(ArvBin *raiz, int *height);

void liberar(ArvBin *raiz);