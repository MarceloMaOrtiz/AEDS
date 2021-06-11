typedef struct aluno_reg{
    char nome[50];
    int matricula;
}aluno;

typedef struct disciplina_reg {
    char nome[50];
    int codigo;
    aluno* matriculados;
    int num_matriculados;
}disciplina;

aluno* mais_aluno(aluno alunos[], int tam);