typedef struct elemento* Pilha;

Pilha* cria_pilha();

int insere_pilha(Pilha *pi, float num);

int remove_pilha(Pilha *pi);

int maior_menor_media(Pilha *pi, float *maior, float *menor, float *media);

void imprime_pilha(Pilha *pi);

void libera_pilha(Pilha *pi);