// Utilizando um Ponteiro da struct no para ter um ponteiro apontando
// para cabeça da pilha, facilitando a implementação de algumas funções
typedef struct no* Pilha;

Pilha *criar_pilha();

void empilhar_pilha(Pilha *pi, char elem);

// Salva em um variável o valor do top da pilha
void consulta_pilha(Pilha *pi, int *elem);

// Libera o topo da pilha
void desempilhar_pilha(Pilha *pi);

void imprimir_pilha(Pilha *pi);

void liberar_pilha(Pilha *pi);