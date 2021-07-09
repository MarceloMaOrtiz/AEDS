// Escreva um procedimento recursivo que receba uma string como parâmetro e a exiba invertida.

#include "stdlib.h"
#include "stdio.h"

void inverte_string(char string[], int tamanho) {
    if (tamanho < 1){
        printf("\n\n");
        return;
    }
    else {
        printf("%c", string[tamanho-1]);
        inverte_string(string, tamanho-1);
    }
}

int main() {
    char s1[] = {'T', 'e', 's', 't', 'a', 'n', 'd', 'o', '\0'};
    char s2[] = "exercicio";
    
    printf("\n\tS1: %s\tSize: %ld\n\tS2: %s\tSize: %ld\n\n", s1, sizeof(s1), s2, sizeof(s2));

    inverte_string(s1, sizeof(s1));
    inverte_string(s2, sizeof(s2));

    return 0;
}