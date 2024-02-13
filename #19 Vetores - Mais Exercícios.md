## 19 Vetores - Mais Exercícios

Ex 1: Simule a memória, usando heap e stack para o seguinte trecho de código

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
  int i, n = 5;
  int *v;
  v = (int*) malloc(n * sizeof(int));
  for(i=0; i < n; i++) {
    v[i] = i;
  }
  free(v);
  v = NULL;
  return 0;
}
```

- Teste de mesa

| Linha | Memóra      | Variável | Valor |
| ----- | ----------- | -------- | ----- |
|       | MEMÓRIA     | STACK    |       |
| 1     | 0x0         | i        | ####  |
| 1     | 0x4         | n        | 5     |
| 2     | 0x8         | \*v      | ####  |
| 3     | 0x8         | \*v      | 0h0   |
| 4     | 0x0         | i        | 0     |
| 5     | \*(0x8 + 0) | v[0]     | 0     |
| 4     | 0x0         | i        | 1     |
| 5     | \*(0x8 + 1) | v[1]     | 1     |
| 4     | 0x0         | i        | 2     |
| 5     | \*(0x8 + 2) | v[2]     | 2     |
| 4     | 0x0         | i        | 3     |
| 5     | \*(0x8 + 3) | v[3]     | 3     |
| 4     | 0x0         | i        | 4     |
| 5     | \*(0x8 + 4) | v[4]     | 4     |
| 4     | 0x0         | i        | 5     |
| 6     | 0x8         | \*v      | NULL  |
|       |             |          |       |
|       | MEMÓRIA     | HEAP     |       |
| 3     | 0h0         | v[0]     | ####  |
| 3     | 0h4         | v[1]     | ####  |
| 3     | 0h8         | v[3]     | ####  |
| 3     | 0h12        | v[4]     | ####  |
| 3     | 0h16        | v[5]     | ####  |
| 5     | 0h0         | v[0]     | 0     |
| 5     | 0h4         | v[1]     | 1     |
| 5     | 0h8         | v[2]     | 2     |
| 5     | 0h12        | v[3]     | 3     |
| 5     | 0h16        | v[4]     | 4     |
| 6     | 0h0         |          | 4     |

Ex 2: Simule a memória, usando heap e stack para o seguinte trecho de código

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
  int v1[5] = {0,1,2,3,4};
  int *v2, *p;
  int i;

  p=v1;
  p[3] = p[4] = 10;

  v2 = malloc(5*sizeof(int));

  for(i=0; i < 5; i++) {
    v2[i] = v1[i];
  }
  free(v2);
  v2 = NULL;
  return 0;
}
```

- Teste de mesa

| Linha | Memóra     | Variável   | Valor   |
| ----- | ---------- | ---------- | ------- |
|       | MEMÓRIA    | STACK      |         |
| 1     | 0x0        | v1         | 0x0     |
| 1     | 0x0        | v1[0]      | 0       |
| 1     | 0x4        | v1[1]      | 1       |
| 1     | 0x8        | v1[2]      | 2       |
| 1     | 0x12       | v1[3]      | 3       |
| 1     | 0x16       | v1[4]      | 4       |
| 2     | 0x20       | \*v2       | ####    |
| 2     | 0x28       | \*p        | ####    |
| 3     | 0x36       | i          | ####    |
| 4     | 0x28       | \*p        | 0x0     |
| 5     | 0x16       | \*(p+4)    | 10      |
| 5     | 0x12       | \*(p+3)    | \*(p+4) |
| 6     | 0x20       | \*v2       | 0h0     |
| 7     | 0x36       | i          | 0       |
| 8     | \*(v2 + 0) | \*(v1 + 0) | 0       |
| 7     | 0x36       | i          | 1       |
| 8     | \*(v2 + 1) | \*(v1 + 1) | 1       |
| 7     | 0x36       | i          | 2       |
| 8     | \*(v2 + 2) | \*(v1 + 2) | 2       |
| 7     | 0x36       | i          | 3       |
| 8     | \*(v2 + 3) | \*(v1 + 3) | 10      |
| 7     | 0x36       | i          | 4       |
| 8     | \*(v2 + 4) | \*(v1 + 4) | 10      |
| 7     | 0x36       | i          | 5       |
| 10    | 0x20       | \*v2       | NULL    |
|       |            |            |         |
|       |            |            |         |
|       | MEMÓRIA    | HEAP       |         |
| 6     | 0h0        | v2[0]      | ####    |
| 6     | 0h4        | v2[2]      | ####    |
| 6     | 0h8        | v2[3]      | ####    |
| 6     | 0h12       | v2[4]      | ####    |
| 6     | 0h016      | v2[5]      | ####    |
| 8     | 0h0        | v[0]       | 0       |
| 8     | 0h4        | v[1]       | 1       |
| 8     | 0h8        | v[2]       | 2       |
| 8     | 0h12       | v[3]       | 10      |
| 8     | 0h16       | v[4]       | 10      |
| 9     | 0h0        |            | 0       |

Ex 3: Qual o problema com este trecho de código?

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
  int v1[5] = {0,1,2,3,4};
  int *v2;

  v2 = malloc(5*sizeof(int));
  v2 = v1;

  free(v2);
}
```

- Resposta
  - a free() é uma função para desalocar memória heap, no código a memória apontado por v2 é da memória stack
  - outro problema é que perdemos a referência da memória heap, logo ela não poderá ser desalocada até o término do programa.

Ex 4: Qual o problema com este trecho de código?

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
  char *v;

  for(int i=0; i < 9999999999; i++) {
    v = malloc(5000 * sizeof(char));
  }
}
```

- Resposta
  - A memória está sendo alocada em cada interação do for e não está sendo desalocada, o que inevitávelmente irá causar um estouro de memória (memory leak)
