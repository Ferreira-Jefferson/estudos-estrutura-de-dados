## 22 Matrizes 3D

# Matriz 3D estática

- A matriz 3D possui como treceira dimensão, a profundidade, uma boa analogia é com o desenho de um quadrado, que seria a matriz normal, ou 2D, e um cubo, que é a matriz 3D.
- A dimensão de profundidade pode ser melhor entendida quando consideramos que cada nível de produndidade é uma **Fatia**, uma fatia de matriz 2D, a cada nova fatia, estamos adicionando uma nova matriz 2D à matriz 3D, ou seja, uma matriz 3D com dois níveis de profundidade, possui duas fatias, a primeira possui uma matriz 2D de tamanho N e a segunda também possui uma outra matriz 2D de tamanho N.
- imagine um vetor de inteiro `[1,2,3,4]`, ao invés de números a matriz 3D possui outras atrizes dentro de cada campo do vetor `m[2][2][1] = [ [[1],[2]], [[3],[4]] ]`.

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int nfatias = 2, nlinhas = 2, ncolunas = 3;
    int m[2][2][3] = {
        // fatia [0]
        {
            // linha [0]
            {1,2,3}, // colunas [0], [1] e [2]
            // linha [1]
            {10,20,30} // colunas [0], [1] e [2]
        },
        // fatia [1]
        {
            // linha [0]
            {100,200,300}, // colunas [0], [1] e [2]
            // linha [1]
            {1000,2000,3000} // colunas [0], [1] e [2]
        }
    };
    int contador = 0;

    printf("&m: %p | m: %p\n\n", &m, m);
    for(int k=0; k < nfatias; k++){
        printf("k[%d]: &m[%d]: %p | m[%d]: %p\n", k, k, &m[k], k, m[k]);

        for(int i=0; i < nlinhas; i++){
            printf("k[%d] i[%d]: &m[%d][%d]: %p | m[%d][%d]: %p\n",
            k, i, k, i, &m[k][i], k, i, m[k][i]);

            for(int j=0; j < ncolunas; j++){
                m[k][i][j] = contador++;
                printf("k[%d] i[%d] j[%d]: &m[%d][%d][%d]: %p | m[%d][%d][%d]: %d\n",
                k, i, j, k, i, j, &m[k][i][j], k, i, j, m[k][i][j]);
            }
            puts("");

        }

        puts("");
    }
  return 0;
}
```

- No for loop, assim como o uso de i indica linha, j coluna, o k é uma convensão de uso para a terceira dimensão da matriz, a produndidade.

# Matriz 3D dinâmicas

- Matrizes 3D dinâmicas são ponteiros de ponteiros, de ponteiros de ponteiros, voltando a analogia dos carteiros, seria o carteiro, do carteiro, do carteiro dos jogadores.
- As matrizes sempre seguem o mesmo princípio, a cada loop é alocado um espaço na memória com o tamanho do ponto em que se está, se estou no nível i, de linhas, aloco o espaço necessário para as linhas e assim por diante, sempre lembrando que a cada nível de for loop, cai um ponteiro (\*), por fim, no último nível do for loop, não se aloca espaço na memória, pois ele é o nível da coluna e a coluna recebe o valor de tipo primitivo e não ponteiros.

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

    printf("&m: %p | m: %p\n\n", &m, m);
    for(int k=0; k < nfatias; k++){
        printf("k[%d]: &m[%d]: %p | m[%d]: %p\n", k, k, &m[k], k, m[k]);
        for(int i=0; i < nlinhas; i++){
            printf("k[%d] i[%d]: &m[%d][%d]: %p | m[%d][%d]: %p\n",
            k, i, k, i, &m[k][i], k, i, m[k][i]);
            for(int j=0; j < ncolunas; j++){
                printf("k[%d] i[%d] j[%d]: &m[%d][%d][%d]: %p | m[%d][%d][%d]: %d\n",
                k, i, j, k, i, j, &m[k][i][j], k, i, j, m[k][i][j]);
            }
            puts("");
        }
        puts("");
    }

    for(int k=0; k < nfatias; k++){
        for(int i=0; i < nlinhas; i++){
            free(m[k][i]);
        }
        free(m[k]);
    }
    free(m);
    m = NULL;
  return 0;
}
```
