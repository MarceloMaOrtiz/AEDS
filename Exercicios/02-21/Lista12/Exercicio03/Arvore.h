typedef struct no* ArvBin;

typedef struct no No;

ArvBin *criar();

int vazia(ArvBin *raiz);

int inserir(ArvBin* raiz, int num);

int eh_binaria_busca(No *raiz, No* left, No* right);

void liberar(ArvBin *raiz);