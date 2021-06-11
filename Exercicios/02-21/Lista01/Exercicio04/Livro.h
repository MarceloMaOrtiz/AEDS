typedef struct livro Livro;

Livro* cria_livro();

void atribui_livros(Livro** livros, int tam);

void preco_medio(Livro **livros, int tam);

void libera_livro(Livro* l);