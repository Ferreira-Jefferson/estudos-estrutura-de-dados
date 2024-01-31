## 11 Funções - Passagem por Referência

Quando uma função recebe o endereço de uma variável por um parâmetro do tipo variável ponteiro, chamamos de passagem por referência

- Referência é é o mesmo que **Endereço de memória**, ou seja, estamos passando o valor de uma variável, não diretamente pelo valor, mas sim por seu endereço de memória, possibilitando que seu valor seja recuperado dentro da função
- Isso é particularmente interessante, pois possibilita alterar o valor de uma variável sem necessáriamente retornar um valor da função

```c
#include <stdio.h>

void minha_funcao(int *p, int a) {
  *p += a;

  puts("Dentro da função");
  printf("&a: %p, a: %d \n", &a, a);
  printf("&p: %p, p: %p, *p: %d \n\n", &p, p, *p);
}

int main(){
  int a = 10;

  puts("Antes da função");
  printf("&a: %p, a: %d \n\n", &a, a);

  minha_funcao(&a, 20);

  puts("Depois da função");
  printf("&a: %p, a: %d \n\n", &a, a);
  return 0;
}

// Antes da função
// &a: 0x7fff8ffb6f34, a: 10

// Dentro da função
// &a: 0x7fff8ffb6f14, a: 20
// &p: 0x7fff8ffb6f18, p: 0x7fff8ffb6f34, *p: 30

// Depois da função
// &a: 0x7fff8ffb6f34, a: 30
```

- Note que o parâmetro "a", nada tem a ver com a variável passada por referência, o parâmetro "a" só existe no escopo da função é como se na memória ela fosse salva com o nome "fn_a" em outro local da memória
  - Seguindo a lógica do que foi explicada e o exemplo acima, se você tentar criar dentro do corpo da função que possui um parâmetro com o nome "a" uma outra variável com o nome "a", dará um erro de _redeclaração_, pois o sistema tentará novamente criar uma variável com o nome "fn_a", mas essa já existe pois foi criada para ser o parâmetro da função `void minha_funcao(int a) { int a; } \\ERRO`
- Perceba que em nenhum momento a variável "a" em "main", recebeu uma atribuição direta, mas ainda assim seu valor foi alterado para 30, isso ocorreu porquê dentro da função "minha_funcao", o valor apontado por "p" foi alterado, recebendo seu próprio valor e adicionando o valor passado pelo parâmetro "a" `[*p += a;]`
