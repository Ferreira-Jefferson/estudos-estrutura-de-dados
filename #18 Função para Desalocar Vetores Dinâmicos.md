## 18 Função para Desalocar Vetores Dinâmicos

# O problema: Criar uma função que desaloque a heap e defina o valor do ponteiro para NULL

```c
#include <stdio.h>
#include <stdlib.h>

void limpa_ponteiro(int *x) {
  free(x);
  x = NULL;
}

int main() {
  int *p = malloc(2 * sizeof(int));
  *p = 3;
  *(p + 2) = 5;

  printf("p: %p | p[0]: %d \n", p, p[0]);
  limpa_ponteiro(p);
  printf("p: %p | p[0]: %d \n", p, p[0]);
  return 0;
}

// p: 0x4392a0 | p[0]: 3
// p: 0x4392a0 | p[0]: 0
```

- Não se engane com o código acima, como pode ser visto no output, o ponteiro **P** ainda possui o endereço de memória da heap
- O que aconteceu é que o free liberou o endereço de memória heap, mas o null foi aplicado no ponteiro X e não no ponteiro **P**
- Note que ainda conseguimos ver o valor da heap por meio do **p[0]**, ele recebeu o valor NULL pela free(), não temos mais controle sobre ele, mas ainda conseguimos acessá-lo.

# Que tal mudarmos a abordagem para zerar o valor do que o X aponta?

```c
#include <stdio.h>
#include <stdlib.h>

void limpa_ponteiro(int *x) {
  free(x);
  *x = NULL;
}

int main() {
  int *p = malloc(2 * sizeof(int));
  *p = 3;
  *(p + 2) = 5;

  printf("p: %p | p[0]: %d \n", p, p[0]);
  limpa_ponteiro(p);
  printf("p: %p | p[0]: %d \n", p, p[0]);
  return 0;
}
// p: 0x12672a0 | p[0]: 3
// p: 0x12672a0 | p[0]: 0

```

- Errado novamente, o endereço que o **X** contém é o endereço da heap, que não está mais em nosso controle, o endereço da heap recebe NULL e com para apresentar o dado estamos usando a flag **%d** que espera por um inteiro, é aprensentado o valor **0**
- Percebe que esse espaço da heap não nos pertence mais, logo ele poderia estar sendo usado por um outro programa e teríamos mudado seu valor para NULL o que poderia resultar em um erro/bug em outro programa que estivesse rodando e usando este espaço de memória

# A Solução

```c
#include <stdio.h>
#include <stdlib.h>

void limpa_ponteiro(int **x) {
  free(*x);
  *x = NULL;
}

int main() {
  int *p = malloc(2 * sizeof(int));
  *p = 3;
  *(p + 2) = 5;

  printf("p: %p | p[0]: %d \n", p, p[0]);
  limpa_ponteiro(&p);
  printf("p: %p  \n", p);
  return 0;
}
// p: 0x20d42a0 | p[0]: 3
// p: (nil)
```

- A maneira correta é transformar **X** em um ponteiro de ponteiro, para que ele possa receber o endereço de **P** e manipular o **P** diretamente
- Note que desta vez o segundo printf não apresenta o valor contido em p[0], isso porquê como p[0] é igual a NULL, e NULL não é um endereço de memória, iríamos receber um erro de Segmantation fault

# Dica

- Lembre-se, nós não liberamos o ponteiro da stack, mas sim o espaço que estava sendo usado na heap, ou seja, nós pegamos o valor que o ponteiro aponta, que é o endereço inicial da memória alocada na heap e limpamos este valor da memória stack, ou seja a stack deixa de "monitorar" o endereço da stack e este endereço fica livre para ser usado por outro ponteiro deste ou de outro programa
  - free(endereço_heap) = liberar o endereço da heap
