#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#include "Arvore.h"

No** cria(){
    No** raiz = (No**)malloc(sizeof(No*));
    if(raiz != NULL)
        *raiz = NULL;
    return raiz;
}

void cadastrar(No** raiz, int titulo, char nome[]){
    
    No* novo;
    novo = (No*)malloc(sizeof(No));
    if(novo == NULL){
        printf("\n  Problema no cadastro...\n\n");
        return;
    }

    Info* eleitor;
    eleitor = (Info*)malloc(sizeof(Info));
    if(eleitor == NULL){
        printf("\n  Problema no cadastro...\n\n");
        return;
    }

    eleitor->titulo_eleitor = titulo;
    strcpy(eleitor->nome, nome);
    eleitor->voto = 0;

    novo->info = eleitor;
    novo->esq = NULL;
    novo->dir = NULL;

    if(*raiz == NULL){
        *raiz = novo;
    }else{
        No* aux = *raiz;
        No* ant = NULL;
        while(aux != NULL){
            ant = aux;
            if(titulo == aux->info->titulo_eleitor){
                printf("\n  Titulo já cadastrado...\n\n");
                free(novo);
                free(eleitor);
                return;
            }
            if(titulo < aux->info->titulo_eleitor)
                aux = aux->esq;
            else
                aux = aux->dir;
        }
        if(titulo < ant->info->titulo_eleitor)
            ant->esq = novo;
        else
            ant->dir = novo;
    }
    printf("\n  Cadastro realizado com sucesso...\n");
}

No* remove_no(No* no){
    No *aux1, *aux2;
    if(no->esq == NULL){
        aux2 = no->dir;
        free(no);
        return aux2;
    }
    aux1 = no;
    aux2 = no->esq;
    while(aux1->dir != NULL){
        aux1 = aux2;
        aux2 = aux2->dir;
    }
    if(aux1 != no){
        aux1->dir = aux2->esq;
        aux2->esq = no->esq;
    }
    aux2->dir = no->dir;
    free(no);
    return aux2;
}

No* remove_no_eleitor(No* no){
    No *aux1, *aux2;
    if(no->esq == NULL){
        aux2 = no->dir;
        free(no->info);
        free(no);
        return aux2;
    }
    aux1 = no;
    aux2 = no->esq;
    while(aux1->dir != NULL){
        aux1 = aux2;
        aux2 = aux2->dir;
    }
    if(aux1 != no){
        aux1->dir = aux2->esq;
        aux2->esq = no->esq;
    }
    aux2->dir = no->dir;
    free(no->info);
    free(no);
    return aux2;
}

void remover(No** raizTitulos, No** raizVotos, int titulo){
    if(raizTitulos == NULL || *raizTitulos == NULL){
        printf("\n  Problema na Remoção...\n\n");
        return;
    }
    No *aux, *ant;
    aux = *raizVotos;
    ant = NULL;
    while(aux != NULL){
        if(titulo == aux->info->titulo_eleitor){
            if(titulo == (*raizVotos)->info->titulo_eleitor){
                *raizVotos = remove_no(aux);
            }else{
                if(ant->dir == aux)
                    ant->dir = remove_no(aux);
                else
                    ant->esq = remove_no(aux);
            }
            break;
        }
        ant = aux;
        if(titulo < aux->info->titulo_eleitor)
            aux = aux->esq;
        else
            aux = aux->dir;
    }
    aux = *raizTitulos;
    ant = NULL;
    while(aux != NULL){
        if(titulo == aux->info->titulo_eleitor){
            if(titulo == (*raizTitulos)->info->titulo_eleitor){
                *raizTitulos = remove_no_eleitor(aux);
            }else{
                if(ant->dir == aux)
                    ant->dir = remove_no_eleitor(aux);
                else
                    ant->esq = remove_no_eleitor(aux);
            }
            printf("\n  Remoção realizada com Sucesso...\n");
            return;
        }
        ant = aux;
        if(titulo < aux->info->titulo_eleitor)
            aux = aux->esq;
        else
            aux = aux->dir;
    }
    printf("\n Eleitor não encontrado...\n");
    return;
}

void nova_votacao(No** raiz){
    if(*raiz == NULL)
        return;
    nova_votacao(&((*raiz)->esq));
    nova_votacao(&((*raiz)->dir));
    (*raiz)->info->voto = 0;
    free(*raiz);
}

Info* busca(No** raiz, int titulo){
    if(*raiz == NULL)
        return NULL;
    No* aux = *raiz;
    while(aux != NULL){
        if(titulo == aux->info->titulo_eleitor)
            return aux->info;
        if(titulo < aux->info->titulo_eleitor)
            aux = aux->esq;
        else
            aux = aux->dir;
    }
    return NULL;
}

void votar(No** raizTitulos, No** raizVotos, int titulo, int voto){
    if(titulo == voto){
        printf("\n  Não é possível votar em você mesmo...\n");
        return;
    }
    Info* eleitor = busca(raizTitulos, titulo);
    if(eleitor == NULL){
        printf("\n  Eleitor não cadastrado...\n");
        return;
    }
    if(eleitor->voto != 0){
        printf("\n  Eleitor já votou...\n");
        return;
    }
    eleitor->voto = voto;

    No* novo = (No*)malloc(sizeof(No));
    novo->info = eleitor;
    novo->esq = NULL;
    novo->dir = NULL;

    if(*raizVotos == NULL)
        *raizVotos = novo;
    else{
        No* aux = *raizVotos;
        No* ant = NULL;
        while(aux != NULL){
            ant = aux;
            if(titulo == aux->info->titulo_eleitor){
                printf("\n  Eleitor já votou...\n");
                free(novo);
                return;
            }
            if(titulo < aux->info->titulo_eleitor)
                aux = aux->esq;
            else
                aux = aux->dir;
        }
        if(titulo > ant->info->titulo_eleitor)
            ant->dir = novo;
        else
            ant->esq = novo;
    }
    printf("\n  Voto realizado com sucesso...\n");
    return;
}

void remover_voto(No** raiz, int titulo){
    if(raiz == NULL)
        return;
    No *aux = *raiz;
    No *ant = NULL;
    while(aux != NULL){
        if(titulo == aux->info->titulo_eleitor){
            if(aux == *raiz)
                *raiz = remove_no(aux);
            else{
                if(ant->dir == aux)
                    ant->dir = remove_no(aux);
                else
                    ant->esq = remove_no(aux);
            }
            printf("\n  Voto removido com sucesso...\n");
            return;
        }
        ant = aux;
        if(titulo < aux->info->titulo_eleitor)
            aux = aux->esq;
        else
            aux = aux->dir;
    }
    printf("\n  Eleitor ainda não votou...\n");
    return;
}

int tamanho_arvore(No** raiz){
    if(*raiz == NULL)
        return 0;
    return 1 + tamanho_arvore(&((*raiz)->esq)) + tamanho_arvore(&((*raiz)->dir));
}

void preenche_vetores(No** raizTitulos, No** raizVotos, Info** candidatos, int* qtd_votos, int tamanho){
    if(*raizVotos == NULL)
        return;
    preenche_vetores(raizTitulos, &((*raizVotos)->esq), candidatos, qtd_votos, tamanho);
    preenche_vetores(raizTitulos, &((*raizVotos)->dir), candidatos, qtd_votos, tamanho);
    int i, voto;
    voto = (*raizVotos)->info->voto;
    for(i = 0; i < tamanho; i++){
        if(candidatos[i] == NULL){
            candidatos[i] = busca(raizTitulos, (*raizVotos)->info->voto);
            qtd_votos[i]++;
            i = tamanho;
        }
        else if(candidatos[i]->titulo_eleitor == voto){
            qtd_votos[i]++;
            i = tamanho;
        }
    }
}

void ordena_vetores(Info** candidatos, int* qtd_votos, int tamanho){
    int i, continua, aux;
    Info* aux_candidato;
    do{
        continua = 0;
        for(i = 0; i < tamanho-1; i++){
            if(qtd_votos[i] < qtd_votos[i+1]){
                aux = qtd_votos[i];
                qtd_votos[i] = qtd_votos[i+1];
                qtd_votos[i+1] = aux;

                aux_candidato = candidatos[i];
                candidatos[i] = candidatos[i+1];
                candidatos[i+1] = aux_candidato;

                continua = 1;
            }
        }
    }while(continua != 0);
}

void resultado_parcial(No** raizTitulos, No** raizVotos){
    if(*raizVotos == NULL){
        printf("\n  Não há votos...\n");
        return;
    }
    int i;
    int tamanho = tamanho_arvore(raizVotos);
    Info** candidatos;
    int* qtd_votos;
    candidatos = (Info**)malloc(tamanho*sizeof(Info*));
    qtd_votos = (int*)malloc(tamanho*sizeof(int));

    for(i = 0; i < tamanho; i++){
        candidatos[i] = NULL;
        qtd_votos[i] = 0;
    }

    preenche_vetores(raizTitulos, raizVotos, candidatos, qtd_votos, tamanho);

    ordena_vetores(candidatos, qtd_votos, tamanho);

    i = 0;
    while(candidatos[i] != NULL){
        printf("\n    Titulo: %d\n", candidatos[i]->titulo_eleitor);
        printf("    Nome: %s\n", candidatos[i]->nome);
        printf("    Votos recebidos: %d\n", qtd_votos[i]);
        i++;
    }
}

void votantes(No** raiz){
    if(*raiz == NULL)
        return;
    votantes(&((*raiz)->esq));
    printf("\n    Titulo: %d\n", (*raiz)->info->titulo_eleitor);
    printf("    Nome: %s\n", (*raiz)->info->nome);
    printf("    Voto: %d\n", (*raiz)->info->voto);
    votantes(&((*raiz)->dir));
}

void libera(No** raiz){
    if(*raiz == NULL)
        return;
    libera(&((*raiz)->esq));
    libera(&((*raiz)->dir));
    free(*raiz);
}

void libera_eleitor(No** raiz){
    if(*raiz == NULL)
        return;
    libera_eleitor(&((*raiz)->esq));
    libera_eleitor(&((*raiz)->dir));
    free((*raiz)->info);
    free(*raiz);
}