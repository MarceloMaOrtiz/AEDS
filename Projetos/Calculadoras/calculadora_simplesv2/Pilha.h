typedef struct no No;

No** cria();

int vazia(No** head);

int tamanho_pilha(No** head);

void push(No** head, int num);

int pop(No** head);

int peek(No** head);

void imprime_pilha(No** head);

void esvazia(No** head);

void libera(No** head);