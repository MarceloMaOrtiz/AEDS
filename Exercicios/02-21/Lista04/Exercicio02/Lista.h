#define MAX 100

struct dado {
    int num;
};

typedef struct lista Lista;

Lista* cria_lista();

int insere_lista(Lista* li, struct dado d);

int troca_elementos(Lista* li, int i, int j);

void imprime_lista(Lista *li);

void libera_lista(Lista* li);