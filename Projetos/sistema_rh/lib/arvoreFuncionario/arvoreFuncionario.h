typedef struct Info_Est Info;

// Utiliza ponteiro para facilitar a troca da raiz, caso necessário
typedef struct No_Est* No;

// Cria o ponteiro Raiz
No* criaArvore();

// Destroi a árvore
void liberaArvore(No* raiz);

// Aloca os funcionários na memória e insere em ambas as árvores
int adicionaFuncionario(No* raiz_nome, No* raiz_cpf, char nome[], int cpf, char profissao[]);