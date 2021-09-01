Ordenação Externa
 - Consiste em Ordenar conjuntos de dados maiores do que a memória
     interna disponível
 - Ordenação deve ser feita em arquivos
 - Os algoritmos devem minimizar o número de acessos às unidades de
     memória externa
 - Diferença em relação a Ordenação Interna
     - Custo de acesso a memória secundária é muito maior
     - Transferência de dados entre a memória interna e externa
     - Acesso sequencial aos dados (Acesso direto é muito caro)
 - MergeSort Externo
     - Método mais importante de ordenação externa
     - Intercalação
         - Combina dois ou mais blocos ordenados em um único bloco,
             maior, ordenado
     - Funcionamento
         - RAM comporta "N" registros de Dados
         - Carregar parte do arquivo na RAM
         - Ordenar os dados na RAM com um algoritmo in-place (ex. QuickSort)
         - Salvar os dados ordenados em um arquivo separado
         - Repetir os passos anteriores até terminar o arquivo original
             - Ao final, temos "K" arquivos ordenados
         - "Multi-Way Merging"
             - Criar "K+1" buffers de tamanho "N / (K + 1)"
                 - 1 de Saída
                 - K de Entrada
             - Carregar parte dos arquivos ordenados nos Buffers de Entrada,
                 intercalar no Buffer de Saída
             - Buffer de Entrada "Vazio" -> Carregar mais Dados
             - Buffer de Saída "Cheio" -> Salvar Dados