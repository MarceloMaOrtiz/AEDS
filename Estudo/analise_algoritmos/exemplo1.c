// Algoritmo procura o maior valor presente em um array "A" contendo "n" elementos 
// e o armazena na variável "M"

// 1-  int M = A[0];
// 2-  for (int i = 0; i < n; i++){
// 3-      if (A[i] >= M){
// 4-          M = A[i];
// 5-      }
// 6-  }

// 1- 1 Instrução
// 2- 2 Instruções (Inicialização -> Atribuição e Comparação) + 2*n instruções 
// (Repetições -> Comparação e Incremento)
// 3- 1*n Instruções (Comparação)
// 4- 1*(casos) (casos depende do resultado da comparação -> Pior caso = array A
// está em ordem crescente -> casos = n; Melhor Caso = Maior elemento está na primeira
// posição -> casos = 0)

// Análise de Pior e Melhor caso - Função de complexidade de tempo
// Pior caso = f(n) = 4n + 3
// Melhor caso = f(n) = 3n + 3

// Comportamento Assintótico - Manter somente os termos que crescem mais rápido
// Pior caso = 4n + 3
// 1º termo = 4n
// 2º termo = 3 -> Não se altera com o aumento de n
// Função pode ser reduzida para
// Pior caso = f(n) = 4n
// Também deve-se descartas os a constante que acompanha n. Isso faz sentido ao pensar
// em diferentes linguagens de programação, pois para uma mesma operação a quantidade
// de instruções podem variar consideravelmente
// Função pode ser reduzida para
// Pior caso = f(n) = n