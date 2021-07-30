typedef struct no* ArvBin;

ArvBin *criar();

int vazia(ArvBin *raiz);

int inserir(ArvBin* raiz, int valor);

int simetrica(ArvBin *raiz1, ArvBin *raiz2);

void liberar(ArvBin *raiz);