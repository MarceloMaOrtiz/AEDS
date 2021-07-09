// Implemente um programa na linguagem C que contemple uma fila de contatos para um call center. As opções
// do programa devem ser:
// a) Inserir Contato: deve solicitar ao usuário os dados do cliente e incluir na fila. Os dados são: ID, nome
// completo e telefone.
// b) Próximo Contato: deve pegar o contato do início da fila, removê-lo e mostrar os seus dados na tela para o
// usuário efetuar o contato com o cliente.
// c) Sair.

#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "Fila.h"

// Função auxiliar para limpar o buffer do teclado
void fflush_stdin(){
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

int main(){
    Fila* fila = cria_fila();
    int x;
    int id, telefone;
    struct contato c;
    char nome[30];
    char opcao;
    printf("\n\t####### Call Center #######\n");
    do{
        printf("\n##### MENU #####\n");
        printf("\ta) Inserir Contato\n");
        printf("\tb) Proximo Contato\n");
        printf("\tc) Sair\n");
        printf("Opcao: ");
        scanf("%c", &opcao);
        fflush_stdin();
        switch(opcao){
            case 'a':
            case 'A':
                printf("\n### Inserir ###\n");
                printf("\tID: ");
                scanf("%d", &id);
                printf("\tNome: ");
                scanf("%s", &nome);
                printf("\tTelefone: ");
                scanf("%d", &telefone);
                fflush_stdin();
                c.ID = id;
                strcpy(c.nome, nome);
                c.tel = telefone;
                x = insere_fila(fila, c);
                break;
            case 'b':
            case 'B':
                remove_fila(fila);
                break;
            case 'c':
            case 'C':
                break;
            default:
                printf("\nOpcao Invalida. Tente novamente.\n");
        }
    }while(opcao != 'c' && opcao != 'C');
    
}