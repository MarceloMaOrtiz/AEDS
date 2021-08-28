#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#include "Arvore.h"

void fflush_entrada(){
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

void clean_fgets(char word[]){
    int len = strlen(word);
    if(len == 0)
        return;
    else
        if(word[len-1] == '\n')
            word[--len] = 0;
}

#include <execinfo.h>
#include <signal.h>
#include <unistd.h>

void handler(int sig) {
    void *array[10];
    size_t size;

    // get void*'s for all entries on the stack
    size = backtrace(array, 10);

    // print out all the frames to stderr
    fprintf(stderr, "Error: signal %d:\n", sig);
    backtrace_symbols_fd(array, size, STDERR_FILENO);
    exit(1);
}

int main(){
    signal(SIGSEGV, handler);

    No **arvoreTitulos;
    No **arvoreVotos;

    arvoreTitulos = cria();
    arvoreVotos = cria();

    int operacao;

    int titulo, voto;
    char nome[50];

    cadastrar(arvoreTitulos, 1, "Marcelo");
    cadastrar(arvoreTitulos, 2, "Sama");
    cadastrar(arvoreTitulos, 3, "Gustavo");
    cadastrar(arvoreTitulos, 4, "Ravena");
    cadastrar(arvoreTitulos, 5, "Wandneia");
    cadastrar(arvoreTitulos, 6, "Wallace");
    cadastrar(arvoreTitulos, 7, "Robo");
    cadastrar(arvoreTitulos, 8, "Tainá");
    cadastrar(arvoreTitulos, 9, "Mamba");

    do{
        printf("\n  Menu\n");
        printf(" 1. Cadastrar Eleitor\n");
        printf(" 2. Remover Eleitor\n");
        printf(" 3. Nova Votação\n");
        printf(" 4. Votar\n");
        printf(" 5. Remover Voto\n");
        printf(" 6. Resultado Parcial\n");
        printf(" 7. Votantes\n");
        printf(" 8. Sair\n");
        printf("\tEscolha: ");
        scanf("%d", &operacao);
        switch(operacao){
            case 1:
                printf("\n  Cadastrar Eleitor\n");
                printf(" Titulo: ");
                scanf("%d", &titulo);
                fflush_entrada();

                printf(" Nome: ");
                fgets(nome, 50, stdin);
                clean_fgets(nome);

                cadastrar(arvoreTitulos, titulo, nome);
                break;
            case 2:
                printf("\n  Romover Eleitor\n");
                printf(" Titulo: ");
                scanf("%d", &titulo);
                fflush_entrada();

                remover(arvoreTitulos, arvoreVotos, titulo);
                break;
            case 3:
                printf("\n  Nova Votação\n");
                nova_votacao(arvoreVotos);
                *arvoreVotos = NULL;
                break;
            case 4:
                printf("\n  Votar\n");
                printf(" Titulo: ");
                scanf("%d", &titulo);
                fflush_entrada();

                printf(" Voto: ");
                scanf("%d", &voto);
                fflush_entrada();

                votar(arvoreTitulos, arvoreVotos, titulo, voto);
                break;
            case 5:
                printf("\n  Remover Voto\n");
                printf(" Titulo: ");
                scanf("%d", &titulo);
                fflush_entrada();

                remover_voto(arvoreVotos, titulo);
                break;
            case 6:
                printf("\n  Resultado Parcial\n");
                resultado_parcial(arvoreTitulos, arvoreVotos);
                break;
            case 7:
                printf("\n  Votantes\n");
                votantes(arvoreVotos);
                break;
            case 8:
                printf("\n  Programa Encerrado.\n");
                libera(arvoreVotos);
                libera_eleitor(arvoreTitulos);
                free(arvoreVotos);
                free(arvoreTitulos);
                break;
            default:
                printf("\n  Operação Invalida.\n\n");
                break;
        }
    }while(operacao != 8);

    return 0;
}