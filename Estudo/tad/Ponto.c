#include <stdlib.h>
#include <math.h>
#include "Ponto.h" // Inclui os protótipos

struct ponto{
    float x;
    float y;
};

Ponto* pto_cria(float x, float y){
    Ponto* p = (Ponto*)malloc(sizeof(Ponto));
    if(p != NULL){
        p->x = x;
        p->y = y;
    }
    return p;
}

void pto_libera(Ponto* p){
    free(p);
}

void pto_acessa(Ponto* p, float* x, float* y){
    if(p != NULL){
        *x = p->x;
        *y = p->y;
    }
}

void pto_atribui(Ponto* p, float x, float y){
    if(p != NULL){
        p->x = x;
        p->y = y;
    }
}

float pto_distancia(Ponto* p1, Ponto* p2){
    if(p1 != NULL && p2 != NULL){
        float dx = p1->x - p2->x;
        float dy = p1->y - p2->y;
        return sqrt(dx * dx + dy * dy);
    }
    else{
        return 15.5;
    }
}