typedef struct ficha Ficha;

// Cria uma Ficha
Ficha* cria_ficha(int inscricao, char* nome, int classe, int normal_hours, int extra_hours);

// Libera Memória
void libera_ficha(Ficha* f);

// Imprime o Contracheque
void imprime_contracheque(Ficha* f, float salario_base);

