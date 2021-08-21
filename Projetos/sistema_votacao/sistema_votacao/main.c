#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#include "ArvoreEleitor.h"

// Função para pausar o programa
void pause(){
    printf("Pressione qualquer tecla para continuar...");
    scanf("%*c"); // lê uma tecla qualquer e descarta o valor dela
}

// Função auxiliar para limpar o buffer do teclado
void fflush_stdin(){
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

// Função para remover \n da palavra
void clean_fgets(char word[]){
    int len = strlen(word);
    if(len == 0)
        return;
    else
        if(word[len-1] == '\n')
            word[--len] = 0;
}


int main(){
    ArvoreEleitor* arvore;
    arvore = criaArvore();
    int opcao;

    printf("-------------------------------\n");
    printf("------ Trabalho 2 - AEDS ------\n");
    printf("---- Mateus ----\n");
    printf("-------------------------------\n\n");
    printf("-------------------------------\n");
    printf("----- Sistema de Votacao -----\n");
    printf("-------------------------------\n\n");

    do{
        printf("----------- MENU -----------\n\n");
        printf("\t1. Cadastrar um titulo\n");
        printf("\t2. Descadastrar um titulo\n");
        printf("\t3. Iniciar nova votacao\n");
        printf("\t4. Votar\n");
        printf("\t5. Retirar voto\n");
        printf("\t6. Mostrar resultado parcial das eleicoes\n");
        printf("\t7. Listar pessoas que ja votaram\n");
        printf("\t8. Sair\n\n");
        printf(" Opcao: ");
        scanf("%d", &opcao);
        printf("\n\n");
        switch(opcao){
            int titulo, voto;
            char nome[50];
            int verificador = 0;
            case 1:
                // system("cls"); // Windows
                system("clear"); // Linux
                printf("----- Cadastrar Eleitor -----\n");

                printf("\tTitulo: ");
                scanf("%d", &titulo);
                fflush_stdin();

                printf("\tNome: ");
                fgets(nome, 50, stdin);
                clean_fgets(nome);

                verificador = insereArvore(arvore, titulo, nome);

                if(verificador)
                    printf("\n\n Eleitor cadastrado com sucesso\n\n");
                else
                    printf("\n\n Eleitor nao foi cadastrado\n\n");

                break;
            case 2:
                // system("cls"); // Windows
                system("clear"); // Linux
                printf("----- Remover Eleitor -----\n");

                printf("\tTitulo: ");
                scanf("%d", &titulo);
                fflush_stdin();

                verificador = removeEleitorArvore(arvore, titulo);

                if(verificador)
                    printf("\n\n Eleitor removido com sucesso\n\n");
                else
                    printf("\n\n Eleitor nao foi encontrado\n\n");
                break;
            case 3:

                verificador = novaVotacao(arvore);

                if(verificador)
                    printf("\n\n Todos os votos removidos\n\n");
                else
                    printf("\n\n Problema ao iniciar nova votacao\n\n");
                break;
            case 4:
                // system("cls"); // Windows
                system("clear"); // Linux
                printf("----- Votar -----\n");

                printf("\tTitulo do Eleitor: ");
                scanf("%d", &titulo);
                fflush_stdin();

                printf("\tVoto: ");
                scanf("%d", &voto);
                fflush_stdin();

                if(titulo == voto){
                    printf("\n\n Nao e possivel votar em voce mesmo\n\n");
                    break;
                }

                verificador = votar(arvore, titulo, voto);

                if(verificador)
                    printf("\n\n Voto realizado com sucesso\n\n");
                else
                    printf("\n\n Voto nao foi realizado\n\n");
                break;
            case 5:
                // system("cls"); // Windows
                system("clear"); // Linux
                printf("----- Retira Voto -----\n");

                printf("\tTitulo do Eleitor: ");
                scanf("%d", &titulo);
                fflush_stdin();

                verificador = retirarVoto(arvore, titulo);

                if(verificador)
                    printf("\n\n Voto removido com sucesso\n\n");
                else
                    printf("\n\n Voto nao foi removido\n\n");
                break;
            case 6:
                // system("cls"); // Windows
                system("clear"); // Linux
                printf("----- Resultado Parcial -----\n");

                resultadoParcial(arvore);

                break;
            case 7:
                // system("cls"); // Windows
                system("clear"); // Linux
                printf("----- Votantes -----\n");

                mostrarVotantes(arvore);

                break;
            case 8:
                // system("cls"); // Windows
                system("clear"); // Linux
                printf("\nObrigado por utilizar o Software...\n");

                liberaArvore(arvore);
                break;
            default:
                printf("\nOpcao invalida. Tente novamente...\n\n");
                break;
        }
    }while(opcao != 8);

    return 0;
}