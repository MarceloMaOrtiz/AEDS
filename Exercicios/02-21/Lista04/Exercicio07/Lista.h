struct dado{
    int num;
};

typedef struct no* Lista;

Lista* cria_lista();

int insere_lista(Lista *li, struct dado d);

void inssub(Lista *l1, int i1, Lista *l2, int i2, int len);

void imprime_lista(Lista *li);

void libera_lista(Lista *li);