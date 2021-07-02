#define MAX 100

struct no {
    int num;
};

typedef struct lista Lista;

Lista* cria_lista();

int insere_lista(Lista* li, struct no no);

int troca_elementos(Lista* li, struct no n1, struct no n2);

void imprime_lista(Lista *li);

void libera_lista(Lista* li);