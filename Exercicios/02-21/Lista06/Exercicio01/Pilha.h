struct TipoItem{
    char chave;
};

typedef struct elemento* Pilha;

Pilha* cria_pilha();

int insere_pilha(Pilha *pi, struct TipoItem);

int remove_pilha(Pilha *pi);

int remove_item_pilha(Pilha *pi, struct TipoItem item);

void imprime_pilha(Pilha *pi);

void libera_pilha(Pilha *pi);