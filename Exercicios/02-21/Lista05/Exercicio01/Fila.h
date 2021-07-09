struct processo{
    int ID;
};

typedef struct fila Fila;

Fila* cria_fila();

int insere_fila(Fila* fi, struct processo p);

int remove_fila(Fila* fi);

void imprimir_fila(Fila* fi);

int tamanho_fila(Fila* fi);

void libera_fila(Fila *fi);