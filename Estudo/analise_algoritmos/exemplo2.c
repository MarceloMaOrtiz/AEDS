// Ordenação Usando Selection Sort.
// 1- Dado um array "V" de tamanho "n", procurar o menor valor (posição "me")
// e colocar na primeira posição.
// 2- Repetir processo para a segunda posição, depois terceira ...
// 3- Para com array ordenado

void selectionSort(int* V, int n) {
    int i, j, me, troca;
    for (i = 0; i < n-1; i++) {
        me = i;
        for (j = i+1; j < n; j++) {
            if (V[j] < V[me]){
                me = j;
            }
        }
        if (i != me) {
            troca = V[i];
            V[i] = V[me];
            v[me] = troca;
        }
    }
}

// Existe 2 comandos de laço
//      Laço Externo = n vezes
//      Laço Interno = (n-1, n-2, n-3, n-4, ..., 2, 1) -> Soma de PA = n * (1 + n) / 2

// Para alguns casos não é simples encontrar o resultado para determinado Laço.
// Possível solução:
//      1- Estimar um "limite superior"
//          - A ideia é alterar o algoritmo para algo "menos eficiente" do que temos
//          - Dessa forma saberemos que o algoritmo original é no máximo tão ruim, ou
//              talvez melhor, que o novo algoritmo
// Alterar o laço interno para diminuir a eficiência do "selection sort", por um laço
// que seja executado sempre "n vezes"
//      Isso simplifica a análise do custo de algoritmo e também piora o seus desempenho
// Com isso a f(n) = n² -> No pior caso o custo do algoritmo é O(n²)