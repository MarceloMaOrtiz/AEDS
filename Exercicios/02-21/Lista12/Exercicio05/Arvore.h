typedef struct no* ArvBin;

typedef struct no No;

ArvBin *criar();

int vazia(ArvBin *raiz);

int inserir(ArvBin* raiz, int num);

int nos_folhas(ArvBin *raiz);

void liberar(ArvBin *raiz);