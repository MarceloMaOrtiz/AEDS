struct dado{
    int num;
};

typedef struct no* Lista;

Lista* cria_lista();

int insere_lista(Lista *li, struct dado d);

int troca_elementos(Lista *li, int ind1, int ind2);

void imprime_lista(Lista *li);

void libera_lista(Lista *li);