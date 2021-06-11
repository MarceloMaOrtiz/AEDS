#include <stdlib.h>
#include <stdio.h>
#include "DisciplinaAluno.h"
#include <string.h>

aluno* mais_aluno(aluno* alunos, int tam){
    aluno *alunos_novo = (aluno*)malloc((tam+1)*sizeof(struct aluno_reg));
    for (int i = 0; i < (tam); i++) {
        strcpy(alunos_novo[i].nome, alunos[i].nome);
        alunos_novo[i].matricula = alunos[i].matricula;
    }
    free(alunos);
    return alunos_novo;
}
