#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#include "Calculadora.h"

int main(){

    char *infixa, *posfixa;
    char equacao[50];

    No** pilha = cria();

    do{
        printf("\n Calculadora Simples\n");
        printf("Para limpar a calculadora digite -> C\n");
        printf("Para sair do programa digite -> S\n");
        printf("Insira a equacao na forma infixa\n");
        printf("Equacao (ou opcoes): ");
        scanf("%s", equacao);
        if(strcmp(equacao, "C") == 0){
            esvazia(pilha);
            printf("\nPilha Esvaziada!\n");
        }
        else if(strcmp(equacao, "S") == 0){
            libera(pilha);
            printf("\nPrograma Encerrado!\n");
        }
        else{
            // imprime_vetor(equacao);
            infixa = acrescenta_parenteses(equacao);
            // imprime_vetor(infixa);
            posfixa = infixa_posfixa(infixa);
            // imprime_vetor(posfixa);
            calculo_final(pilha, posfixa);
        }
    }while(strcmp(equacao, "S"));

    return 0;
}