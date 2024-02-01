## 13 Vetores Estáticos

# O que são Vetores?

- ´É a forma mais simples de estruturar elementos na linguagem C
- Um vetor é uma lista de elementos alocados sequêncialmente
- O vetor é **prativamente** ponteiro que aponta para o início de uma sequência

  - ⚠️: O vetor estático não chega a ser um ponteiro propriamente dito, pois ele não possui endereço próprio, essa é uma das peculiaridade do C, tanto o endereço do vetor, quanto o valor contido pelo vetor são o mesmo endereço que o endereço de seu primeiro índice `&v == v == &v[0]`

  - É importante notar que o vetor não sabe todos os endereços que ele possui
  - O que ele faz é a chamada **Aritmética de Ponteiro**, que nada mais é que à partir de um determinado ponto e sabendo o tipo do dado contido, é possível se deslocar a qualquer ponto do vetor
  - ⚠️: A Aritmética de Ponteiro permite você invadir um endereço de memória passando um índice que não pertence ao vetor declarado, isso porquê o vetor não sabe quais endereços ele possui, ele só sabe seu endereço inicial
    - `int v[2] = {2, 5}; int a = v[4];` => Não dará erro, mas o valor obtido é apenas _Lixo de Memória_

- Eles são representados colocando **[]** (colchetes) após o nome da variável `int nome_var[];`
- A declaração de um vetor reserva um espaço contínuo na memória
- O espaço total reservado é equivalente a (dimensão do vetor X tamanho do tipo)
- Dimensão do vetor, nada mais é do que a quantidade de valores que o vetor pode referenciar

  - Exemplo:
    - `int v[5]`
    - dimensão do vetor: 5
    - memória inicial: 0x3
    - espaço reservado: 5(dimensão do vetor) x 4(bytes) = 20 bytes
    - memória do último indice do vetor: 3 (end memória do índice inicial) + "espaço reservado" = 0x23

- Qunado valor acessar o valor de uma posição do vetor, usamos um número para isso, este número é chamado de **índice**
- A indexação do vetor inicia em **0**(zero) e vai até **N-1** onde N é a dimensão do vetor
- **Em C** a inserção de valores na declaração de um vetor é feita usando chaves `int v[2] = {10, 20};`
- Para acessar/usar o valor de um elemento usa-se o nome vetor, seguido por índice onde o valor está, dentro de colchetes `int recebe-valor-indice-2 = v[2] = 10;` | `printf("%d", v[2]);`
  - Internamente o sistema converte a nomemclatura do vetor para a nomenclatura de ponteiro clássico
    - _int recebe-valor-indice-2 = v[2]_ = 10; = **\*&(v + 2) = 10**
    - _printf("%d", v[2]);_ = **printf("%d", \*&(v + 2));**
    - 🤓 : O **v + 2** representa a _Aritmética de Ponteiro_

```c
#include <stdio.h>

int main(){
  int v[5] = {2,4,6,8,10};

  for(int i=0; i < 5; i++) {
    printf("&v[%d]: %p, v[%d]: %d \n", i, &v[i], i, v[i]);
  }

  printf("\n&v[8]: %p, v[8]: %d \n", &v[8], v[8]);
  return 0;
}

// &v[0]: 0x7ffc4696ce10, v[0]: 2
// &v[1]: 0x7ffc4696ce14, v[1]: 4
// &v[2]: 0x7ffc4696ce18, v[2]: 6
// &v[3]: 0x7ffc4696ce1c, v[3]: 8
// &v[4]: 0x7ffc4696ce20, v[4]: 10

// &v[8]: 0x7ffc4696ce30, v[8]: 1
```
