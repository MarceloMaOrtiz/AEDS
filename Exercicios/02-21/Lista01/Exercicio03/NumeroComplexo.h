typedef struct numero_complexo NumeroComplexo;

NumeroComplexo* cria_numero();

void atribui_numero(NumeroComplexo* n, float r, float i);

void imprime_numero(NumeroComplexo* n);

void copia_numero(NumeroComplexo* n1, NumeroComplexo* n2);

NumeroComplexo* soma(NumeroComplexo* n1, NumeroComplexo* n2);

void libera_numero(NumeroComplexo* n);

