typedef struct no* ArvBin;

ArvBin *criar();

int vazia(ArvBin *raiz);

int inserir(ArvBin* raiz, int valor);

int nos_folhas(ArvBin *raiz);

void liberar(ArvBin *raiz);