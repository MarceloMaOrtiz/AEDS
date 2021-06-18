// Escreva um algoritmo que, dado um conjunto S de n inteiros e outro inteiro x, determina se
// existe ou não dois elementos de S cuja soma é exatamente x. Em seguida, análise a complexidade
// deste algoritmo.

#include "stdlib.h"
#include "stdio.h"

int verifica_soma(int S[], int n, int x){
    int i, j, soma;
    for(i = 0; i < n-1; i++){
        for(j = i+1; j < n; j++){
            soma = S[i] + S[j];
            if(soma == x)
                return 1;
        }
    }
    return 0;
}

int main(){
    int S[7];

    for(int i = 0; i < 7; i++){
        S[i] = i + 3;
    }

    int verifica = 0;
    verifica = verifica_soma(S, 7, 20);
    printf("\n%d\n", verifica);
}