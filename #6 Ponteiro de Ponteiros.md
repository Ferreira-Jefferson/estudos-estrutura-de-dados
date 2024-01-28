## 6 Ponteiro de Ponteiros

Ponteiros de ponteiros é um tipo de variável que guardo o endereço de um ponteiro, é declarado usando dois asteríscos antes do nome da variável.

- int \*p;
- int \*\*p = &p;

Tentar atribuir a um ponteiro de ponteiro um outro valor que não seja um endereço de ponteiro do mesmo tipo do ponteiro de ponteiro, acaretará em um erro, assim como é impossível adicionar algo diferente de um endereço de uma variável do mesmo tipo de um ponteiro a um ponteiro de variável;

- char c = 'A';
- int i = 10;
- int \*p = c; ❌: não é um endereço de variável
- int \*p = i; ❌: não é um endereço de variável
- int \*p = &c; ❌: o endereço não é de uma variável do mesmo tipo
- int \*p = &c; ✅: é um endereço e é do mesmo tipo

- int \*\*p = p; ❌: não é um endereço de ponteiro
- int \*\*p = \*p; ❌: não é um endereço de ponteiro
- int \*\*p = &p; ✅: é um endereço e é do mesmo tipo

O apontamento na linguagem C é indefinido, você pode sempre apontar o endereço de uma variável, ponteiro, ponteiro de ponteiro, ponteiro de ponteiro de ponteiro, etc. Sendo necessário apenas se atentar que o tipo que recebe o endereço deve um **"Ponteiro Superior"**, ou seja, se o endereço é de um ponteiro \*\*, a variável que irá receber o endereço do ponteiro deve ser \*\*\*.

Outro ponto interessante e também simples de entender é sobre a ecuperação de valores

- Se declaramos um ponteiro de ponteiro, usar um asterísco irá trazer o valor do ponteiro apontado, ou seja, o endereço da variável que o ponteiro aponta.
- Se quisermos o valor da variável é necessário apontar também para o endereço que o ponteiro aponta.
- Em resumo, se eu quiser obter o valor da variável que iniciou o apontamento, eu tenho que usar a mesma quantidade de asteríscos que o ponteiro em questão.
- No código abaixo isso pode ser melhor observado e entendido.

```c
#include <stdio.h>

int main(){
  int a = 10;
  int *p = &a;
  int **pp = &p;
  int ***ppp = &pp;

  printf("ppp: %p == &pp: %p \n", ppp, &pp);
  printf("*ppp: %p == pp: %p == &p: %p \n", *ppp, pp, &p);
  printf("**ppp: %p == &a: %p \n", **ppp, &a);
  printf("***ppp: %i == a: %i \n", ***ppp, a);
  return 0;
}

// ppp: 0x7ffc5fe70788 == &pp: 0x7ffc5fe70788
// *ppp: 0x7ffc5fe70780 == pp: 0x7ffc5fe70780 == &p: 0x7ffc5fe70780
// **ppp: 0x7ffc5fe7077c == &a: 0x7ffc5fe7077c
// ***ppp: 10 == a: 10
```
