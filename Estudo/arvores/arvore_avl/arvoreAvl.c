#include "stdio.h"
#include "stdlib.h"
#include "Arvore.h"

#include <execinfo.h>
#include <signal.h>
#include <unistd.h>


void handler(int sig) {
  void *array[10];
  size_t size;

  // get void*'s for all entries on the stack
  size = backtrace(array, 10);

  // print out all the frames to stderr
  fprintf(stderr, "Error: signal %d:\n", sig);
  backtrace_symbols_fd(array, size, STDERR_FILENO);
  exit(1);
}

int main(int argc, char **argv) {
    signal(SIGSEGV, handler);   // install our handler
    ArvAVL *arv;
    arv = cria_ArvAVL();

    insere_ArvAVL(arv, 20);
    insere_ArvAVL(arv, 30);
    insere_ArvAVL(arv, 25);
    insere_ArvAVL(arv, 84);
    insere_ArvAVL(arv, 56);
    insere_ArvAVL(arv, 12);
    insere_ArvAVL(arv, 1);
    insere_ArvAVL(arv, 69);
    insere_ArvAVL(arv, 78);

    consulta_ArvAVL(arv, 69);
    consulta_ArvAVL(arv, 81);

    

    remove_ArvAVL(arv, 25);

    remove_ArvAVL(arv, 20);
    remove_ArvAVL(arv, 1);
    remove_ArvAVL(arv, 30);
    remove_ArvAVL(arv, 78);
    remove_ArvAVL(arv, 56);
    remove_ArvAVL(arv, 12);
    remove_ArvAVL(arv, 84);
    remove_ArvAVL(arv, 69);


    libera_ArvAVL(arv);

    return 0;
}