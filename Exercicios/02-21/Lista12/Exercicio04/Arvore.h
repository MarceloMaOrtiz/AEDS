typedef struct no* ArvBin;

typedef struct no No;

ArvBin *criar();

int vazia(ArvBin *raiz);

int inserir(ArvBin* raiz, int num);

int max_no(ArvBin* raiz);

int min_no(ArvBin* raiz);

void liberar(ArvBin *raiz);