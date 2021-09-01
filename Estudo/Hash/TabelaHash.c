#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "TabelaHash.h"

// Estrutura onde itens, armazena o endereço do endereço inicial do primeiro elemento
// de um lista de Alunos
struct hash{
    int qtd, TABLE_SIZE;
    Aluno **itens;
};

// Aloca os espaços o array de ponteiros e inicializa com NULL
Hash* cria_hash(int TABLE_SIZE){
    Hash* ha = (Hash*)malloc(sizeof(Hash));
    if(ha != NULL){
        int i;
        ha->qtd = 0;
        ha->TABLE_SIZE = TABLE_SIZE;
        ha->itens = (Aluno**)malloc(TABLE_SIZE*sizeof(Aluno*));
        if(ha->itens == NULL){
            free(ha);
            return NULL;
        }
        for(i = 0; i < TABLE_SIZE; i++){
            // Justamente a falta dessa linha torna possível a economia de memória
            // ha->itens[i] = (Aluno*)malloc(sizeof(Aluno));
            ha->itens[i] = NULL;
        }
    }
    return ha;
}

// Método da Divisão
int chave_divisao(int chave, int TABLE_SIZE){
    return (chave & 0x7FFFFFFF) % TABLE_SIZE;
}

// Método da Multiplicação
int chave_multiplicacao(int chave, int TABLE_SIZE){
    float A = 0.6180339887; // Constante A entre 1 e 0
    float val = chave * A;
    val = val - (int)val;
    return (int)(TABLE_SIZE * val);
}

// Método da Dobra
int chave_dobra(int chave, int TABLE_SIZE){
    int num_bits = 10;
    int parte1 = chave >> num_bits; // Desloca a chave 10 Bits para a direita
    int parte2 = chave & (TABLE_SIZE-1); // Operação E-Bit-a-Bit
    return (parte1 ^ parte2); // Ou exclusivo
}

int valor_string(char *str){
    int i, valor = 7;
    int tam = strlen(str);
    for(i = 0; i < tam; i++)
        valor = 31 * valor + (int)str[i];
    return valor;
}

int insere_hash_sem_colisao(Hash* ha, Aluno al){
    if(ha == NULL || ha->qtd == ha->TABLE_SIZE)
        return 0;
    int chave = al.matricula;
    int pos = chave_divisao(chave, ha->TABLE_SIZE);
    // Poderia ser o nome, mas o nome sozinho poderia repetir
    // int chave = valor_string(al.nome);
    Aluno *novo;
    novo = (Aluno*)malloc(sizeof(Aluno));
    if(novo == NULL)
        return 0;
    *novo = al;
    ha->itens[pos] = novo;
    ha->qtd++;
    return 1;
}

int busca_hash_sem_colisao(Hash* ha, int mat, Aluno* al){
    if(ha == NULL)
        return 0;
    int pos = chave_divisao(mat, ha->TABLE_SIZE);
    if(ha->itens[pos] == NULL)
        return 0;
    *al = *(ha->itens[pos]);
    return 1;
}

int sondagem_linear(int pos, int i, int TABLE_SIZE){
    return ((pos + i) & 0x7FFFFFFF) % TABLE_SIZE;
}

int sondagem_quadratica(int pos, int i, int TABLE_SIZE){
    pos = pos + 2 * i + 5 * i * i;
    return (pos & 0xFFFFFFF) % TABLE_SIZE;
}

int duplo_hash(int H1, int chave, int i, int TABLE_SIZE){
    int H2 = chave_divisao(chave, TABLE_SIZE-1) + 1;
    return ((H1 + i * H2) & 0x7FFFFFFF) % TABLE_SIZE;
}

int insere_hash_endereco_aberto(Hash* ha, Aluno al){
    if(ha == NULL || ha->qtd == ha->TABLE_SIZE)
        return 0;
    int chave = al.matricula;
    int i, pos, newPos;
    pos = chave_divisao(chave, ha->TABLE_SIZE);
    for(i = 0; i < ha->TABLE_SIZE; i++){
        newPos = sondagem_linear(pos, i, ha->TABLE_SIZE);
        // newPos = sondagem_quadratica(pos, i, ha->TABLE_SIZE);
        // newPos = duplo_hash(pos, chave, i, ha->TABLE_SIZE);
        if(ha->itens[newPos] == NULL){
            Aluno *novo;
            novo = (Aluno*)malloc(sizeof(Aluno));
            if(novo == NULL)
                return 0;
            *novo = al;
            ha->itens[newPos] = novo;
            ha->qtd++;
            return 1;
        }
    }
    return 0;
}

int busca_hash_endereco_aberto(Hash* ha, int mat, Aluno* al){
    if(ha == NULL)
        return 0;
    int i, pos, newPos;
    pos = chave_divisao(mat, ha->TABLE_SIZE);
    for(i = 0; i < ha->TABLE_SIZE; i++){
        newPos = sondagem_linear(pos, i, ha->TABLE_SIZE);
        // newPos = sondagem_quadratica(pos, i, ha->TABLE_SIZE);
        // newPos = duplo_hash(pos, chave, i, ha->TABLE_SIZE);
        if(ha->itens[newPos] == NULL)
            return 0;
        if(ha->itens[newPos]->matricula == mat){
            *al = *(ha->itens[newPos]);
            return 1;
        }
    }
    return 0;
}

// Percorre todo o array e verifica se existe um elemento para ser desalocado
void libera_hash(Hash* ha){
    if(ha != NULL){
        int i;
        for(i = 0; i < ha->TABLE_SIZE; i++){
            if(ha->itens[i] != NULL)
                free(ha->itens[i]);
        }
        free(ha->itens);
        free(ha);
    }
}
