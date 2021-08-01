// Utilizando um Ponteiro da struct no para ter um ponteiro apontando
// para cabeça da pilha, facilitando a implementação de algumas funções
typedef struct no_char* PilhaChar;

PilhaChar *criar_pilha_char();

void empilhar_pilha_char(PilhaChar *pi, char elem);

// Salva em um variável o valor do top da pilha
void consulta_pilha_char(PilhaChar *pi, char *elem);

// Libera o topo da pilha
void desempilhar_pilha_char(PilhaChar *pi);

// Converte string infixa para posfixa
char *infixa_para_posfixa(char *infixa);

void liberar_pilha_char(PilhaChar *pi);