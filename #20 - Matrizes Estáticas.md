## 20 - Matrizes Estáticas

- Matrizes são vetores de duas ou mais dimensões
- Matrizes assim como vetores, são pseudo-ponteiros, ou seja, &matriz == matriz == &matriz[0][0]
- para declarar matrizes bidemensionais usamos dois colchetes, no primeiro é informado a quantidade de linhas e no segundo a quantidade de colunas: `nome_matriz[rows][cols]`
- para atribuir valores a uma matriz em sua inicialização usamos chaves aninhadas: `matriz[2][3] = {{1,2,3}, {4,5,6}}`
- a declaração de tipo ocorre normalmente seguindo a regra padrão da linguagem `int matriz[2][3] = {{1,2,3}, {4,5,6}}`
- Na memória os valores da matriz ficam alinhados sequêncialmente

| Endereço | Nome         | Valor |
| -------- | ------------ | ----- |
| 0x0      | matriz[0][0] | 1     |
| 0x4      | matriz[0][1] | 2     |
| 0x8      | matriz[0][2] | 3     |
| 0x12     | matriz[1][0] | 4     |
| 0x16     | matriz[1][1] | 5     |
| 0x16     | matriz[1][2] | 6     |

Ex: Codifique um programa que aloque uma matriz estática que imprima o endereço de cada elemento da matriz

```c
#include <stdio.h>

int main(){
  int matriz[2][3] = {{1,2,3}, {4,5,6}};
  int rows = 2;
  int cols = 3;

  printf("&matriz: %p \nmatriz: %p \n&matriz[0][0]: %p  \n\n", &matriz, matriz, &matriz[0][0]);

  for(int i=0; i < rows; i++) {
    for(int j=0; j < cols; j++){
      printf("&matriz[%d][%d]: %p | matriz[%d][%d]: %d\n", i, j, &matriz[i][j], i, j, matriz[i][j]);
    }
    puts("");
  }
  return 0;
}
```
