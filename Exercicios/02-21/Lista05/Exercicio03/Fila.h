typedef struct fila Fila;

Fila* cria_fila();

int vazia(Fila *fi);

int enfileira(Fila *fi, int num);

int desenfileira(Fila *fi);

void libera_fila(Fila *fi);