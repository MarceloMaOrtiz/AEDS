#include "Eleitor.h"

typedef struct No_Est No;

// Utiliza ponteiro para auxiliar durante a troca da raiz, quando necessário
typedef struct No_Est* ArvoreEleitor;

// Cria o ponteiro Raiz
ArvoreEleitor* criaArvore();

// Função responsável por inserir eleitor na árvore
int insereArvore(ArvoreEleitor* raiz, int titulo, char nome[]);

// Função responsável por remover um eleitor da árvore
int removeEleitorArvore(ArvoreEleitor* raiz, int titulo);

// Função responsável por remover todos os votos dos eleitores
int novaVotacao(ArvoreEleitor* raiz);

// Função responsável por efetuar o voto
int votar(ArvoreEleitor* raiz, int titulo, int voto);

// Função responsável por remover voto de determinado eleitor
int retirarVoto(ArvoreEleitor* raiz, int titulo);

// Função responsável por imprimir em ordem decrescente o resultado parcial
void resultadoParcial(ArvoreEleitor* raiz);

// Função responsável por imprimir as pessoas que ja votaram
void mostrarVotantes(ArvoreEleitor* raiz);

// Destroi a árvore
void liberaArvore(ArvoreEleitor* raiz);
