Hash
 - Conceitos Básicos
     - Busca
         - Funcionam segundo um mesmo princípio. Procurar a informação desejada
             com base na comparação de suas chaves
         - Problema
             - Algoritmos eficientes necessitam que os elementos estejam ordenados
             - Custo de ordenação no melhor caso: O(n*log(n))
             - Custo da busca: O(log(n))
     - Busca ideal
         - Acesso direto ao elemento procurado, sem nenhuma etapa de comparação
             de chaves
              - Custo: O(1)
     - Arrays
         - Permite acessar uma determinada posição com custo: O(1)
         - Problema
             - Não possui nenhum mecanismo que permita calcular a posição onde
                 uma informação está armazenada, de modo que a operação de busca
                 em um array seja O(1)
     - Solução
         - Tabela Hash - Tabela de Indexação - Espalhamento
             - Generalização da ideia de array
             - Utiliza uma função para espalhar os elementos que queremos armazenar
                 na tabela
                 - O espalhamento faz com que os elementos fiquem dispersos de forma
                     não ordenada dentro do array que define a tabela
         - Função de Hashing
             - Função que espalha os elementos na tabela
         - Espalhar os elementos melhora a busca
             - Uma tabela Hash permite a associação de valores a chaves
                 - Chave: Parte da informação que compõe o elemento a ser inserido
                     ou buscado na tabela
                 - Valor: É a posição (índice) onde o elemento se encontra no array
                     que define a tabela
             - Assim, a partir de uma chave podemos acessar de forma rápida uma
             determinada posição do array
             - Na media, essa operação tem custo: O(1) 
     - Vantagens
         - Alta eficiência na operação de busca
         - Tempo de busca é praticamente independente do número de chaves armazenadas
             na tabela
         - Implementação simples
     - Desvantagem
         - Alto custo para recuperar os elementos da tabela ordenados pela chave
             - Nesse caso, é preciso ordenar a tabela
         - Pior caso: O(n)
             - n é o tabalho da tabela
                 - Alto índice de colisões
     - Aplicações
         - Busca de elementos em base de dados
         - Criptografia
             - MD5 e Família SHA (Secure Hasg Algorithm)
         - Implementação da tabela de símbolos dos compiladores
         - Armazenamento de senhar com segurança
             - Senha não é armazenada no servidor, mas sim o resultado da função hash
         - Verificação de integridade de dados e autenticação de mensagens
     - Colisões
         - Dois elementos tentam ocupar o mesmo lugar na tabela
 - Implementação
     - Utiliza uma estrutura similar a uma Lista Sequencial Estática
     - Utiliza uma array para armazenar os elemementos
     - Desvantagem
         - Necessário definir o tamanho do array previamente
             - Limita o número de elementos que podemos armazenar
     - Importante
         - Por questões de desempenho, a Tabela Hash armazenará apenas endereço
             para a estrutura que contém os dados do Aluno, e não os dados em si.
             - Objetivo: Evitar gasto excessivo de memória
         - A medida que os elementos são inseridos na tabela, nós realizamos
             a alocação daquele único elemento
         - Ao escolher o tamanho da tabela hash o ideal é escolher um número primo
             e evitar valores que sejam uma potência de dois
             - Número primo reduz a probabilidade de colisões, mesmo que a função
                 de hash não seja muito eficaz
             - Uma potência de dois melhroa a velocidade, mas pode aumentar os problemas
                 de colisão se estivermos utilizando uma função de hashing mais simples
     - Função de Hashing
         - Permite calcular a posição (índice) a partir de uma escolhida a partir dos
             dados
         - Extramamente importante para o bom desempenho da tabela
             - Responsável por distribuir as informações de forma equilibrada
                 pela tabela hash
         - Inserção e Busca
             - Necessário calcular a posição dos dados dentro da tabela
         - Necessário satisfazer as seguintes condições
             - Ser simples e barata de se calcular
             - Garantir que valores diferentes produzam posições diferentes
             - Gerar uma distribuição equilibrada dos dados na tabela
                 - Cada posição da tabela tem a mesma chance de receber uma chave
                     - Máximo espalhamento
         - Importante
             - A implementação da tabela depende do conhecimento prévio da natureza
                 e domínio da chave a ser utilizada
         - Métodos
             - Método da Divisão - Método da Congruência Linear
                 - Consiste em calcular o resta da divisao do valor inteiro que
                     representa o elemento pelo tamanho da tabela, TABLE_SIZE
                 - Função simples e direta
                 - Observação
                     - Operação "E bit-a-bit" com o valor 0x7FFFFFFF elimina o bit
                         de sinal do valor da chave
                         - Evita o risco de ocorrer overflow e obtermos um
                             número negativo
             - Método da Multiplicação - Método da Congruência Linear Multiplicativo
                 - Usa um valor A, onde 0 < A < 1, para multiplicar o valor da chave que
                     representa o elemento. Em seguida, a parte fracionária resultante
                     é multiplicada pelo tamanho da tabela para calcular a posição do
                     elemento
             - Método da Dobra
                 - Utiliza um esquema de dobrar e somar os dígitos do valor para calcular
                     a sua posição
                 - Considera o valor inteiro, que representa o elemento como uma sequência
                     de dígitos escritos num pedaço de papel
                     - Enquanto eses valor for maior que o tamanho da tabela, o papel é
                         dobrado e os dígitos sobrepostos são somados, desconsiderando-se
                         as dezenas
                 - Exemplo
                     - 52936410
                     - 6410 + 3925
                     - 9335
                     - 35 + 39
                     - 64
                 - Mais comum utilizar valores binários
                     - Utiliza a operação Ou Exclusivo
                     - Dobra é realizada de k em k bits
                         - Resultando em um valor de posição entre 0 e 2^k+1
                 - Exemplo
                     - Posição do valor 71 -> 0001000111 em binário
                     - k = 5
                     - 00010 ^ 00111
                     - 00101
                     - 5
             - Tratando uma String como chave
                 - Calcular um valor numérico a partir dos valores ASCII
                     - Considerar, também, a posição da letra
                 - Cuidado
                     - Não deve apenas somar os caracteres
                         - Palavras com letras iguais em posições diferentes irão
                             produzir o mesmo valor
         - Inserção e Busca Sem Colisão
             - Para entender primeiro o simples
             - Inserção
                 - Calcular a posição da chave no array
                 - Alocar espaço para os dados
                 - Armazenar os dados na posição calculada
             - Busca
                 - Calcular a posição da chave no array
                 - Verificar se há dados na posição
                 - Retornar os dados
         - Problemas
             - Função de Hashing está sujeita ao problema de gerar posições iguais
                 para chaves diferentes
                 - Por se tratar de uma função determinística, ela pode ser manipulada
                     de forma indesejada
             - Conhecendo a função de Hashing é possível escolher as chaves de entrada
                 de modo que todas colidam
                 - Diminuindo o desempenho da tabela de busca para O(n)
                     - Poderia ser um ataque a um sistema que utiliza tabela hash
             - Solução
                 - Hashing Universal
                     - Estratégia que busca minimizar esse problema de colisões
                         - Devemos escolher aleatóriamente, em tempo de execução, a
                             função de hashing que será utilizada
                             - Construindo um conjunto (família) de funções hashing
                     - Exemplo de família de funções
                         - Escolher um número primo P de tal modo que o valor de
                             qualquer chave K a ser inserida na tabela seja menor do
                             que P e >= 0
                             - 0 <= K < P
                         - P é maior do que o tamanho da tabela, TABLE_SIZE
                         - Escolher aleatóriamente dois números
                             - 0 < A <= P
                             - 0 <= B <= P
                         - Função de Hashing Universal
                             h(k)_{a, b} = ((a*k + b) % p) % TABLE_SIZE
                 - Hashing Perfeito e Imperfeito
                     - Dependendo do tamanho da tabela é possível classificar a função
                         de hashing como Imperfeita ou Perfeita
                     - Hashing Perfeito
                         - Garante que não há colisão das chaves dentro da tabela
                             - Chaves diferentes sempre irão produzir posições diferentes
                         - Pior caso (Busca e Inserção): O(1)
                         - Utilizado onde a colisão não é tolerável
                             - Trata-se de um tipo de aplicação muito específico
                         - É de conhecimento o conteúdo armazenado na tabela
                     - Hashing Imperfeito
                         - Para chaves diferentes, a saída da função é mesma posição
                             na tabela -> Colisões
                         - A colisão não tabela não é algo exatamente ruim, é apenas algo
                             indesejável
                             - Diminui o desempenho do sistema
                         - Muitas tabelas hash utilizam outra estrutura de dados para lidar
                             com o problema da colisão
         - Colisão
             - Idealmente, uma função de hashing irá sempre fornecer posições diferentes
                 para cada uma das chaves inseridas
                 - Hashing Perfeito
             - Independente da função de hashing utilizada, a função vai retornar a mesma
                 posição para duas chaves diferentes
             - A criação de uma tabela hash consiste então de duas coisas
                 - Uma função de hashing
                 - Uma abordagem para tratamento de colisões
             - Motivos que geram colisões
                 - Temos mais chaves para armazenar do que o tamanho da tabela suporta
             - Tratamento de Colisões
                 - Escolha adequada da função de hashing e do tamanho da tabela podem
                     minimizar as colisões
                     - A ideia é produzir um espalhamento uniforme das chaves
                 - Não se pode garantir que as funções de hashing possuam um bom
                     potencial de espalhamento, por que as colisões também são uniformemente
                     distribuidas
                 - São teoricamente, inevitáveis
                 - Algumas formas de tratar colisões
                     - Endereçamento Aberto - Open Addressing - Rehash
                         - No caso de uma colisão
                             - Percorre a tabela has em busca de uma posição livre
                         - Evitar o uso de listas encadeadas
                         - Vantagens
                             - Maior número de posições para a mesma quantidade de
                                 memória usada no Encadeamento Separado
                                 - Diminui o número de colisões
                             - A busca é realizada dentro da própria tabela
                                 - Diminui o número de colisões
                             - Ao invés de acessarmos ponteiros, calculamos a sequencia
                                 de posições a serem armazenadas
                         - Desvantagens
                             - Maior esforço de processamento no cálculo das posições
                             - Custo de inserção se torna O(n) quando todos os elementos
                                 inseridos colidem
                         - Implementação
                             - Três abordagens
                                 - Sondagem Linear - Tentatica Linear - rehash Linear
                                     - Tenta espalhar os elementos de forma sequencial
                                         a partir da posição calculada utilizando a
                                         função hashing
                                     - Funcionamento
                                         - Primeiro elemento é colocado na posição obtida
                                             pela função hashing: pos
                                         - Segundo elemento é colocado na posição pos+1
                                         - Terceiro elemento é colocado na posição pos+2
                                     - Problema
                                         - Agrupamento Primário
                                             - Presença de longas sequências de posições
                                                 ocupadas
                                             - A medida que a tabela hash fica cheia, o
                                                 tempo para incluir ou buscar aumenta
                                             - Quanto maior o agrupamento primário, maior
                                                 a probabilidade de aumentá-lo, diminuindo
                                                 o desempenho
                                 - Sondagem Quadrática - Tentativa Quadrática - rehash quadrático
                                     - Tenta espalhar os elementos utilizando um equação do
                                         2º grau
                                         - pos + (c1 * i) + (c2 * i²)
                                             - pos -> posição obtida pela tabela hash
                                             - i -> tentativa atual
                                             - c1, c2 -> coeficientes da equação
                                     - Funcionamento
                                         - Primeiro elemento é colocado na pos
                                         - Segundo elemento (colisão) é colocado na pos
                                             gerada a partir da equação de 2º grau
                                     - Problema
                                         - Resolve o problema do agrupamento primário
                                         - Gera o Agrupamento Secundário
                                             - Ocorre pois as chaves produzem as mesmas
                                                 posições na sondagem quadrática
                                     - A degradação na tabela é menor que a produziada
                                         no agrupamento primário
                                 - Duplo Hash - Espalahamento Duplo
                                     - Tenta espalhar os elementos utilizando duas
                                         funções de hashing
                                         - H1 + i * H2
                                             - H1 -> Utilizada para calcular a posição
                                                 inicial
                                             - H2 -> Utilizada para calcular os deslocamentos
                                                 em relação a posição inicial
                                     - Funcionamento
                                         - Primeiro elemento é colocado na posição obtida
                                             por H1
                                         - Segunda elemento (colisão) é colocado na posição
                                             obtida a partir da função acima
                                     - Diminui a ocorrência de agrupamentos
                                         - Metodo bom para tratar colisões em Endereçamento
                                             aberto
                                     - Cuidado
                                         - Necessário duas funções hashings distintas
                                         - A segunda função não pode resultar em um valor
                                             igual a 0, pois não haveria deslocamento
                                             - Loop Infinito
                                     - Dica
                                         - Usar um tamanho de tabela um pouco menor na segunda
                                             função
                                         - Somar +1 ao valor da posição obtida na segunda função
                                             - Evitando assim o 0
                     - Endereçamento Separado - Separate Chaining
                         - Não procura por posições vagas dentro da tabela hash
                         - Armazena dentro de cada posição do array o início de uma
                             lista dinâmicamente encadeada
                         - Vantagens
                             - Pior caso da inserção é O(1) se a lista não for ordenada
                         - Desvantagens
                             - A busca leva um tempo proporcional ao número de elementos
                                 dentro da lista procurando aquele elemento
                             - Maior consumo de memória
                                 - É preciso armazenar os ponteiros da lista
         - Inserção e Busca Com Colisão
             - Inserção
                 - Calcular a posição da chave no array
                 - Recalcular a posição enquanto houver colisão
                     - Limitar o número de tentativas
                 - Alocar espaço para os dados
                 - Armazenar os dados na posição calculada
             - Busca
                 - Calcular a posição da chave no array
                 - Verificar se há dados na posição e se os dados combinam com a chave
                 - Recalcular a posição enquanto os dados forem diferentes da chave
                 - Retornar os dados