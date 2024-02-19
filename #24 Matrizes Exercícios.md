## 24 Matrizes Exercícios

Ex 1:

- Codifique uma função para:
  - Alocar uma matriz dinâmica
  - Imprimir os elementos de uma matriz e seus endereços de memória
  - Adicionar um escalar a uma matriz (in place)
  - Desalocar uma matriz, atribuindo valor NULL ao ponteiro

```c
#include <stdio.h>
#include <stdlib.h>

int** alocar(int linhas, int colunas) {
  int **m = (int**) calloc(linhas, sizeof(int*));
  for(int i=0; i < linhas; i++) {
    m[i] = calloc(colunas, sizeof(int));
  }
  return m;
}

void print_matriz(const int *m[], int linhas, int colunas) {
  for(int i=0; i < linhas; i++)
    for(int j=0; j < colunas; j++)
      printf("&m[%d][%d]: %p | m[%d][%d]: %d \n", i, j, &m[i][j], i, j, m[i][j]);
    puts("");
}

void adicionar_valores(int *m[], int linhas, int colunas) {
  int count = 0;
  for(int i=0; i < linhas; i++)
    for(int j=0; j < colunas; j++)
      m[i][j] = count++;
}

void soma_scalar(int *m[], int linhas, int colunas, int scalar) {
  for(int i=0; i < linhas; i++)
    for(int j=0; j < colunas; j++)
      m[i][j] += scalar;
}

void desalocar(int** *m, int linhas) {
  for(int i=0; i < linhas; i++) {
    free((*m)[i]);
  }
  free(*m);
  *m = NULL;
}

int main() {
  int linhas = 2, colunas = 3, scalar = 10;
  int **m = alocar(linhas, colunas);
  adicionar_valores(m, linhas, colunas);
  soma_scalar(m, linhas, colunas, scalar);
  print_matriz((const int**) m, linhas, colunas);
  desalocar(&m, linhas);
  printf("m==NULL ? %d", m==NULL);

  return 0;
}
```
