#define MAX 100

struct no {
    int num;
};

typedef struct lista Lista;

Lista* cria_lista();

int insere_lista(Lista* li, struct no no);

void imprime_lista(Lista *li);

void libera_lista(Lista* li);