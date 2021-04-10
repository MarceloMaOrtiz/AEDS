// Foi necessário declarar toda a estrutura aqui no .h para termos acesso ao tipo Info
struct Info_Est{
    int CPF;
    char Nome[50];
    char Profissao[30];
};

typedef struct Info_Est Info;

// Utiliza ponteiro para facilitar a troca da raiz, caso necessário
struct No_Est{
    Info *info;
    struct No_Est *esq;
    struct No_Est *dir;
};

typedef struct No_Est* No;

// Cria o ponteiro Raiz
No* criaArvore();

// Destroi a árvore
void liberaArvore(No* raiz, int limpaInfo);

// Aloca os funcionários na memória e insere em ambas as árvores
int adicionaFuncionario(No* raiz_nome, No* raiz_cpf, char nome[], int cpf, char profissao[]);

// Remove o nó da Árvore utilizando nome como busca principal
int removeNoArvoreNome(No* raiz, char nome[], int limpaInfo);

// Remove o nó da Árvore utilizando cpf como busca principal
int removeNoArvoreCPF(No* raiz, int cpf, int limpaInfo);

// Retorna a Info de um Nó utilizando o Nome como busca
Info buscaNoNome(No* raiz, char nome[]);

// Retorna a Info de um Nó utilizando o CPF como busca
Info buscaNoCPF(No* raiz, int cpf);

// Exibe todos os funcionários em Ordem Crescente
void exibirEmOrdemArvore(No* raiz);

// Remove todos os funcionários
int removerFuncionarios(No* raiz_nome, No* raiz_cpf);