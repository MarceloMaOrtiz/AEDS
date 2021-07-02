struct dado{
    int num;
};

typedef struct no* Lista;

Lista* cria_lista();

int insere_lista(Lista *li, struct dado d);

void troca(Lista *li, struct dado d);

void imprime_lista(Lista *li);

void libera_lista(Lista *li);