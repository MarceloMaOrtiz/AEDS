struct carro{
    char placa[7];
    int manobras;
};

struct entrada{
    struct carro car;
    char sentido;
};

typedef struct elemento* Pilha;

Pilha* cria_pilha();

int insere_pilha(Pilha *pi, struct carro c);

int remove_pilha(Pilha *pi);

int remove_carro_pilha(Pilha *pi, struct carro c);

void imprime_pilha(Pilha *pi);

int processa_entradas(struct entrada entradas[], int tam);

void libera_pilha(Pilha *pi);