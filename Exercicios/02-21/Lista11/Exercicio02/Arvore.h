typedef struct no* ArvBin;

ArvBin *criar();

int vazia(ArvBin *raiz);

int inserir(ArvBin* raiz, int valor);

int total_no(ArvBin *raiz);

int soma_nos(ArvBin *raiz);

int altura(ArvBin *raiz);

void liberar(ArvBin *raiz);