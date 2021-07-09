//  - Protótipos das funções
//  - Tipo de dado armazenado na lista
//  - Ponteiro lista

typedef struct descritor ListaDescritor;

ListaDescritor* cria_lista_descritor();

int insere_lista_descritor_inicio(ListaDescritor* li, struct aluno al);

int insere_lista_descritor_final(ListaDescritor* li, struct aluno al);

int remove_lista_descritor_inicio(ListaDescritor* li);

int remove_lista_descritor_final(ListaDescritor* li);

void libera_lista_descritor(ListaDescritor* li);