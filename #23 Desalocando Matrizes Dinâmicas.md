## 23 Desalocando Matrizes Dinâmicas

- A maneira correta de se desalocar uma matriz é sempre de entro para fora, ou seja, do último vetor alocado até o primeiro
- Não é necessário apontar os ponteiros internos para NULL, pois iremos perder a referência deles, o único que apontamos para NULL é o da variável que raiz que criamos inicialmente

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int nfatias = 2, nlinhas = 2, ncolunas = 3;
    int ***m = NULL;
    int contador = 0;

    m = calloc(nfatias, sizeof(int**));
    for(int k=0; k < nfatias; k++){
        // alocar fatias
        m[k] = calloc(nlinhas, sizeof(int*));
        for(int i=0; i < nlinhas; i++){
            // alocar linhas
             m[k][i] = calloc(ncolunas, sizeof(int));
            for(int j=0; j < ncolunas; j++){
                // atribuir um valor a cada coluna
                m[k][i][j] = contador++;
            }
        }
    }

  for(int k=0; k < nfatias; k++){
      for(int i=0; i < nlinhas; i++){
          // desalocar linhas
          free(m[k][i]);
      }
      // desalocar fatias
      free(m[k]);
  }
  // desalocar ponteiro raiz
  free(m);
  m = NULL;
  return 0;
}
```

- Não foi dado nenhum exemplo no vídeo, mas ao arrumar o exercício 21 me dei conta que quando fazemos a desalocação por meio de uma função, devemos subir um nível de ponteiro, para que possamos trabalhar diretamente com o ponteiro que desejamos desalocar e neste.
  - Fiquei quebrando a cabeça para entender o porque de `int** aux=*mt;` funcionar, mas usar o *mt diretamente não ia.
    Depois que entendi que o o *mt funciona no free, e que o erro de segmentation fault estava dando dentro do loop.
    Depois de muito teste ví que (*m)[i] funcionava e o problema era a precedência..quando uso *mt[i] ele faz a lógica de ponteiros entre mt + i e depois tentava pegar o conteúdo do endereço resultante, sendo que o mt é uma variável local, que só existe na função, para que dê certo é necessário, antes da lógica de ponteiro, pegar o endereço que veio pelo parâmetro e só então aplicar a lógica de ponteiros.

```c
#include <stdio.h>
#include <stdlib.h>

void free_matriz_aux(int** *mt, int nrows) {
    int** aux = *mt;
    for(int i=0; i < nrows; i++){
        free(aux[i]);
    }
    free(aux);
    *mt = NULL;
}

void free_matriz(int ** *mt, int nrows) {
    for(int i=0; i < nrows; i++){
        free((*mt)[i]);
    }
    free(*mt);
    *mt = NULL;
}

int main() {
  int **m = NULL;
  int nrows = 2;
  int ncols = 3;

  m = calloc(nrows, sizeof(int*));
  printf("&m: %p | m: %p \n\n", &m, m);

  for(int i=0; i < nrows; i++) {
      m[i] = calloc(ncols, sizeof(int));
  }

  free_matriz(&m, nrows);

  return 0;
}
```
