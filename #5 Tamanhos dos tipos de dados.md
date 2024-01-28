## 5 Tamanhos dos tipos de dados

O professor explica que apesar de cada tipo possuir um tamanho próprio, os ponteiros, por outro lado, sempre possuem o mesmo tamanho, de acordo com a arquitetura do sistema

- Arquiteturas 32 bits o tamanho de um ponteiro é de 4 bytes
- Arquiteturas 64 bits o tamanho de um ponteiro é de 8 bytes

Isso é válido também para ponteiros de ponteiros, ponteiros de ponteiros de ponteiro, etc, pois no final ele sempre está guardando um endereço de memória e seu tamanho é fixo.

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
  short a = 10;
  float b = 50.2;
  char c = 'D';

  printf("[short] sizeof(a): %ld \n", sizeof(a));
  printf("[float] sizeof(b): %ld \n", sizeof(b));
  printf("[char] sizeof(c): %ld \n\n", sizeof(c));

  short *pa = &a;
  float *pb = &b;
  char *pc = &c;

  printf("[short*] sizeof(pa): %ld \n", sizeof(pa));
  printf("[float*] sizeof(pb): %ld \n", sizeof(pb));
  printf("[char*] sizeof(pc): %ld \n\n", sizeof(pc));

  short **ppa = &pa;
  short ***pppa = &ppa;
  printf("[short**] sizeof(ppa): %ld \n", sizeof(ppa));
  printf("[short***] sizeof(pppa): %ld \n", sizeof(pppa));

  return 0;
}

// [short] sizeof(a): 2
// [float] sizeof(b): 4
// [char] sizeof(c): 1

// [short*] sizeof(pa): 8
// [float*] sizeof(pb): 8
// [char*] sizeof(pc): 8

// [short**] sizeof(ppa): 8
// [short***] sizeof(pppa): 8
```
