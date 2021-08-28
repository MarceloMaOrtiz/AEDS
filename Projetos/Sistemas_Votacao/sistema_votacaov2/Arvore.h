#include "Eleitor.h"

typedef struct No_Est{
    Info *info;
    struct No_Est *esq;
    struct No_Est *dir;
}No;

No** cria();

void cadastrar(No** raiz, int titulo, char nome[]);

void remover(No** raizTitulos, No** raizVotos, int titulo);

void nova_votacao(No** raiz);

void votar(No** raizTitulos, No** raizVotos, int titulo, int voto);

void remover_voto(No** raiz, int titulo);

void resultado_parcial(No** raizTitulos, No** raizVotos);

void votantes(No** raiz);

void libera_eleitor(No** raiz);

void libera(No** raiz);