typedef struct no* Pilha;

Pilha *criar();

int vazia(Pilha *p);

int inserir(Pilha *p, int n);

int consultar(Pilha *p, int *n);

int remover(Pilha *p);

void liberar(Pilha *p);