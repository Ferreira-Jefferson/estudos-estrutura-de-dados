## 26 Row e Column Major Order na Prática

- O código abaixo demonstra escrita de um dado utilizando as diferentes abordagens de layout de dados

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int** create_matrix(int nrows, int ncols){
  int **m = calloc(nrows, sizeof(int*));
  for(int i=0; i < nrows; i++)
    m[i] = calloc(ncols, sizeof(int));
  return m;
}

void row_major_order(int nrows, int ncols){
  int **m = create_matrix(nrows, ncols);

  for(int i=0; i < nrows; i++)
    for(int j=0; j < ncols; j++)
      m[i][j] = (i+j) % 2;
}

void column_major_order(int nrows, int ncols){
  int **m = create_matrix(nrows, ncols);

  for(int j=0; j < ncols; j++)
    for(int i=0; i < nrows; i++)
      m[i][j] = (i+j) % 2;
}

int main(){
  clock_t start = clock();
    row_major_order(10000, 10000);
  clock_t end = clock();

  double cpu_time_used = ((double) end - start) / CLOCKS_PER_SEC;
  printf("Tempo de execução [ROW-MAJOR]: %f \n", cpu_time_used);

  start = clock();
    column_major_order(10000, 10000);
  end = clock();

  cpu_time_used = ((double) end - start) / CLOCKS_PER_SEC;
  printf("Tempo de execução [COLUMN-MAJOR]: %f \n", cpu_time_used);

  return 0;
}
// Tempo de execução [ROW-MAJOR]: 0.389149
// Tempo de execução [COLUMN-MAJOR]: 0.789425
```

- Como pode ser observado neste pequeno exemplo o mesmo código, mudando apenas a ordem de leitura, resulta no dobro do tempo de execução, logo fica claro que o layout de dados row-major order é muito mais eficiente e isso se dá por ele processar os dados de maneira similar ao cache do processador, conforme explicado no estudo do vídeo [#25 Row e Column Major Order](./%2325%20Row%20e%20Column%20Major%20Order.md)

# Alocação dinâmica: vetor como matriz

- O que é?: ao invés de criar uma matriz tradicional, criar um vetor e trababalhar com ele como matriz
- Por quê?: A cada alocação que uma matriz exige, vão surgindo buracos entre os dados, o que faz com que uma matriz não possua todos seus dados sequênciais.
- Qual a utilizade?: Em alguns casos é importante que todos os dados estejam em sequência, seja para gravar um buffer ou para a transferência de dados entre linguagens, a matriz não permite isso, já um vetor sim.
- Como isso é feito?:
  - Supondo que estejamos trabalhando com uma matriz 2D, multiplicamos a quantidade de linhas pela quantidade de colunas e com isso obtemos o tamanho que o vetor deve ter.
    - `nelements = nrows * ncols`
  - Por ser um vetor, não é possível acessar utilizando v[i][j], neste caso devemos descobir o índice correto fazendo o seguinte cálculo
    - `index_element = (i * ncols) + j`
    - Sendo o **i** o índice da linha e **j** o índice da coluna e **index_element** é o índice que usaremos no vetor `v[index_element]`
- Existem desvantagens?: Sim, existe um custo a mais por conta do cálculo para descobrir o índice do elemento, mas normalmente é bem baixo este custo, é necessário analisar cada cenário para ver se há a necessidade de aplicar esta abordagem.

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int** create_matrix(int nrows, int ncols){
  int **m = calloc(nrows, sizeof(int*));
  for(int i=0; i < nrows; i++)
    m[i] = calloc(ncols, sizeof(int));
  return m;
}

void row_major_order(int nrows, int ncols){
  int **m = create_matrix(nrows, ncols);

  for(int i=0; i < nrows; i++)
    for(int j=0; j < ncols; j++)
      m[i][j] = (i+j) % 2;
}

void vetor_as_matrix(int nrows, int ncols){
  int nelems = nrows * ncols;
  int *v = calloc(nelems, sizeof(int));

  for(int i=0; i < nrows; i++){
    for(int j=0; j < ncols; j++){
      int index_elem = (i * ncols) + j;
      v[index_elem] = (i+j) % 2;
    }
  }
}

int main(){
  clock_t start = clock();
    row_major_order(10000, 10000);
  clock_t end = clock();

  double cpu_time_used = ((double) end - start) / CLOCKS_PER_SEC;
  printf("Tempo de execução [ACESSO VIA MATRIZ]: %f \n", cpu_time_used);

  start = clock();
    vetor_as_matrix(10000, 10000);
  end = clock();

  cpu_time_used = ((double) end - start) / CLOCKS_PER_SEC;
  printf("Tempo de execução [VETOR COMO MATRIX]: %f \n", cpu_time_used);

  return 0;
}
// Tempo de execução [ACESSO VIA MATRIZ]: 0.475508
// Tempo de execução [VETOR COMO MATRIX]: 0.481230
```

- Como pode ser visto, o custo é bem baixo, comparado a vantagem no caso da necessidade de ter que trabalhar com dados sequênciais

# Matriz 3D como vetor

- Esse tópico não é abordado no vídeo, mas um aluno fez essa pergunta pelos comentários e o professor repondeu, segue a pergunta e resposta na íntegra

  - Professor, como ficaria a operação pra alocar uma matriz 3D em formato vetorial?
  - Oi, Matteus.
    Seria um vetor do mesmo jeito. O que mudaria é o cômputo dos índices da matriz 3D, que deverá levar em conta a profundidade da matriz.

    Suponha que as dimensões de uma matriz 3D sejam dadas pelas variáveis: nz (profundidade), ny (num. linhas), nx (num. colunas).

    Suponha que essa matriz é representada como um vetor v.

    Para acessar o elemento [z][y][x] da matriz, precisamos achar qual é o índice do vetor v que representa essa coordenada.
    Para isso, basta aplicarmos a equação abaixo:
    `i = x + (y \* nx) + (z \* nx \* ny)`

    Por outro, dado um índice [i] do vetor, se você quiser achar as coordenadas correspondentes da matriz 3D:
    `x = (i % (ny \* nx)) % nx`
    `y = (i % (ny \* nx)) / nx`
    `z = i / (ny \* nx)`

    onde % significa o resto da divisão.
