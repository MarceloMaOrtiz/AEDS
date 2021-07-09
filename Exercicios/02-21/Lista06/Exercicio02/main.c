// Considero que um estacionamento da Rua Direita, em Ouro Preto, é composto por uma única alameda que
// guarda até dez carros. Existe apenas uma entrada/saída no estacionamento, e esta extremidade da alameda dá
// acesso justamente à Rua Direita. Se chegar um cliente para retirar um carro que não seja o mais próximo da
// saída, todos os carros bloqueando seu caminho sairão do estacionamento. O carro do cliente será manobrado
// para fora do estacionamento, e os outros carros voltarão a ocupar a mesma sequência inicial.
// Escreva um programa que processe um grupo de linhas de entrada. Cada linha de entrada contém um ‘E’, de
// entrada, ou um ‘S’ de saída, e o número da placa do carro. Presume-se que os carros cheguem e partam na
// mesma ordem que entraram no estacionamento. O programa deve imprimir uma mensagem sempre que um
// carro chegar ou sair. Quando um carro chegar, a mensagem deve especificar se existe ou não vaga para o carro
// no estacionamento. Se não houver vaga, o carro partirá sem entrar no estacionamento. Quando um carro sair
// do estacionamento, a mensagem deverá incluir o número de vezes em que o carro foi manobrado para fora do
// estacionamento para permitir que os outros carros saíssem.

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "Pilha.h"

int main(){
    struct entrada entradas[30];
    int x;
    struct carro c[15];
    strcpy(c[0].placa, "RIO5B79");
    c[0].manobras = 0;
    strcpy(c[1].placa, "RIO3J21");
    c[1].manobras = 0;
    strcpy(c[2].placa, "ESP4219");
    c[2].manobras = 0;
    strcpy(c[3].placa, "ESP3C14");
    c[3].manobras = 0;
    strcpy(c[4].placa, "SPM4215");
    c[4].manobras = 0;
    strcpy(c[5].placa, "RIO4A21");
    c[5].manobras = 0;
    strcpy(c[6].placa, "MTS2K19");
    c[6].manobras = 0;
    strcpy(c[7].placa, "YOP1C39");
    c[7].manobras = 0;
    strcpy(c[8].placa, "KEJ1E14");
    c[8].manobras = 0;
    strcpy(c[9].placa, "RIJ1J23");
    c[9].manobras = 0;
    strcpy(c[10].placa, "RYU5A39");
    c[10].manobras = 0;
    strcpy(c[11].placa, "RUO3E79");
    c[11].manobras = 0;
    strcpy(c[12].placa, "ESP9W79");
    c[12].manobras = 0;
    strcpy(c[13].placa, "ZVC6G26");
    c[13].manobras = 0;
    strcpy(c[14].placa, "LOK3E56");
    c[14].manobras = 0;

    entradas[0].car = c[0];
    entradas[0].sentido = 'E';
    entradas[1].car = c[1];
    entradas[1].sentido = 'E';
    entradas[2].car = c[2];
    entradas[2].sentido = 'E';
    entradas[3].car = c[3];
    entradas[3].sentido = 'E';
    entradas[4].car = c[4];
    entradas[4].sentido = 'E';
    entradas[5].car = c[5];
    entradas[5].sentido = 'E';
    entradas[6].car = c[3];
    entradas[6].sentido = 'S';
    entradas[7].car = c[2];
    entradas[7].sentido = 'S';
    entradas[8].car = c[6];
    entradas[8].sentido = 'E';
    entradas[9].car = c[7];
    entradas[9].sentido = 'E';
    entradas[10].car = c[1];
    entradas[10].sentido = 'S';
    entradas[11].car = c[0];
    entradas[11].sentido = 'S';
    entradas[12].car = c[8];
    entradas[12].sentido = 'E';
    entradas[13].car = c[9];
    entradas[13].sentido = 'E';
    entradas[14].car = c[10];
    entradas[14].sentido = 'E';
    entradas[15].car = c[11];
    entradas[15].sentido = 'E';
    entradas[16].car = c[12];
    entradas[16].sentido = 'E';
    entradas[17].car = c[13];
    entradas[17].sentido = 'E';
    entradas[18].car = c[14];
    entradas[18].sentido = 'E';
    entradas[19].car = c[4];
    entradas[19].sentido = 'S';
    entradas[20].car = c[7];
    entradas[20].sentido = 'S';
    entradas[21].car = c[12];
    entradas[21].sentido = 'S';
    entradas[22].car = c[10];
    entradas[22].sentido = 'S';
    entradas[23].car = c[9];
    entradas[23].sentido = 'S';
    entradas[24].car = c[11];
    entradas[24].sentido = 'S';

    x = processa_entradas(entradas, 25);
    return 0;
}