typedef struct elemento* Pilha;

Pilha* cria_pilha();

int insere_pilha(Pilha *pi, int item);

int remove_pilha(Pilha *pi);

int iguais(Pilha *p1, Pilha *p2);

void imprime_pilha(Pilha *pi);

void libera_pilha(Pilha *pi);