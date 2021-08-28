#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#include "ArvoreEleitor.h"

struct No_Est{
    Info *info;
    struct No_Est *esq;
    struct No_Est *dir;
};

// Cria o ponteiro raiz
ArvoreEleitor* criaArvore(){
    ArvoreEleitor* raiz = (ArvoreEleitor*)malloc(sizeof(ArvoreEleitor));
    if(raiz != NULL){ // Verifica se a alocação deu certo
        *raiz = NULL;
    }
    return raiz;
}

// Verifica se Eleitor existe - Função auxiliar
int eleitorExiste(ArvoreEleitor* raiz, int titulo){
    if(raiz == NULL)
        return 1;
    if(*raiz == NULL)
        return 0;
    No* atual = *raiz;
    while(atual != NULL){
        if(atual->info->titulo_eleitor == titulo)
            return 1;
        if(atual->info->titulo_eleitor > titulo)
            atual = atual->esq;
        else
            atual = atual->dir;
    }
    return 0;
}

// Cria um Eleitor - Função auxiliar
Info* criaEleitor(int titulo, char nome[]){
    Info* eleitor = (Info*)malloc(sizeof(Info));
    if(eleitor != NULL){
        eleitor->titulo_eleitor = titulo;
        strcpy(eleitor->Nome, nome);
        eleitor->voto = 0;
    }
    return eleitor;
}

// Insere o Eleitor na Arvore
int insereArvore(ArvoreEleitor* raiz, int titulo, char nome[]){
    if(raiz == NULL)
        return 0;
    if(eleitorExiste(raiz, titulo))
        return 0;
    No* novo;
    novo = (No*)malloc(sizeof(No));
    if(novo == NULL)
        return 0;
    Info* eleitor = criaEleitor(titulo, nome);
    novo->info = eleitor;
    novo->esq = NULL;
    novo->dir = NULL;
    if(*raiz == NULL)
        *raiz = novo;
    else{
        No* atual = *raiz;
        No* ant = NULL;

        int titulo_atual;

        while(atual != NULL){
            ant = atual;
            titulo_atual = atual->info->titulo_eleitor;
            if(titulo == titulo_atual){
                free(novo);
                return 0;
            }
            if(titulo < titulo_atual)
                atual = atual->esq;
            else
                atual = atual->dir;
        }
        if(titulo < titulo_atual)
            ant->esq = novo;
        else
            ant->dir = novo;
    }
    return 1;
}

// Função responsável por zerar os votos dos eleitores que votaram em determinado titulo
int limparVotos(ArvoreEleitor* raiz, int titulo){
    if(raiz == NULL)
        return 0;
    if(*raiz != NULL){
        if((*raiz)->info->voto == titulo)
            (*raiz)->info->voto = 0;
        limparVotos(&((*raiz)->esq), titulo);
        limparVotos(&((*raiz)->dir), titulo);
    }
    return 1;
}

// Função responsável por remover o nó
No* removeNoAtual(No* atual){
    No *no1, *no2;
    // Casos com 0 ou 1 nó filhos
    if(atual->esq == NULL){
        no2 = atual->dir;
        free(atual->info);
        free(atual);
        return no2;
    }
    // Procura filho mais a direita na sub-árvore da esquerda
    no1 = atual; // Utilizado para evitar uma situação específica onde o nó mais a direita possui um filho
    no2 = atual->esq; // associa a sub-árvore da esquerda
    while(no2->dir != NULL){ // Procura o nó mais a direita
        no1 = no2;
        no2 = no2->dir;
    }
    if(no1 != atual){ // Caso o no1 não seja o nó removido é necessário fazer uma correção
        no1->dir = no2->esq; // Como o nó mais a direita será removido, o nó anterior irá apontar para o nó da esquerda do no2
        no2->esq = atual->esq; // Novo nó aponta para sub-árvore da esquerda do nó removido
    }
    no2->dir = atual->dir; // Corrige o apontamento do novo posicionamento do nó em relação a sub-arvore da direita
    free(atual->info);
    free(atual); 
    return no2; // Retorna o novo nó que será linkado ao nó anterior ao removido
}

// Remove o Eleitor da Arvore
int removeEleitorArvore(ArvoreEleitor* raiz, int titulo){
    if(raiz == NULL)
        return 0;
    No* ant = NULL;
    No* atual = *raiz;
    while(atual != NULL){
        if(titulo == atual->info->titulo_eleitor){
            if(atual == *raiz)
                *raiz = removeNoAtual(atual);
            else{
                if(ant->esq == atual)
                    ant->esq = removeNoAtual(atual);
                else
                    ant->dir = removeNoAtual(atual);
            }
            int verifica = 0;
            verifica = limparVotos(raiz, titulo);
            if(verifica)
                return 1;
            else
                return 0;
        }
        ant = atual;
        if(titulo < atual->info->titulo_eleitor)
            atual = atual->esq;
        else
            atual = atual->dir;
    }
    return 0;
}

int novaVotacao(ArvoreEleitor* raiz){
    if(raiz == NULL)
        return 0;
    if(*raiz != NULL){
        (*raiz)->info->voto = 0;
        novaVotacao(&((*raiz)->esq));
        novaVotacao(&((*raiz)->dir));
    }
    return 1;
}

int votar(ArvoreEleitor* raiz, int titulo, int voto){
    if(raiz == NULL)
        return 0;
    if(*raiz == NULL)
        return 0;
    No* atual = *raiz;
    while(atual != NULL){
        if(titulo == atual->info->titulo_eleitor){
            if(atual->info->voto == 0){
                atual->info->voto = voto;
                return 1;
            }else
                return 0;
        }
        if(titulo < atual->info->titulo_eleitor)
            atual = atual->esq;
        else
            atual = atual->dir;
    }
    return 0;
}

int retirarVoto(ArvoreEleitor* raiz, int titulo){
    if(raiz == NULL)
        return 0;
    if(*raiz == NULL)
        return 0;
    No* atual = *raiz;
    while(atual != NULL){
        if(titulo == atual->info->titulo_eleitor){
            if(atual->info->titulo_eleitor != 0){
                atual->info->voto = 0;
                return 1;
            }else
                return 0;
        }
        if(titulo < atual->info->titulo_eleitor)
            atual = atual->esq;
        else
            atual = atual->dir;
    }
    return 0;
}

int tamanhoArvore(ArvoreEleitor* raiz){
    if(raiz == NULL)
        return 0;
    if(*raiz == NULL)
        return 0;
    if(*raiz != NULL){
        return 1 + tamanhoArvore(&((*raiz)->esq)) + tamanhoArvore(&((*raiz)->dir));
    }
}

// Função auxiliar para inserir determinado voto nos vetores
void insereCandidatoVetor(int voto, int* candidatos, int* total_votos, int tam){
    int i;
    for(i = 0; i < tam; i++){
        if(candidatos[i] == -1){
            candidatos[i] = voto;
            total_votos[i]++;
            return;
        }
        if(candidatos[i] == voto){
            total_votos[i]++;
            return;
        }
    }
}

// Percorre toda a arvore, verificando se o voto é 0, caso não adiciona o voto nos vetores
void geraVetoresCandidatos(ArvoreEleitor* raiz, int* candidatos, int* total_votos, int tam){
    if((*raiz) != NULL){
        if((*raiz)->info->voto != 0)
            insereCandidatoVetor((*raiz)->info->voto, candidatos, total_votos, tam);
        geraVetoresCandidatos(&((*raiz)->esq), candidatos, total_votos, tam);
        geraVetoresCandidatos(&((*raiz)->dir), candidatos, total_votos, tam);
    }
}

// Função auxiliar para imprimir informações de um Eleitor
void mostrarEleitor(ArvoreEleitor* raiz, int titulo){
    No* atual = *raiz;
    while(atual != NULL){
        if(titulo == atual->info->titulo_eleitor){
            printf("\n------------------------\n");
            printf("\tTitulo: %d\n", titulo);
            printf("\tNome: %s\n", atual->info->Nome);
            return;
        }
        if(titulo < atual->info->titulo_eleitor)
            atual = atual->esq;
        else
            atual = atual->dir;
    }
}

// Função responsável por imprimir resultado parcial
void resultadoParcial(ArvoreEleitor* raiz){
    if(raiz == NULL)
        return;
    if(*raiz == NULL){
        return;
    }
    int i, j, aux, continua;
    int tam_arv = tamanhoArvore(raiz);
    // Vetores utilizados para controlar quem já recebeu votos e a quantidade
    int *candidatos = (int*)malloc(tam_arv*sizeof(int));
    int *total_votos = (int*)malloc(tam_arv*sizeof(int));
    for(i = 0; i < tam_arv; i++){
        candidatos[i] = -1;
        total_votos[i] = 0;
    }
    geraVetoresCandidatos(raiz, candidatos, total_votos, tam_arv);

    // Utiliza BubbleSort para ordenadar os vetor candidatos e total_votos
    do{
        continua = 0;
        for(i = 0; i < tam_arv-1; i++){
            if(total_votos[i] < total_votos[i+1]){
                aux = total_votos[i];
                total_votos[i] = total_votos[i+1];
                total_votos[i+1] = aux;

                aux = candidatos[i];
                candidatos[i] = candidatos[i+1];
                candidatos[i+1] = aux;
                
                continua = 1;
            }
        }
    }while(continua != 0);

    for(i = 0; i < tam_arv; i++){
        if(candidatos[i] == -1){
            i = tam_arv;
        }else{
            mostrarEleitor(raiz, candidatos[i]);
            printf("\tTotal: %d votos\n", total_votos[i]);
        }
    }

}

void mostrarVotantes(ArvoreEleitor* raiz){
    if(raiz == NULL)
        return;
    if((*raiz) == NULL)
        return;
    mostrarVotantes(&((*raiz)->esq));
    if((*raiz)->info->voto != 0){
        printf("\n------------------------\n");
        printf("\tTitulo: %d\n", (*raiz)->info->titulo_eleitor);
        printf("\tNome: %s\n", (*raiz)->info->Nome);
    }
    mostrarVotantes(&((*raiz)->dir));
}

// Função auxiliar para percorrer a árvore liberando os nós
void liberaNo(No* no){
    if(no == NULL)
        return;
    liberaNo(no->esq);
    liberaNo(no->dir);
    free(no->info);
    free(no);
}

// Destroi a árvore
void liberaArvore(ArvoreEleitor* raiz){
    if(raiz == NULL)
        return;
    liberaNo(*raiz);
    free(raiz);
}

