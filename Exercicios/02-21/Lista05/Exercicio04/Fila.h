struct contato{
    int ID;
    char nome[30];
    int tel;
};

typedef struct fila Fila;

Fila* cria_fila();

int insere_fila(Fila *fi, struct contato c);

int remove_fila(Fila *fi);

void libera_fila(Fila *fi);