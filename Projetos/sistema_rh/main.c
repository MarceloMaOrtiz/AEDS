#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Para utilizar strlen()

#include "lib/arvoreFuncionario/arvoreFuncionario.h"

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

    No* arvoreNome;
    No* arvoreCPF;

    // Para declarar dessa forma foi necessário inserir a estrutura no .h
    Info infoNo; // Utilizado para armazenar informações de um único nó

    int opcao; // Controla as opções do menu

    // Variáveis que serão utilizadas armazenamento auxiliar das variáveis
    int cpf; 
    char nome[50];
    char profissao[30];

    // Verificações das funções para controlar o compartamento do programa de acordo com os retornos
    int verifica_insercao;
    int verifica_remocao_nome;
    int verifica_remocao_cpf;
    int verifica_remocao;

    // Inicialização das árvores
    arvoreNome = criaArvore();
    arvoreCPF = criaArvore();

    do{
        // system("cls"); // Windows
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
                // system("cls"); // Windows
                system("clear"); // Linux
                printf(" #############  CADASTRO DE FUNCIONÁRIO  #############\n\n");

                // Leitura dos dados
                printf("\tNome: ");
                fgets(nome, 50, stdin);
                clean_fgets(nome);

                printf("\tCPF: ");
                scanf("%d", &cpf);
                fflush_stdin();

                printf("\tProfissão: ");
                fgets(profissao, 30, stdin);
                clean_fgets(profissao);

                // Adiciona funcionário em ambas as árvores
                // Retornando: 1 = Sucesso, -1 = Já existe nome, -2 = Já existe CPF, 0 = Error
                verifica_insercao = adicionaFuncionario(arvoreNome, arvoreCPF, nome, cpf, profissao);
                
                if(verifica_insercao == 1)
                    printf("\n\tFuncionário adicionado com sucesso.\n\n");
                else if(verifica_insercao == -1){
                    printf("\n\tNome já está sendo utilizado\n");
                    printf("\tFuncionário não foi adicionado.\n\n");
                }
                else if(verifica_insercao == -2){
                    printf("\n\tCPF já está sendo utilizado\n");
                    printf("\tFuncionário não foi adicionado.\n\n");
                }
                else{
                    printf("\tFuncionário não foi adicionado.\n\n");
                }

                break;
            case 2:
                // system("cls"); // Windows
                system("clear"); // Linux
                printf(" #########  REMOÇÃO DE FUNCIONÁRIO PELO NOME  #########\n\n");

                printf("\tNome: ");
                fgets(nome, 50, stdin);
                clean_fgets(nome);

                infoNo = buscaNoNome(arvoreNome, nome);
 
                verifica_remocao_nome = removeNoArvoreNome(arvoreNome, nome, 0); // 0 é para não liberar memória da Info

                if(verifica_remocao_nome == 1)
                    verifica_remocao_cpf = removeNoArvoreCPF(arvoreCPF, infoNo.CPF, 1); // 1 é para liberar memória da Info

                if(verifica_remocao_nome == 1 && verifica_remocao_cpf == 1)
                    printf("\n\tRemoção do %s feita com sucesso.\n\n", nome);
                else
                    printf("\n\tFuncionário %s não encontrado.\n\n", nome);

                break;
            case 3:
                // system("cls"); // Windows
                system("clear"); // Linux
                printf(" #########  REMOÇÃO DE FUNCIONÁRIO PELO CPF  #########\n\n");

                printf("\tCPF: ");
                scanf("%d", &cpf);
                fflush_stdin();

                infoNo = buscaNoCPF(arvoreCPF, cpf);

                verifica_remocao_cpf = removeNoArvoreCPF(arvoreCPF, cpf, 0); // 0 é para não liberar memória da Info

                if(verifica_remocao_cpf == 1)
                    verifica_remocao_nome = removeNoArvoreNome(arvoreNome, infoNo.Nome, 1); // 1 é para liberar memória da Info

                if(verifica_remocao_nome == 1 && verifica_remocao_cpf == 1)
                    printf("\n\tRemoção do CPF %d feita com sucesso.\n\n", cpf);
                else
                    printf("\n\tCPF %d não encontrado.\n\n", cpf);

                break;
            case 4:
                // system("cls"); // Windows
                system("clear"); // Linux
                printf(" ##########  BUSCA DE FUNCIONÁRIO PELO NOME  ##########\n\n");

                printf("\tNome: ");
                fgets(nome, 50, stdin);
                clean_fgets(nome);

                infoNo = buscaNoNome(arvoreNome, nome);

                if(infoNo.CPF != -1){
                    printf("\n\tNome: %s\n", infoNo.Nome);
                    printf("\tCPF: %d\n", infoNo.CPF);
                    printf("\tProfissão: %s\n\n", infoNo.Profissao);
                }
                else
                    printf("\n\tFuncionário não encontrado.\n\n");

                break;
            case 5:
                // system("cls"); // Windows
                system("clear"); // Linux
                printf(" ##########  BUSCA DE FUNCIONÁRIO PELO CPF  ##########\n\n");

                printf("\tCPF: ");
                scanf("%d", &cpf);
                fflush_stdin();

                infoNo = buscaNoCPF(arvoreCPF, cpf);

                if(infoNo.CPF != -1){
                    printf("\n\tNome: %s\n", infoNo.Nome);
                    printf("\tCPF: %d\n", infoNo.CPF);
                    printf("\tProfissão: %s\n\n", infoNo.Profissao);
                }
                else
                    printf("\n\tFuncionário não encontrado.\n\n");

                break;
            case 6:
                // system("cls"); // Windows
                system("clear"); // Linux
                printf(" ###################  FUNCIONÁRIOS  ###################\n\n");

                exibirEmOrdemArvore(arvoreNome);

                break;
            case 7:

                verifica_remocao = removerFuncionarios(arvoreNome, arvoreCPF);

                if(verifica_remocao == 1)
                    printf("\n\tTodos funcionários removidos com sucesso.\n\n");
                else
                    printf("\n\tÁrvore já está vazia.\n\n");

                break;
            case 8:
                // system("cls"); // Windows
                system("clear"); // Linux
                printf("\n\tObrigado por utilizar o sistema.\n");
                printf("\n\tEspero que tenha gostado.\n");
                printf("\n\tElielson Batista Oliveira.\n\n");
                break;
            default:
                printf("\n\tOpção inválida.\n\n");
                break;
        }

        pause();

    }while(opcao != 8);
    
    liberaArvore(arvoreNome, 0); // 0 não limpará a info do funcionário
    liberaArvore(arvoreCPF, 1); // 1 limpará a info do funcionário

    return 0;
}