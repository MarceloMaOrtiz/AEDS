#include "stdio.h"
#include "stdlib.h"
#include "PilhaChar.h"

struct no_char{
    char elem;
    struct no_char *prox;
};
typedef struct no_char NoChar;

// Complexidade: O(1)
PilhaChar *criar_pilha_char(){
    PilhaChar *pi = (PilhaChar*)malloc(sizeof(PilhaChar));
    if(pi != NULL)
        *pi = NULL;
    return pi;
}

// Complexidade: O(1)
void empilhar_pilha_char(PilhaChar *pi, char elem){
    if(pi == NULL)
        return;
    NoChar * no = (NoChar*)malloc(sizeof(NoChar));
    if(no == NULL)
        return;
    no->elem = elem;
    no->prox = (*pi);
    *pi = no;
}

// Complexidade: O(1)
// Salva em um variável o valor do top da pilha
void consulta_pilha_char(PilhaChar *pi, char *elem){
    if(pi == NULL)
        return;
    if((*pi) == NULL)
        return;
    *elem = (*pi)->elem;
}

// Complexidade: O(1)
// Libera o topo da pilha
void desempilhar_pilha_char(PilhaChar *pi){
    if(pi == NULL)
        return;
    if((*pi) == NULL)
        return;
    NoChar *no = *pi;
    *pi = no->prox;
    free(no);
}

// Complexidade: Pior caso temos O(n²) pois temos um loop for e em alguns case
//      temos while, sendo assim duas estruturas de repetição, porém, normalmente,
//      somente o for variará de acordo com n, já os while percorrem uma pilha que não
//      armazena os números da equação, somente armazena os simbolos. Dessa forma para
//      termos o pior caso teriamos que ter uma equação sem números, o que não faz sentido.
//      Portanto podemos considerar que a complexidade é O(n*log(n)) para a grande maioria
//      dos casos.
// Função responsável por converter expressao infixa para posfixa
char *infixa_para_posfixa(char *infixa){
    PilhaChar *pi;
    pi = criar_pilha_char();
    char *p_fixa;
    
    // alloca dinâmicamente uma vetor de char para posteriormente linkar com
    // o posFix da main
    p_fixa = (char*)malloc(100*sizeof(char));
    int j = 0, first_numero = 0; // first_numero utilizado para inserir E quando necessário
    empilhar_pilha_char(pi, infixa[0]); // Empilha o primeiro '('
    for(int i = 1; infixa[i] != '\0'; i++){
        switch(infixa[i]){
            char atual; 
            case '(':
                empilhar_pilha_char(pi, infixa[i]);
                first_numero = 0;
                break;
            case ')':
                consulta_pilha_char(pi, &atual);
                desempilhar_pilha_char(pi);
                while(atual != '('){
                    p_fixa[j] = atual;
                    j++;
                    consulta_pilha_char(pi, &atual);
                    desempilhar_pilha_char(pi);
                }
                first_numero = 0;
                break;
            case '+':
            case '-':
                consulta_pilha_char(pi, &atual);
                desempilhar_pilha_char(pi);
                while(atual != '('){
                    p_fixa[j] = atual;
                    j++;
                    consulta_pilha_char(pi, &atual);
                    desempilhar_pilha_char(pi);
                }
                empilhar_pilha_char(pi, atual);
                empilhar_pilha_char(pi, infixa[i]);
                first_numero = 0;
                break;
            case '*':
            case '/':
                consulta_pilha_char(pi, &atual);
                desempilhar_pilha_char(pi);
                while(atual != '(' && atual != '+' && atual != '-'){
                    p_fixa[j] = atual;
                    j++;
                    consulta_pilha_char(pi, &atual);
                    desempilhar_pilha_char(pi);
                }
                empilhar_pilha_char(pi, atual);
                empilhar_pilha_char(pi, infixa[i]);
                first_numero = 0;
                break;
            default:
                if(first_numero == 0){
                    p_fixa[j] = 'E';
                    j++;
                    first_numero = 1;
                }
                p_fixa[j] = infixa[i];
                j++;
                break;
        }
    }
    p_fixa[j] == '\0';
    return p_fixa;
}

// Complexidade: O(n) onde n é o número de nós na pilha
void liberar_pilha_char(PilhaChar *pi){
    if(pi != NULL){
        NoChar *no;
        while((*pi) != NULL){
            no = *pi;
            *pi = (*pi)->prox;
            free(no);
        }
        free(pi);
    }
}