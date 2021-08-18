#define MAX 100

typedef struct fila_prioridade FilaPrio;

FilaPrio* cria_fila();
int consulta_fila_array(FilaPrio* fp, char* nome);
int insere_fila_array(FilaPrio* fp, char* nome, int prio);
int remove_fila_array(FilaPrio* fp);
int consulta_fila_heap(FilaPrio* fp, char* nome);
int insere_fila_heap(FilaPrio* fp, char* nome, int prio);
int remove_fila_heap(FilaPrio* fp);
int tamanho_fila(FilaPrio* fp);
int esta_cheia(FilaPrio* fp);
int esta_vazia(FilaPrio* fp);
void libera_fila(FilaPrio* fp);