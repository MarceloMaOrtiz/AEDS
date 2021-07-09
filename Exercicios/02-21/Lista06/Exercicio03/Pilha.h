typedef struct elemento* Pilha;

Pilha* cria_pilha();

int insere_pilha(Pilha *pi, char c);

int remove_pilha(Pilha *pi);

Pilha* inverte_letras(Pilha *pi);

void imprime_pilha(Pilha *pi);

void libera_pilha(Pilha *pi);