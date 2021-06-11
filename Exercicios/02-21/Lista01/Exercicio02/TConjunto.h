typedef struct tconjunto TConjunto;

TConjunto* cria_conjunto(int tam);

void ler_dados(TConjunto* tc);

void imprimir_conjunto(TConjunto* tc);

void uniao_conjuntos(TConjunto *tc1, TConjunto* tc2);

void intersecao_conjuntos(TConjunto* tc1, TConjunto* tc2);

void iguais_conjuntos(TConjunto* tc1, TConjunto* tc2);

void libera_conjunto(TConjunto* tc);