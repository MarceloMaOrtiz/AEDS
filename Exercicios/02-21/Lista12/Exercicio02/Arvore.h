typedef struct no* ArvBin;

ArvBin *criar();

int vazia(ArvBin *raiz);

int inserir(ArvBin* raiz, int cod, float valor);

void desenhar(ArvBin *raiz);

void pre_ordem(ArvBin *raiz);

void pos_ordem(ArvBin *raiz);

void central(ArvBin *raiz);

void liberar(ArvBin *raiz);