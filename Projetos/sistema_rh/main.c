#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Para utilizar strlen()

#include "lib/arvoreFuncionario/arvoreFuncionario.h"

// Função para pausar o programa
void pause(){
    printf("Pressione qualquer tecla para continuar...");
    scanf("%*c"); // lê um tecla qualquer e descarta o valor dela
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

    No* arvoreNome;
    No* arvoreCPF;

    int opcao;

    arvoreNome = criaArvore();
    arvoreCPF = criaArvore();

    do{
        system("clear"); // Linux
        printf(" ####################################################\n");
        printf(" ####  Trabalho Algoritmo e Estrutura de Dados  #####\n");
        printf(" ####################################################\n\n");
        printf(" Bem vindo ao Sistema de RH do Elielson.\n\n");
        printf(" Função do Software é gerenciar os Funcionários.\n\n");
        printf(" ####################################################\n");
        printf(" ######################  MENU  ######################\n");
        printf(" ####################################################\n\n");
        printf(" 1- Cadastrar um funcionário\n");
        printf(" 2- Remover um funcionário pelo nome\n");
        printf(" 3- Remover um funcionário pelo CPF\n");
        printf(" 4- Buscar e exibir os dados de um funcionário pelo nome\n");
        printf(" 5- Buscar e exibir os dados de um funcionário pelo cpf\n");
        printf(" 6- Exibir os dados de todos os funcionários ordenados pelo nome\n");
        printf(" 7- Remover todos os funcionários\n");
        printf(" 8- Sair\n\n");

        printf("\tOpção: ");
        scanf("%d", &opcao);
        fflush_stdin();

        switch(opcao){
            case 1:
                printf(" #############  CADASTRO DE FUNCIONÁRIO  #############\n\n");
                
                int verifica_insercao;

                int cpf;
                char nome[50];
                char profissao[30];

                // Leitura dos dados
                printf(" NOME: ");
                fgets(nome, 50, stdin);
                clean_fgets(nome);

                printf(" CPF: ");
                scanf("%d", &cpf);
                fflush_stdin();

                printf(" PROFISSÃO: ");
                fgets(profissao, 30, stdin);
                clean_fgets(profissao);

                printf("NOME: %s\n", nome);
                printf("PROFISSAO: %s\n", profissao);
                printf("LEN: %ld\n", strlen(profissao));
                printf("\nCPF = %d\n\n", cpf);


                // Adiciona funcionário em ambas as árvores
                // Retornando: 1 = Sucesso, -1 = Já existe, 0 = Error
                verifica_insercao = adicionaFuncionario(arvoreNome, arvoreCPF, nome, cpf, profissao);

                printf("\nInsersao: %d\n", verifica_insercao);
                
                break;
            case 2:
                printf("OPCAO 2\n\n");
                break;
            case 3:
                printf("OPCAO 3\n\n");
                break;
            case 4:
                printf("OPCAO 4\n\n");
                break;
            case 5:
                printf("OPCAO 5\n\n");
                break;
            case 6:
                printf("OPCAO 6\n\n");
                break;
            case 7:
                printf("OPCAO 7\n\n");
                break;
            case 8:
                printf("OPCAO 8\n\n");
                break;
            default:
                printf("OPCAO INVALIDA\n\n");
                break;
        }

        pause();

    }while(opcao != 8);
    
    liberaArvore(arvoreCPF);
    liberaArvore(arvoreNome);

    return 0;
}