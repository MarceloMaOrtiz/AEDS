#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#include "Calculadora.h"

char* acrescenta_parenteses(char* equacao){
    int tamanho = strlen(equacao);
    char* infixa = (char*)malloc(tamanho+2*sizeof(char));
    infixa[0] = '(';
    for(int i = 0; i < tamanho; i++){
        infixa[i+1] = equacao[i];
    }
    infixa[tamanho+1] = ')';
    infixa[tamanho+2] = '\0';
    return infixa;
}

int prioridade(char ch){
    int prioridade;
    switch(ch){
        case '+':
        case '-':
            prioridade = 1;
            break;
        case '*':
        case '/':
            prioridade = 2;
            break;
        default:
            prioridade = 0;
            break;
    }
    return prioridade;
}

char* infixa_posfixa(char* infixa){
    int tamanho = strlen(infixa);
    char* posfixa = (char*)malloc(tamanho*2*sizeof(char));
    strcpy(posfixa, "");
    No** pilha = cria();
    int cont = 0;
    int primeiro_numero = 1;
    char atual, aux;
    while(cont < tamanho){
        atual = infixa[cont];
        switch(atual){
            case '*':
            case '/':
            case '+':
            case '-':
                primeiro_numero = 1;
                while((!vazia(pilha)) && prioridade(atual) <= prioridade((char)((int)peek(pilha)))){
                    aux = (char)((int)pop(pilha));
                    strncat(posfixa, &aux, 1);
                }
                push(pilha, (int)atual);
                break;
            case '(':
                primeiro_numero = 1;
                push(pilha, (int)atual);
                break;
            case ')':
                primeiro_numero = 1;
                while((char)((int)peek(pilha)) != '('){
                    aux = (char)((int)pop(pilha));
                    strncat(posfixa, &aux, 1);
                }
                if((char)((int)peek(pilha)) == '(')
                    pop(pilha);
                break;
            default:
                if(primeiro_numero){
                    aux = 'E';
                    strncat(posfixa, &aux, 1);
                }
                primeiro_numero = 0;
                strncat(posfixa, &infixa[cont], 1);
                break;
        }
        cont++;
    }
    while(tamanho_pilha(pilha) > 0){
        if((char)((int)peek(pilha)) != '('){
            aux = (char)((int)pop(pilha));
            strncat(posfixa, &aux, 1);
        }
        else
            pop(pilha);
    }

    return posfixa;
}

void calculo_final(No** head, char* posfixa){
    if(head == NULL)
        return;
    int tamanho = strlen(posfixa);
    int cont = 0;
    int x, y;
    char atual;
    while(cont < tamanho){
        atual = posfixa[cont];
        switch(atual){
            case 'E':
                push(head, (int)0);
                break;
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                x = pop(head);
                x = x*10+((int)atual - 48);
                push(head, x);
                break;                
            case '+':
                x = pop(head);
                y = pop(head);
                x = y + x;
                push(head, x);
                break;
            case '-':
                x = pop(head);
                y = pop(head);
                x = y - x;
                push(head, x);
                break;
            case '*':
                x = pop(head);
                y = pop(head);
                x = y * x;
                push(head, x);
                break;
            case '/':
                x = pop(head);
                y = pop(head);
                if(x == 0){
                    printf("\nErro. Divisao por 0.\n");
                    esvazia(head);
                    return;
                }
                x = y / x;
                push(head, x);
                break;
            default:
                break;
        }
        imprime_pilha(head);
        cont++;
    }
}

void imprime_vetor(char* vetor){
    for(int i = 0; i <= strlen(vetor); i++){
        printf("%c", vetor[i]);
    }
    printf("\n");
}