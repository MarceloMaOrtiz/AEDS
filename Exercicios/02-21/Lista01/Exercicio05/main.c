// Escreva um programa na linguagem C que use alocação dinâmica para criar 2 (duas) disciplinas. Em seguida,
// peça ao usuário para digitar as informações (nome e matrícula) de vários alunos para cada disciplina. Seu
// programa deve perguntar se o usuário quer adicionar mais alunos, e se a resposta for positiva, deve alocar
// espaço dinamicamente para inclusão desse aluno. Por último, o programa deve imprimir na tela as informações
// das duas disciplinas e dos alunos matriculados nelas.

#include <stdlib.h>
#include <stdio.h>
#include "DisciplinaAluno.h"
#include <string.h>

// Função auxiliar para limpar o buffer do teclado
void fflush_stdin(){
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

int main() {
    disciplina* disciplinas = (disciplina*)malloc(2*sizeof(struct disciplina_reg));

    strcpy(disciplinas[0].nome, "Calculo II");
    disciplinas[0].codigo = 1;
    disciplinas[0].num_matriculados = 0;

    strcpy(disciplinas[1].nome, "AEDS");
    disciplinas[1].codigo = 2;
    disciplinas[1].num_matriculados = 0;

    int continua = 0;
    int opcao = 'y';

    aluno* alunos_disc1 = (aluno*)malloc(sizeof(struct aluno_reg));
    aluno* alunos_disc2 = (aluno*)malloc(sizeof(struct aluno_reg));

    int contador = 0;

    printf("\n\n#### Alunos de %s ####\n", disciplinas[0].nome);
    do {
        printf("\n\t # Aluno %d\n", (contador + 1));
        printf("\n\tNome: ");
        fgets(alunos_disc1[contador].nome, 50, stdin);
        printf("\n\tMatricula: ");
        scanf("%d", &alunos_disc1[contador].matricula);
        fflush_stdin();

        disciplinas[0].num_matriculados = contador + 1;

        printf("\n\tDeseja inserir mais aluno (y / N)? R: ");
        scanf("%c", &opcao);
        fflush_stdin();
        if (opcao == 'n' || opcao == 'N')
            continua = 1;

        if (!continua) {
            contador++;
            alunos_disc1 = mais_aluno(alunos_disc1, contador);
        }
        
    }while(!continua);

    disciplinas[0].matriculados = alunos_disc1;

    contador = 0;
    continua = 0;

    printf("\n\n#### Alunos de %s ####\n", disciplinas[1].nome);
    do {
        printf("\n\t # Aluno %d\n", (contador + 1));
        printf("\n\tNome: ");
        fgets(alunos_disc2[contador].nome, 50, stdin);
        printf("\n\tMatricula: ");
        scanf("%d", &alunos_disc2[contador].matricula);
        fflush_stdin();

        disciplinas[1].num_matriculados = contador + 1;

        printf("\n\tDeseja inserir mais aluno (y / N)? R: ");
        scanf("%c", &opcao);
        fflush_stdin();
        if (opcao == 'n' || opcao == 'N')
            continua = 1;

        if (!continua) {
            contador++;
            alunos_disc2 = mais_aluno(alunos_disc2, contador);
        }
        
    }while(!continua);

    disciplinas[1].matriculados = alunos_disc2;

    printf("dis_contador = %d", disciplinas[0].num_matriculados);

    for(int i = 0; i < 2; i++) {
        printf("\n\n\t### %s ###\n", disciplinas[i].nome);
        printf("\tCodigo: %d\n", disciplinas[i].codigo);
        printf("\t# Alunos\n");
        for(int j = 0; j < disciplinas[i].num_matriculados; j++) {
            printf("\t\tNome: %s", disciplinas[i].matriculados[j].nome);
            printf("\t\tMatricula: %d\n\n", disciplinas[i].matriculados[j].matricula);
        }
    }

    return 0;
}