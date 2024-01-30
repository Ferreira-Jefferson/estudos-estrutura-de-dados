## 8 Ponteiros: Exercícios

Teste de mesa

```c
#include <stdio.h>

int main(){
  int a,
   b,
   *p1,
   *p2;

  a = 4;
  b = 3;
  p1 = &a;
  p2 = p1;

  *p2 = *p1 + 3;
  b = b * (*p1);
  (*p2)++;
  p1 = &b;

  printf("*p1: %d, *p2: %d\n", *p1, *p2);
  printf("a: %d, b: %d\n", a, b);

  return 0;
}
```

- Dado o código acima, identifique o que acontece na memóra ram em cada execução de linha

  - Eu coloquei cada trecho do código em uma linha para facilitar a visualização do teste de mesa
  - \#\#\#\# representa algum lixo de memória

  | Linha | Memóra | Variável | Valor |
  | ----- | ------ | -------- | ----- |
  | 1     | 0x0    | a        | ####  |
  | 2     | 0x4    | b        | ####  |
  | 3     | 0x8    | \*p1     | ####  |
  | 4     | 0x16   | \*p2     | ####  |
  | 5     | 0x0    | a        | 4     |
  | 6     | 0x4    | b        | 3     |
  | 7     | 0x8    | p1       | 0x0   |
  | 8     | 0x16   | p2       | 0x0   |
  | 9     | 0x16   | \*p2     | 7     |
  | 10    | 0x4    | b        | 21    |
  | 11    | 0x16   | \*p2     | 8     |
  | 12    | 0x8    | p1       | 0x4   |

- Qual valor será retornado pelos 2 printf?
  - // *p1: 21, *p2: 8
  - // a: 8, b: 21
