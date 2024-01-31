## 10 Codificando Funções

Hands-on

- O professor nos convida a replicar o código aprensentado e ver quais são os resultados obtidos
- O objetivo é mostrar que os endereços das variáveis passadas por valor ou criadas localmente na função, possuem endereços não sequênciais ao do programa principal, mostrando assim que elas são alocadas em outra regão da memória
- Outro conhecimento adquirido é de que o endereço de uma variável passada por valor é diferente do endereço da variável declarada como parâmetro que a recebe o valor passado.

```c
#include <stdio.h>

int soma(int x, int y) {
  int z;
  z = x + y;

  puts("Função Soma");
  printf("&x: %p, x: %i \n", &x, x);
  printf("&y: %p, y: %i \n", &y, y);
  printf("&z: %p, z: %i \n\n", &z, z);

  return z;
}

int main(){
  int x = 10, y = 20, z;

  puts("Antes de chamar Soma");
  printf("&x: %p, x: %i \n", &x, x);
  printf("&y: %p, y: %i \n", &y, y);
  printf("&z: %p, z: %i \n\n", &z, z);

  z = soma(x, y);

  puts("Depois de chamar Soma");
  printf("&x: %p, x: %i \n", &x, x);
  printf("&y: %p, y: %i \n", &y, y);
  printf("&z: %p, z: %i \n\n", &z, z);

  return 0;
}

// Antes de chamar Soma
// &x: 0x7fff87fd1f8c, x: 10
// &y: 0x7fff87fd1f90, y: 20
// &z: 0x7fff87fd1f94, z: 0

// Função Soma
// &x: 0x7fff87fd1f5c, x: 10
// &y: 0x7fff87fd1f58, y: 20
// &z: 0x7fff87fd1f64, z: 30

// Depois de chamar Soma
// &x: 0x7fff87fd1f8c, x: 10
// &y: 0x7fff87fd1f90, y: 20
// &z: 0x7fff87fd1f94, z: 30

```
