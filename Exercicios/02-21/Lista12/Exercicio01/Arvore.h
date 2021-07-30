typedef struct no* ArvBin;

ArvBin *criar();

int vazia(ArvBin *raiz);

int inserir(ArvBin* raiz, int cod, float valor);

void buscar(ArvBin* raiz, int cod);

int remover(ArvBin* raiz, int cod);

void liberar(ArvBin *raiz);