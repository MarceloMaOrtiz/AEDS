struct dado{
    int num;
};

typedef struct no* Lista;

Lista* cria_lista();

int insere_lista(Lista *li, struct dado d);

int troca_elementos(Lista *li, struct dado d1, struct dado d2);

void imprime_lista(Lista *li);

void libera_lista(Lista *li);