typedef struct no *ListaNomes;

ListaNomes* cria_lista();

int insere_lista_ordenado(ListaNomes *li, char *nome);

void imprime_lista(ListaNomes *li);

void libera_lista(ListaNomes *li);