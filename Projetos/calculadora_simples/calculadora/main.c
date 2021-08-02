#include "stdio.h"
#include "stdlib.h"
#include "Pilha.h"
#include "PilhaChar.h"

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

// Complexidade: O(n*log(n)) para maioria dos casos onde n é a quantidade de caracteres
//      Pois a função relevante, infixa_para_posfixa, é executada uma única vez
//      a cada intereção do usuário. E ao utilizar a outra função relevante,
//      empilhar_pilha, possue um loop somente quando recebe o caractere 'C',
//      e ao utilizar esse caractere na main, a função é executada uma única vez.
//      Quando utilizado uma equação inteira, essa equação passar por um loop for,
//      chamando a função empilhar_pilha, que terá o comportamento de O(1), Resultando
//      novamente em um O(n).
//      Portanto para o pior caso temos o comportamento O(n*log(n)).
int main(){
    signal(SIGSEGV, handler);
    printf("########## TRABALHO 1 AEDS ##########\n");
    printf("# ALUNO: Guilherme Machado Pacheco #\n");
    printf("###### MATRICULA: NOME COMPLETO #####\n");

    Pilha *pilha;
    pilha = criar_pilha(pilha);
    char *equacao, *posfixa;
    equacao = (char*)malloc(100*sizeof(char));
    do{
        printf("\n#####################################\n");
        printf("######## CALCULADORA SIMPLES ########\n");
        printf("#####################################\n\n");
        printf("Insira a equação no formato Infixo.\n");
        printf("Sempre comece com '(' e Encerre com ')'.\n");
        printf("Insira C/c para Limpar a Pilha da Calculadora.\n");
        printf("Insira S/s para Encerrar o programa.\n\n");
        printf("Equacao: ");
        scanf("%s", equacao);
        if(equacao[0] != 's' && equacao [0] != 'S'){
            posfixa = infixa_para_posfixa(equacao);
            if(equacao[0] == 'c' || equacao[0] == 'C'){
                empilhar_pilha(pilha, 'C');
                printf("\nCaractere: C");
                printf("\nPilha: ");
                imprimir_pilha(pilha);
            }else{
                printf("\nPosFixa: %s\n", posfixa);
                for(int i = 0; posfixa[i] != '\0'; i++){
                    empilhar_pilha(pilha, posfixa[i]);
                    printf("\nCaractere: %c", posfixa[i]);
                    printf("\nPilha: ");
                    imprimir_pilha(pilha);
                }
            }
        }
        printf("%c", equacao[0]);
    }while(equacao[0] != 'S' && equacao[0] != 's');
    liberar_pilha(pilha);
    free(equacao);
    free(posfixa);
    return 0;
}